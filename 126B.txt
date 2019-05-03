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
const int NN = 300011;
string in;
int dp[NN];
int tmp[NN];
int n, m, k, s, x, y, z, c, d, a, b, e, q, answww = 0;
vector<int>pp;

void pref(string ss){
	pp.resize(ss.length());
	int xx = 0;
	pp[0] = 0;
	for (int i = 1; i < ss.length(); i++){
		xx = pp[i - 1];
		while (xx>0 && ss[xx] != ss[i]){
			xx = pp[xx - 1];
		}
		if (ss[xx] == ss[i]){
			xx++;
		}
		pp[i] = xx;
	}
}


int main(){

	cin >> in;
	pp.resize(in.length());
	b = in.length();
	pref(in);
	int ff = pp[b - 1];
	string done = in.substr(0, ff);
	if (ff == 0){
		printf("Just a legend");
		exit;
	}

	for (int i = ff; i + 1 < b; i++){
		if (pp[i] == ff){
			cout << done << endl;
			exit;
		}
	}
	ff = pp[ff - 1];
	if (ff == 0){
		printf("Just a legend");
		exit;
	}

	string 	done1 = in.substr(0, ff);
	cout << done1 << endl;
	exit;




}






