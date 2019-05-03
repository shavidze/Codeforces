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
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define mid ((tl+tr)>>1)
#define SZ(x) ((int)x.size())
const double eps = 1e-10;


using namespace std;
int N;
int popcount(int x){ int cnt = 0; for (int i = 0; i < N; i++){ if (x&(1 << i)){ cnt++; } }	return cnt; }
int zzz = 0;
const int NN = 100022;

vector<pair<ll, ll>>cr;
map<PII, int>mp;
int  M, L, K;
int a, b;
int  y[NN];
double dro;
set<int>st;
int pas[NN];
int main(){


	cin >> N;
	vector<int>x(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> x[i];
		st.insert(x[i]);
	}
	sort(x.begin(), x.end());
	cin >> M;
	for (size_t i = 0; i < M; i++)
	{
		cin >> y[i];
		auto index = upper_bound(x.begin(), x.end(), y[i]);
		int ind = index - x.begin();
		pas[i] = ind;
	}
	for (int i = 0; i < M; i++){
		cout << pas[i] << endl;
	}

	exit;
	PS;
}








