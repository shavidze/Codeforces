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
#include <stdio.h>
#define MOD 1000000007
#define exit return 0
#define inf 1000000000000000000LL
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
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 1011101;
const int NZ = 511100;
const int MM = 151;

const int need = (1 << 30) - 1;

//car,road a-b

int n, m, s, x, i, j, t, a, b, k, c, r, col[NN];

int l;
ll in[NN];

vector<PII> gr;
int main(){


	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		a--, b--;
		gr.push_back({ min(a, b), max(a, b) });
	}

	sort(gr.begin(), gr.end());
	set<int>sv;
	for (int i = 0; i < n; i++)sv.insert(i);
	vector<vector<int>>reswww;
	while (!sv.empty()){

		int ff = *sv.begin();
		sv.erase(ff);
		vector<int>comp;
		queue<int>qq;
		qq.push(ff);

		while (!qq.empty()){
			int v = qq.front();
			qq.pop();

			comp.push_back(v);
			vector<int>trm;

			for (auto it : sv){
				int x = it;
				int a = min(x, v);
				int b = max(x, v);
				if (!binary_search(gr.begin(), gr.end(), make_pair(a, b))){
					trm.push_back(x);
					qq.push(x);
				}

			}

			for (int i = 0; i < trm.size(); i++){
				sv.erase(trm[i]);

			}
		}
		reswww.push_back(comp);
	}

	printf("%d\n", reswww.size());

	for (int i = 0; i < reswww.size(); i++){
		printf("%d", reswww[i].size());
		for (int j = 0; j < reswww[i].size(); j++){
			printf(" %d", reswww[i][j] + 1);
		}
		printf("\n");
	}


	exit;
}
