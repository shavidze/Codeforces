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

const int NN = 400111;
const int NZ = 1111;
const int MM = 151;

const int need = (1 << 30) - 1;

//car,road a-b

int n, m, s, x, i, j, t, a, b, k, c, r, col[NN];
vector<int>gr[NN];
int l;
ll in[NN];
string res = "";
ll answer = 0;
map<ll, int>f;
int main(){

	scanf("%d %d", &n, &k);

	R0(i, n)scanf("%d", &in[i]);
	l = 0;



	for (int i = 0; i < n; i++){
		f[in[i]] += 1;
		while (f[in[i]] >= k){
			answer += n - i;
			f[in[l]] -= 1;
			l++;
		}

	}

	printf("%I64d\n", answer);
	exit;
	PS;

}
