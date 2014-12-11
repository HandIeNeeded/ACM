void dfsBigSonAndColor(int x, int fa, int deepth, int color){
    vis[x] = 1;
    g[x].size = 1, g[x].fa = fa;
    g[x].dep = deepth, g[x].col = color;
    for (int p = fir[x]; p; p = next[p])
	if (!vis[e[p]]){
	    dfsBigSonAndColor(e[p], x, deepth + 1, 1 - color);
	    g[x].size += g[e[p]].size;
	    g[e[p]].edLab = lab[p];
	    if (g[e[p]].size > g[g[x].bigSon].size)
		g[x].bigSon = e[p];
	}
}

void dfsHeavyedge(int x, int fa)
{
    rank[x] = ++now, slack[now] = x;
    vis[x] = 1;
    if (!g[x].bigSon)
    {
	REPP(i, last + 1, now) 
	    g[slack[i]].top = slack[last + 1];
	last = now;
	return ;
    }
    dfsHeavyedge(g[x].bigSon, x);
    for (int p = fir[x]; p; p = next[p])
	if (e[p] != g[x].bigSon && !vis[e[p]])
	    dfsHeavyedge(e[p], x);
}



void addPath(int u, int v, int value)
{
    for (; g[u].top != g[v].top; v = g[g[v].top].fa)
    {
	if (g[g[u].top].dep > g[g[v].top].dep) swap(u, v);
	add(rank[g[v].top], rank[v], value);
    }
    if (g[u].dep > g[v].dep) swap(u, v);
    add(rank[u] + 1, rank[v], value);
}
