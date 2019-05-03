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
#define dd _CRT_SECURE_NO_WARNINGS
#define MOD 1000000007
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
const double eps = 1e-10;


using namespace std;
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 100222;
const int NZ = 111000;
const int MM = 151;
const int mask = (1 << 4);
const int need = (1 << 30) - 1;
int vv[NN];
int dp[111][3];
vector<int>gr[NN];
int n, k, m, s, x, a, b, c, q;
int l, pp, answww;
//1-contest,2-gym
// not consecutive 2-zero,3-one;

int main(){
	scanf("%d %d", &n, &m);
	if (m - (2 * n) > 2 || n - m > 1){
		puts("-1");
		exit;
	}

	if (m == n - 1){
		for (int i = 0; i < m; i++){
			printf("01");
		}
		puts("0");
		exit;
	}

	if (m == n){
		for (int i = 0; i < n; i++)
		{
			printf("10");
		}
		exit;
	}

	while (n){
		if (m == n || m == n + 1){
			m--, n--;
			printf("10");
		}
		else{
			printf("110");
			m -= 2, n -= 1;
		}
	}
	for (int i = 0; i < m; i++)printf("1");
	exit;
	PS;
}












