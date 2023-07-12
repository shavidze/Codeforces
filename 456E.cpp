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
const int NN = 301008;

//ll aa[NN][NN], bb[NN][NN], cc[NN][NN], dd[NN][NN], in[NN][NN];
int comp[NN];
int n, m, q, a, b, c;
vector<int>gr[NN];
int dimms[NN];

int dm, out;

void dfs(int v, int par = -1, int dep = 0){
	if (dep >= dm)dm = dep, out = v;
	for (int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		if (to != par){
			dfs(to, v, dep + 1);
		}
	}
}

int find_set(int i){
	if (comp[i] == i)return i;
	return comp[i]=find_set(comp[i]);
}
int main(){

	scanf("%d %d %d", &n, &m, &q);

	for (int i = 1; i <= n; i++){
		comp[i] = i;
	}

	for (int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		int nv = find_set(a);
		int nc = find_set(b);
		if (nv == nc)continue;
		comp[nc] = nv;
		gr[a].push_back(b);
		gr[b].push_back(a);

	}

	for (int i = 1; i <= n; i++){
		if (find_set(i) == i){
			//find component diameter
			dm = 0;
			dfs(i);
			dm = 0;
			dfs(out);
			dimms[i] = dm;
		}
	}

	while (q--){
		scanf("%d ", &a);

		if (a == 1){
			scanf("%d", &b);
			printf("%d\n", dimms[find_set(b)]);
		}
		else{
			scanf("%d %d", &b, &c);
			if (rand()&1)swap(b, c);
			c = find_set(c);
			b = find_set(b);
			if (c == b)continue;
			comp[b] = c;
			dimms[c] = max(max(dimms[b], dimms[c]), (dimms[b] + 1) / 2 + (dimms[c] + 1) / 2 + 1);
		}
	}
	return 0;
}

