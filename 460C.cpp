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

const int NN = 21;
const int MM = 151;
const int need = (1 << 30) - 1;
int N, M, W, l, x, y;
string in[55];
int i, j, p;
ll zz[100111];
ll up[100111];
ll cur, high, md, low;
bool OK(ll md){

	for (int i = 0; i <= N; i++){
		up[i] = 0;
	}
	for (int i = 1; i <= N; i++){
		up[i] = up[i - 1];

		cur = zz[i] + up[i - 1] - up[max(i - W, 0)];
		if (cur < md){
			up[i] += (md - cur);
		}
	}
	return up[N] <= M;
}

int main(){

	scanf("%d %d %d", &N, &M, &W);
	for (int i = 1; i <= N; i++){
		scanf("%I64d", &zz[i]);
	}

	low = 0, high = 100000000000;

	while (low <= high){

		ll md = (low + high) / 2;

		if (OK(md)){
			low = md + 1;
		}
		else
			high = md - 1;
	}


	printf("%I64d\n", high);
	return 0;
}
