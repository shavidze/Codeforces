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
#define PII pair<int,int>
#define MOD 1000000009
#define exit return 0
#define inf 100000000
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
int N;
int popcount(int x){ int cnt = 0; for (int i = 0; i < N; i++){ if (x&(1 << i)){ cnt++; } }	return cnt; }
int zzz = 0;
const int NN = 100022;

vector<pair<ll, ll>>cr;
map<PII, int>mp;
int  M, L, K;

ll dp[1 << 19][20];
int sat[22];
int xx[22][22];

int main(){

	scanf("%d %d %d", &N, &M, &K);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++){
		scanf("%d", &sat[i]);
	}
	int nn;
	nn = (1 << N);
	for (int i = 0; i < K; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		xx[a - 1][b - 1] = c;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++)dp[1 << i][i] = sat[i];
	for (int mask = 0; mask < nn; mask++){
		int cnt = popcount(mask);
		for (int i = 0; i < N; i++){
			if (mask&(1 << i)){
				// gamovrtot da gadavarchiot kvela wertili saidanac ak mosvla zagvizs :D
				int nmsk = mask ^ (1 << i);
				for (int x = 0; x < N; x++){
					if (mask&(1 << x)){
						dp[mask][i] = max(dp[mask][i], dp[nmsk][x] + xx[x][i] + sat[i]);
					}
				}
				if (cnt == M){
					ans = max(ans, dp[mask][i]);
				}
			}
		}
	}
	printf("%I64d\n", ans);
	exit;
	PS;
}








