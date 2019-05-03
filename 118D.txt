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
#include <sstream>
#include <stack>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#define MOD 100000000   
#define exit return 0
#define inf 10000000000
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define mid ((tl+tr)>>1)
#define SZ(x) ((int)x.size())
#define MX(a,b)a>b?a:b
const double eps = 1e-10;


using namespace std;
//using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;
string ss, ff;
const int NN = 3003;
vector<int>gr[NN];
int dp[111][111][11][11];
int n1, n2, k1, k2, k;
int m, s, x, a, b, c, d, e, q;
int dd;
int answww1, answww2;
int go(int aa, int bb, int ka, int ke){
	if (!aa && !bb)return 1;
	int res = dp[aa][bb][ka][ke];
	if (res != -1)return res;
	res = 0;
	if (ka != k1&&aa)res += go(aa - 1, bb, ka + 1, 0);
	res %= MOD;
	if (ke != k2&&bb)res += go(aa, bb - 1, 0, ke + 1);
	res %= MOD;
	dp[aa][bb][ka][ke] = res;
	res %= MOD;
	return res;
}

int answww;

int main(){

	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	memset(dp, -1, sizeof(dp));

	cout << (go(n1, n2, 0, 0)) % MOD;
	//PS;
	exit;


}
