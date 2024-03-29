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
#define MOD 1000000007
#define exit return 0
#define N 1555
#define inf 1000000000000000000LL
typedef long long ll;
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left v<<1
#define right left|1
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
using namespace std;

struct seg{
	int val;
	seg *l, *r;
	seg(){
		l = r = NULL;
		val = 0;
	}
};
#define mid ((tl+tr)>>1)
void add(seg &v, int tl, int tr, int pos, int val){
	if (tl == tr){
		v.val += val;
		v.val %= MOD;
		return;
	}
	if (!v.r)v.r = new seg;
	if (!v.l)v.l = new seg;
	if (pos <= mid){
		add(*v.l, tl, mid, pos, val);
	}
	else add(*v.r, mid + 1, tr, pos, val);
	v.val = (v.l->val + v.r->val) % MOD;
}

int get(seg &v, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return 0;
	}
	if (tl >= l&&tr <= r){
		return v.val;
	}
	if (!v.l)v.l = new seg;
	if (!v.r)v.r = new seg;
	int L = get(*v.l, tl, mid, l, r);
	int R = get(*v.r, mid + 1, tr, l, r);
	return (L + R) % MOD;
}
int n, m, i, j, k;
seg *root;
int main(){
	root = new seg;
	add(*root, 1, 1200000000, 1, 1);
	scanf("%d %d", &n, &m);
	n += 1;
	vector<pair<int, int>>vc(m);
	R0(i, m){
		scanf("%d %d", &vc[i].second, &vc[i].first);
		vc[i].second += 1; vc[i].first += 1;
	}
	sort(vc.begin(), vc.end());
	R0(i, vc.size()){
		swap(vc[i].first, vc[i].second);
		int pas = get(*root, 1, 1200000000, vc[i].first, vc[i].second - 1);
		add(*root, 1, 1200000000, vc[i].second, pas);
	}
	cout << get(*root, 1, 1200000000, n, n);
	//printf("%d", get(*root, 1, 1200000000, n, n));
	exit;
}
