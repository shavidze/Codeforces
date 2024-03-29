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
#define inc(A) cin>>A
#define ins(A) scanf("%d",&A)
#include <cstdlib>
#include <ctime>
#include <cstring>
#define ll long long
using namespace std;
#define NN 100010
int N, M, P[NN];
#define exit return 0
#define PS system("pause")
int type[NN], a, b;
int timer, s[NN], ds[NN], tin[NN], tout[NN];
vector<int> gr[NN];

void modify(int x, int v) {
	while (x <= N) {
		s[x] += v;
		x = (x | (x - 1)) + 1;
	}
}

int findsum(int x) {
	int v = 0;
	while (x > 0) {
		v += s[x];
		x &= x - 1;
	}
	return v;
}

void dfs(int v){
	tin[v] = ++timer;
	for (auto x : gr[v]){
		ds[x] = ds[v] + 1;
		dfs(x);
	}
	tout[v] = timer;
}

vector<int> qs[NN];
int x[NN], y[NN];
int result[NN];
int main(){

	inc(N); inc(M);

	for (int i = 1; i <= N; i++){
		P[i] = i;
		gr[i].clear();
	}

	vector<int>docm;
	for (int i = 0; i < M; i++){

		cin >> type[i];
		if (type[i] == 2){
			cin >> x[i];
			docm.push_back(i);
		}
		else{
			cin >> x[i] >> y[i];
			if (type[i] == 1){
				P[x[i]] = y[i];
				gr[y[i]].push_back(x[i]);
			}
			else{
				qs[docm[y[i] - 1]].push_back(i);
				result[i] = -1;
			}
		}
	}
	timer = 0;
	for (int i = 1; i <= N; i++){
		if (P[i] == i){
			ds[i] = 0;
			dfs(i);
		}
	}

	for (int i = 1; i <= N; i++){
		s[i] = 0;
	}

	for (int i = 0; i < M; i++){
		if (type[i] == 1){
			modify(tin[x[i]], 1);
			modify(tout[x[i]] + 1, -1);
			continue;
		}
		if (type[i] == 2){
			int from = x[i];
			for (int j = 0; j < qs[i].size(); j++){
				result[qs[i][j]] = 0;
				int to = x[qs[i][j]];
				if (tin[to] <= tin[from] && tout[from] <= tout[to]){
					if (findsum(tin[from]) - findsum(tin[to]) == ds[from] - ds[to]){
						result[qs[i][j]] = 1;
					}
				}
			}
			continue;
		}

		puts(result[i] ? "YES" : "NO");
	}
	return 0;
}
