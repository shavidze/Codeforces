#define _CRT_SECURE_NO_WARNINGS


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
#define ll long long
//using ul = unsigned long long;
using PII = pair<int, int>;
const long NN = (1 << 18);
int answww;
int n, m, q, d, a, b, c;
int x, y;
int zzz;
int tt[NN], in[NN];
int t[NN], vv[NN];
map<int, set<PII>>marj, marcx;
int T[11];
int main(){

	scanf("%d %d", &n, &m);

	vector<set<int>>rr(n);
	vector<set<int>>col(n);
	vector<PII>ssin(m);
	for (int i = 0; i < m; i++){
		scanf("%d %d", &ssin[i].first, &ssin[i].second);
		ssin[i].first--, ssin[i].second--;
		rr[ssin[i].first].insert(ssin[i].second);
		col[ssin[i].second].insert(ssin[i].first);
		marcx[ssin[i].first + ssin[i].second].insert({ ssin[i].first, ssin[i].second });
		marj[ssin[i].first - ssin[i].second + n].insert({ ssin[i].first, ssin[i].second });
	}
	for (auto xx : ssin){
		answww = 0;
		if ((int)rr[xx.first].size() > 1){
			answww += 2;
			// leftmost
			if (*rr[xx.first].begin() == xx.second)answww -= 1;
			//rightmost
			if (*rr[xx.first].rbegin() == xx.second)answww -= 1;
		}

		if ((int)col[xx.second].size() > 1){
			answww += 2;
			if (*col[xx.second].begin() == xx.first)answww -= 1;
			if (*col[xx.second].rbegin() == xx.first)answww -= 1;
		}

		if ((int)marcx[xx.second + xx.first].size() > 1){
			answww += 2;
			if (*marcx[xx.second + xx.first].begin() == xx)answww -= 1;
			if (*marcx[xx.first + xx.second].rbegin() == xx)answww -= 1;
		}

		if ((int)marj[xx.first - xx.second + n].size() > 1){
			answww += 2;
			if (*marj[xx.first - xx.second + n].begin() == xx)answww -= 1;
			if (*marj[xx.first - xx.second + n].rbegin() == xx)answww -= 1;
		}

		T[answww] += 1;
	}

	for (int i = 0; i < 9; i++){
		printf("%d ", T[i]);
	}
	printf("\n");
	return 0;
}

