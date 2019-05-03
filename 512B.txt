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
int zzz = 0;
const int NN = 100022;

vector<pair<ll, ll>>cr;
map<PII, int>mp;
int N, M, L;
ll answ;
set<int>st;


bool isOn(int x, int y){
	return mp.count({ x, y }) && mp[{x, y}] != -1;
}


bool check(int x, int y){
	if (!isOn(x, y))return 1;
	if (y == 0)return 1;

	if (!isOn(x - 1, y - 1) && !isOn(x, y - 1) && !isOn(x + 1, y - 1)){
		return 0;
	}
	return 1;
}

bool good(int p){
	int cx = cr[p].first, cy = cr[p].second;

	mp[{cx, cy}] = -1;

	if (!check(cx - 1, cy + 1) || !check(cx, cy + 1) || !check(cx + 1, cy + 1)){
		mp[{cx, cy}] = p;
		return 0;
	}
	mp[{cx, cy}] = p;
	return 1;

}


void refresh(int x, int y){
	if (!isOn(x, y))return;
	int p = mp[{x, y}];
	if (st.count(p))st.erase(p);
	if (good(p))st.insert(p);
}

void removeIt(int p){
	answ = (answ*N + p) % MOD;
	mp[{cr[p].first, cr[p].second}] = -1;
	st.erase(p);
	int a = cr[p].first, b = cr[p].second;
	refresh(a - 2, b);
	refresh(a - 1, b);
	refresh(a + 1, b);
	refresh(a + 2, b);
	refresh(a - 1, b - 1);
	refresh(a, b - 1);
	refresh(a + 1, b - 1);
}


int main(){



	scanf("%d", &N);
	cr.resize(N);
	for (int i = 0; i < N; i++){
		scanf("%d %d", &cr[i].first, &cr[i].second);
		mp[{cr[i].first, cr[i].second}] = i;
	}

	for (size_t i = 0; i < N; i++)
	{
		if (good(i))st.insert(i);
	}
	for (int i = 0; i < N; i++){
		if (i % 2 == 0){
			removeIt(*(st.rbegin()));
		}
		else{
			removeIt(*(st.begin()));
		}
	}
	printf("%I64d\n", answ);
	exit;
	PS;
}








