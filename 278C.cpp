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
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 2002;
vector<int>gr[NN];
ll n, k;
ll m, s, x, a, b, c, d, e, q;
int answww;
int in[NN], aa[NN], bb[3];
int dd[NN][NN];
const string al = "abcdefghijklmnopqrstuvwxyz";
map<char, int>ft;
string gg[NN];
int vis[NN];

void dfs(int v){
	vis[v] = 1;
	for (auto x : gr[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

int main(){

	scanf("%d %d", &n, &m);
	a = 1;

	for (int i = 1; i <= n; i++){
		scanf("%d", &k);
		if (k)a = 0;
		for (int xx = 1; xx <= k; xx++){
			scanf("%d", &b);
			b += n;
			gr[b].push_back(i);
			gr[i].push_back(b);
		}
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			answww++;
			dfs(i);
		}
	}

	answww -= 1;
	if (a){
		answww = n;
	}
	cout << answww;
	exit;
}
