#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#pragma warning (disable : 4996)
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define N 150
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

	po operator * (const po &t) const{
		po tem;
		mem(tem.a);
		LL r, i, j;
		for (i = r = 0; i < N; ++i)
			for (j = 0; j < N; ++j){
				if (i + j < N) {
					tem.a[i + j] += (a[i] * t.a[j] + r);
					r = tem.a[i + j] / M;
					tem.a[i + j] %= M;
				}
				else {
					r = 0;
					break;
				}
			}
		return tem;
	}

	po operator + (const po &t) const{
		po tem;
		mem(tem.a);
		LL r, i;
		for (i = 0, r = 0; i < N; ++i){
			tem.a[i] = a[i] + t.a[i] + r;
			r = tem.a[i] / M;
			tem.a[i] %= M;
		}
		return tem;
	}

	po operator / (const LL &t) const{
		po tem;
		mem(tem.a);
		LL i, r;
		for (i = N - 1, r = 0; i >= 0; --i){
			tem.a[i] = (a[i] + r * M) / t;
			r = (a[i] + r * M) % t;
		}
		return tem;
	}

}ans, tar;

int  main(){
	char s[N * 8], t[8 * N];
	int i, j, k, n, len;
	mem(tar.a);
	scanf("%s", s);
	len = sl(s);
	for (i = 0; i < len && s[i] == '0'; ++i);
	strcpy(t, s + i);
	len = sl(t);
	for (i = len - 1, k = 0; i >= 0; i -= 9, k++){
		for (j = 0; j < 9; ++j) 
			if (i - 8 + j >= 0) tar.a[k] = 10 * tar.a[k] + t[i - 8 + j] - '0';
	}
	po st, en, m, d;
	mem(st.a), mem(en.a), mem(d.a);
	st.a[((len + 1) / 2 - 1) / 9] = pow(10, ((len + 1) / 2 - 1) % 9);
	en.a[(len + 1) / 2 /9] = pow(10, (len + 1) / 2 % 9);
	d.a[0] = 2;
	while (1){
		if (st + d > en) {
			ans = st;
			break;
		}
		else{
			m = (st + en) / 2;
			if (m * m > tar) en = m;
			else st = m; 
		}
	}
	for (i = N - 1; i >= 0 && st.a[i] == 0; --i);
	printf("%lld", st.a[i--]);
	for (; i >= 0; --i) printf("%09lld", st.a[i]);
	return 0;
}//高精乘压九位

