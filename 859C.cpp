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
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define exit return 0
#define N 1555
#define inf 1000000000000000000LL
typedef long long ll;
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (int i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left v<<1
#define right left|1
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
using namespace std;
int n,m,k,b,a;
int in[100];
int f[100];
int answ = INT32_MAX;
vector<int>floors[123];
int main(){

    scanf("%d\n",&n);

    for(int i = 0; i<n;i++)scanf("%d",&in[i]);

    f[n] = 0;
    for(int i = n-1;i>=0;i--){
        f[i] = abs(in[i]-f[i+1]);
    }

    int sum = accumulate(in,in+n,1ll);

    printf("%d %d\n",(sum-f[0])/2,(sum+f[0])/2);

    exit;

    return 0;

}
