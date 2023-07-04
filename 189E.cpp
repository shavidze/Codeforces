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

using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 200111;
const int NZ = 1111;
const int MM = 151;

const int need = (1 << 30) - 1;

//car,road a-b

int n, m, s, t, a, b, k, c;
int r;
int col[NN];
vector<int>gr[NN];
int push(int x){
	set<pair<int, int>>st;
	int d[NN];
	for (int i = 0; i < NN; i++){
		d[i] = 1000000000;
	}
	int res = -1;
	d[s] = 0;
	st.insert({ d[s], s });

	while (!st.empty()){
		PII a = *st.begin();
		int wona = a.first;
		int wvero = a.second;
		st.erase(st.begin());
		if (wona == x)continue;
		int to;
		for (int y = 0; y < gr[wvero].size(); y++){
			to = gr[wvero][y];
			if (d[to]>wona + 1){
				int ff;
				if (to == t)return 1;
				st.erase({ d[to], to });
				if (col[to]){
					ff = 0;
				}
				else{
					ff = wona + 1;
				}
				d[to] = ff;
				st.insert({ ff, to });
				res = max(res, ff);
			}
		}
	}
	return 0;
}



int main(){


	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++){
		int a;
		scanf("%d", &a);
		col[a] = 1;
	}
	for (int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	scanf("%d %d", &s, &t);
	//col[s] = col[t] = 1;
	int low = 0, high = n;
	int md = -1;
	bool flag = 0;
	while (low < high){
		md = (low + high) >> 1;
		if (push(md)){
			high = md;
		}
		else{
			low = md + 1;
		}
	}
	if (!push(low)){
		printf("%d\n", -1);
		exit;
	}
	printf("%d\n", low);
	exit;
	PS;

}





