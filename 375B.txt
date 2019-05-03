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
const int NN = (409);
int m,n,N,x;
int a,b,c;
int dp[5005][5005];
char in[5004][5004];
int answww=0;
int main() {
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        scanf("%s",in[i]+1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(in[i][j]=='1') {
                dp[i][j] += dp[i][j - 1] + 1;
            }
        }


    }
    for(int i=1;i<=m;i++){
        vector<int>ss;
        for(int j=1;j<=n;j++){
            ss.push_back(dp[j][i]);
        }
        sort(ss.begin(),ss.end());
        for(int k=ss.size()-1;k>=0;k--){
            //take k-th largest
            //there are n-k larger or equal exists
            answww = max(answww,((int)ss.size()-k)*ss[k]);
        }
    }
    printf("%d\n",answww);






    return 0;
}


