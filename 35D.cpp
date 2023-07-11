#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
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
#define REP(i,a,n) for(int i=(int)a;i<n;i++)
#define REPP(i,a,n) for(int i=(int)a;i<=n;i++)
#include <cmath>
#define PI pair<int,int>
#include <cstdlib>
#define inf 1000007
#include <ctime>
#define exit return 0
#define N 222222
using namespace std;

vector<int>gr[N];
vector<int>pref[N];//k>j
vector<int>suff[N];//all child of i k<j-ze 

int dp[111][11111], ans[N], c[N], jam[N], pas, NN, X;
int i, j, k;

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	scanf("%d %d", &NN, &X);
	REPP(i, 1, NN)scanf("%d", &c[i]), ans[i] = c[i] * (NN - i + 1);
	sort(ans + 1, ans + NN + 1);
	for (int i = 1; i <= NN; i++){
		if (ans[i] > X)break;
		else {
			X -= ans[i];
			pas += 1;
		}

	}

	printf("%d", pas);

	return 0;




}
