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

const int NN = 100007;
const int NZ = 511100;
const int MM = 151;

const int need = (1 << 30) - 1;

int n, m, s, x, i, j, dp[NN], col[NN];

int l, pp;
int in[NN];
string s1, s2;
int xx[NN];
int did[NN], small[NN];
vector<pair<double, int>>res;
char ss[NN];
int main(){


	scanf("%d", &n);
	int answww = 0;
	R0(i, n)scanf("%d", &in[i]);

	for (int i = 0; i < n; i++){
		dp[in[i]] = 1;
		vector<int>div;
		int y = in[i];

		for (int j = 1; j *j <= y; j++){
			if (y%j == 0){
				if (j != 1)
					div.push_back(j);
				if (y / j != j){
					if (y / j != 1)
						div.push_back(y / j);
				}
			}
		}

		for (int j = 0; j < div.size(); j++){
			dp[in[i]] = max(dp[in[i]], col[div[j]] + 1);
		}

		for (int j = 0; j < div.size(); j++){
			col[div[j]] = dp[in[i]];
		}
		answww = max(answww, dp[in[i]]);
	}



	printf("%d\n", answww);




	//PS;
	exit;
}
