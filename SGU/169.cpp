#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma warning (disable : 4996)
#define N 3333
#define mem(a) memset(a, 0, sizeof(a))
#define LL long long
#define inf 111111111
#define sl(a) strlen(a)
using namespace std;

int go(int x){
	int re = 1, t = 0;
	for (int i = 0; i < x; ++i){
		t = (t * 10 + 1) % 7;
	}
	if (t == 1) return 1;
	return 0;
}

int main(){
	int ca = 1, i, j, k, l, n, t, tem, num, re, d, x, y, z;
	scanf("%d", &t);
	if (t == 1) printf("8\n");
	else {
		re = 1;
		if (t % 3 == 1) {
			re += 2;
			if (go(t)) re++;
		}
		printf("%d\n", re);
	}
	return 0;
}//数论，n, n + 1互质, 前缀只能是1
