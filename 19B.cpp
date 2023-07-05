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
#define MOD 1000000009
#define exit return 0
#define N 1000005
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
int n, A, B, a, b, i, j, k, m, pas;
int d[101][101];
int over;
//int f[N][N];
vector<int>gr[N];
vector<ll>diff;
int in[N];
map<int, int>mp;
int used[N];
double maxWays;
const int mx = 2e3 + 555;
long long dp[mx][mx];
int t[N], c[N];
// find a subset of elements with minimal sum of c_i 
//whose sum of t_i + 1 does not exceed n, or something similar.
//This is solved by basic dp with two parameters, dp[i][j] 
//is minimal sum of subset of first i elements whose sum of t_i 
//is at least j.
int main(){

	scanf("%d ", &n);
	R0(i, n){
		scanf("%d %d", &t[i], &c[i]);
		t[i] += 1;
	}
	for (int i = 1; i <= n; i++)dp[0][i] = inf;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= n; j++){
			if (j >= t[i]){
				dp[i + 1][j] = min(dp[i][j], dp[i][j - t[i]] + c[i]);
			}
			else dp[i + 1][j] = min(dp[i][j], dp[i][0] + c[i]);
		}
	}
	printf("%I64d ", dp[n][n]);
	//cout << dp[n][n];
	exit;
	PS;

}
