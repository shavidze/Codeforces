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
#define mod 1000000007
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
using ul = unsigned long long;
ul powmod(ul a, ul b) {
	ul res = 1;
	a %= mod;
	for (; b; b >>= 1){
		if (b & 1)res = res*a%mod;
		a = a*a%mod;
	}
	return res;
}

const int NN = 543210;
const int NZ = 200022;
const int MM = 151;
const int need = (1 << 30) - 1;

using PII = pair<int, int>;

ll N, M, m, p, h, q, k, t1, t2, l, r;
double n;
int ooo = 0;
ll res;
int main(){
	cin >> n;
	int a, b, c;

	cin >> a >> b >> c;
	if (a + b + c == 0){
		cout << 0 << " " << 0 << " " << 0;
		exit;
	}
	N = (a + b + c);
	n /= N;
	
	printf("%.18f %.18f %.18f", n*a, n*b, n*c);
	exit;

}





