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
#define N 1<<18
using namespace std;

vector<int>gr[N];
vector<int>pref[N];//k>j
vector<int>suff[N];//all child of i k<j-ze 

int dp[111][11111], h[N], c[N], jam[N], pas, NN, X;
int i, j, k, KK, R;
vector<int>ans;
double M[22][22];
multiset<int>S;
int index;
int main(){
	scanf("%d %d", &NN, &KK);

	REP(i, 0, NN)scanf("%d", &h[i]);

	REP(i, 0, NN){

		S.insert(h[i]);

		while (1){
			if (*S.rbegin() - *S.begin() > KK){
				S.erase(S.find(h[index++]));
			}
			else break;
		}

		if (S.size() > R){
			ans.clear(); R = S.size();
		}

		if (S.size() == R){
			ans.push_back(i);
		}

	}


	printf("%d %d\n", R, ans.size());

	REP(i, 0, ans.size()){
		printf("%d %d\n", ans[i] - R + 2, ans[i] + 1);
	}


	return 0;




}

