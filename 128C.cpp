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
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define mid ((l+r)>>1)
#define SZ(x) ((int)x.size())
#define MX(a,b)a>b?a:b
const double eps = 1e-10;

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
#define ll long long
using ul = unsigned long long;
//using PII = pair<int, int>;
const int NN = (3005);
const int EE = 5*NN;
long long C[NN][NN];
int m,n;
int a,b,c;
ll doit(int N,int K){
    if (K>N)return 0;
    return C[N][K];
}
int main() {
    scanf("%d %d %d",&a,&b,&c);
    C[0][0]=1;
    for (int i = 0; i <3001; ++i) {
        for(int j=0;j<=i;j++){
            if(i==j||j==0){
                C[i][j]=1;
                continue;
            }else {
                C[i][j]=(C[i-1][j]%MOD+C[i-1][j-1]%MOD)%MOD;
                C[i][j]%=MOD;
            }
        }
    }

    ll ans = ((doit(a-1,2*c)*doit(b-1,2*c)))%MOD;
    ans%=MOD;
    printf("%d\n",ans);
    return 0;

}


