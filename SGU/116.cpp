#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
#define N 10005

int p[N], sp[300], vis[N], pre[N], dp[N], ans[N], add[N];
bool cmp(int a, int b) {return a > b;}

int main(){
	int num, n, i, j, k, t;
	for (i = 2, k =0; i < N; ++i){
		if (vis[i] == 0){
			p[k++] = i;
			for (j = 2 * i; j < N; j += i) vis[j] = 1;
		}
	}
	for (k = 0; p[k] < N && p[k] != 0 && p[p[k]] != 0; ++k) sp[k] = p[p[k] - 1];
	num = k;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	//for (t = 1; t < 101; ++t){ n = t;
	for (i = 0; i < num; ++i) dp[sp[i]] = 1, pre[sp[i]] = sp[i];
	for (i = 4; i <= n; ++i) {
		for (j = 0; sp[j] < i && sp[j] != 0; ++j){
			if (dp[i - sp[j]] != -1){
				if (dp[i] == -1 || dp[i] > dp[i - sp[j]] + 1){
					dp[i] =  dp[i - sp[j]] + 1;
					pre[i] = i - sp[j];
					add[i] = sp[j];
				}	
			} 
		}
	}
	if (dp[n] > 0){
		printf("%d\n", dp[n]);
		k = 0;
		while (pre[n] != n){
			ans[k++] = add[n];
			n = pre[n];
		}
		ans[k++] = n;
		sort(ans, ans + k, cmp);
		for (i = 0; i < k; ++i) printf("%d ", ans[i]);
		printf("\n");
	}
	else printf("0\n");
	//}
	return 0;
}//看清题目，非增输出， 背包，两个数组记录路径