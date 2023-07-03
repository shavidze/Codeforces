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
#define N 123457
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
vector<int>gr[N];
//int gr[55][55];
//vector<int>A, B;
//double L, R;





#define exit return 0
int col, PP, timer;
int sec[5005];
int depth[555555];

double pasux;
//https://apps.topcoder.com/wiki/display/tc/SRM+580
//https://community.topcoder.com/stat?c=problem_statement&pm=11616&rd=14548


void dfs(int v, int p = -1){
	for (auto x : gr[v]){
		if (x != p){
			depth[x] = depth[v] + 1;
			dfs(x, v);
		}
	}
}



int am, bm;
int main(){
	cin >> PP;
	for (int i = 0; i < PP - 1; i++){
		cin >> am >> bm;
		gr[am - 1].push_back(bm - 1);
		gr[bm - 1].push_back(am - 1);
	}

	dfs(0);
	//depth[1] = 0;
	for (int i = 1; i <= PP; i++)pasux += 1. / (depth[i] + 1);
	printf("%.17f", pasux);

	exit;
	//PS;
	//cout << dp[PP];
	//PS;

}
