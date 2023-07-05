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
const double eps = 1e-10;


using namespace std;
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 1005;
const int NZ = 111000;
const int MM = 151;
const int mask = 1 << 4;
const int need = (1 << 30) - 1;
vector<int>gr[NN];
int n, k, m, s, x, a, b, c, d, e, q;
ll answww[NN], in[NN], aa[5];
#define MX(a,b)a>b?a:b
ll cur;
int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &in[i]);
	scanf("%I64d %I64d %I64d %I64d %I64d", &aa[0], &aa[1], &aa[2], &aa[3], &aa[4]);
	for (int i = 0; i < n; i++){
		cur += in[i];
		for (int j = 4; j >= 0; j--){
			answww[j] += (cur / aa[j]);
			cur %= aa[j];
		}

	}
	for (int i = 0; i < 5; i++){
		printf("%I64d ", answww[i]);
	}
	printf("\n");
	printf("%I64d\n", cur);
	exit;

}
