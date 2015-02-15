//tarjan 强连通，割顶，桥，点双连通，边双连通 LCA

void tarjan(int x)
{ //强连通：注意要判元素是否弹栈过
    low[x] = dfn[x] = ++now; 
    slack[++top] = x;    
    for (int p = fir[x]; p; p = next[p])
		if (inS[e[p]] == 0)   //判断是否已经弹栈
	    	if (!dfn[e[p]]) 
	    	{
				tarjan(e[p]);
				low[x] = min(low[x], low[e[p]]);
	    	}
	    	else low[x] = min(low[x], dfn[e[p]]);
    if (low[x] == dfn[x])
    {   //belong 属于的强联通分量标号
			cou[belong[x] = ++tot] = 1;   //cou 强联通分量元素个数
			inS[x] = 1;
			for (; low[slack[top]] != dfn[slack[top]]; --top)
			{
	   			cou[belong[slack[top]] = tot]++;
	    		inS[slack[top]] = 1;
			}
			--top;
    }	
}   

割点和点双联通
void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++top;
    f[x] = fa;
    for (int p = fir[x]; p; p = next[p])
	if (!vis[p] && dfn[e[p]] <= dfn[x]) //避免横叉边和重边等情况
	{
	    vis[p] = vis[p ^ 1] = 1;
	    slack.PB(MP(x, e[p]));
	    if (!dfn[e[p]])
	    {
		tarjan(e[p], x);
		low[x] = min(low[x], low[e[p]]);
		if (low[e[p]] >= dfn[x]) //这个过程还不能判割点，因为起始点1会有问题
		{
		    g[++cnt].clear();
		    for (;;) {
			int u = slack.back().FI;
			int v = slack.back().SE;
			if (belong[u] != cnt) ++tot[cnt], g[cnt].push_back(u);
			if (belong[v] != cnt) ++tot[cnt], g[cnt].push_back(v);
			belong[u] = belong[v] = cnt;
			slack.pop_back();
			if (u == x && v == e[p]) break;
		    }
		}
	    } else low[x] = min(low[x], dfn[e[p]]);
	}
}

REPP(i, 2, n)
{
    if (f[i] == 1) ++sonOne;
    else if (low[i] >= dfn[f[i]]) //!!! 注意此处的else，dfs树要单独考虑
	isCut[f[i]] = 1;
}
if (sonOne >= 2) isCut[1] = 1;

求桥改成 low[i]>dfn[f[i]]
边双连通分支，去掉桥之后求连通块
点双连通分量性质：
每条边恰好属于一个双连通分量；
不同双连通分量最多只有一个公共点，且一定是割顶；
任意割顶都是至少两个不同双连通分量的公共点.

求lca
void dfs(int x, LL len)
{
    vis[x] = 1;
    d[x] = len;   //带Q的为询问的邻接表
    for (int p = firQ[x]; p; p = nextQ[p])
	if (vis[eQ[p]]) lca[lab[p]] = getfa(eQ[p]);
    for (int p = fir[x]; p; p = next[p])
	if (!vis[e[p]])
	{
	    dfs(e[p], len + 1LL * c[p]);
	    f[e[p]] = x;
	}
}
