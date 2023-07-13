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
#define inf 1000000000000000000LL
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
const double eps = 1e-10;
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
#define ll long long
using ul = unsigned long long;
const int NN = (5005);
int m,n,N,x;
int a,b,c,K;
// numbef of ways to go from floor {i}
ll dp[NN];
ll ss[NN];//sum of all dp[0...i]


int main() {

    scanf("%d %d %d %d",&n,&a,&b,&K);

    for(int i=1;i<=n;i++){
        dp[i]=1;
        //with k=0 lifts
    }
    for(int st = 1;st<=K;st++){
        ss[0]=0;
        for(int i=1;i<=n;i++){
            ss[i] = (ss[i-1]+dp[i])%MOD;
        }
        int low,high;
        for(int i=1;i<=n;i++){
            low = max(1,i-(abs(b-i)-1));
            high = min(n,i+(abs(b-i)-1));
            //dp[0...high]-dp[0...low-1] = dp[low...high] that includes
            //case y=x and so we subtracting dp[i] to avoid this case
            dp[i] = ss[high] - ss[low-1] - dp[i];
        }
    }
    dp[a]%=MOD;
    if(dp[a]<0)dp[a]+=MOD;
    cout<<dp[a]%MOD;
    //printf("%I64d",dp[a]%MOD);
    return 0;
}


