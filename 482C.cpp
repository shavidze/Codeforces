#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

string s[51];
double dp[1050000];
int b[1050000];
long long bm[1050000];
int N, M;

void prep(){
    for(int i=0;i<(1<<M);++i)
        bm[i] = 0;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            int cur = 0;
            for(int k=0;k<M;++k){
                if(s[i][k] == s[j][k]){
                    cur |= 1<<k;
                }
            }
            bm[cur] |= 1LL<<i;
            bm[cur] |= 1LL<<j;
        }
    }
    for(int i=(1<<M)-1;i>=0;--i){
        for(int j=0;j<M;++j){
            bm[i & (~(1<<j))] |= bm[i];
        }
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> s[i];
    }
    M = s[0].size();
    int lim = 1<<M;
    prep();
    b[0] = 0;
    for(int i=0;i<lim;++i){
        b[i] = b[i/2] + i%2;
    }
    double cnt, prob, p, tot;
    long long cur;
    dp[lim-1] = 0;
    for(int i=lim-2;i>=0;--i){
        tot = 0;
        p = 1 / ((double)M - b[i]);
        dp[i] = 0;
        tot = (double)__builtin_popcount(bm[i]);
        tot += (double)__builtin_popcount(bm[i]>>32);
        if(bm[i] == 0){
            dp[i] = 0;
            continue;
        }
        for(int j=0;j<M;++j){
            if(!(i & (1<<j))){
                cnt = 0;
                cur = bm[i ^ (1<<j)] | ~bm[i];
                cur = ~cur;
                cnt = __builtin_popcount(cur);
                cnt += __builtin_popcount(cur>>32);
                prob = cnt/tot;
                dp[i] += ((dp[i ^ (1<<j)] + 1) * (1-prob) + prob) * p;
            }
        }
    }
    printf("%.12lf\n", dp[0]);
    return 0;
}
