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
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#define MOD 1000000007
#define exit return 0
#define inf 1000000000000000000LL
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

using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 200111;
const int NZ = 1111;
const int MM = 151;

const int need = (1 << 30) - 1;

//car,road a-b

int n, m, s, x, t, a, b, k, c, r, col[NN];
vector<int>gr[NN];
double xx1, yy1, r1, xx2, yy2, r2;
int main(){

	cin >> xx1 >> yy1 >> r1;
	cin >> xx2 >> yy2 >> r2;

	double efs = 1e-6;

	double man = hypot((xx2 - xx1), (yy2 - yy1));
	double h = man;
	man -= (r1 + r2);
	if (man > 0){
		printf("%.18f", max(0.0, man / 2.0));
	}
	else{
		printf("%.18f", max((max(r1, r2) - h - min(r1, r2)) / 2.0, 0.0));
	}

	exit;
	PS;









}


