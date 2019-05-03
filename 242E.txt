#define _CRT_SECURE_NO_WARNINGS


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
#include <stack>
#include <cassert>
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#define MOD 100000000   
#define exit return 0
#define inf 10000000000
#define exit return 0
#define PS system("pause")
#define S 100007
#define mx(a,b) a>b?a:b
#define R0(i,n) for (i = 0; i < n; i++)
#define R1(i,n) for (i = 1; i <= n; i++)
#define MS(a,x) memset(x, a, sizeof(x));
#define left (v<<1)
#define right (left|1)
#define mid ((tl+tr)>>1)
#define SZ(x) ((int)x.size())
#define MX(a,b)a>b?a:b
const double eps = 1e-10;

using namespace std;
using ll = long long;
//using ul = unsigned long long;
using PII = pair<int, int>;
const long NN = (1 << 18);
int answww[NN];
int n, m, q, a, b, c;
ll x;
int zzz;
int tt[NN], in[NN];
struct sgs{
	int sum;
	bool pushed;
	sgs *l, *r;

	void up(){
		this->sum = l->sum + r->sum;
	}

	sgs(){}

	sgs(int x) :sum(x), l(0), r(0), pushed(0){

	}

	sgs(sgs *_l, sgs *_r){
		this->pushed = 0;
		l = _l, r = _r;
		up();
	}

	void pushit(int tl, int tr, int md){
		if (this->pushed){
			this->pushed = 0;
			this->l->pushed ^= 1;
			this->r->pushed ^= 1;
			this->l->sum = (md - tl + 1) - this->l->sum;
			this->r->sum = (tr - md - this->r->sum);
		}
	}
	void change(int tl, int tr){
		this->pushed ^= 1;
		this->sum = (tr - tl + 1) - this->sum;
	}

};

sgs *TT[20];
sgs *build(int tl, int tr){
	if (tl == tr){
		return new sgs(tt[tl]);
	}
	return new sgs(build(tl, mid), build(mid + 1, tr));
}


void xorOn(sgs *on, int tl, int tr, int l, int r){
	if (tl > r || tr < l)return;

	if (tl >= l&&tr <= r){
		on->change(tl, tr);
		return;
	}

	on->pushit(tl, tr, mid);
	xorOn(on->l, tl, mid, l, r);
	xorOn(on->r, mid + 1, tr, l, r);
	on->up();
}

int get(sgs *on, int tl, int tr, int l, int r){
	if (tl > r || tr < l)return 0;

	if (tl >= l&&tr <= r){
		return on->sum;
	}
	on->pushit(tl, tr, mid);
	return get(on->l, tl, mid, l, r) + get(on->r, mid + 1, tr, l, r);

}

void doit(int l, int r, int x){
	for (int i = 0; i < 20; i++){
		if (x&(1 << i)){
			xorOn(TT[i], 0, n - 1, l, r);
		}
	}
}

long long answer(int l, int r){
	long long ret = 0;
	for (int i = 0; i < 20; i++){
		ret += (1LL << i)*get(TT[i], 0, n - 1, l, r);
	}
	return ret;
}

int tipo, l, r;
int main(){

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}

	for (int i = 0; i < 20; i++){
		for (int aa = 0; aa < n; aa++){
			if (in[aa] & (1 << i)){
				tt[aa] = 1;
			}
		}
		TT[i] = build(0, n - 1);
		memset(tt, 0, sizeof(tt));
	}

	scanf("%d", &q);
	while (q--)
	{
		scanf("%d %d %d", &tipo, &l, &r);
		if (tipo == 1){
			printf("%I64d\n", answer(l - 1, r - 1));
		}
		else{
			scanf("%d ", &x);
			doit(l - 1, r - 1, x);
		}
	}
	return 0;
}





