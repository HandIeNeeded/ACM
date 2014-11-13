int in[N], out[N], a[N << 1], id[N << 1];
int dp[N << 1][20];
int fi[N], ne[N << 1], en[N << 1], edge;
 
void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}
 
int clk;
 
void dfs(int x, int p) {
	in[x] = clk, a[clk] = in[x], id[clk] = x, clk++;
	int good = 0;
	for (int go = fi[x]; go; go = ne[go]) {
		if (en[go] != p) {
			good = 1;
			dfs(en[go], x);
			a[clk] = in[x], id[clk] = x, out[x] = clk, clk++;
		}
	}
	if (!good) out[x] = in[x];
}
 
void ST() {
	REPP(i, 1, 2 * n) dp[i][0] = a[i];
	REPP(i, 1, 20) {
		REPP(j, 1, 2 * n) {
			if (j + (1 << i) - 1 <= 2 * n) {
				dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
			}
			else break;
		}
	}
}
 
int RMQ(int l, int r) {
	int len = 0;
	while (1 << (len + 1) < r - l + 1) len++;
	return min(dp[l][len], dp[r - (1 << len) + 1][len]);
}
 
int find_lca(int x, int y) {
	int ql = in[x], qr = in[y];
	if (ql > qr) swap(ql, qr);
	return id[RMQ(ql, qr)];
}
 
int query(int x, int y, int z) {
	int lca1 = find_lca(x, z), lca2 = find_lca(y, z);
	if (lca1 == lca2) return find_lca(x, y); //考虑两个lca是否相同
	if (in[lca1] <= in[lca2] && out[lca1] >= out[lca2]) return lca2;
	return lca1;
}
//先转化为固定根的lca, 然后询问以z为根的树上的x,y的lca