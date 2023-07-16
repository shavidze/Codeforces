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
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000009
#define exit return 0
#define N 2234571
#define inf 1000000000000000000LL
typedef long long ll;
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left v<<1
#define right left|1
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
using namespace std;
ll n, a, b, i, j, pas;
ll dp[N][3];
int over;
vector<ll>pr;
vector<ll>diff;
int in[N];

void goprimes(ll a){
	for (int i = 2; i*i <= a; i++){
		if (a%i == 0){
			pr.push_back(i);
			while (a%i == 0){
				a /= i;
			}
		}
	}
	if (a > 1){
		pr.push_back(a);
	}
}
ll ans = inf;
//dp[n][3]->[0]-if haven't start to cut
//-->[1] if started and [2] if finished
void go(ll div){
	R1(i, n){
		dp[i][0] = dp[i][1] = dp[i][2] = inf;
		ll flag = -1;
		if (in[i - 1] % div == 0){
			flag = 0;
		}
		else if ((in[i - 1] + 1) % div == 0 || (in[i - 1] - 1) % div == 0){
			flag = 1;
		}
		if (flag != -1){
			dp[i][0] = dp[i - 1][0] + b*(ll)(flag);
			dp[i][2] = dp[i - 1][2] + b*(ll)(flag);
			dp[i][2] = min(dp[i][2], dp[i - 1][0] + b*(ll)(flag));
			dp[i][2] = min(dp[i][2], dp[i - 1][1] + b*(ll)(flag));
		}
		dp[i][1] = dp[i - 1][1] + a;
		dp[i][1] = min(dp[i][1], dp[i - 1][0] + a);
	}

	ll pas1 = min(dp[n][0], dp[n][1]);
	pas1 = min(pas1, dp[n][2]);
	ans = min(ans, pas1);
}
int main(){
	cin >> n >> a >> b;
	//scanf("%I64d %I64d %I64d", &n, &a, &b);
	R0(i, n){
		//cin >> in[i];
		scanf("%d", &in[i]);
	}
	goprimes(in[0]);
	goprimes(in[0] - 1);
	goprimes(in[0] + 1);
	goprimes(in[n - 1]);
	goprimes(in[n - 1] + 1);
	goprimes(in[n - 1] - 1);
	sort(pr.begin(), pr.end());
	diff.push_back(pr[0]);
	for (int i = 1; i <= pr.size() - 1; i++){
		if (pr[i] != pr[i - 1]){
			diff.push_back(pr[i]);
		}
	}
	//pr = diff;
	for (int i = 0; i < diff.size(); i++){
		go(diff[i]);
	}
	cout << ans << endl;
	//PS;
	exit;
}
