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
#include <functional>
#include <utility>
#include <deque>
#include <ctime>
#include <sstream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
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
int _maxx, _maxy;
ll n, i, j, k, p, l, m, a, b, x;

ll pas;
//int go[305][305];
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = {0,}
//
//bool isOut(int x, int y){
//	return (x >= 1 && x <= n&&y >= 1 && y <= m);
//}
//
//bool used[500][500];
//void dfs(int x, int y){
//	used[x][y] = 1;
//	for (int i = 0; i < 4; i++){
//
//	}
//}
ll A[123456];
int main(){
    scanf("%I64d %I64d %I64d",&n,&m,&k);
	R0(i, n){
	    scanf("%I64d",&A[i]);
	}
	R0(i, n - 1){
		int x = A[i];
		int f = x / k;
		int nasht = x%k;
		pas += f;
		if (nasht + A[i + 1] <= m){
			A[i + 1] += nasht;
		}
		else{
			pas += 1;
		}
	}
	int x = A[n - 1];
	if (x%k != 0){
		pas += x / k;
		pas += 1;
	}
	else pas += x / k;
	printf("%I64d",pas);
}
