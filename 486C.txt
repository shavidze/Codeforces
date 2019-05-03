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
//using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 201;
vector<int>gr[NN];
int n, k;
int m, s, x, a, b, c, d, e, q;
int answww;
int comp[NN], sz[NN], shv[NN][NN];
string in;
int AB(int i){
	return i >= 0 ? i : -i;
}

int weneed(int i){
	int xx = n - i - 1;

	int dif = AB((int)in[i] - (int)in[xx]);
	int diffse = 26 - dif;
	return min(diffse, dif);

}


int main(){
	scanf("%d %d", &n, &m);
	cin >> in;

	for (int i = 0; i < n / 2; i++){
		answww += weneed(i);
	}

	if (answww == 0){
		printf("%d\n", answww);
		exit;
	}

	m--;
	int l, r;

	if (m < n / 2){
		l = 0, r = n / 2;
	}
	else{
		l = n / 2, r = n;
	}

	int ll = 123456, rr = -1;
	for (int i = l; i < r; i++){
		if (in[i] != in[n - i - 1]){
			ll = min(ll, i);
			rr = max(rr, i);
		}
	}

	answww += (rr - ll) + min(AB(rr - m), AB(m - ll));
	printf("%d\n", answww);
	exit;
}
