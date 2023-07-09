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
#include <stack>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#define MOD 100000000   
#define exit return 0
#define inf 10000000000
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
#define MX(a,b)a>b?a:b
const double eps = 1e-10;


using namespace std;
//using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;
const int NN = 100300;
vector<set<int>>gr(NN);
int cc[NN], ff[NN];
int dp[211][2][11][11];
int n, n1, k1, k2, k;
int m, s, x, a, b, c, d, e, q;
int dd;
int answww;


int main(){
	scanf("%d %d", &n, &m);
	dd = 111111;
	for (int i = 1; i <= n; i++){
		scanf("%d", &cc[i]);
		dd = min(dd, cc[i]);
	}

	while (m--){
		scanf("%d %d", &a, &b);
		if (cc[a] != cc[b]){
			gr[cc[a]].insert(cc[b]);
			gr[cc[b]].insert(cc[a]);
		}
	}

	int col;

	for (int i = 1; i <= NN; i++){
		if (answww < gr[i].size()){
			col = i;
			answww = gr[i].size();
		}
	}
	for (int i = 1; i <= NN; i++){
		if (answww == gr[i].size()){
			col = min(col, i);
		}
	}
	if (answww == 0)printf("%d\n", dd); else
		printf("%d\n", col);
	exit;


}
