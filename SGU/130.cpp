#include <iostream>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
#define dou double
#define LL long long
#define N 35

LL f[N];

int main(){
        int i, j;
	for (i = 2, f[0] = f[1] = 1; i < N; ++i)
		for (j = 0; j < i; ++j)
			f[i] += f[j] * f[i - j - 1];
    	LL n, m;
    	cin >> n;
    	printf("%lld %lld\n", f[n], n + 1);
    	//system("pause");
    	return 0;
}//所有弦不相交时块最少，方案数为卡特兰数
