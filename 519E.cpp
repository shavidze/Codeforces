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
#define MOD 1000000009
#define exit return 0
#define inf 1000000000000000000LL
typedef long long ll;
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
int zzz = 0;
const int NN = 111222;
int N, M;
int pas;
vector<int>gr[NN];


int dp[NN];
int depth[NN], sz[NN], tin[NN], tout[NN], timer, up[NN][20];
void go(int v, int p = 1, int d = 0){
	up[v][0] = p;
	depth[v] = d;
	sz[v] = 1;
	tin[v] = timer++;
	for (int i = 1; i <= 19; i++){
		up[v][i] = up[up[v][i - 1]][i - 1];
	}

	for (int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		if (to != p){
			go(to, v, d + 1);
			sz[v] += sz[to];
		}
	}
	tout[v] = timer++;
}


bool isIn(int a, int b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b){
	if (isIn(a, b))return a;
	if (isIn(b, a))return b;
	for (int i = 19; i >= 0; i--){
		if (!isIn(up[a][i], b)){
			a = up[a][i];
		}
	}
	return up[a][0];
}
int doit(int a, int b){
	for (int i = 19; i >= 0; i--){
		if (!isIn(up[a][i], b)){
			a = up[a][i];
		}
	}
	return a;
}
int getr(int a, int b){
	int lc = lca(a, b);

	int res = -1;

	if (a == b){
		res = N;
	}
	else if (depth[a] - depth[lc] == depth[b] - depth[lc]){
		a = doit(a, lc);
		b = doit(b, lc);
		res = N - sz[a] - sz[b];
	}
	else{
		if (depth[a] < depth[b]){
			swap(a, b);
		}

		int to = a;

		int dst = depth[a] + depth[b] - 2 * depth[lc];

		if (dst % 2){
			res = 0;
		}
		else{
			dst /= 2;

			for (int i = 19; i >= 0; i--){
				if (depth[a] - depth[up[to][i]] < dst){
					to = up[to][i];
				}
			}
			int md = up[to][0];
			res = sz[md] - sz[to];
		}
	}

	return res;
}
int main(){
	cin >> N;

	for (int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	go(1);
	cin >> M;
	while (M--){
		int a, b;
		cin >> a >> b;
		int c = getr(a, b);
		cout << c << endl;
	}
	return 0;
	PS;
}
