int mat[N], vis[N]; //vis[x] 右边x有没有被访问过 mat[x] 右边x所匹配的边

bool dfs(int x) {//x为来自左边的点
	for (int go = fi[x]; go; go = ne[go]) if (!vis[en[go]]) {
		vis[en[go]] = 1;
		if (!mat[en[go]] || dfs(mat[en[go]])) {
			mat[en[go]] = x;
			return true;
		}
	}
	return false;
}

int Hungarian(){
	int match = 0;
	mem(mat);
	REPP(i, 1, n) {
		mem(vis);
		if (dfs(i)) match++;
	}
	return match;
}
