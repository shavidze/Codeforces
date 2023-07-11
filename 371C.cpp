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

string ch;
ll B,C,S;
ll R;
ll na,nb,nc,pa,pb,pc;
int main() {

    cin>>ch;

    for(int i=0;i<ch.size();i++){
        if(ch[i]=='B'){
            B++;
        }
        if(ch[i]=='S'){
            S++;
        }
        if(ch[i]=='C'){
            C++;
        }
    }

    cin>>na>>nb>>nc;
    cin>>pa>>pb>>pc;
    cin>>R;
    if(C==0){
        nc=1000000000000000000,C=1;
        pc=0;
    }
    if(B==0){
        na=1000000000000000000,B=1;
        pa=0;
    }
    if(S==0){
        nb=1000000000000000000,S=1;
        pb=0;
    }
    int gvak = min(min(na/B,nb/S),nc/C);
    ll nna=na-B*gvak;
    ll nnb=nb-S*gvak;
    ll nnc=nc-C*gvak;
    ll low = 0,high = 20000000000001;
    while(low+1<high){
        ll md = (low+high)/2;
        //md -cals
        ll gadA = (B*md*pa) -(nna*pa);
        if(gadA<0)gadA=0;
        ll gadB = (S*md*pb) - (nnb*pb);
        if(gadB<0)gadB=0;
        ll gadC = (C*md*pc) - (nnc*pc);
        if(gadC<0)gadC=0;
        if(gadA+gadB+gadC<=R){
            low = md;

        }else high = md;
    }

    cout<<low+gvak<<endl;
    return 0;

}


