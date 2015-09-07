#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n, k;
int l[5005], r[5005], s[10005];
long long dp[5005][10005];

int main(){
	freopen("Fin", "r", stdin);
	scanf("%d%d", &n, &k);
	int m = 1; s[0] = k;
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &l[i], &r[i]);
		s[m++] = l[i];
		s[m++] = r[i];
	}
	sort(s, s + m);
	m = unique(s, s + m) - s;
	for (int i = 0; i < m; ++ i){
		dp[0][i] = 2 * abs(k - s[i]) + abs(l[0] - s[i]) + abs(r[0] - s[i]) - abs(r[0] - l[0]);
	}
	for (int i = 1; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			dp[i][j] = dp[i-1][j] + abs(l[i] - s[j]) + abs(r[i] - s[j]) - abs(r[i] - l[i]);
		}
	}
	long long ans = 1e18;
	for (int i = 0; i < m; ++ i){
		ans = min(ans, dp[n-1][i]);
	}
	cout << ans / 2 << endl;
	return 0;
}