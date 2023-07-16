#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <vector>
#define S 51234
#define ll long long
#define pb push_back
using namespace std;
vector<int>g[S];
int a[S][502];
int n, m;
ll ans;
void dfs(int start, int from = 0){
	a[start][0] = 1;
	for (int i = 0; i < (int)g[start].size(); i++){
		int to = g[start][i];
		if (to != from){
			dfs(to, start);
			for (int j = 0; j < m; j++){
				ans += a[start][j] * a[to][m - j - 1];
			}
			for (int j = 0; j < m; j++){
				a[start][j + 1] += a[to][j];
			}
		}
	}
}
int main(){
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
