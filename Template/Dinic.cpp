//O(N^2*M)
//struct 注意总结点数，以及cur的赋值的范围是1-tot

int source, sink;
int fi[N], en[M << 1], ne[M << 1], e[M << 1], edge; //M number of edge 
//edge = 1, mem(fi);
int lvl[N], vis[N]; //N number of vertex	uesd in bfs
int cur[N]; //dangqianhu index

void _add(int x, int y, int z) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, e[edge] = z;
}

//undirected _add(x, y, z) _add(y, x, z)
//directed
void add(int x, int y, int z) { //edge x -> y cap z    invedge y -> x cap 0 
	_add(x, y, z);
	_add(y, x, 0); //invedge　initially cap is 0, can be positive
}

int bfs() {
	queue<int> q;
	mem(lvl), mem(vis);
	q.push(source); vis[source] = 1;
	int x, y;
	while (!q.empty()) {
		x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) if (!vis[en[go]] && e[go] > 0){
			y = en[go];
			lvl[y] = lvl[x] + 1;
			q.push(y), vis[y] = 1;
		}
	}
	return lvl[sink];
}

int dfs(int x, int flow) {
	if (x == sink || flow == 0) return flow;
	int ans = 0, tmp, y;
	for (int& go = cur[x]; go; go = ne[go]) {
		y = en[go];
		if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, e[go]))) > 0) {
			e[go] -= tmp, e[go ^ 1] += tmp;
			flow -= tmp, ans += tmp;
			if (flow == 0) break;
		}
	}
	return ans;
}

int Dinic() {
	int maxflow = 0, tmp;
	while (bfs()) {
		REPP(i, 1, sink) cur[i] = fi[i]; //all vertex 1 -> sink (sink is the largest vertex) !!!!!!
		while (tmp = dfs(source, INF)) maxflow += tmp;
	}
	return maxflow;
}

