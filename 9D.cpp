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
ll n, a, b, c, d, i, j, m, r, to;
int s[N], t[N], k;
//dynamic problem about like max sum without 2 adj 
//on tree
int road[N / 10][N / 10];
vector<int>gr[N];
int car[N][N];
int dp[N / 10][N / 10];
ll f[N][N];
int g[N / 10][N / 10][N / 10];
int over;
int main(){
	scanf("%d %d", &n, &m);
	//cin >> n >> m;
	f[0][0] = f[1][1] = 1;
	for (int i = 1; i <= n; i++){
		for (int h = 2; h <= n; h++){
			for (int j = 0; j < i; j++){
				for (int h1 = 0; h1 < h - 1; h1++){
					f[i][h] += f[j][h - 1] * f[i - j - 1][h1];
					f[i][h] += f[j][h1] * f[i - j - 1][h - 1];
				}
				f[i][h] += f[j][h - 1] * f[i - j - 1][h - 1];
			}
		}
	}
	ll pas = 0;
	for (int i = m; i <= n; i++){
		pas += f[n][i];
	}
	printf("%I64d\n ", pas);
	exit;
}
