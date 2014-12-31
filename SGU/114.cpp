#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#pragma warning (disable : 4996)
using namespace std;
#define dou double
#define LL long long
#define N 15005

LL sum[2][N];

struct po{
	LL p, n;
}c[N];

bool cmp(po a, po b){
	return a.p < b.p;
}

int main(){
	LL cnt, i, j;
	LL k, b, cost, x, pt, pm;
	scanf("%I64d", &cnt);
	for (i = 1; i <= cnt; ++i){
		scanf("%I64d%I64d", &c[i].p, &c[i].n);
	}
	sort(c + 1, c + cnt + 1, cmp); //排序要注意是c+cnt+1，总之最后元素指针加一
	for (i = 1; i <= cnt; ++i){
		sum[0][i] = sum[0][i -1] + c[i].p * c[i].n;
		sum[1][i] = sum[1][i - 1] + c[i].n;
	}
	if (cnt == 1) printf("%I64d\n", c[1].p);
	else{
		for (i = 1, pm = 0, cost = -1; i < cnt; ++i){
			k = 2 * sum[1][i] - sum[1][cnt];
			b = sum[0][cnt] - 2 * sum[0][i]; 
			if (k >= 0) pt = c[i + 1].p;
			else pt = c[i].p;
			x = k * pt + b;
			if (cost < 0 || x < cost) cost = x, pm = pt;
		}
		printf("%I64d\n", pm);
	}
	return 0;
}