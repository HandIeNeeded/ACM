#include <bits/stdc++.h>

#define N 100100
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define LL long long

using namespace std;

int nex[N], tail[26], maxi[1 << 26];
short vis[1 << 26], now;
char str[N], bit[1 << 13];
int use[26];

int get(int x) {
	return bit[x >> 13] + bit[x & ((1 << 13) - 1)];
}

int main() {
	freopen("jingles.in", "r", stdin);
	freopen("jingles.out", "w", stdout);
	int T;
	scanf("%d", &T);
	REP(i, 1 << 13) bit[i] = __builtin_popcount(i);
	while (T--) {
		scanf("%s", str);
		int n = strlen(str);
		for (int i = 0; i < n; i++) str[i] -= 'a';
		for (int i = 0; i < 26; i++) tail[i] = n;
		for (int i = n - 1; i >= 0; i--) nex[i] = tail[str[i]], tail[str[i]] = i;
		memset(use, -1, sizeof(use));
		int tot = 0;
		for (int i = 0; i < n; i++) {
			if (use[str[i]] < 0) {
				use[str[i]] = tot++;
			}
			str[i] = use[str[i]];
		}
		int K = tot;
		now++;
		LL ans = 0;
		int cnt = 0;
		for (int k = 1; k <= K; k++) {
			int l = 0, r = 0;
			int mask = 0;
			while (r < n) {
				while (r < n && get(mask | (1 << str[r])) <= k) mask |= (1 << str[r++]);
				if (vis[mask] != now) {
					maxi[mask] = 0;
					vis[mask] = now;
					cnt++;
				}
				if (r - l > maxi[mask]) {
					ans += get(mask) * (r - l - maxi[mask]);
					maxi[mask] = r - l;
				}
				while (l < n && nex[l] < r) l++;
				mask ^= (1 << str[l++]);
			}
		}
		printf("%d %I64d\n", cnt, ans);
	}
	return 0;
}
