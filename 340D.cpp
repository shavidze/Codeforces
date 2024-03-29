#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MX(a,b)a>b?a:b
#define S 123457
using namespace std;
int n, A[S], T[4 * S];
int res;
int sum(int x){
	int ans = 0;
	while (x > 0){
		ans = MX(ans, T[x]);
		x -= (x&-x);
	}
	return ans;
}

void up(int x, int val){
	while (x <= n){
		T[x] = max(T[x], val);
		x += (x&-x);
	}
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &A[i]);
	}
	up(A[1], 1);
	for (int i = 2; i <= n; i++){
		int a = sum(A[i]);
		up(A[i], a + 1);
		res = MX(res, a + 1);
	}
	printf("%d", res);
	return 0;
	//system("pause");
}
