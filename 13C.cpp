#include <algorithm> 
#include <string> 
#include <vector> 
#include <queue> 
#include <iostream> 
#include <cmath> 
#include <sstream> 
#include <map> 
#include <set> 
#include <functional> 
using namespace std;
#define pb push_back 
#define MOD 1000000007
#define eps 1e-8
#define INF 1000000000 
#define L(s) (int)((s).size()) 
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++) 
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--) 
#define rep(i,n) FOR(i,1,(n)) 
#define rept(i,n) FOR(i,0,(n)-1) 
#define C(a) memset((a),0,sizeof(a)) 
#define ll long long 

//ll dp[10005][10055];// curprice,cur index


int NN, VV, K;

#define PS system("pause")
int in[5555];
int X, Y;
//string inn;

//int gr[55][55];
//vector<int>A, B;
//double L, R;





#define exit return 0
int col, PP, timer;
int sec[5005];
ll dp[2][5005];
int main(){
	scanf("%d", &NN);

	for (int i = 0; i < NN; i++){

		scanf("%d", &in[i]);
		sec[i] = in[i];
	}

	sort(sec, sec + NN);
	for (int i = 0; i < NN; i++){
		dp[0][i] = abs(in[0] - sec[i]);
	}

	for (int i = 0; i < NN - 1; i++){
		int ci = i & 1;
		int ni = 1 - ci;

		ll cur = 1e18;
		for (int j = 0; j < NN; j++){
			if (cur>dp[ci][j])cur = dp[ci][j];
			dp[ni][j] = cur + abs(in[i + 1] - sec[j]);
		}
	}
	int ci = (NN - 1) & 1;
	ll pas = 1e18;
	for (int i = 0; i < NN; i++){
		if (pas>dp[ci][i]){
			pas = dp[ci][i];
		}
	}
	printf("%I64d", pas);
	//-1 2 2 3 11

	//PS;


	exit;

}
