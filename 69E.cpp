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
const long NN = (200005);
set<int>qq;
map<int,int>ff;
int in[NN];
int m,n;


void rus() {
    if(!qq.size()){
        printf("Nothing\n");
    }else{
        printf("%d\n",*qq.rbegin());
    }
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }

    for(int i=0;i<m;i++){
        if(ff[in[i]]==0){
            qq.insert(in[i]);
        }
        if(ff[in[i]]==1){
            qq.erase((in[i]));
        }
        ff[in[i]]+=1;
    }
    rus();
    for(int i=0;i<n-m;i++){
        if(ff[in[i+m]]==1){
            qq.erase((in[i+m]));
        }
        if(ff[in[i+m]]==0){
            qq.insert((in[i+m]));
        }
        //how many times have so far
        ff[in[i+m]]+=1;
        if(ff[in[i]]==2){
            qq.insert((in[i]));
        }
        if(ff[in[i]]==1){
            qq.erase((in[i]));
        }
        ff[in[i]]-=1;
        rus();
    }

    return 0;
}
