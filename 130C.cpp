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
int n, A, B, a, b, i, j, k, m, pas;
int d[101][101];
int over;
int f[N][N];
vector<int>gr[N];
vector<ll>diff;
int in[N];
int ans;
int fix[N];
int fx = 0;
int maxind = 1;
int dst[N];
double was[N][N];
int go[N], en[N];
double maxWays;

int main(){
	cin >> n >> m;
	R1(i, n) R1(j, n) d[i][j] = 5555;
	R1(i, m){ cin >> a >> b; d[a][b] = d[b][a] = was[a][b] = was[b][a] = 1; }
	R1(k, n) R1(i, n) R1(j, n){
		int goman = d[i][k] + d[k][j];
		if (goman > d[i][j])continue;
		if (goman < d[i][j])was[i][j] = 0;
		was[i][j] += was[i][k] * was[k][j];
		d[i][j] = goman;
	}
	maxWays = was[1][n];
	for (int i = 2; i < n; i++){
		if (d[1][n] == d[1][i] + d[i][n]){
			maxWays = max(maxWays, 2 * was[1][i] * was[i][n]);
		}
	}
	if (n == 0)cout << maxWays << endl;
	else
		printf("%.12f", maxWays*1. / was[1][n]);
	exit;
	PS;

}
