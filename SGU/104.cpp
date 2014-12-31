#include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
#define mem(a) memset(a, 0, sizeof(a))

int a[N], b[N];
int dp[N], p[100005];

bool Cmp(int x,int y){
	if (y==0) return 1;
	if (b[x-1]<b[x]&&b[y-1]<b[y]) return 1;
	if (b[x-1]>b[x]&&b[y-1]>b[y]) return 1;
	if (b[x-1]==b[x]&&b[y-1]==b[y]) return 1;
	return 0;
}

bool Cmp2(int x,int y){
	if (y==0) return 1;
	if (a[x-1]<a[x]&&b[y-1]<b[y]) return 1;
	if (a[x-1]>a[x]&&b[y-1]>b[y]) return 1;
	if (a[x-1]==a[x]&&b[y-1]==b[y]) return 1;
	return 0;
}

int main(){
	int n, i, j, k, re, x, y, tem, m;
	while (cin >> n >> m >> k){
		mem(a), mem(b), mem(cnt), mem(dp);
		for (i = 1; i <= n; ++i) scanf("%d", a + i), cnt[a[i]]++;
		for (i = 1; i <= m; ++i) scanf("%d", b + i);
		next[1]=0;
		now=0;
		for (int i=2;i<=m;i++){
			while (now&&!Cmp(i,now+1))now=next[now];
			if (Cmp(i,now+1))now++;
			next[i]=now;
		}
		now=0;
		for (int i=1;i<=n;i++){
			while (now&&Cmp2(i,now+1))now=next[now];
			if (Cmp2(i,now+1))now++;
			if (now==m) p[i-m+1]=1;
		}
		for (i = 1; i < m; ++i) dp[i] = 0;
		for (i = m; i <= n; ++i) dp[i] = max(dp[i - 1], dp[i - m] + p[i - m + 1]);
		cout << dp[n] << endl;
	}
	
	return 0;
}