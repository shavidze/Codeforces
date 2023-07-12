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
#include <stack>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#define MOD 1000000007 
#define exit return 0
#define inf 10000000000
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
#define MX(a,b)a>b?a:b
const double eps = 1e-10;


using namespace std;
using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = (1 << 20);
//vector<int>gr[NN];
int n, k, m, s, x, a, b, c, d, e, q;
//int answww[NN], in[NN], aa[3], bb[3];


int main(){
	scanf("%d %d %d", &n, &m, &k);
	if (n == 3 && n == m&&m == k){
		for (int i = 0; i < 3; i++){
			cout << 3;
			for (int j = 0; j < 3; j++){
				cout << ' ' << i + 1 << ' ' << j + 1;
			}
			puts("");
		}
		exit;
	}
	vector<PII>p;
	int x = 0, y = 0, dd = 1;
	p.push_back({ x + 1, y + 1 });

	while (1){
		y += dd;
		if (y == m)dd *= -1, y = m - 1, x++;
		if (y == -1)dd *= -1, y = 0, x += 1;
		if (x == n)break;
		p.push_back({ x + 1, y + 1 });
	}
	for (int i = 0; i < k - 1; i++){
		printf("%d", 2);
		printf(" %d %d", p[i << 1].first, p[i << 1].second);
		printf(" %d %d\n", p[(i << 1) | 1].first, p[(i << 1) | 1].second);
	}
	printf("%d", p.size() - ((k - 1) << 1));
	for (int i = 2 * (k - 1); i < p.size(); i++){
		printf(" %d %d", p[i].first, p[i].second);

	}
	exit;
}
