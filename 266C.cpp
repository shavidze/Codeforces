#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define endl '\n'
#define EPS (1e-9)
#define Pi 3.14159265358979
#define INF 1000000500
#define pb push_back
#define mp make_pair
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int , int >
#define VI vector < int >
#define DID (long long)
#define ll long long
#define AL(a) (a).begin(),(a).end()
#define FORI(i,s,n) for (i = (s) ;i <=n ;i++)
using namespace std;
ll a[500080], sum[500090], ans, k;
ll n, i, j;
int main(){
    cin >> n;
    FORI(i, 1, n){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (a[n] % 3 != 0){ cout << 0; return 0; }
    ll best = a[n] / 3;
    ll ori = 2;
    FORI(i, 1, n - 1){
        if (a[i] == ori * best){
            ans += k;
        }
        if (a[i] == best){ k++; }
    }
    cout << ans;
}
