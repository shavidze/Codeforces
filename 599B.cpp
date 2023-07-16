#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>
#define PS system("pause")
using namespace std;
string s;
int N;
int var;
int A[1234567];
int B[1234589];
int fx[1234567];
int id[1234567];
int mx[2];
int mn[2];
int n, m;
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> A[i];
		fx[A[i]]++;
		id[A[i]] = i;
	}
	for (int i = 1; i <= m; i++){
		cin >> B[i];
		if (fx[B[i]] == 0){
			puts("Impossible");
			return 0;
		}
	}
	for (int i = 1; i <= m; i++){
		if (fx[B[i]] > 1){
			puts("Ambiguity");
			return 0;
		}
	}
	puts("Possible");
	for (int i = 1; i <= m; i++){
		cout << id[B[i]] << " ";
	}
	return 0;
}
