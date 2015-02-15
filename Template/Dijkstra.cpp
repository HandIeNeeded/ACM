#define PII pair<int, int>

struct cmp{
	bool operator () (const PII& a, const PII& b) {
		return a.first > b.first;
	}
};
 
priority_queue<PII, VP, cmp> q;
//priority_queue<PII, VP, greater<PII> > q;
 
int fi[N], en[M << 1], ne[M << 1], v[M << 1], tot;
 
void add(int x, int y, int z) {
	ne[++tot] = fi[x], fi[x] = tot, en[tot] = y, v[tot] = z;
}
 
int d[N], vis[N];
 
void dijkstra() {
	REPP(i, 1, n) d[i] = INF;
	d[1] = 0;
	q.push(MP(0, 1));
	while (!q.empty()) {
		PII tem = q.top();
		q.pop();
		int x = tem.second;
		if (vis[x]) continue;
		vis[x] = 1;
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go], z = v[go];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				q.push(MP(d[y], y));
			}
		}
	}
}
