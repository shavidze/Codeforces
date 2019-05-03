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
string save;
int main() {
    cin>>n;
    if(n==1){
        printf("%d\n",1);
        exit;
    }
    if(n==2){
        printf("%d\n",3);
        exit;
    }
    if(n==3){
        printf("%d\n",5);
        exit;
    }
    int i;
    for(i=1;i<=100;i+=2){
        if((i*i+1)/2 >=n){
            break;
        }
    }
    printf("%d\n",i);
}


