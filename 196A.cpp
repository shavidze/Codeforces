#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define MN(a,b)a<b?a:b

using namespace std;
int i, j, n, m, A[100];
int dp[100];
int main(){

	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> A[i];
	}
	sort(A, A + m + 1);
	int ANS = INT_MAX;
	for (int i = 1; i <= m - n + 1; i++){
		ANS = MN(ANS, A[i + n - 1] - A[i]);
	}
	if (ANS == INT_MAX){
		cout << 0; return 0;
	}
	cout << ANS;
	return 0;
}
