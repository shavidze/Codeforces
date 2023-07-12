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
const int NN = 100011;
int aa[NN], cc[NN];
string in;
int dp[NN];
int tmp[NN];
int n, m, k, s, x, y, z, c, d, a, b, e, q, answww = 0;
vector<int>pp;





int main(){

	set<int>xt;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &aa[i]);
	}
	sort(aa, aa + n);
	if (n == 1)
	{
		puts("-1");
		return 0;
	}

	int bb = 0;
	for (int i = 0; i < n; i++){
		if (aa[i] != aa[0]){
			bb = 1;
		}
	}
	if (bb == 0){
		printf("%d\n", 1);
		printf("%d", aa[0]);
		exit;
	}
	for (int i = 1; i < n; i++){
		cc[i] = aa[i] - aa[i - 1];
	}
	sort(cc, cc + n);
	if (n == 2){
		pp.push_back(aa[0] - (aa[1] - aa[0]));
		if ((aa[0] + aa[1]) % 2 == 0){
			pp.push_back((aa[0] + aa[1]) / 2);
		}
		pp.push_back(aa[1] + (aa[1] - aa[0]));
		printf("%d\n", pp.size());
		for (int i = 0; i < pp.size(); i++){
			printf("%d ", pp[i]);
		}
		return 0;
	}

	if (cc[1] == cc[n - 1]){
		printf("%d\n", 2);
		printf("%d %d", aa[0] - cc[1], aa[n - 1] + cc[1]);
		return 0;
	}
	if (cc[1] == cc[n - 2] && cc[n - 1] == 2 * cc[1]){
		for (int i = 1; i < n; i++){
			if (aa[i] - aa[i - 1] == cc[n - 1]){
				printf("%d\n", 1);
				printf("%d", (aa[i] - aa[i - 1]) / 2 + aa[i - 1]);
				return 0;
			}
		}
	}
	puts("0");
	//PS;
	exit;




}






