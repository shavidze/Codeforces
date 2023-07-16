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
const int NS = 2700;
const int L = 350;
int n, i, m, k, h, p, l, r, timer;
int dp[NS][NS];
int X[55];
char NX[NS];
char in[S];
int go(int x, int y){
	if (x > y)return 0;
	if (dp[x][y])return dp[x][y];
	if (x == y)return dp[x][y] = 1;
	if (in[x] == in[y])return dp[x][y] = go(x + 1, y - 1) + 2;
	return dp[x][y] = max(go(x + 1, y), go(x, y - 1));
}

void R(int x, int y){
	if (x > y)return;
	if (x == y)NX[timer++] = in[x];

	else if (in[x] == in[y]){
		NX[timer++] = in[x];
		R(x + 1, y - 1);
		NX[timer++] = in[y];
	}
	else {
		if (dp[x + 1][y] > dp[x][y - 1]){
			R(x + 1, y);
		}
		else R(x, y - 1);
	}
}

int main(){
	scanf("%s", in);
	//cin >> in;
	n = strlen(in);
	if (n >= 2600){
		for (int i = 0; i < n; i++){
			++X[in[i] - 'a'];
		}
		for (int i = 0; i < 26; i++){
			if (X[i] >= 100){
				for (int j = 0; j < 100; j++){
					char pal = (i + 'a');
					printf("%c", pal);
				}
				exit;
			}
		}
		exit;
	}
	else{
		go(0, n - 1);
		timer = 0;
		R(0, n - 1);
		if (timer <= 100)printf("%s\n", NX);
		else{
			for (int i = 0; i < 50; i++){
				printf("%c", NX[i]);
				//cout << NX[i];
			}
			for (int i = timer - 50; i < timer; i++){
				printf("%c", NX[i]);
				//cout << NX[i];
			}
			puts("");
		}
	}
	//PS;
	exit;
}
