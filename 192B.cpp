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

const int NN = 2222;
const int NZ = 111000;
const int MM = 151;
const int mask = 1 << 4;
const int need = (1 << 30) - 1;

int n, k, m, s, x, a, b, c, q;
int l, pp;
int in[NN], comp[NN], ins[NN], low[NN];
pair<int, int>tin[NN], timer;



int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a);
		tin[i] = { a, i };
		in[i] = 1;
	}

	sort(tin + 1, tin + n + 1);
	int t = tin[n].first;
	for (int i = 1; i <= 1000000; i++){
		int y = tin[i].first;
		in[tin[i].second] = 0;
		for (int j = 1; j <= n - 1; j++){
			if (in[j]){
				int flag = 0;
				if (in[j + 1] && j + 1 <= n){
					in[j + 1] = 1;
					flag = 1;
				}
				if (in[j + 2] && j + 2 <= n){
					in[j + 2] = 1;
					flag = 1;
				}
				if (!flag){
					cout << y << endl;
					exit;
				}
			}
		}
		if (in[n] == 0 || in[1] == 0){
			cout << y << endl;
			exit;
		}
		in[tin[i].second] = 0;
	}
	exit;
}
