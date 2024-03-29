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

using namespace std;

const int nmax = 101;
const int MOD = 1000000007;

int dp[nmax][nmax * nmax];
int C[nmax][nmax];
int powC[nmax][2];

int modpow(int x, long long p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return x;
	long long X = modpow(x, p / 2);
	X = (X * X) % MOD;
	if (p & 1)
		X = X * x % MOD;
	return X;
}

int main()
{
	int n, i, j, k, s;
	long long m;
	cin >> n >> m >> s;

	for (i = 0; i <= n; i++)
	{
		C[i][0] = 1;
		for (j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}

	for (i = 0; i <= n; i++)
	{
		powC[i][0] = modpow(C[n][i], m / n);
		powC[i][1] = powC[i][0] * 1LL * C[n][i] % MOD;
	}

	dp[0][0] = 1;
	for (i = 0; i < n; i++)
	for (j = 0; j <= s; j++)
	{
		if (dp[i][j] == 0) continue;
		for (k = 0; k <= n && j + k <= s; k++)
			dp[i + 1][j + k] = (dp[i + 1][j + k] + 1LL * dp[i][j] * powC[k][m % n > i]) % MOD;
	}

	cout << dp[n][s] << endl;

	return 0;
}
