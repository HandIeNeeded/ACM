#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#pragma warning (disable : 4996)
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define N 30
#define M 1000000000
#define LL long long
#define sl(s) strlen(s)

struct po{
	LL a[N];
	bool operator > (const po &t) const{
		LL i;
		for (i = N - 1; i >= 0 && a[i] == t.a[i]; --i);
		if (i < 0) return false;
		else return a[i] > t.a[i];
	}

	bool operator == (const po &t) const{
		LL i;
		for (i = N - 1; i >= 0 && a[i] == t.a[i]; --i);
		if (i < 0) return true;
		else return false;
	}

	po operator * (const int &t) const{
		po tem;
		mem(tem.a);
		LL r, i, j;
		for (i = r = 0; i < N; ++i){
			tem.a[i] = (a[i] * t + r);
			r = tem.a[i] / M;
			tem.a[i] %= M;
		}
		return tem;
	}

	po operator - (const po &t) const{
		po tem;
		mem(tem.a);
		LL r, i;
		for (i = 0; i < N; ++i) tem.a[i] = a[i] - t.a[i];
		for (i = 0; i < N - 1; ++i) if (tem.a[i] < 0) tem.a[i] += 1000000000, tem.a[i + 1]--;
		return tem;
	}

};

int  main(){
	int i, j, k, n, len, a, b;
	/*freopen("in.txt", "r", stdin);
		freopen("myout.txt", "w", stdout);*/
	while (scanf("%d%d", &a, &b) > 0){
		po st, en, d, tem;
		mem(st.a), mem(en.a), mem(tem.a);
		st.a[0] = en.a[0] = 1;
		for (i = 0; i < b; ++i) st = st * a;
		for (i = 0; i < a; ++i) en = en * b;
		if (st == en) printf("0\n");
		else if (st > en) {
			tem = st - en;
			for (i = N - 1; i >= 0 && tem.a[i] == 0; --i); 
			printf("%I64d", tem.a[i--]);
			for (; i >= 0; --i) printf("%09I64d", tem.a[i]);
			printf("\n");
		}
		else{
			printf("-");
			tem = en - st;
			for (i = N - 1; i >= 0 && tem.a[i] == 0; --i); 
			printf("%I64d", tem.a[i--]);
			for (; i >= 0; --i) printf("%09I64d", tem.a[i]);
			printf("\n");
		}
	}
	return 0;
}

