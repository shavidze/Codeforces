#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define exit return 0
using namespace std;
int N, a, b, c;
int X[3];
int win[777][777];
int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		//cin >> X[i];
		scanf("%d",&X[i]);
		b ^= X[i];
	}

	int flag = 0;
	if (N == 3){
		if (b){
			puts("BitLGM");
		}
		else puts("BitAryo");
		exit;
	}
	win[0][0] = 0;
	if (N == 2){
		for (int i = 0; i <= X[0]; i++){
			for (int j = 0; j <= X[1]; j++){
				for (int k = 1; k <= 300; k++){
					if (win[i][j] == 0){
						win[i + k][j] = 1;
						win[i][j + k] = 1;
						win[i + k][j + k] = 1;
					}
				}
			}
		}
		if (win[X[0]][X[1]]){
			puts("BitLGM");
		}
		else{
			puts("BitAryo");
		}
		exit;
	}
	if (X[0] != 0){
		puts("BitLGM");
		exit;
	}
	puts("BitAryo");
	exit;

}
