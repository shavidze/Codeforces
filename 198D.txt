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
#include <functional>
#include <utility>
#include <deque>
#include <ctime>
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
int _maxx, _maxy;
int n, i, j, k, l, m, a, b;
bool gr[20][20], H[20][20];
int low[1 << 20]; ll dp[1 << 20][20];
int mask;
ll tree[1200][1200][4];

int indX(int x, int y){
	int pas = 0;
	if (!(x & 1))pas += 1;
	if (!(y & 1))pas += 2;
	return pas;
}
void up2D(int x, int y, ll val){
	int y1;
	int goes = indX(x, y);
	while (x <= n){
		y1 = y;
		while (y1 <= n){
			tree[x][y1][goes] ^= val;
			y1 += (y1&-y1);
		}
		x += (x&-x);
	}
}

ll get(int x, int y){
	ll sum = 0;
	int goes = indX(x, y);
	while (x){
		int y1 = y;
		while (y1){
			sum ^= tree[x][y1][goes];
			y1 -= (y1&-y1);
		}
		x -= (x&-x);
	}
	return sum;
}

ll getans(int x1, int y1, int x2, int y2){

	ll pas = get(x2, y2);
	pas ^= get(x2, y1 - 1); pas ^= get(x1 - 1, y2); pas ^= get(x1 - 1, y1 - 1);
	return pas;
}

ll pas;

int main(){

	scanf("%d %d", &n, &m);
	while (m--){

		scanf("%d", &a);
		int x1, y1, x2, y2;
		if (a == 1){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			ll pas = getans(x1, y1, x2, y2);
			printf("%I64d\n", pas);
		}
		else{
			ll add;
			scanf("%d %d %d %d %I64d", &x1, &y1, &x2, &y2, &add);

			up2D(x1, y1, add);
			up2D(x1, y2 + 1, add);
			up2D(x2 + 1, y1, add);
			up2D(x2 + 1, y2 + 1, add);
		}
	}
	exit;
	PS;
}
