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
const double eps = 1e-10;


using namespace std;
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 100002;
const int NZ = 111000;
const int MM = 151;
const int mask = 1 << 4;
const int need = (1 << 30) - 1;
vector<int>gr[NN];
int up[NN][25];
int n, k, m, s, x, a, b, c, q;
int dp[322][322], tin[NN], tout[NN], timer, cc[NN];
map<PII, int>fx;
int cur[NN];
int answww[NN];
#define MX(a,b)a>b?a:b
void doit(int v, int p = 1){
	up[v][0] = p;
	tin[v] = ++timer;
	for (int i = 1; i <= 20; i++){
		up[v][i] = up[up[v][i - 1]][i - 1];
	}

	for (int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		if (to != p){
			doit(to, v);
		}
	}
	tout[v] = ++timer;
}


bool is_child(int a, int b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b){
	if (is_child(a, b))return a;
	if (is_child(b, a))return b;
	for (int i = 20; i >= 0; i--){
		if (!is_child(up[a][i], b)){
			a = up[a][i];
		}
	}
	return up[a][0];
}

void dfs(int v, int p = -1){

	for (auto x : gr[v]){
		if (x != p){
			dfs(x, v);
			cc[v] += cc[x];
			int ff = min(v, x);
			int se = max(v, x);
			answww[fx[{ff, se}]] = cc[x];
		}
	}
}

int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n - 1; i++){
		scanf("%d %d", &a, &b);
		gr[a].push_back(b);
		gr[b].push_back(a);
		if (a > b)swap(a, b);
		fx[{a, b}] = i;
	}
	doit(1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		cc[a] += 1; cc[b] += 1;
		cc[lca(a, b)] -= 2;
	}

	dfs(1);

	for (int i = 1; i < n; i++){
		printf("%d\n", answww[i]);
	}
	exit;

}
