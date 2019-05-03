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
const int NN = (10000009);
long long sum[NN];
int m,n;
int a,b,c;
pair<long long,long long >gg[100005];


int main() {
    scanf("%d",&n);
    for (int i = 0; i <n; ++i) {
        cin>>gg[i].first>>gg[i].second;
    }
    sort(gg,gg+n);
    long long x = gg[0].second;
    for(int i=1;i<n;i++){
        if(x>gg[i].second){
            a++;
        } else x= gg[i].second;
    }
    if(a==0){
        cout<<0;exit;
    }
    cout<<a;
    return 0;

}


