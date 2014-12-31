#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma warning (disable : 4996)
#define N 511111
#define Max (1 << 19)
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

bool p[19][Max];
char s[N];

int cal(int st, int m){
	int re = 0, i;
	for (i = st; i < st + m; ++i){
                if (s[i] == 'a') re <<= 1;
				else re = (re << 1) + 1;
	}
	return re;
}

int main(){
    int l, i, j, k, m;
	scanf("%d%s", &l, s);
	for (i = 1; (1 << i) <= l - i + 1; ++i);
	m = i;
	for (i = 1; i <= m; ++i){
		for (j = 0; j + i <= l; ++j) p[i - 1][cal(j, i)] = true;
	}
	for (j = 1; j <= m; ++j)
                for (i = 0; i < (1 << j); ++i) if (!p[j - 1][i]){
                        k = 0;
                        printf("%d\n", j);
                        while (k < j){
                                if (i & 1) s[j - k - 1] = 'b';
                                else s[j - k - 1] = 'a';
                                i >>= 1; k++;
                        }
						s[j] = 0;
						puts(s);
                        return 0;
                }
}//卡内存！！

