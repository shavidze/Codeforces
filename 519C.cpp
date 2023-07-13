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
int zzz = 0;
const int NN = 555777;
int N, M;
int pas;
int main(){

	cin >> N >> M;
	while (N > 0 && M > 0){
		if (N + M < 3)break;
		if (N >= M&&N - 2 >= 0 && M >= 1){
			N -= 2;
			M--;
			pas += 1;
		}
		if (N < M&&N - 1 >= 0 && M >= 2){
			M -= 2;
			N -= 1;
			pas += 1;
		}
	}
	cout << pas << endl;
	return 0;
	PS;
}
