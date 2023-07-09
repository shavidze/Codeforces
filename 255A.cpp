#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000009
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
#define REP(i,a,n) for(i=a;i<n;i++)
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
#define REPP(i,a,n) for(i=a;i<=n;i++)
#include <cmath>
#define PI pair<int,int>
#include <cstdlib>
#define inf 1000007
#include <ctime>
#define exit return 0
using namespace std;


//int dp[1111][31111], h[N], c[N], jam[N], pas, NN, X;
int i, j, j3, k, KK, R, NN;
//vector<int>ans;

//http://www.spoj.com/problems/GREED/
//http://www.spoj.com/problems/TAXI/
//http://www.spoj.com/problems/IM/
//https://apps.topcoder.com/wiki/display/tc/SRM+578
//https://apps.topcoder.com/wiki/display/tc/TCO+2013+Round+2C
//https://apps.topcoder.com/wiki/display/tc/SRM+579#TravellingPurchasingMan
/*

string in;

bool MP[720];
int cap[720][720];*/
const int N = 222222;

ll in1[N], in2[N];

double duration;
int n, m, a, b, idi, X;

//ll rmq[N][21][2]
string s;
ll pas;
int R1, R2;

set<int>sz;
int dp[2][33][33][33][2], T, res;
int chest, bic, bck;

int main(){

	cin >> NN;
	REP(i, 1, NN + 1){
		cin >> res;
		if (i % 3 == 1){
			chest += res;
		}
		else if (i % 3 == 2)bic += res;
		else bck += res;
	}
	if (chest > bic&&chest > bck){
		cout << "chest" << endl;
	}
	else if (bic > chest&&bic > bck){
		cout << "biceps" << endl;
	}
	else{
		cout << "back" << endl;
	}

	exit;
}

