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
#define N 770
#define inf 1000000009
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
int n, a, b, c, d, i, j, m, r, to;
int s[N], t[N], k;
//dynamic problem about like max sum without 2 adj 
//on tree
int road[N / 10][N / 10];
vector<int>gr[N];
int car[N][N];
int dp[N / 10][N / 10];

//
int f[N / 10][N / 10][N / 10];
int over;
int main(){
	//cin >> n >> m >> r;
	scanf("%d %d %d", &n, &m, &r);
	R1(c, m){
		R1(j, n) R1(d, n)scanf("%d", &car[j][d]);
		R1(i, n) R1(j, n) R1(k, n) car[j][k] = min(car[j][k], car[j][i] + car[i][k]);
		R1(i, n) R1(j, n) if (c == 1 || dp[i][j] > car[i][j])dp[i][j] = car[i][j];
	}

	R1(i, n){
		R1(j, n) R0(k, n + 1) f[i][k][j] = dp[i][j];
		R0(k, n) R1(j, n) R1(d, n) f[i][k + 1][d] = min(f[i][k + 1][d], f[i][k][j] + dp[j][d]);
	}

	R0(i, r){
		//cin >> a >> b >> c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", f[a][min(c, n)][b]);
		//cout << << endl;
	}
	exit;
	PS;
}
