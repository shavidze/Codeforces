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
#define PII pair<int,int>
#define MOD 1000000009
#define exit return 0
#define inf 100000000
typedef long long ll;
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (int i = 0; i < n; i++)
#define R1(i,n) for (int i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define mid ((tl+tr)>>1)
#define SZ(x) ((int)x.size())
const double eps = 1e-10;


using namespace std;
int N;
int popcount(int x){ int cnt = 0; for (int i = 0; i < N; i++){ if (x&(1 << i)){ cnt++; } }	return cnt; }
const int NN = 1002;

int  M, L, K, X, P;
int x[NN];
vector<int>pb[NN];
int main(){

	cin >> N >> M >> K;
	R0(i, M){
		cin >> x[i];
	}
	cin >> L;
	int raod = 0;
	for (int i = 0; i < M; i++){
		int arm1 = x[i];
		int y = L^x[i];
		int k = 0;
		for (int t = 20; t >= 0; t--){
			if (y&(1 << t)){
				k++;
			}
		}
		if (k <= K){
			raod++;
		}
	}
	cout << raod;
	exit;
	PS;
}








