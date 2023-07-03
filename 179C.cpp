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
#include <ctime>
#define exit return 0
using namespace std;
int N, a, b, c, m;
int K;
int won[55];
ll go[222][55][55];//50,100,boatid
int fix[5555];
ll C[55][55];
int ax[5555];
vector<int>gr[5555];


void binom(){
	for (int i = 0; i < 54; i++){
		for (int j = 0; j < 54; j++){
			if (i == 0 || i == j){
				C[i][j] = 1;
			}
			else{
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
			}
		}
	}
}

int pirveli, meore;

int main(){
	binom();

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++){
		scanf("%d", &a);
		if (a == 50)pirveli++; else meore++;
	}
	int X;
	go[0][pirveli][meore] = 1;
	for (X = 0; X <= 210; X++){
		for (int i = 0; i <= pirveli; i++){

			for (int j = 0; j <= meore; j++){
				ll tmp = go[X][i][j];

				for (int di = 0; di <= i; di++){
					for (int dj = 0; dj <= j; dj++){
						if (di == 0 && dj == 0)continue;
						if (50 * di + 100 * dj > K)continue;
						int axP = pirveli - (i - di);
						int axM = meore - (j - dj);
						go[X + 1][axP][axM] += (((C[i][di] % MOD) * (C[j][dj] % MOD) * tmp%MOD) % MOD) % MOD;
						go[X + 1][axP][axM] %= MOD;
					}
				}
			}
		}
		if ((X + 1) % 2 == 1 && go[X + 1][pirveli][meore]){
			printf("%d\n", X + 1);
			printf("%I64d\n", go[X + 1][pirveli][meore]);
			exit;
		}
	}
	printf("-1\n");
	printf("0\n");
	exit;
}
