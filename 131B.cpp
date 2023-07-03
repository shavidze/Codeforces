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
int dp[(1 << 22) + 1];
int main(){
	for (int i = 1; i < (1 << 22); i++)dp[i] = -1;
    scanf("%d",&n);
	for (int i = 1; i <= n; i++){
	scanf("%d",&in[i]);
		dp[in[i]] = in[i];
	}
	for (int i = 1; i < (1 << 22); i++){
		if (dp[i]>0){
			for (int j = 0; j < 22; j++){
				dp[i | (1 << j)] = dp[i];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		printf("%d ", dp[((1 << 22) - 1) ^ in[i]]);
	}
	exit;
	PS;

}
