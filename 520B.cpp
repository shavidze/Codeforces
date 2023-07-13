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
const int NN = 111222;
double  xf, yf;
int N, M, L;
int pas;
string in;
int mp[22222];
queue<pair<int, int>> qq;
int main(){
	cin >> N >> M;
	memset(mp, -1, sizeof(mp));
	qq.push({ N, 0 });
	while (qq.size() > 0){
		int f = qq.front().first;
		int s = qq.front().second;
		qq.pop();
		if (f<1 || f>20000 || mp[f] >= 0)continue;
		mp[f] = s;
		qq.push({ f - 1, s + 1 });
		qq.push({ f << 1, s + 1 });
	}
	cout << mp[M] << endl;
	return 0;
	PS;







}








