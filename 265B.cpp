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
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 1011101;
const int NZ = 511100;
const int MM = 151;

const int need = (1 << 30) - 1;

int n, m, s, x, i, j, col[NN];

int l;
ll in[NN];
string s1, s2;
int xx[NN];
int main(){
	cin >> n;
	int y = 0;
	for (int i = 1; i <= n; i++){
		cin >> xx[i];
	}
	y = xx[1] + 1;
	for (int i = 2; i <= n; i++){
		if (xx[i] != xx[i - 1]){
			y += 2 + abs(xx[i] - xx[i - 1]);
		}
		else{
			y += 2;
		}
	}
	cout << y;
	exit;
}
