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

const int NN = 100111;
const int MM = 151;
const int need = (1 << 30) - 1;
int N, M, W, l, x, y;
string in[55];
int i, j, p;
int zz[NN], ds[100111];
map<int, int>was;
int a, b;
int vis[NN], sat2[NN];
int find(int x){
	if (ds[x] == x){
		return x;
	}
	else return find(ds[x]);
}



int main(){

	scanf("%d %d %d", &N, &a, &b);


	for (int i = 1; i <= N; i++){
		scanf("%d ", &zz[i]);

		was[zz[i]] = i;
		ds[i] = i;
	}

	for (int i = 1; i <= N; i++){
		if (was[a - zz[i]]){
			ds[find(was[a - zz[i]])] = find(i);
			vis[i] |= 1;
		}
		if (was[b - zz[i]]){
			ds[find(was[b - zz[i]])] = find(i);
			vis[i] |= 2;
		}
	}

	for (int i = 1; i <= N; i++){
		sat2[i] = 3;
	}

	for (int i = 1; i <= N; i++){
		sat2[find(i)] &= vis[i];
	}

	for (int i = 1; i <= N; i++){
		if (sat2[i] == 0){
			puts("NO");
			exit;
		}
	}
	puts("YES");

	for (int i = 1; i <= N; i++){
		int sg = sat2[find(i)];
		if (sg == 1){
			putchar('0' + 0);
		}
		else{
			putchar('0' + 1);
		}
		if (i >= 1)putchar(' ');
	}

	puts("");
	//PS;
	return 0;

}
