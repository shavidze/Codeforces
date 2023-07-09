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
#define S 525231
#define R0(i,n) for(int i=0;i<(int)n;i++)
#define R1(i,n) for(int i=1;i<=(int)n;i++)
using namespace std;
//vector<ll> dataMul(N), dataAdd(N);
int n, i, m, k, h, p, l, r;
ll dp[2][555][555];
int *col;
char C[555][555];
int N, M;
vector<int>ST;

inline void add(int &x, int y){
	x += y;
	if (x >= MOD){
		x -= MOD;
	}
}

bool inC(int x){
	return (x >= 1 && x <= M);;
}
bool inR(int x){
	return (x >= 1 && x <= N);
}

inline bool valid(int x1, int y1, int x2, int y2){
	return (inR(x1) && inC(y1) && inR(x2) && inC(y2));
}

inline ll go(int x1, int y1, int x2, int y2){
	if (valid(x1, y1, x2, y2))return dp[x1 & 1][y1][x2];
	return 0;
}



int main(){
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			C[i][j] = getchar();
		}
		getchar();
	}
	for (int i = (N + M); i >= 2; i--){
		for (int x1 = N; x1 >= 1; x1--){
			int y1 = i - x1;
			for (int x2 = N; x2 >= 1; x2--){
				int y2 = N + M - x2 - x1 - y1 + 2;
				if (!valid(x1, y1, x2, y2))continue;
				else if (C[x1][y1] != C[x2][y2])dp[x1 & 1][y1][x2] = 0;
				else if (abs(x2 - x1) + abs(y2 - y1) <= 1)dp[x1 & 1][y1][x2] = 1;
				else if (y1 > y2 || x1 > x2)dp[x1 & 1][y1][x2] = 0;
				else {
					int pas = 0;
					int toadd = go(x1 + 1, y1, x2, y2 - 1);
					add(pas, toadd);
					toadd = go(x1 + 1, y1, x2 - 1, y2);
					add(pas, toadd);
					toadd = go(x1, y1 + 1, x2, y2 - 1);
					add(pas, toadd);
					toadd = go(x1, y1 + 1, x2 - 1, y2);
					add(pas, toadd);
					dp[x1 & 1][y1][x2] = pas;
				}
			}
		}
	}
	printf("%I64d", dp[1][1][N]);
	exit;
	PS;


	exit;


	//PS;
}
