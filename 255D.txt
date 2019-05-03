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
#define REP(i,a,n) for(i=(int)a;i<n;i++)
#define REPP(i,a,n) for(i=(int)a;i<=n;i++)
#include <cmath>
#define PI pair<int,int>
#include <cstdlib>
#define inf 1000007
#include <ctime>
#define exit return 0
#define N 1<<18
using namespace std;

vector<int>gr[N];
vector<int>pref[N];//k>j
vector<int>suff[N];//all child of i k<j-ze 
//number of substrings with sum 0
//dp-state number of valid substrings that ends with i ,sum of j 
int dp[1111][31111], h[N], c[N], jam[N], pas, NN, X;
int i, j, k, KK, R;
vector<int>ans;

void add(int x){
	if (x > MOD){
		x -= MOD;
	}
}



const int SUM = 10000;
#define PS system("pause")
int main(){

	cin >> NN;

	REP(i, 0, NN)cin >> c[i];
	//current index with sum of j
	dp[0][SUM] = 1;
	REP(i, 0, NN){

		REPP(j, 0, SUM + SUM){
			if (j >= c[i])
				dp[i + 1][j] += dp[i][j - c[i]];

			if (j + c[i] <= SUM + SUM)
				dp[i + 1][j] += dp[i][j + c[i]];
			dp[i + 1][j] %= MOD;

		}
		pas = (pas + dp[i + 1][SUM]) % MOD;
		//add(dp[i + 1][SUM]);
		dp[i + 1][SUM] += 1;
		dp[i + 1][SUM] %= MOD;
		//add(dp[i + 1][SUM]);

	}



	cout << pas;



	//PS;

	return 0;




}
