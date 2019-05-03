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
#define left (v+v)
#define right (v+v+1)
#define mid ((tl+tr)>>1)
#define SZ(x) ((int)x.size())
const double eps = 1e-10;


using namespace std;

const int NN = 100003;
const int need = (1 << 30) - 1;
int N, M;

int i, j, p;
int le[NN], ri[NN], q[NN];
int in[NN];
int sum[NN];
int tree[4*NN];
void build(int v, int tl, int tr){
	if (tl == tr){
		tree[v] = in[tl];
		return;
	}
	build(left, tl, mid);
	build(right, mid + 1, tr);
	tree[v] = tree[v + v] & tree[v + v + 1];
}

int query(int v, int tl, int tr, int l, int r){
	if (tl > r || tr < l || tl>tr)return -1;

	if (tl >= l&&tr <= r){
		return tree[v];
	}
	int a = query(v + v, tl, mid, l, r);
	int b = query(v + v + 1, mid + 1, tr, l, r);
	if (a == -1)return b;
	if (b == -1)return a;
	return a&b;
}

int main(){

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++){
		scanf("%d %d %d ", &le[i], &ri[i], &q[i]);
		le[i]--, ri[i]--;
	}

	for (int x = 0; x <= 30; x++){
		for (int i = 0; i < N; i++)sum[i] = 0;
		for (int i = 0; i < M; i++){
			if ((q[i] >> x) & 1){
				sum[le[i]] += 1;
				sum[ri[i] + 1] -= 1;
			}
		}
		for (int i = 0; i < N; i++){
			if (i>0){
				sum[i] += sum[i - 1];
			}
			if (sum[i]>0){
				in[i] |= (1 << x);
			}

		}
	}

	build(1, 0, N - 1);

	for (int i = 0; i < M; i++){
		if (query(1, 0, N - 1, le[i], ri[i]) != q[i]){
			puts("NO");
			return 0;
		}
	}

	puts("YES");


	for (int i = 0; i < N; i++){
		if (i>0)printf(" ");
		printf("%d", in[i]);
	}


	exit;


}








