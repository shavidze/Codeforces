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
#define ll long long
//using ul = unsigned long long;
using PII = pair<int, int>;
const long NN = (1 << 18);
int answww;
int n, m, q, d, c;
int x, y;
int zzz;



struct Trie{
	char c;
	bool is;
	Trie* child[26];
	Trie(){
		c = 0;
		is = false;
		for (int i = 0; i < 26; i++){
			child[i] = NULL;
		}
	}
	Trie(char _c){
		c = _c;
		is = false;
		for (int i = 0; i < 26; i++){
			child[i] = NULL;
		}
	}

	void addEdge(char pp){
		if (child[pp - 'a'] == NULL){
			child[pp - 'a'] = new Trie(pp);
		}
	}

	Trie* get(char _c){
		return child[_c - 'a'];
	}
};

Trie rr;
int ans;

Trie* addW(Trie *on, string &s, int xx){
	if (xx == s.length())return on;
	on->addEdge(s[xx]);
	return addW((on->get(s[xx])), s, xx + 1);
}


Trie *getW(Trie *on, string &s, int xx){
	if (xx == s.length()){
		if (!(on->is)){
			on->is = true;
			ans++;
		}
		return on;
	}
	return getW(on->get(s[xx]), s, xx + 1);

}

int main(){

	string ss, bt;
	cin >> ss >> bt;


	scanf("%d", &c);

	for (int i = 0; i < ss.length(); i++){
		string save = "";
		Trie *vv = &rr;
		for (int j = i; j < ss.length(); j++){
			save += ss[j];
			vv = addW(vv, save, j - i);
		}
	}

	for (int i = 0; i < ss.length(); i++){
		string was = "";
		Trie *vv = &rr;
		int bads = 0;
		for (int j = i; j < ss.length(); j++){
			was += ss[j];
			if (bt[ss[j] - 'a'] == '0')bads++;
			if (bads>c)break;
			vv = getW(vv, was, j - i);
		}
	}

	printf("%d", ans);
	//PS;
	return 0;
}
