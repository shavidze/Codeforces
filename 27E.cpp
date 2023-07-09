#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <utility>
#include <deque>
#include <ctime>
#include <sstream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define exit return 0
#define N 1555
#define inf 1000000000000000000LL
typedef unsigned long long ll;
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
int nn, i, j, k, l, m, a, b;
ll dp[3232][2323];
vector<int> A;
ll primes[16] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };
ll pas = inf;
bool was[1005][15][77];
ll get[1005][15][77];
void dfs(int ps = 0, ll n = 1, int divnum = 1, int pr = 105){
	ll X = n;

	if (divnum == nn){
		pas = min(pas, n);
	}

	for (int i = 1; i <= pr; i++){
		ll Y = primes[ps];
		if (X > pas / Y)break;
		X *= Y;
		if (nn % (divnum*(i + 1)) == 0){
			dfs(ps + 1, X, divnum*(i + 1), i);
		}
	}
}

int main(){
	cin >> nn;
	//cout << pas << endl;
	dfs();
	//go();
	cout << pas << endl;
	exit;
}
