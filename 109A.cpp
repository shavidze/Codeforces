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
int m, s, x, c, d, a, e, q;
int dd;
string s1, s2;
int answw = 1111111;

int f1 = -1;
int f2 = -1;
int main(){

	scanf("%d", &n);
	//sum,last digit
	for (int i = 0; 4 * i <= n; i++){
		if ((n - 4 * i) % 7 == 0){
			int b = (n - 4 * i) / 7;
			if (f1 == -1 || i + b <= f1 + f2){
				f1 = i; f2 = b;
			}
		}

	}
	if (f1 == -1 && f2 == -1){
		cout << -1 << endl;
	}
	for (int i = 0; i < f1; i++){
		cout << "4";
	}
	for (int i = 0; i < f2; i++){
		cout << "7";
	}
	cout << endl;

	exit;
}


