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
#define inf 10000000000
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
#define MX(a,b)a>b?a:b
const double eps = 1e-10;


using namespace std;
//using ll = long long;
using ul = unsigned long long;
using PII = pair<int, int>;
string ss, ff;
const int NN = 3003;
vector<int>gr[NN];
int n, k;
int m, s, x, a, b, c, d, e, q;
int answww;
int main(){
	cin >> ss;

	if (ss.size() < 3)cout << ss;
	else if (ss.size() == 3){
		if (ss[0] != ss[1] || ss[1] != ss[2]){
			cout << ss;
			exit;
		}
		else{
			ss.pop_back();
			cout << ss << endl;
			exit;
		}
	}
	else{
		ff.push_back(ss[0]);
		ff.push_back(ss[1]);
		for (int i = 2; i < ss.size(); i++){
			if (ss[i] == ff[ff.size() - 1] && ff[ff.size() - 1] == ff[ff.size() - 2])continue;
			if (i >= 3){
				if (ff[ff.size() - 2] == ff[ff.size() - 3] && ff[ff.size() - 1] == ss[i])continue;
			}

			ff.push_back(ss[i]);

		}


	}
	cout << ff << endl;

	exit;


}
