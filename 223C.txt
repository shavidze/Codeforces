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
#include <fstream>
#include <cstring>
#include <numeric>
#include <ctype.h>
#define MOD 1000000007
#define MN(a,b)a<b?a:b
#define N 10100
#define PS system("pause")
#define exit return 0
//#define inf 1000000000000000000LL
//#define left (v<<1)
//#define right (left|1)
#define tm ((tl+tr)>>1)
typedef long long ll;
//#define S 525231
#define R0(i,n) for(int i=0;i<(int)n;i++)
#define R1(i,n) for(int i=1;i<=(int)n;i++)


using namespace std;

struct sg{
	int pasL = 0, pasR = 0, pas = 0;
	int X, Y, SZ;
	sg *left, *right;
	sg(){
		/*pasL = 0, pasR = 0, pas = 0;
		left = right = NULL;*/
	}
};

sg *F = new sg;
sg *root;

int getSZ(sg *T){
	if (T)return T->SZ;
	else return 0;
}


void upSZ(sg *&T){
	if (T)T->SZ = getSZ(T->left) + getSZ(T->right) + 1;
}


void UpdateInfo(sg *&T, sg *L, sg *R){
	T->pas = L->pas + R->pas + min(L->pasL, R->pasR);
	T->pasL = L->pasL + R->pasL - min(L->pasL, R->pasR);
	T->pasR = L->pasR + R->pasR - min(L->pasL, R->pasR);
}

void UP(sg *&T){
	if (T){
		sg *tmp = F;
		sg *T1 = F;
		T1->pas = T1->pasL = T1->pasR = 0;
		if (T->X == 1)T1->pasL = 1;
		else T1->pasR = 1;

		if (!T->left&&!T->right){
			T->pasL = T1->pasL;
			T->pasR = T1->pasR;
			T->pas = T1->pas;
			return;
		}


		if (!T->left){
			UpdateInfo(T, T1, T->right);
			return;
		}
		if (!T->right){
			UpdateInfo(T, T->left, T1);
			return;
		}
		UpdateInfo(tmp, T->left, T1);
		UpdateInfo(T, tmp, T->right);
	}

}


void split(sg *t, sg *&L, sg *&R, int K, int add){
	if (!t){
		L = R = NULL;
		return;
	}
	int cur_Key = add + getSZ(t->left);
	if (cur_Key < K){
		split(t->right, t->right, R, K, cur_Key + 1);
		L = t;
	}
	else {
		split(t->left, L, t->left, K, add);
		R = t;
	}
	upSZ(t);
	UP(t);
}

void merge(sg *&t, sg *L, sg *R){

	if (!L)t = R;
	else if (!R)t = L;
	else if (L->Y > R->Y){
		merge(L->right, L->right, R);
		t = L;
	}
	else{
		merge(R->left, L, R->left);
		t = R;
	}
	upSZ(t);
	UP(t);

}


//void insertIt(sg *&T, sg *it){
//	if (!T)T = it;
//
//	if (it->Y > T->Y){
//		split(T, it->left, it->right, it->X, 0);
//		T = it;
//	}
//	else{
//		if (T->X <= it->X)insertIt(T->right, it);
//		else insertIt(T->left, it);
//	}
//}
//

//void eraseIt(sg *&T, int K){
//	if (!T)return;
//	if (T->X == K){
//		sg *tmp = T;
//		merge(T, T->left, T->right);
//		free(tmp);
//	}
//	else if (T->X < K){
//		eraseIt(T->right, K);
//	}
//	else eraseIt(T->left, K);
//}


sg *goit(int K){
	sg *on = new sg;
	on->X = K;
	on->Y = rand();
	on->SZ = 1;
	on->pas = on->pasL = on->pasR = 0;
	if (K == 1)on->pasL = 1;
	else on->pasR = 1;
	on->left = on->right = NULL;
	return on;
}

char  in[1000005];
int Q, l, r;
sg *tmp;
int main(){
	root = NULL;
	scanf("%s", in);
	int siz = strlen(in);
	for (int i = 0; i < siz; i++){
		tmp = goit(((in[i] == '(') ? 1 : 2));
		if (!root){
			root = tmp;
		}
		else{
			merge(root, root, tmp);
		}
	}
	scanf("%d", &Q);
	sg *T1, *T2, *T3, *T4;

	while (Q--){
		scanf("%d %d", &l, &r);
		l--, r--;
		split(root, T1, T2, l, 0);
		split(T2, T3, T4, r - l + 1, 0);
		printf("%d\n", T3->pas * 2);
		merge(T2, T3, T4);
		merge(root, T1, T2);
	}
	exit;
	//PS;
}
