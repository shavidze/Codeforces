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
#define MOD 9901
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
#define mid ((l+r)>>1)
#define SZ(x) ((int)x.size())
#define MX(a,b)a>b?a:b
const double eps = 1e-10;
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
#define ll long long
using ul = unsigned long long;
//using PII = pair<int, int>;
const int NN = (77000);
const int EE = 5*NN;
int in[NN];
int m,n;

int typo[NN];
double co[NN];
int dp[NN];



int main() {
    scanf("%d %d",&n,&m);

    for (int i = 0; i <n; ++i) {
        scanf("%d ",&typo[i]);
        cin>>co[i];
    }
    int maxx = -1;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(typo[j]<=typo[i]){
                if(dp[j]+1>=dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
        }
        maxx = max(maxx,dp[i]);
    }
    printf("%d\n",n-maxx);
    return 0;

}


