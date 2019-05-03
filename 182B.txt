#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
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
#define ll long long
#include <cmath>
#include <cstdlib>
#define inf 1000007
#include <ctime>
#define exit return 0
using namespace std;
int N, a, b, d, dist, c, m;
int K;
ll dp[inf];
int in[inf];
int benefit[1234];
int X[1234], Y[1234];
int gr[1234][1234];
int floyd[1234][1234];
int main(){
	/*cin >> N >> d;*/
	scanf("%d %d", &N, &d);
	for (int i = 2; i <= N - 1; i++){
		//cin >> benefit[i];
		scanf("%d", &benefit[i]);
	}

	for (int i = 1; i <= N; i++){
		//cin >> X[i] >> Y[i];
		scanf("%d %d", &X[i], &Y[i]);
	}


	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == j){
				floyd[i][j] = floyd[j][i] = 0;
			}
			else{
				floyd[i][j] = (abs(X[i] - X[j]) + abs(Y[i] - Y[j]))*d - benefit[j];
			}
		}
	}

	for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	//cout << floyd[1][N];
	printf("%d", floyd[1][N]);
	exit;


}

