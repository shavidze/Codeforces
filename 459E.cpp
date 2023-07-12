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
const int NN = 300011;

int dp[NN];
int tmp[NN];
int n, n1, k1, k2, k;
int m, s, x, y, z, xx, yy, zz, c, d, a, b, e, q;
int answww = 0;

vector <pair<int, int>> gr[NN + 2];

int main(){

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);

		gr[c].push_back({ a, b });
	}

	for (int i = 1; i <= NN; i++){

		for (auto gg : gr[i]){
			tmp[gg.second] = 0;
		}
		//best v with this weight increasing sequences
		for (auto gg : gr[i]){
			tmp[gg.second] = max(tmp[gg.second], dp[gg.first] + 1);
		}
		//update answers for each vertex
		for (auto gg : gr[i]){
			dp[gg.second] = max(dp[gg.second], tmp[gg.second]);
		}
	}

	for (int i = 1; i <= n; i++){
		answww = max(answww, dp[i]);
	}

	printf("%d\n", answww);
	exit;




}






