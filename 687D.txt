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
#define R0(i,n) for (int i = 0; i < n; i++)
#define R1(i,n) for (int i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define mid ((tl+tr)>>1)
#define SZ(x) ((int)x.size())
const double eps = 1e-10;


using namespace std;

int N;

int popcount(int x){ int cnt = 0; for (int i = 0; i < N; i++){ if (x&(1 << i)){ cnt++; } }	return cnt; }

const int NN = 500100;
const int NZ = 1010;
int  n, m, l, k, x;
int u[NN], v[NN], w[NN];
int uu[NN], vv[NN], ww[NN];

int col[NZ], cmp[NZ], sz[NZ], id[NN];
int shv[NZ][NZ];
inline bool comp(int a, int b){
	return w[a] > w[b];
}


int find(int x){ return (x == cmp[x] ? x : find(cmp[x])); }

int main(){
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++){

		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		u[i]--, v[i]--;
		id[i] = i;

	}

	sort(id, id + m, comp);

	for (int i = 0; i < m; i++){
		uu[i] = u[id[i]];
		vv[i] = v[id[i]];
		ww[i] = w[id[i]];
	}

	while (k--){
		int from, to;

		scanf("%d %d", &from, &to);
		from -= 1, to -= 1;
		for (int i = 0; i < n; i++){
			col[i] = 0;
			sz[i] = 1;
			cmp[i] = i;
			shv[i][0] = i;
		}
		int pas = -1;
		for (int i = 0; i < m; i++){
			if (from <= id[i] && id[i] <= to){
				if (cmp[uu[i]] == cmp[vv[i]]){
					if (col[uu[i]] == col[vv[i]]){
						pas = ww[i];
						break;
					}
				}
				else{
					int x = cmp[uu[i]];
					int y = cmp[vv[i]];

					if (sz[x] < sz[y]){
						swap(x, y);
					}

					int inv = (col[uu[i]] == col[vv[i]]);
					for (int ch = 0; ch < sz[y]; ch++){
						int ver = shv[y][ch];
						cmp[ver] = x;
						col[ver] ^= inv;
						shv[x][sz[x]++] = ver;
					}
				}
			}
		}

		printf("%d\n", pas);
	}

	exit;

	PS;
}








