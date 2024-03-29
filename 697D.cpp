#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;

ll powmod(ll a, ll b) { ll res = 1; for (; b; b >>= 1){ if (b & 1)res = res*a; a = a*a; }return res; }


static const int INF = 1000000000;
static const int MAX_N = 50;
static const int MAX_OP = 450;


int dp[MAX_N + 1][MAX_OP + 1][2];
int NN;

vector<int>D, R;
int T, X, S;
int RT;


//https://apps.topcoder.com/wiki/display/tc/SRM+537  dp
//https://apps.topcoder.com/wiki/display/tc/SRM+535  binary search

int pos;
int SM;
map<ll, ll>gr;
string in;
#define PS system("pause")
#define exit return 0



vector < int > g[100020];
double ans[100020];
int sz[100020];

int dfs1(int p, int u)
{
	for (int i = 0; i<g[u].size(); i++)
	if (g[u][i] != p)
	{
		dfs1(u, g[u][i]);
		sz[u] += sz[g[u][i]];
	}
	sz[u]++;
}
void dfs2(int p, int u)
{
	for (int i = 0; i<g[u].size(); i++)
	if (g[u][i] != p)
	{
		ans[g[u][i]] = ans[u] + 1.0*(sz[u] - sz[g[u][i]] - 1) / 2.0 + 1;
		dfs2(u, g[u][i]);
	}
}

int n, i, a;

int main()
{
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &a);
		g[a].push_back(i);
		g[i].push_back(a);
	}
	dfs1(0, 1);
	dfs2(0, 1);
	for (i = 1; i <= n; i++)
		printf("%.8f ", ans[i] + 1);
}
