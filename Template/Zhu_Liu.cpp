//求森林的最小树形图时建虚拟根到每个点连无穷大的边
double zhu_liu(int root){ 
	double tmp = 0;
	int tot = n, ntot;
	for (; tot; ){
	REPP(i, 1, tot) inW[i] = oo, belong[i] = vis[i] = 0;
	REPP(i, 1, m) //找每个点最小的入边
		if (e[i].u != e[i].v && inW[e[i].v] > e[i].w)
			inW[e[i].v] = e[i].w, pre[e[i].v] = e[i].u;
	ntot = 0;
	pre[root] = 0;  //这里很容易忽略！！！
	inW[root] = 0.0;
	REPP(i, 1, tot)  {//缩点
		if (inW[i] > 1e15) return -1;
		tmp += inW[i];
		if (vis[i]) continue;
		int h = i;
		for (; !vis[h]; h = pre[h]) vis[h] = i;
		if (h == 0 || vis[h] != i) continue;
		belong[h] = ++ntot;
		int tt = h;
		for (h = pre[h]; h != tt; h = pre[h])
		belong[h] = ntot;
	}
	REPP(i, 1, tot)
		if (!belong[i]) belong[i] = ++ntot;
		if (tot == ntot) return tmp;
		tot = ntot;
		REPP(i, 1, m){
			e[i].w -= inW[e[i].v];
			e[i].u = belong[e[i].u];
			e[i].v = belong[e[i].v];
		}
		root = belong[root]; //！！！
	}
	return tmp;
}

