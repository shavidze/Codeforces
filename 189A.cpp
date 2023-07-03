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
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define exit return 0
#define inf 1000000000000000000LL
typedef long long ll;
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
const double eps = 1e-10;


using namespace std;

using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 543210;
const int NZ = 200022;
const int MM = 151;
const int need = (1 << 30) - 1;

int n, a, b, c;
int t;
int dp[4444444];
int main(){
	cin >> n >> a >> b >> c;

	int x = min(a, min(b, c));
	dp[a] = 1, dp[b] = 1, dp[c] = 1;
	for (int i = 0; i <= n; i++){
		if (dp[i] > 0){
			dp[i + a] = max(dp[i] + 1, dp[i + a]);
			dp[i + b] = max(dp[i] + 1, dp[i + b]);
			dp[i + c] = max(dp[i] + 1, dp[i + c]);
		}

	}
	cout << dp[n] << endl;
	exit;
	PS;
}





