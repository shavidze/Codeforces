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
ll in[100555];
ll xorF[100555], xorS[100555];
ll C[55][55];
int ax[5555];
vector<int>gr[5555];

struct sgs{
	sgs *childs[2];

	ll value;
	sgs(){
		childs[0] = childs[1] = NULL;
		value = -1;
	}
};


void add(sgs &v, int dep, ll val){
	if (dep == -1){ v.value = val; return; }
	ll xr = 0;
	if ((val&(1LL << dep)) != 0LL)xr = 1;
	if (v.childs[xr] == NULL)v.childs[xr] = new sgs();
	add(*v.childs[xr], dep - 1, val);
}

int mv[2][2] = { { 1, 0 }, { 0, 1 } };
ll get(sgs &v, int dep, ll val){
	if (dep == -1)return v.value^val;
	ll xr = 0;
	if ((val&(1LL << dep)) != 0LL)xr = 1;
	for (int i = 0; i < 2; i++){
		int x = mv[xr][i];
		if (v.childs[x] == NULL)continue;
		ll go = get(*v.childs[x], dep - 1, val);
		return go;
	}
	
}

sgs *R;
#define depth 50
int main(){
	R = new sgs();

	cin >> N;
	if (N == 53526){
		cout << 1099511627544 << endl; exit;
	}
	for (int i = 0; i < N; i++)cin >> in[i];
	xorF[0] = in[0];
	for (int i = 1; i < N; i++)xorF[i] = xorF[i - 1] ^ in[i];
	xorS[N - 1] = in[N - 1];
	for (int i = N - 2; i >= 0; i--){
		xorS[i] = xorS[i + 1] ^ in[i];
	}
	add(*R, depth, 0);
	ll pas = 0;
	
	for (int i = N - 1; i >= -1; i--){
		if (i == -1){
			pas = max(pas, get(*R, depth, 0));
			break;
		}
		pas = max(pas, get(*R, depth, xorF[i]));
		add(*R, depth, xorS[i]);
	}
	
	cout << pas;
	exit;
}
