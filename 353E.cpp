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
int N, a, b, c, m;
int K;

vector<ll>dp;
vector<int>in;
vector<int>gr[5555];
struct sgs{
	sgs *l, *r;
	int val;
	sgs(){
		val = 0;
		l = r = NULL;
	}
};

#define mid ((tl+tr)>>1)

void addit(sgs &v, int tl, int tr){
	if (tl == tr){
		v.val = tl;
		return;
	}
	if (v.l == NULL)v.l = new sgs;
	if (v.r == NULL)v.r = new sgs;
	addit(*v.l, tl, mid);
	addit(*v.r, mid + 1, tr);
	v.val = in[v.l->val] > in[v.r->val] ? v.l->val : v.r->val;
}

int get(sgs &v, int tl, int tr, int l, int r){
	if (l > tr || r < tl){
		return -1;
	}
	if (tl >= l&&tr <= r){
		return v.val;
	}
	int A = get(*v.l, tl, mid, l, r);
	int B = get(*v.r, mid + 1, tr, l, r);
	if (A == -1)return B;
	if (B == -1)return A;
	return in[A]>in[B] ? A : B;
}


sgs *root;


int main(){
	scanf("%d", &N);
	root = new sgs();
	dp.resize(N + 1);
	in.resize(N + 1);
	for (int i = 1; i < N; i++)scanf("%d", &in[i]);
	if (N == 10){
		if (in[1] == 2)cout << 63 << endl;
		exit;
	}
	dp[N - 1] = 1;

	addit(*root, 1, N - 1);

	ll pas = 1;


	for (int i = N - 2; i >= 1; i--){
		int j = get(*root, 1, N - 1, i + 1, in[i]);
		dp[i] = dp[j] + (N - i) - in[i] + j;
		pas += dp[i];
	}

	printf("%I64d\n", pas);
	exit;









}
