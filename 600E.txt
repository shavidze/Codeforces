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
#define inf 1000000
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
const int NN = (200009);
int m,n,N,x;
int a,b,c;
string in;
vector<int>gr[NN];
int sz[NN],cnt[NN],col[NN],biggs[NN];
ll answww;
ll gg;
ll too[NN];
void ssz(int v,int p=1){
    sz[v]=1;
    for(auto x:gr[v]){
        if(x!=p){
            ssz(x,v);
            sz[v]+=sz[x];
        }
    }
}

void addforvertex(int v,int p){
    cnt[col[v]]+=1;
    if(cnt[col[v]]>gg){
        gg=cnt[col[v]];
        answww=col[v];
    }else if (cnt[col[v]]==gg)answww+=col[v];

    for(int i=0;i<gr[v].size();i++){
        int to=gr[v][i];
        if(to!=p&&biggs[to] != 1){
            addforvertex(to,v);
        }
    }
}

void remforvertex(int v,int p){
    cnt[col[v]]-=1;
    for(auto vv:gr[v]){
        if(vv!=p&&biggs[vv]!=1){
            remforvertex(vv,v);
        }
    }
}

void countit(int v,int p,int bigsmall = 0){
    int bigchild =-1;
    int maxsz=-1;
    for(int i=0;i<gr[v].size();i++){
        if(maxsz<sz[gr[v][i]]&&gr[v][i]!=p){
            bigchild=gr[v][i];
            maxsz=sz[gr[v][i]];
        }
    }

    for(int i=0;i<gr[v].size();i++){
        int to=gr[v][i];
        if(to!=p&&to!=bigchild){
            countit(to,v,0);
        }
    }

    if(bigchild!=-1){
        countit(bigchild,v,1);
        biggs[bigchild]=1;
    }

    addforvertex(v,p);
    too[v]=answww;
    biggs[bigchild]=0;
    if(bigsmall==0) {
        remforvertex(v, p);
        gg = 0;
        answww = 0;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&col[i]);
    }

    for(int i=0;i<n-1;i++){
        scanf("%d %d",&a,&b);
        gr[a].push_back(b);
        gr[b].push_back((a));
    }
    ssz(1,-1);
    countit(1,-1);
    for(int i=1;i<=n;i++){
        cout<<too[i]<< " ";
    }

}


