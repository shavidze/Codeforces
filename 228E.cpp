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
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 222;
const int NZ = 111000;
const int MM = 151;
const int mask = 1 << 4;
const int need = (1 << 30) - 1;

int n, k, m, s, x, a, b, c, q;
int l, pp;
int in[NN], comp[NN];
bool used[NN];
vector<int>gr[NN], aa, bb;
stack<int>cc;
void addasp(int a, int b){
	a <<= 1, b <<= 1;
	gr[a].push_back(b);
	gr[b].push_back(a);
	gr[a ^ 1].push_back(b ^ 1);
	gr[b ^ 1].push_back(a ^ 1);
}

void notadd(int a, int b){
	a <<= 1, b <<= 1;
	gr[a ^ 1].push_back(b);
	gr[b].push_back(a ^ 1);
	gr[a].push_back(b ^ 1);
	gr[b ^ 1].push_back(a);
}

void dfs(int v, bool flag){
	used[v] = 1;
	for (auto x : gr[v]){
		if (!used[x]){
			dfs(x, flag);
		}
	}
	if (flag){
		comp[v] = c;
	}
	else{
		aa.push_back(v), cc.push(v);
	}
}
int main(){
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if (c){
			addasp(a, b);
		}
		else{
			notadd(a, b);
		}
	}

	for (int i = 2; i <= 2 * n + 1; i++){
		if (!used[i]){
			dfs(i, 0);
		}
	}

	memset(used, 0, sizeof(used));

	while (cc.size()){
		if (!used[cc.top()]){
			c++, dfs(cc.top(), 1);
		}
		cc.pop();
	}

	for (int i = 2; i <= 2 * n + 1; i++){
		if (comp[i] == comp[i ^ 1]){
			puts("Impossible");
			exit;
		}
	}
	memset(used, 0, sizeof(used));

	for (auto x : aa){
		if (!used[x / 2]){
			used[x / 2] = 1;
			if (x % 2 == 0){
				bb.push_back(x / 2);
			}
		}
	}

	printf("%d\n", bb.size());

	for (auto x : bb){
		printf("%d", x);
		puts(" ");
	}
	//QPS;
	exit;
}
