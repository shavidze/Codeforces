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
//using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;

const int NN = 3003;
vector<int>gr[NN];
int n, k;
int m, s, x, a, b, c, d, e, q;
int answww;
bool fix[NN][NN];
int main(){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		gr[a].push_back(b);
		fix[a][b] = 1;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j){
				int yy = 0;
				for (auto x : gr[i]){
					if (fix[x][j]){
						yy++;
					}
				}
				answww += (yy*(yy - 1) / 2);
			}
		}
	}
	printf("%d\n", answww);
	exit;


}
