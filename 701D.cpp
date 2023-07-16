#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#define REP(i,n)for(int i=0;i<n;i++)
#define REPP(i,n)for(int i=1;i<=n;i++) 
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;

const int NN = 170;
#define MOD 1000000007
//dig three six nine

//ll dp[52][52][52][52];
//int in[222];
const int SZ = 200;
int N, l, v1, v2, k;

ll LP[SZ + 1];
vector<ll>pr;
void SV(){
	for (int i = 2; i <= SZ; i++){
		if (LP[i] == 0){
			LP[i] = i;
			pr.push_back(i);
		}

		for (int j = 0; j < pr.size() && pr[j] <= LP[i] && i*pr[j] <= SZ; j++){
			LP[i*pr[j]] = pr[j];
		}
	}

}


#define PS system("pause")
#define exit return 0

//ll go(int dig, int thr, int six, int nine){
//	if (dig == 0){
//		if (thr == six&&six == nine&&thr > 0)return 1;
//		return 0;
//	}
//
//	if (dp[dig][thr][six][nine] != -1)return dp[dig][thr][six][nine];
//
//	ll res = 0;
//
//	for (int i = 0; i <= 9; i++){
//		if (i == 3){
//			res += go(dig - 1, thr + 1, six, nine);
//			res %= MOD;
//		}
//		else if (i == 6){
//			res += go(dig - 1, thr, six + 1, nine);
//			res %= MOD;
//		}
//		else if (i == 9){
//			res += go(dig - 1, thr, six, nine + 1);
//			res %= MOD;
//		}
//		else res += go(dig - 1, thr, six, nine);
//		res %= MOD;
//	}
//	res %= MOD;
//	dp[dig][thr][six][nine] = res;
//	return dp[dig][thr][six][nine];
//}

//ll doit(char in[]){
//	int three = 0;
//	int six = 0;
//	int nine = 0;
//	ll pas = 0LL;
//	int len = strlen(in);
//	int cur_len = len;
//	for (int i = 0; i < len; i++){
//		cur_len -= 1;
//		int D = in[i] - '0';
//		for (int j = 0; j < D; j++){
//			if (j == 3){
//				pas = (pas + go(cur_len, three + 1, six, nine)) % MOD;
//			}
//			else if (j == 6){
//				pas = (pas + go(cur_len, three, six + 1, nine)) % MOD;
//			}
//			else if (j == 9){
//				pas = (pas + go(cur_len, three, six, nine + 1)) % MOD;
//			}
//			else{
//				pas = (pas + go(cur_len, three, six, nine)) % MOD;
//			}
//
//		}
//		if (D == 3)three += 1;
//		if (D == 6)six += 1;
//		if (D == 9)nine += 1;
//	}
//	pas %= MOD;
//	return pas;
//}



//
int main() {
	cin >> N >> l >> v1 >> v2 >> k;
	double low = 0.;
	double high = 200000000001.;

	int autobus = (int)(N + k - 1.) / k;

	double C = autobus*1. / (v2 - v1) + (autobus - 1.) / (v1 + v2);

	printf("%.17f", l*C / (1. + C*v1));
	exit;
	//PS;
}
