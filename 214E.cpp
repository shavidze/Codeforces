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
#define inf 1000000000
#define exit return 0
#define PS system("pause")
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define SZ(x) ((int)x.size())
#define MX(a,b)a>b?a:b
#define oo lld
const double eps = 1e-10;
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
#define ll long long
int n,m,q,a,b,k;
int so;
int allin,games;

const int N = (110000);
int in[302][302];
//row,col1,col2
int f[607][301][301];
using PII = pair<int,int>;
//digit,sig
int T;
int main() {
    scanf("%d",&n);
    rep(i,n){
        rep(j,n){
            scanf("%d",&in[i][j]);
        }
    }
    int K = 2*n-2;
    f[0][0][0]=in[0][0];
    //cout<<f[0][0][0];
    for(int k=1;k<=K;k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[k][i][j]=-inf;
                int x1 = i, y1 = k-x1;
                int x2 = j,y2 = k-x2;
                if(x1>k||x2>k||y1>=n||y2>=n)continue;
                if(k - i - 1>=0&& k- j -1>=0){
                    f[k][i][j] = max(f[k][i][j],f[k-1][i][j]);
                }
                if(i>0 && k - j -1>=0){
                    f[k][i][j] = max(f[k][i][j],f[k-1][i-1][j]);
                }
                if(j>0 &&k-i-1>=0){
                    f[k][i][j] = max(f[k][i][j],f[k-1][i][j-1]);
                }
                if(i>0&&j>0){
                    f[k][i][j] = max(f[k][i][j],f[k-1][i-1][j-1]);
                }
                if(i==j){
                    f[k][i][j]+=in[k-i][i];
                }else{
                    f[k][i][j]+=(in[k-i][i]+in[k-j][j]);
                }
            }
        }
    }

    printf("%d\n",f[K][n-1][n-1]);
    return 0;

}


