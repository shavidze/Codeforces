#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#define N 100010
#define REP(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int n, m, i, j;
vector<long long>D(N, 1e18);
vector<int>P(N, -1);
bool visited[N];
vector<pair<int, int>>G[N];
priority_queue<pair<int, int>> Q;
int main(){
    cin >> n >> m;
    //.memset(visited, 0, sizeof(visited));
    vector<long long>T;
    long long X, Y, Z;
    REP(i, 1, m){
        cin >> X >> Y >> Z;
        G[X].push_back(make_pair(Y, Z));
        G[Y].push_back(make_pair(X, Z));
    }
    D[1] = 0;
    Q.push(make_pair(-D[1], 1));
    while (!Q.empty()){
        pair<int, int> a = Q.top();
        Q.pop();
        int v = a.second;
        long long d = -a.first;
        if (D[v] < d)continue;
        long long to;
        for (int j = 0; j < G[v].size(); j++){
            to = G[v][j].first;
            int length = G[v][j].second;
            if (D[to]>length + D[v]){
                P[to] = v;
                D[to] = length + D[v];
                Q.push(make_pair(-D[to], to));
            }
        }

    }
    if (D[n] == 1e18){
        cout << "-1";
        return 0;
    }
    while (n != -1){
        T.push_back(n);
        n = P[n];
    }
    reverse(T.begin(), T.end());
    for (long long path : T){
        cout << path << " ";
    }
    //system("pause");
    return 0;

}
