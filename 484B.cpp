#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2000009;

int n, m, k, answww;
int in[N];
int mm[N];
int near[N];
int main(){
	scanf("%d ", &n);
	while (n--){
		scanf("%d", &k);
		mm[k] = k;
	}

	for (int i = 1; i <= N; i++){
		if (mm[i]){
			near[i] = i;
		}
		else{
			near[i] = near[i - 1];
		}
	}

	for (int i = 1; i <= N; i++){
		if (mm[i] == i){
			for (int j = i + i - 1; j <= N; j += i){
				answww = max(answww, near[j] % i);
			}
		}
	}
	printf("%d\n", answww);
	return 0;
}
