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
int zzz = 0;
const int NN = 100022;

vector<pair<ll, ll>>cr;
map<PII, int>mp;
int N, M, L, k;
int dp[30005][210][2][2][2];
int in[30005];

void made(int &a, int b){
	if (b > a)a = b;
}
int sign[2] = { 1, -1 };
int main(){

	cin >> N >> k;
	for (int i = 1; i <= N; i++){
		cin >> in[i];
	}
	for (int i = 0; i <= N + 1; i++){
		for (int j = 0; j <= k + 1; j++){
			for (int e = 0; e < 2; e++){
				for (int c1 = 0; c1 < 2; c1++){
					for (int c2 = 0; c2 < 2; c2++){
						dp[i][j][e][c1][c2] = -inf;
						if (j == 0 && e == 0){
							dp[i][j][e][c1][c2] = 0;
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < N; i++){
		for (int j = 0; j <= k; j++){
			for (int e = 0; e < 2; e++){
				for (int c1 = 0; c1 < 2; c1++){
					for (int c2 = 0; c2 < 2; c2++){
						if (dp[i][j][e][c1][c2] == -inf)continue;
						if (j == 0){
							dp[i + 1][j + 1][1][c1][c2] = max(dp[i + 1][j + 1][1][c1][c2], sign[c2] * in[i + 1]);
						}
						else if (j <= k - 1){
							dp[i + 1][j][1][c1][c2] = max(dp[i + 1][j][1][c1][c2], (j == 1 ? 0 : -sign[c1] * in[i + 1]) + sign[c2] * in[i + 1] + dp[i][j][e][c1][c2]);
							if (e == 0)dp[i + 1][j][e][c1][c2] = max(dp[i + 1][j][e][c1][c2], dp[i][j][e][c1][c2]);
							if (e != 0){
								for (int x = 0; x < 2; x++){
									dp[i + 1][j + 1][0][c2][x] = max(dp[i + 1][j + 1][0][c2][x], dp[i][j][e][c1][c2]);

									dp[i + 1][j + 1][1][c2][x] = max(dp[i + 1][j + 1][1][c2][x], -sign[c2] * in[i + 1] + (j == k - 1 ? 0 : sign[x] * in[i + 1]) + dp[i][j][e][c1][c2]);
								}
							}
						}
						else if (j == k){
							dp[i + 1][j][1][c1][c2] = max(dp[i + 1][j][1][c1][c2], -sign[c1] * in[i + 1] + dp[i][j][e][c1][c2]);
							if (e == 0){
								dp[i + 1][j][e][c1][c2] = max(dp[i + 1][j][e][c1][c2], dp[i][j][e][c1][c2]);
							}
						}
					}
				}
			}
		}
	}

	int ans = -inf;

	for (int i = 0; i <= N; i++){
		for (int c1 = 0; c1 < 2; c1++){
			for (int c2 = 0; c2 < 2; c2++){
				ans = max(ans, dp[i][k][1][c1][c2]);
			}
		}
	}


	printf("%d", ans);
	exit;
	PS;
}








