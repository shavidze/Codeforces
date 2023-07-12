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
#define MX(a,b)a>b?a:b
const double eps = 1e-10;


using namespace std;
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 2002;
vector<int>gr[NN];
ll n, k;
ll m, s, x, a, b, c, d, e, q;
int answww;
//int in[NN], aa[3], bb[3];
int dp[NN][NN];


int main(){
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	
	ll low = 1LL, high = 250000000000LL;


	while (low < high){

		ll ff = (low + high) / 2;
		ll pos = 0;
		for (int i = 1; i <= n; i++){
			pos += min(ff / i, m);
		}

		if (pos >= k){
			high = ff;
		}
		else low = ff + 1;
	}
	printf("%I64d\n", low);
	exit;
}


