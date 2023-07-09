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
//using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 1011101;
const int NZ = 511100;
const int MM = 151;

const int need = (1 << 30) - 1;

int n, m, s, x, i, j, col[NN];

int l, pp;
int in[NN];
string s1, s2;
int xx[NN];
int did[NN], small[NN];
vector<pair<double, int>>res;
char ss[NN];
int main(){
	scanf("%s", &ss);
	int nn = strlen(ss);
	for (int i = 0; i < nn; i++){
		if (ss[i] == 'l'){
			did[x++] = i + 1;
		}
		else{
			small[s++] = i + 1;
		}
	}

	for (int i = 0; i < s; i++){
		printf("%d\n", small[i]);
	}

	for (int i = x - 1; i >= 0; i--){
		printf("%d\n", did[i]);
	}

	exit;
}
