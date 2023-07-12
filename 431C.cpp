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
#define N 223456
#define PS system("pause")
#define exit return 0
#define inf 12345678
#define left (v<<1)
#define right (left|1)
#define tm ((tl+tr)>>1)
typedef long long ll;
#define S 525231
using namespace std;
int n, k, d;
int f[N];
int dp[N][2];
int answ;
int flag = 0;
inline void add(int &a, int b){
	a += b;
	if (a >= MOD){
		a -= MOD;
	}
}
int main(){
	cin >> n >> k >> d;
	//cout << answ;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++){
		dp[i][0] = dp[i][1] = 0;
		for (int j = 1; j <= k; j++){
			if (i - j < 0)break;
			if (j < d){
				add(dp[i][0], dp[i - j][0]);
				add(dp[i][1], dp[i - j][1]);
			}
			else{
				add(dp[i][1], dp[i - j][0]);
				add(dp[i][1], dp[i - j][1]);
			}
		}
	}
	cout << dp[n][1] << endl;
	exit;
}
