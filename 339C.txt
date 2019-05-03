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
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;
const int NN = 1008;
int answww[NN];
int n, m, q, a, b, c;
int dp[1001][11][11];
string in;
int dimms[NN];

int go(int raod, int prev, int balance){

	if (raod == m){
		printf("YES\n");
		for (int i = 0; i < m; i++){
			printf("%d ", answww[i]);
		}
		return 1;
	}

	if (dp[raod][prev][balance])return 0;
	dp[raod][prev][balance] = 1;
	for (int g = 0; g < 10; g++){
		if (in[g] == '1'&&g + 1 - balance>0 && g != prev){
			answww[raod] = g + 1;
			if (go(raod + 1, g, abs(g + 1 - balance)))return 1;
		}
	}
	return 0;
}


int main(){

	cin >> in;
	scanf("%d", &m);
	if (!go(0, 10, 0)){
		printf("NO");
	}

	return 0;
}






