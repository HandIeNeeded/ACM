#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 1111
#define mem(a) memset(a, 0, sizeof(a))
#define LL long long
using namespace std;

int SG[N], vis[N], p[11] = {1};

int check(int x){
        int i, j;
        for (j = 1; j < 5; ++j)
                for (i = 0; i < x; ++i){
                        if (SG[i + 500 + j * x] != SG[i + 500]) return 0;
                }
        return 1;
}

int main(){
	int n, i, j, k, t, re, d;
	ios :: sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n >> k;
		for (i = 1; i <= k; ++i){
			cin >> p[i];
		}
		SG[0] = 1, SG[1] = 0;
		for (i = 2; i < N; ++i){
			mem(vis);
			for (j = 0; j <= k; ++j) if (i - p[j] >= 0) vis[SG[i - p[j]]] = 1;
			for (j = 0; j < N; ++j) if (!vis[j]) {SG[i] = j; break;}
		}
		for (i = 10; i < 100; ++i) {
                        if (check(i)){
                               d = i; break;
                        }
		}
		//for (i = 0; i < 1000; ++i) cout << i << ' ' << SG[i] << endl;
		if (n > 500) {
                        if (SG[(n - 500) % d + 500]) printf("FIRST PLAYER MUST WIN\n");
                        else printf("SECOND PLAYER MUST WIN\n");
		}
		else {
                        if (SG[n]) printf("FIRST PLAYER MUST WIN\n");
                        else printf("SECOND PLAYER MUST WIN\n");
		}
	}
	return 0;
}//SG[]函数，暴力找规律，找周期，证明至今仍然不会
