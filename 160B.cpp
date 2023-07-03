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
#define N 123456
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
int n, a, b, c, d, i, j, k, m;
double f[N];
//dynamic problem about like max sum without 2 adj 
//on tree
vector<int>gr[N];
long long dp[185][185][185];
ll F[N], g[N], diameter;
ll sms;
int P;
double pasx;
int over;
int main(){
	cin >> n;
	R1(i, n){
		cin >> g[i];
		sms += g[i];
	}
	cin >> P;
	long double pas = 0.0;
	if (sms <= P){
		cout << n << endl; exit;
	}
	f[0] = 1;
	for (int i = 1; i <= 60; i++)f[i] = f[i - 1] * i;
	R1(over, n){
		R0(i, 70){
			R0(j, 60){
				R0(k, 60){
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][0] = 1;
		R1(i, n){
			R0(j, i + 1){
				R0(k, 60){
					if (dp[i - 1][j][k]){
						dp[i][j][k] += dp[i - 1][j][k];
						if (i != over){
							dp[i][j + 1][k + g[i]] += dp[i - 1][j][k];
						}
					}
				}
			}
		}
		R0(i, n + 1){
			R0(j, P + 1){
				if (j + g[over] > P){
					pasx += dp[n][i][j] / f[n] * f[i] * f[n - i - 1] * i;
				}
			}
		}
	}
	printf("%.10f", pasx);
	exit;
}
