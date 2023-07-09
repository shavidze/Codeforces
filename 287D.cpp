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
#define N 1555
#define inf 1000000000000000000LL
typedef long long ll;
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left v<<1
#define right left|1
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
using namespace std;
int n, A, B, a, b, i, j, k, m, pas;
int d[101][101];
int f[1111][111][2];
int go[1111];

double maxWays;

int main(){
	cin >> n >> k >> m;
	f[0][0][0] = 1;
	go[0] = 1;
	for (int i = 1; i <= n; i++)go[i] = (go[i - 1] * 10) % k;
	pas = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) for (int x = 0; x < 2; x++){
		for (int d = 0; d < 10; d++){
			int tmp = x;
			int z = (j + d*go[i]) % k;
			if (z == 0 && d != 0){
				tmp = 1;
			}
			f[i + 1][z][tmp] = (f[i + 1][z][tmp] + f[i][j][x]) % m;
			if (i == n - 1 && d != 0 && tmp == 1){
				pas = (pas + f[i][j][x]) % m;
			}
		}
	}
	cout << pas << endl;
	exit;
}
