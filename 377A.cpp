#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

char cc[505][505];
bool vis[505][505];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isin(int x, int y){
	if (x > 0 && x <= n && y > 0 && y <= m)return 1;
	return 0;
}


void dfs(int x, int y){
	
	for (int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (isin(xx, yy) && cc[xx][yy] != '#'&&!vis[xx][yy]){
			vis[xx][yy] = 1;
			dfs(xx, yy);
		}
	}
	if (k>0)
	{

		if (cc[x][y] == '.'){
			cc[x][y] = 'X';
			k--;
		}
	}
}
#define PS system("pause")
int main(){

	scanf("%d %d %d", &n, &m, &k);
	int gox = 0, goy = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> cc[i][j];
		}
	}
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++){
		if (cc[i][j] == '.'&&k > 0){
			dfs(i, j);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cout << cc[i][j];
		}
		printf("\n");
	}
	return 0;
	PS;
}
