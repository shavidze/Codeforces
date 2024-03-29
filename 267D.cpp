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
#define MOD 1000000007
#define MN(a,b)a<b?a:b
#define PS system("pause")
#define exit return 0
#define inf 1000000000000000000LL
#define left (v<<1)
#define right (left|1)
#define tm ((tl+tr)>>1)
typedef long long ll;
#define S 525231
#define R0(i,n) for(int i=0;i<(int)n;i++)
#define R1(i,n) for(int i=1;i<=(int)n;i++)
using namespace std;
//vector<ll> dataMul(N), dataAdd(N);
int n, i, m, k, h, p, l, r;
string in, t;
map<string, int>MP;
vector<vector<int>>gr(222333);
vector < pair<ll, ll>>val;
vector<int>txt;
bool vis[223457];
ll dp[223457][2];
int col[223457];
int low[223457];
int timer, timein[234578], mark;
int N, M;
vector<int>ST;
void tarjan(int u, int p = -1){
	ST.push_back(u);
	vis[u] = 1;
	low[u] = timein[u] = ++timer;
	for (int &x : gr[u]){
		if (vis[x]){
			if (col[x] == 0){
				low[u] = min(low[u], timein[x]);
			}
		}
		else{
			tarjan(x);
			low[u] = min(low[u], low[x]);
		}
		if (dp[col[x]][0] == val[u].first){
			val[u].second = min(val[u].second, dp[col[x]][1]);
		}
		else if (dp[col[x]][0] < val[u].first){
			val[u].first = dp[col[x]][0];
			val[u].second = dp[col[x]][1];
		}
	}
	if (timein[u] == low[u]){
		while (!ST.empty()){
			int v = ST.back();
			ST.pop_back();
			col[v] = mark;
			if (dp[mark][0] == val[v].first)dp[mark][1] = min(dp[mark][1], val[v].second);
			else if (dp[mark][0] > val[v].first)dp[mark][0] = val[v].first, dp[mark][1] = val[v].second;
			if (v == u)break;
		}
		mark += 1;
	}

}

int main(){
	cin >> N;
	R0(i, N){
		cin >> in;
		int cnt = 0;
		for (int j = 0; j < in.size(); j++){
			in[j] = tolower(in[j]);
			if (in[j] == 'r')++cnt;
		}
		if (MP.find(in) == MP.end()){
			MP[in] = n++;
			val.push_back({ cnt, in.size() });
		}
		txt.push_back(MP[in]);
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> in >> t;
		int cnt = 0;
		for (int j = 0; j < in.size(); j++){
			in[j] = tolower(in[j]);
			if (in[j] == 'r')++cnt;
		}
		if (MP.find(in) == MP.end()){
			MP[in] = n++;
			val.push_back({ cnt, in.size() });
		}
		cnt = 0;
		for (int j = 0; j < t.size(); j++){
			t[j] = tolower(t[j]);
			if (t[j] == 'r')++cnt;
		}
		if (MP.find(t) == MP.end()){
			MP[t] = n++;
			val.push_back({ cnt, t.size() });
		}
		int a = MP[in], b = MP[t];
		gr[a].push_back(b);
	}
	for (int i = 0; i <= 200000; i++){
		for (int j = 0; j < 2; j += 1){
			dp[i][j] = inf;
		}
	}
	ll len = 0, pas = 0;
	mark = 1;
	for (int i = 0; i < txt.size(); i++){
		if (!vis[txt[i]])tarjan(txt[i]);
		pas += dp[col[txt[i]]][0], len += dp[col[txt[i]]][1];
	}
	cout << pas << " " << len << endl;
	exit;
	//PS;
}
