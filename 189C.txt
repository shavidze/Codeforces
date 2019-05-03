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
#define MOD 1000000007
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
using PII = pair<int, int>;

const int NN = 243210;
const int NZ = 200022;
const int MM = 151;
const int need = (1 << 30) - 1;

int n, a, b, c;
int t;
map<int, int>fx1, fx2;
int in1[NN], in2[NN];
int main(){
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> in1[i];
	}
	int x = 0;
	for (int i = 0; i < n; i++){
		cin >> in2[i];
		if (in2[i] == in1[x]){
			x++;
		}
	}
	cout << n - x << endl;
	exit;
	PS;
}





