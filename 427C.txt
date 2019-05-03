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
const double eps = 1e-10;
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
#define ll long long
int n,a,b,k;
int so,in;
int allin,games;

const int N = 200007;
//f[i] - number of towers when i know
// that i have r red blocks
//heigh is H
int r,g;
int f[N];
vector<int>gr[N];
int tin[N],comps,comp[N],timer, stck[N],sz,low[N],isin[N],cost[N];
void tarjan(int v){
    low[v] = tin[v] = ++timer;
    stck[sz++] = v;
    isin[v] = 1;

    for(int i=0; i < gr[v].size(); i++){
        int to = gr[v][i];
        if(tin[to] == -1){
            tarjan(to);
            //update
            low [v] = min(low[v],low[to]);
        }else if(isin[to]){
            low [v] = min(low[v],tin[to]);
        }
    }

    if(low[v] == tin[v]){
        int y = -1;
        comps++;
        do{
            y = stck[--sz];
            comp[y] = comps;
            isin[y] = 0;
        }while(y!=v);
    }
}


void go(){

    memset(tin,-1,sizeof(tin));
    comps = timer = sz = 0;
    rep(i,n){
        if(tin[i] == -1)tarjan(i);
    }
}
int mn[N],cnt[N];
int main(){

    scanf("%d ",&n);
    rep(i,n){
        scanf("%d",&cost[i]);
    }

    int m;
    scanf("%d ",&m);

    while(m--){
        scanf("%d %d",&a,&b);
        a--,b--;
        gr[a].push_back(b);
    }

    go();
    //cout<<comps<<endl;
    for(int i=1;i<=comps;i++)mn[i] = (2123123123);
    rep(i,n){
        int cc = comp[i];
        int ww = cost[i];
        if(mn[cc] > ww){
           mn[cc] = ww;
            cnt[cc] = 1;
        }else if(mn[cc]==ww){
            cnt[cc] += 1;
        }
    }

    ll aa = 0, bb = 1;
    //cout<<comps;
    for(int i=1;i<=comps;i++) {
        aa += mn[i];
        bb *= (cnt[i]);
        bb %= MOD;
    }
    printf("%I64d %I64d",aa,bb);
}


