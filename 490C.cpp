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
const int NN = 1003000;
vector<set<int>>gr(NN);
int cc[NN], ff[NN];
//int dp[211][2][11][11];
int n, n1, k1, k2, k;
int m, s, x, c, d, e, q;
int dd;
int a, b, gg, rr;
int answww;
string op;
int a1, a2;
int main(){
	a1 = 10;
	a2 = 1;
	cin >> op;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < op.size(); i++){
		if (i>0){
			ff[i] = (ff[i - 1] * a1) % a + (op[i] - '0') % a;
			ff[i] %= a;
		}
		else{
			ff[i] = (op[i] - '0') % a;
		}
	}
	//	for (int i = 0; i <= op.size(); i++)cc[i] = 1;

	for (int i = op.size() - 1; i >= 1; i--){
		cc[i] = cc[i + 1] + a2* (op[i] - '0');
		a2 *= 10;
		a2 %= b;
		cc[i] %= b;

	}

	for (int i = 0; i < op.size() - 1; i++){
		if (!ff[i] && !cc[i + 1] && op[i + 1] != '0'){
			printf("YES");
			printf("\n");
			cout << op.substr(0, i + 1) << endl;
			cout << op.substr(i + 1, op.size() - i - 1);
			exit;
		}
	}
	puts("NO");
	exit;
	PS;

}


