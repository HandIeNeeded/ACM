int q[N], dp[N], vis[N], pre[N], cnt[N], st, en, bad;
int mp[N][N];
//vis的作用就是表示当前的点是否在队列里面

void spfa(int x) {
	memset(dp, 0x3f, sizeof(dp));
	dp[x] = 0;
	q[st] = x, vis[st] = 1, pre[x] = 0, en = 1;//所有点从1开始标号
	while (st < en) {
		int y = q[st];
		REP(i, N) {
			if (mp[y][i] && dp[i] > dp[y] + mp[y][i]) {
				pre[i] = x;
				dp[i] = dp[y] + mp[y][i];
				if (!vis[i]) {
					cnt[i]++, q[en++] = i;
					if (cnt[i] >= N - 1) {
						bad = 1;
						break;
					}
				}
			} 
		}
		st++, vis[y] = 0;
		if (bad) break;
	}
}
