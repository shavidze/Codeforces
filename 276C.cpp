//2104
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define left v<<1
#define right left|1
#define S 251234
#define ll long long
using namespace std;
ll A[S], B[S], n, m, sume;
ll Tree[S * 4];
ll N, Q, a, b;
ll sum(int idx){
	ll s = 0;
	while (idx > 0){
		s += Tree[idx];
		idx -= (idx&-idx);
	}
	return s;
}

void update(int idx, int val){
	while (idx <= S){
		Tree[idx] += val;
		idx += (idx&-idx);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d ", &A[i]);
	}
	sort(A, A + n);
	for (int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		update(a, 1);
		update(b + 1, -1);
	}
	for (int i = 1; i <= n; i++){
		B[i - 1] = sum(i);
	}
	sort(B, B + n);
	for (int i = n - 1; i >= 0; i--){
		sume += A[i] * B[i];
	}
	printf("%I64d\n", sume);
	return 0;
}
