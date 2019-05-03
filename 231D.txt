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
const int NN = 1001;
//vector<set<int>>gr(NN);
//int cc[NN], ff[NN];
int dp[211][211];
int n, n1, k1, k2, k;
int m, s, x, y, z, xx, yy, zz, c, d, a, e, q;
int dd;
int aa[6];
int answww = 0;



int main(){


	cin >> x >> y >> z >> xx >> yy >> zz;

	for (int i = 1; i <= 6; i++){
		cin >> aa[i];
	}
	if (y < 0)answww += aa[1];
	if (y>yy)answww += aa[2];
	if (x < 0)answww += aa[5];
	if (x>xx)answww += aa[6];
	if (z < 0)answww += aa[3];
	if (z>zz)answww += aa[4];
	printf("%d\n", answww);
	exit;




}






