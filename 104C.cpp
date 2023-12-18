#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <utility>
#include <deque>
#include <ctime>
#include <sstream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define exit return 0
#define N 1555
#define inf 1000000000000000000LL
typedef long long ll;
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left v<<1
#define right left|1
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
using namespace std;
int _maxx, _maxy;
int n, i, j, k, l, m, a, b;
//bool gr[20][20], H[20][20];
//int low[1 << 20]; ll dp[1 << 20][20];
//int mask;
//ll tree[1200][1200][4];
map<int, int>mp;
int dont;
int in[1000005];
vector<int>sv;
ll dp[3232][2323];
ll C[10000055];
long long powerofn(int x, int y){
	if (!y) return 1;
	long long res = powerofn(x, y / 2);
	res = (res*res) % MOD;
	if (y & 1) res = (res*x) % MOD;
	return res;
}
bool lucky(int x){
	while (x){
		if (x % 10 != 4 && x % 10 != 7)return 0;
		x /= 10;
	}
	return 1;
}
ll pas;

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> in[i];
	for (int i = 0; i < n; i++)if (lucky(in[i]))mp[in[i]] += 1; else dont++;
	for (auto &x : mp){
		sv.push_back(x.second);
	}
	C[0] = 1;
	for (int i = 1; i <= n; i++)C[i] = C[i - 1] * i%MOD;
	dp[0][0] = 1;
	for (int i = 0; i < sv.size(); i++){
		for (int j = 0; j <= sv.size(); j++){
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * sv[i]) % MOD;
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;;
		}
	}
	for (int i = 0; i <= sv.size(); i++){
		if (i <= k&&k - i <= dont){
			b = C[dont];
			b = b*(powerofn(C[k - i], MOD - 2)) % MOD;
			b = b*powerofn(C[dont - k + i], MOD - 2) % MOD;
			pas = (pas + dp[sv.size()][i] * b) % MOD;
		}
	}
	cout << pas << endl;
	exit;
	PS;
}
```
