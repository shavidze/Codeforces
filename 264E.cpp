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
#define MOD 1000000009
#define exit return 0
#define inf 1000000000000000000LL
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

const int NN = 543210;
const int NZ = 200022;
const int MM = 151;
const int need = (1 << 30) - 1;

using PII = pair<int, int>;

int N, M, n, m, p, h, q, k, t;

int ooo = 0;

int tr[2][NN];

struct seg{
	int *sg;

	seg(){
		sg = tr[ooo++];
	}

	void up(int v, int tl, int tr, int i, int val){
		if (tl == tr){
			sg[v] = val;
			return;
		}
		if (i <= mid){
			up(left, tl, mid, i, val);
		}
		else up(right, mid + 1, tr, i, val);
		sg[v] = max(sg[left], sg[right]);
	}

	int get(int v, int tl, int tr, int l, int r){
		if (tl > r || tr < l)return 0;

		if (tl >= l&&tr <= r){
			return sg[v];
		}

		return max(get(left, tl, mid, l, r), get(right, mid + 1, tr, l, r));
	}
};
seg segx, segy;
set<int>sx, sy;
int xc[NN], yc[NN];
void plant(int x, int y){
	sx.insert(x);
	sy.insert(y);
	xc[x] = y;
	yc[y] = x;
	vector<PII>sv;
	for (auto it : sy){
		int y2 = it;
		int x2 = yc[y2];
		sv.push_back({ x2, y2 });
		segx.up(1, 0, NZ, x2, 0);
		segy.up(1, 0, NZ, y2, 0);
		if (y2 == y)break;
	}
	for (int i = sv.size() - 1; i >= 0; i--){
		int x1 = sv[i].first, y1 = sv[i].second;
		int mim = segx.get(1, 0, NZ, x1 + 1, NZ) + 1;
		segx.up(1, 0, NZ, x1, mim);
		segy.up(1, 0, NZ, y1, mim);
	}
}


void cut(int v){
	vector<PII>sv;
	for (auto it : sx){
		int x2 = it, y2 = xc[x2];
		segx.up(1, 0, NZ, x2, 0);
		segy.up(1, 0, NZ, y2, 0);
		sv.push_back({ x2, y2 });
		v--;
		if (v == 0)break;
	}
	for (int i = sv.size() - 1; i >= 0; i--){
		int gg = 0;
		int fc = sv[i].first;
		int sc = sv[i].second;
		if (i == sv.size() - 1){
			sx.erase(fc);
			sy.erase(sc);
		}
		else{
			gg = segy.get(1, 0, NZ, sc + 1, NZ) + 1;
		}
		segx.up(1, 0, NZ, fc, gg);
		segy.up(1, 0, NZ, sc, gg);
	}
}
int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++){
		scanf("%d", &m);
		if (m == 1){
			scanf("%d %d", &p, &h);
			p--;
			plant(p, h - i + q);
		}
		else{
			scanf("%d", &p);
			cut(p);
		}
		int ans = segx.get(1, 0, NZ, 0, NZ);
		printf("%d\n", ans);
	}

	//PS;
	return 0;

}
