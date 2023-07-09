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
#include <stdio.h>
#define MOD 1000000007
#define exit return 0
#define inf 1000000000000000000LL
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
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 100111;
const int NZ = 111000;
const int MM = 151;

const int need = (1 << 30) - 1;

int n, m, s, x, i, j, q;
ll res1, res2;
ll coll;
ll dp[NN];
int l, pp;
int in[NN];
int cc[NN], vv[NN];
int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)scanf("%d", &vv[i]);
	for (int i = 0; i < n; i++){
		scanf("%d", &cc[i]);
		cc[i]--;
	}

	while (q--){
		ll a, b;
		scanf("%I64d %I64d", &a, &b);

		for (int i = 0; i < n; i++){
			dp[i] = -(1LL << 60);
		}
		int col[2] = { 0, 1 };

		for (int i = 0; i < n; i++){
			dp[cc[i]] = max(dp[cc[i]], max(dp[cc[i]] + vv[i] * a, vv[i] * b));

			ll maxwell = -(1LL << 60);
			for (int xx = 0; xx < 2; xx++){
				if (cc[i] != col[xx]){
					maxwell = max(maxwell, dp[col[xx]]);
				}
			}
			dp[cc[i]] = max(dp[cc[i]], maxwell + vv[i] * b);
			if (cc[i] != col[0] && dp[cc[i]]>dp[col[1]]){
				col[1] = cc[i];
			}
			if (dp[col[0]] < dp[col[1]]){
				swap(col[0], col[1]);
			}
		}
		ll answww = 0;
		for (int i = 0; i < n; i++){
			answww = max(answww, dp[i]);
		}
		printf("%I64d\n", answww);
	}

	exit;
}
