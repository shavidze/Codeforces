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
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define MN(a,b)a<b?a:b
#define PS system("pause")
#define exit return 0
#define inf 1000000000000000000LL
#define left (v<<1)
#define right (left|1)
#define tm ((tl+tr)>>1)
typedef long long ll;
#define S 52523
#define R0(i,n) for(int i=0;i<(int)n;i++)
#define R1(i,n) for(int i=1;i<=(int)n;i++)
using namespace std;
//vector<ll> dataMul(N), dataAdd(N);
const int NS = 2700;
const int N = 750;
int n, i, m, k, h, p, l, r, timer;
int dp[NS][NS];
int X[55];
char NX[NS];
char in[S];
int L[N], R[N];
int parent[N][N];
void go(int v, int SZ){
	if (SZ == 0)return;
	int mid = parent[v][SZ];
	printf("(");
	go(v + 1, mid);
	printf(")");
	go(v + mid + 1, SZ - mid - 1);
}

int main(){
	cin >> n;
	R0(i, n)cin >> L[i] >> R[i];
	for (int i = 0; i <= n; i++)dp[i][0] = 1;

	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j < n - i; j++){
			for (int k = 0; k <= j; k++){
				if (L[i] <= 2 * k + 1 && 2 * k + 1 <= R[i] && dp[i + 1][k] && dp[i + k + 1][j - k]){
					dp[i][j + 1] = 1;
					parent[i][j + 1] = k; break;

				}
			}
		}
	}
	if (dp[0][n])go(0, n), puts("");
	else puts("IMPOSSIBLE");
	exit;
}
