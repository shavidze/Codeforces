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
const int NN = 100008;
int answww[NN];
int n, m, q, a, b, c;

char in[NN];

int main(){

	scanf("%s", &in);
	int sz = strlen(in);

	ll odd = 0;
	ll even = 0;
	//0-even,1-odd
	ll count[2][2];

	for (int i = 0; i < 2; i++)for (int j = 0; j < 2; j++)count[i][j] = 0;

	for (int i = 0; i < sz; i++){
		//ending wiht in[i]
		odd++;
		if (i % 2 == 0){
			//add ending in 
			even += count[1][in[i] - 'a'];
			odd += count[0][in[i] - 'a'];
			count[0][in[i] - 'a'] += 1;
		}
		else{
			even += count[0][in[i] - 'a'];
			odd += count[1][in[i] - 'a'];
			count[1][in[i] - 'a'] += 1;
		}

	}

	printf("%I64d %I64d", even, odd);

	return 0;
}






