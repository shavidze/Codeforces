#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
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
#define ll long long
#include <cmath>
#define PI pair<int,int>
#include <cstdlib>
#define inf 1000007
#include <ctime>
#define exit return 0
#define N 222222
using namespace std;
vector<int>gr[N];
vector<int>pref[N];//k>j
vector<int>suff[N];//all child of i k<j-ze 
ll dp[N];
int ans[N];
void dfs(int x){
	dp[x] = 1;
	for (int &to : gr[x]){
		dfs(to);
		dp[x] = (dp[x] * 1LL * (dp[to] + 1)) % MOD;
	}

	int A = 1, B = 1;

	for (int i = 0; i < gr[x].size(); i++){
		int toLeft = gr[x][i];
		int NN = gr[x].size();
		int toRight = gr[x][NN - i - 1];

		pref[x].push_back(A);
		suff[x].push_back(B);

		A = (A * 1LL * (dp[toLeft] + 1)) % MOD;
		B = (B * 1LL * (dp[toRight] + 1)) % MOD;

	}

	reverse(suff[x].begin(), suff[x].end());

}



void doit(int v, int p = -1){
	ans[v] = dp[v];

	for (int i = 0; i < gr[v].size(); i++){
		int to = gr[v][i];
		int savechild = dp[to];
		int saveV = dp[v];

		dp[v] = (pref[v][i] * 1LL * suff[v][i]) % MOD;
		if (p != -1)dp[v] = (dp[v] * 1LL * (dp[p] + 1)) % MOD;
		dp[to] = (dp[to] * 1LL * (dp[v] + 1)) % MOD;
		doit(to, v);
		dp[v] = saveV;
		dp[to] = savechild;


	}


}

int NN;
int main(){

	cin >> NN;

	for (int i = 0; i < NN - 1; i++){
		int par;
		scanf("%d", &par);
		gr[par - 1].push_back(i + 1);

	}

	dfs(0);
	doit(0);

	for (int i = 0; i < NN; i++){
		if (i>0){
			puts("\n");
		}
		printf("%d", ans[i]);
	}


	return 0;




}


