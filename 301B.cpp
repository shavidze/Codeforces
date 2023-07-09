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
using namespace std;
int N, a, b, d, dist, c, m;
int K;
int dp[1234];
int in[inf];
int benefit[1234];
int X[125], Y[1254];

//int gr[1234][1234];
//int floyd[1234][1234];

int getAbs(int x, int y){
	return abs(X[x] - X[y]) + abs(Y[x] - Y[y]);
}

bool likeDJ(int mid){
	bool vis[125] = { 0 };
	memset(dp, -1, sizeof(dp));

	dp[1] = mid;
	priority_queue<PI>pq;
	pq.push(make_pair(dp[1], 1));


	while (!pq.empty()){

		PI nowa = pq.top();
		int v = nowa.second;
		int dst = nowa.first;

		pq.pop();
		//if (dp[v] < dst)continue;
		vis[v] = 1;
		if (v == N)return 1;

		for (int i = 1; i <= N; i++){
			if (vis[i])continue;
			if (dp[i] < dp[v] - d*getAbs(v, i) + benefit[i]){
				dp[i] = dp[v] - d*getAbs(v, i) + benefit[i];
				pq.push({ dp[i], i });
			}
		}
	}

	return 0;
}






//282231

#define PS system("pause") 

int main(){
	/*cin >> N >> d;*/
	scanf("%d %d", &N, &d);
	for (int i = 2; i <= N - 1; i++){
		//cin >> benefit[i];
		scanf("%d", &benefit[i]);
	}

	for (int i = 1; i <= N; i++){
		//cin >> X[i] >> Y[i];
		scanf("%d %d", &X[i], &Y[i]);
	}
				  //avejis gadazidva	
	ll s = 0, e = 555256060;
	ll mid = 0;
	int pas = -1;
	while (s <= e){
		mid = (s + e) >> 1;
		if (likeDJ(mid)){
			e = mid - 1;
			pas = mid;
		}
		else s = mid + 1;
	}
	printf("%d", pas);
	//PS;
	exit;









}



