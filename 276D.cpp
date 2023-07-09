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
const int N = 1000009;
int n, i, m, k, h, p, l, r, timer;
//int dp[NS][NS];
//int X[55];
//char NX[NS];
int in[N];
ll A[N], B[N];
//int parent[N][N];
struct node{
	int val, MX;
	node *l, *r;
	node(){
		l = r = NULL;
	}

};

int main(){
	scanf("%d", &n);
	R1(i, n){
		scanf("%d", &in[i]);
	}
	for (int i = 2; i <= n; i++){
		if (in[i - 1] < in[i] && in[i - 1] < in[i - 2]){
			A[i] = max(A[i - 2] + in[i] - in[i - 1], A[i - 1]);
			continue;
		}
		if (in[i - 1]>in[i] && in[i - 1]>in[i - 2]){
			A[i] = max(A[i - 2] + in[i - 1] - in[i], A[i - 1]);
			continue;
		}
		A[i] = A[i - 1] + abs(in[i] - in[i - 1]);
	}

	
	printf("%I64d", A[n]);


	exit;
}
