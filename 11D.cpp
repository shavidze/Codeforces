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
#include <functional>
#include <utility>
#include <deque>
#include <ctime>
#include <sstream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
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

int n, i, j, k, l, m, a, b;

bool gr[20][20], H[20][20];
int low[1 << 20]; ll dp[1 << 20][20];
int mask;
ll pas;
int main(){
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	R0(i, m){
		//cin >> a >> b;
		scanf("%d %d", &a, &b);
		a--, b--;
		gr[a][b] = gr[b][a] = 1;
	}

	R0(mask, (1 << n)){
		if (mask != 0){
			for (j = 0; j < n; j++){
				if (mask &(1 << j)){
					break;
				}
			}
			low[mask] = j;
		}
	}


	for (int i = 0; i < n; i++){
		dp[1 << i][i] = 1;
	}



	for (int mask = 0; mask < (1 << n); mask++){
		for (int j = 0; j < n; j++){
			if (dp[mask][j]>0){
				for (int i = low[mask] + 1; i < n; i++){
					if (gr[j][i] && !(mask & (1 << i))){
						dp[mask ^ (1 << i)][i] += dp[mask][j];
					}
				}
			}
		}
	}


	for (int mask = 0; mask < (1 << n); mask++){
		if (__builtin_popcount(mask) >= 3){
			for (int i = 0; i < n; i++){
				if (gr[i][low[mask]]){
					pas += dp[mask][i];
				}
			}
		}
	}

	pas /= 2;
	printf("%I64d", pas);
	exit;
	PS;
}
