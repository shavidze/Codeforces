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
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define MN(a,b)a<b?a:b
#define PS system("pause")
#define exit return 0
#define inf 1000000000000000000LL
#define left (v<<1)
#define right (left|1)
#define tm ((tl+tr)>>1)
typedef long long ll;
#define S 52523
#define R0(i,n) for(int i=0;i<(int)n;i++)
#define R1(i,n) for(int i=1;i<=(int)n;i++)
using namespace std;
//vector<ll> dataMul(N), dataAdd(N);
//const int NS = 2700;
const int N = 155555;
ll n, i, m, k, h, d, p, l, r, timer;
pair<int, ll>PR[N];
ll X;
int main(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> PR[i].first >> PR[i].second;
	}
	sort(PR + 1, PR + 1 + n);

	for (int i = 1; i <= n; i++){
		PR[i].second += PR[i - 1].second;
	}
	l = 1;
	for (int i = 1; i <= n; i++){
		while (PR[l].first + d <= PR[i].first)l++;
		X = max(X, PR[i].second - PR[l - 1].second);
	}

	cout << X;
	exit;
}
