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
#define rep(i, n) for (int i = 1; i <= n; i++)

using namespace std;
#define ll long long
int n,a,b,k;
int so;
int allin,games;

const int N = 200009;
//f[i] - number of towers when i know
// that i have r red blocks
//heigh is H
ll in[N];
bool was[N][2];
ll f[N][2];

ll dfs(int x,bool fl){
    if(x<=0||x>n){
        return 0;
    }
    if(fl && x==1){
        return -1;
    }

    if(was[x][fl]){
        return f[x][fl];
    }

    was[x][fl] = 1;
    f[x][fl] = -1;

    ll tmp = dfs(x + (fl ? in[x] : -in[x]),!fl);
    if(tmp==-1){
        f[x][fl] = tmp;
    }else{
        f[x][fl] = tmp + in[x];
    }
    return f[x][fl];
}

int main() {

    scanf("%d ", &n);

    for(int i=2;i<=n;i++) {
        scanf("%I64d", in + i);
    }

    for(int i=2;i<=n;i++){
        in[1] =i-1;
        dfs(i,0);
        if(f[i][0] == - 1){
            printf("-1\n");
        }else{
            printf("%I64d\n",f[i][0] + in[1]);
            //cout<<f[i][0] + i -1 <<endl;
        }
        //if("%I64d\n",(f[i][0] == -1 ? -1 : f[i][0] + i -1));

    }

}


