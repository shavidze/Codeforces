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
const int NN = (200009);
int m,n;
int a,b,c;
long long answww;
long long dp[NN];
int main() {
    scanf("%d %d",&n,&m);
    int H;
    for( H=1;(H*(H+1))/2<= n+m;H++);
    H-=1;
    //no red and no green
    dp[0]=1;
    for(int i=1;i<=H;i++){
        for(int x=n;x>=0;x--){
            dp[x]+=(x>=i)?dp[x-i]:0;
            if(dp[x]>MOD)dp[x]-=MOD;
        }
    }
    for(int i=0;i<=n;i++){
        if((m+i)>=(H*(H+1)/2)){
            answww+=dp[i];
            if(answww>MOD)answww-=MOD;
        }
    }
    printf("%I64d\n",answww);
    return 0;

}


