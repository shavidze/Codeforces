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
#include <cstdlib>
#include <ctime>
#include <cstring>
#define ll long long
using namespace std;

ll powmod(ll a, ll b) { ll res = 1; for (; b; b >>= 1){ if (b & 1)res = res*a; a = a*a; }return res; }


int N, K;

int in[2222], C[2222];
int curMX;

int dp[2222];
bool check(ll mid){
	int ans = 0;
	for (int i = 0; i < N; i++)dp[i] = 0;
	for (int i = 0; i < N; i++){

		for (int j = 0; j < i; j++){

			if (abs(in[i] - in[j]) <= (i - j)*mid){
				dp[i] = max(dp[i], dp[j]);
			}
		}
		ans = max(ans, dp[i] += 1);
	}

	if (N - ans <= K)return 1;
	return 0;
}



int main(){

	cin >> N >> K;

	for (int i = 0; i < N; i++)cin >> in[i];

	ll low = -1, high = 2000000001;

	while (low + 1 < high){
		int mid = (low + high) / 2;

		if (check(mid))high = mid;
		else low = mid;
	}

	cout << high << endl;
	return 0;
}











