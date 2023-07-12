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
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000009
#define MN(a,b)a<b?a:b
#define N 223456
#define PS system("pause")
#define exit return 0
#define inf 12345678
#define left (v<<1)
#define right (left|1)
#define tm ((tl+tr)>>1)
typedef long long ll;
#define S 525231
using namespace std;
int m, n, x, y;
int i, j, k;
int ans;
vector<int>gr[S];
bool vis[S];
int Num[S];
int D[S];
int man[S];
int fen[S][2];
int timer; int timein[S], timeout[S];

void dfs(int v, int p = -1){
	timein[v] = ++timer;
	for (int i = 0; i < (int)gr[v].size(); i++){
		int to = gr[v][i];
		if (to != p){
			man[to] = 1 + man[v];
			dfs(to, v);
		}
	}
	timeout[v] = timer;
}

void update(int v, int tl, int tr, int l, int r, int val, bool add){
	if (tl > r || tr < l){
		return;
	}
	if (tl >= l&&tr <= r){
		fen[v][add] += val;
		fen[v][!add] -= val;
		return;
	}
	update(left, tl, tm, l, r, val, add);
	update(right, tm + 1, tr, l, r, val, add);
}

int get(int v, int tl, int tr, int pos, bool add){
	if (tl > pos || tr < pos)return 0;
	int answer = 0;
	answer += fen[v][add];
	if (tl == tr){
		return answer;
	}
	answer += get(left, tl, tm, pos, add);
	answer += get(right, tm + 1, tr, pos, add);
	return answer;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &Num[i]);
	}
	for (int i = 0; i < n - 1; i++){
		scanf("%d %d", &x, &y);
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1);
	while (m--){
		scanf("%d", &x);
		if (x == 1){
			scanf("%d %d", &y, &k);
			update(1, 1, n, timein[y], timeout[y], k, man[y] & 1);
		}
		else{
			scanf("%d", &y);
			int K = get(1, 1, n, timein[y], man[y] & 1);
			printf("%d\n", (K + Num[y]));
		}
	}
	exit;
}
/*
6 5
1 5
1 6
6 7
6 4
4 2
4 3
*/
