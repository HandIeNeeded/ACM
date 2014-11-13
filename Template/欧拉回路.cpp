void dfs(int x) {
	REPP(i, 1, n) {
		if (mp[x][i]) {
			mp[x][i]--, mp[i][x]--;
			dfs(i);
		}
	}
	path[now++] = x;
}
