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

int N, M, n, m, p, h, q, k, t, l, r;

int ooo = 0;
ll in[NN];

struct seg{
	ll sg[2][NN];

	void up(int v, int tl, int tr, int i, int val){
		if (tl == tr){
			sg[0][v] = i;
			sg[1][v] = val;
			return;
		}
		if (i <= mid){
			up(left, tl, mid, i, val);
		}
		else up(right, mid + 1, tr, i, val);

		sg[0][v] = in[sg[0][left]] > in[sg[0][right]] ? sg[0][left] : sg[0][right];
		sg[1][v] = sg[1][left] + sg[1][right];
	}

	ll getsum(int v, int tl, int tr, int l, int r){
		if (tl > r || tr < l)return 0;

		if (tl >= l&&tr <= r){

			return sg[1][v];
		}
		ll a = getsum(v + v, tl, mid, l, r);
		ll b = getsum(v + v + 1, mid + 1, tr, l, r);
		return a + b;
	}


	int getrmq(int v, int tl, int tr, int l, int r){

		if (tl > r || tr < l)return 0;

		if (tl >= l&&tr <= r){
			return sg[0][v];

		}
		int md = (tl + tr) >> 1;
		int a = getrmq(v + v, tl, md, l, r);
		int b = getrmq(v + v + 1, md + 1, tr, l, r);
		return in[a]>in[b] ? a : b;
	}
};


seg sg;
int main(){


	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &in[i]);
		sg.up(1, 1, n, i, in[i]);
	}
	while (m--){

		scanf("%d", &k);
		if (k == 1){
			scanf("%d %d", &l, &r);
			printf("%I64d\n", sg.getsum(1, 1, n, l, r));
		}
		else if (k == 2){
			scanf("%d %d %d", &l, &r, &p);
			q = sg.getrmq(1, 1, n, l, r);
			while (in[q] >= p){
				in[q] %= p;
				sg.up(1, 1, n, q, in[q]);
				q = sg.getrmq(1, 1, n, l, r);
			}
		}
		else{
			scanf("%d %d", &l, &r);
			in[l] = r;
			sg.up(1, 1, n, l, in[l]);
		}
	}


}





