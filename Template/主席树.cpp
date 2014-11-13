const int N = 100005;

struct SGT{
	int l, r, cnt;
	SGT(int a = 0, int b = 0, int c = 0) : l(a), r(b), cnt(c) {}
}p[N * 20];

int fi[N], ne[N << 1], en[N << 1], edge;
int fa[N], path[N << 1], mp[N << 1], in[N], val[N], clk;
int dp[N << 1][20], head[N];
int n, m, node;

void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

int New_Node() {
	p[node] = SGT();
	return node++;
}

void update(int pre, int &now, int num, int l, int r) {
	now = New_Node();
	if (l == r) {
		p[now].cnt = p[pre].cnt + 1;
	}
	else {
		int mid = l + r >> 1;
		if (num <= mid) {
			update(p[pre].l, p[now].l, num, l, mid);
			p[now].r = p[pre].r;
		}
		else {
			update(p[pre].r, p[now].r, num, mid + 1, r);
			p[now].l = p[pre].l;
		}
		p[now].cnt = p[p[now].l].cnt + p[p[now].r].cnt;
	}
}

int query(int x, int y, int z, int w, int num, int l, int r) {
	if (l == r) {
		return p[x].cnt + p[y].cnt - p[z].cnt - p[w].cnt > 0;
	}
	else {
		int mid = l + r >> 1;
		int tmp = p[x].cnt + p[y].cnt - p[z].cnt - p[w].cnt;
		if (tmp == 0) return 0;
		else {
			if (num <= mid) {
				return query(p[x].l, p[y].l, p[z].l, p[w].l, num, l, mid);
			}
			else {
				return query(p[x].r, p[y].r, p[z].r, p[w].r, num, mid + 1, r);
			}
		}
	}
}

void getpath(int x, int p) {
	in[x] = ++clk;
	path[clk] = in[x];
	mp[clk] = x;
	for (int go = fi[x]; go; go = ne[go]) if (en[go] != p) {
		getpath(en[go], x);
		path[++clk] = in[x];
		mp[clk] = x;
	}
}

void ST() {
	n = 2 * n - 1;
	REPP(i, 1, n) dp[i][0] = path[i];
	REPP(len, 1, 20) {
		if ((1 << len) <= n) {
			REPP(i, 1, n) {
				if (i + (1 << len) - 1 <= n) {
					dp[i][len] = min(dp[i][len - 1], dp[i + (1 << (len - 1))][len - 1]);
				}
				else {
					break;
				}
			}
		}
		else {
			break;
		}
	}
	n = (n + 1) >> 1;
}

void dfs(int x, int p) {
	fa[x] = p;
	if (val[x] <= n && val[x] >= 1) update(head[p], head[x], val[x], 1, n);
	for (int go = fi[x]; go; go = ne[go]) if (en[go] != p) {
		dfs(en[go], x);
	}
}

int findlca(int x, int y) {
	int ql = in[x], qr = in[y];
	if (ql > qr) swap(ql, qr);
	int len = 0;
	while ((1 << (len + 1)) < qr - ql + 1) len++;
	return mp[min(dp[ql][len], dp[qr - (1 << len) + 1][len])];
}

//New_Node() 0号节点作为空节点, head[0] = 1是空树的根, 从1开始标号
//head 每棵线段树的起始点 val　每个节点上存的数字 fa 每个节点的父亲节点
//dp倍增做RMQ为了得到LCA
//path 树的欧拉序列　mp映射表(clk -> node)　in节点第一次进入的时间

