
//#include"pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <math.h>
using namespace std;
int Min(int a, int b);
int a[100008], l[100008]; int n, m; int results[100008]; int keepDist[100005];
int main()
{
	cin >> n >> m;
	results[0] = 0;

	int size = sizeof(keepDist) / sizeof(int);
	for (int i = 0; i < sizeof(keepDist) / sizeof(int); i++) {
		keepDist[i] = 0;
	}
	results[n + 1] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = n; i >= 0; i--) {
		results[i] = results[i + 1];

		if (keepDist[a[i]] == 0)
			results[i] += 1;

		keepDist[a[i]] += 1;
	}
	for (int i = 1; i <= m; i++) {
		cin >> l[i];
	}
	//cout << "111111111111" << endl;
	for (int i = 1; i <= m; i++) {
		cout << results[l[i]] << endl;
	}

	//system("pause");
	return 0;
}

int Min(int a, int b) {
	return a > b ? b : a;
}
