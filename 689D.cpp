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
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
#define REPP(i,a,n) for(i=(int)a;i<=n;i++)
#include <cmath>
#define PI pair<int,int>
#include <cstdlib>
#define inf 1000007
#include <ctime>
#define exit return 0
using namespace std;


//int dp[1111][31111], h[N], c[N], jam[N], pas, NN, X;
int i, j, k, KK, R, NN;
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
ll m, a, b, idi, X;

//ll rmq[N][21][2];
multiset<ll>s1, s2, t1, t2;


int MX(multiset<ll>&s){
	multiset<ll>::reverse_iterator it = s.rbegin();
	return *it;
}

int MN(multiset<ll>&s){
	multiset<ll>::iterator it = s.begin();
	return *it;
}

string s;
ll pas;
int R1, R2;
int main(){
	//clock_t start;
	//start = clock();
	//scanf_s("%I64d", &NN);

	cin >> NN;
	for (int i = 1; i <= NN; i++)cin >> in1[i];//scanf_s("%I64d", &in1[i]);
	for (int i = 1; i <= NN; i++)cin >> in2[i];//scanf_s("%I64d", &in2[i]);
	R1 = NN, R2 = NN;
	for (int i = NN; i >= 1; i--){
		s1.insert(in1[i]);
		s2.insert(in1[i]);
		t1.insert(in2[i]);
		t2.insert(in2[i]);

		while ((int)s2.size()  && MX(s2) > MN(t2)){
			auto x = s2.find(in1[R2]);
			s2.erase(x);
			auto y = t2.find(in2[R2]);
			t2.erase(y);
			R2--;

		}

		while ((int)s1.size() && MX(s1) >= MN(t1)){
			auto x = s1.find(in1[R1]);
			s1.erase(x);
			auto y = t1.find(in2[R1]);
			t1.erase(y);
			R1--;
		}
		pas += R2 - R1;
	}

	cout << pas << endl;


	//system("pause");
	exit;
	return 0;

}

