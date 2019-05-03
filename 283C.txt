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
#define NN 444
#define MOD 1000000007
#include <cstring>
#define md 100000
#define ll long long
#define VI vector<int>
#define PS system("pause")
#define exit return 0
ll N, q, t;
ll dp[1111111];
ll in[NN], b[NN], c[NN];
bool p[NN];
ll gr[NN];

using namespace std;


int main() {
	memset(gr, -1, sizeof(gr));
	cin >> N >> q >> t;
	for (int i = 0; i < 444; i++)p[i] = 1;
	for (int i = 0; i < N; i++)cin >> in[i];

	for (int i = 0; i < q; i++){
		cin >> b[i] >> c[i];
		b[i] -= 1, c[i] -= 1;
		gr[b[i]] = c[i];
		p[c[i]] = 0;
	}

	int K = 0;
	for (int i = 0; i < N; i++){
		if (!p[i])continue;

		int on = i;
		ll sm = 0;
		while (on != -1){
			sm += in[on];
			in[on] = sm;
			if (gr[on] != -1)t -= sm;
			K++;
			on = gr[on];
		}
	}
	if (t < 0 || K != N){
		cout << 0 << endl;
		//PS;
		exit;
	}
	dp[0] = 1;

	for (int i = 0; i < N; i++){
		for (ll j = 0; j <= t; j++){
			if (j + in[i] <= t){
				dp[j + in[i]] = (dp[j] + dp[j + in[i]]) % MOD;
			}
		}
	}

	cout << dp[t];
	//PS;
	return 0;

}




