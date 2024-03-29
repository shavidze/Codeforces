#include <iostream>
#include <algorithm>
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


// faster than scanf
int readInt() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch - '0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


const int NN = 170;
#define MOD 1000000007
//dig three six nine

//ll dp[52][52][52][52];

const int SZ = 200;
int N, M;
vector<int>pas;
//ll LP[SZ + 1];
vector<ll>pr;
//void SV(){
//	for (int i = 2; i <= SZ; i++){
//		if (LP[i] == 0){
//			LP[i] = i;
//			pr.push_back(i);
//		}
//
//		for (int j = 0; j < pr.size() && pr[j] <= LP[i] && i*pr[j] <= SZ; j++){
//			LP[i*pr[j]] = pr[j];
//		}
//	}
//
//}
int x;
bool dp[505][505][505];
int c[505];
int main() {

	N = readInt();
	M = readInt();

	for (int i = 0; i < N; i++){
		c[i] = readInt();
	}
	dp[0][0][0] = 1;
	dp[0][0][c[0]] = 1;
	dp[0][c[0]][0] = 1;
	for (int i = 1; i < N; i++){
		dp[i][0][0] = 1;
		for (int j = 0; j <= M; j++){
			for (int k = 0; k <= M; k++){
				if (c[i] <= j){
					dp[i][j][k] = max(dp[i - 1][j - c[i]][k], dp[i][j][k]);
				}
				if (c[i] <= k){
					dp[i][j][k] = max(dp[i - 1][j][k - c[i]], dp[i][j][k]);
				}
				dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k]);
			}
		}
	}

	for (int i = 0; i <= M; i++){
		if (dp[N - 1][i][M - i])pas.push_back(i);
	}

	printf("%d\n", pas.size());
	for (int x : pas){
		printf("%d", x);
		putchar(' ');
	}
	printf("\n");
	//system("pause");
	return 0;

}
