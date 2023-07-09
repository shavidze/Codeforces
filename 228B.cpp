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

const int NN = 55;
const int NZ = 111000;
const int MM = 151;

const int need = (1 << 30) - 1;

int n, k, m, s, x, i, j, q;
ll res1, res2;
ll coll;
ll dp[NN];
int l, pp;
int in[NN];
int cc[NN][NN], vv[NN][NN];
int main(){
	string str;
	cin >> n >> m;
	int n1 = n, m1 = m;
	for (int i = 1; i <= n; i++){
		cin >> str;
		for (int j = 0; j < str.size(); j++){
			if (str[j] == '0'){
				cc[i][j + 1] = 0;
			}
			else{
				cc[i][j + 1] = 1;
			}
		}
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> str;
		for (int j = 0; j < str.size(); j++){
			if (str[j] == '0'){
				vv[i][j + 1] = 0;
			}
			else{
				vv[i][j + 1] = 1;
			}
		}
	}
	ll res = -1;
	ll jam = 0;
	ll cx = -1, cy = -1;
	for (int x = -50; x <= 50; x++){
		for (int y = -50; y <= 50; y++){
			res = 0;
			for (int i = 1; i <= n1; i++){
				if (i + x<1 || i + x>n)continue;
				for (int j = 1; j <= m1; j++){
					if (j + y<1 || j + y>m || i + x<1 || i + x>n)continue;
					res += cc[i][j] * vv[x + i][y + j];
				}
			}
			if (jam < res){
				jam = res;
				cx = x, cy = y;
			}
		}
	}
	cout << cx << " " << cy << endl;
	//PS;
	exit;
}
