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
#include <cstring>
#define ll long long
using namespace std;

ll powmod(ll a, ll b) { ll res = 1; for (; b; b >>= 1){ if (b & 1)res = res*a; a = a*a; }return res; }


int N, K;
ll a, b, w, x, C;
int in[2222];
int curMX;

bool check(ll mid){

	a -= (b + mid*x) / w;
	C -= mid;
	if (C <= a)return 1;
	return 0;


}

#define PS system("pause")


ll _a, _b, _w, _x, _C;
int main(){

	cin >> _a >> _b >> _w >> _x >> _C;

	if (_C <= _a){
		cout << 0 << endl;
		return 0;
	}

	ll low = -1, high = 200000000000001;

	while (low + 1 < high){

		ll mid = (low + high) / 2;
		a = _a, b = _b, w = _w, x = _x, C = _C;
		b = w - b - 1;
		if (check(mid)){
			high = mid;
		}
		else low = mid;
	}

	cout << high << endl;

	//PS;


	return 0;









}














