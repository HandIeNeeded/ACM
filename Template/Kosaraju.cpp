//SCC O(N+M)

VI mp[N], g[N], s; // mp 原图邻接表 g 原图转置邻接表 原图节点从0开始标号 栈
int vis[N], sccno[N], scc_cnt; //i 所属于的SCC的标号 1--> scc_cnt，SCC数量

void dfs1(int x) {
	vis[x] = 1;
	REP(i, SZ(mp[x])) if (!vis[mp[x][i]]) dfs1(mp[x][i]);
	s.PB(x);
}

void dfs2(int x) {
	sccno[x] = scc_cnt;
	REP(i, SZ(g[x])) if (!sccno[g[x][i]]) dfs2(g[x][i]);
}

void find_scc(int n) {
	scc_cnt = 0;
	s.clear();
	mem(vis), mem(sccno);
	REP(i, n) if (!vis[i]) dfs1(i);
	for (int i = n - 1; i >= 0; --i) {
		if (!sccno[s[i]]) {
			scc_cnt++; 
			dfs2(s[i]);
		} 
	}
}
