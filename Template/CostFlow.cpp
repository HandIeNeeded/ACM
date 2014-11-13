int line[SI], nex[SI];
int capa[SI], cost[SI];
int en[N], hs[N], f[N], dist[N];
bool sta[N], inpath[N];
int s, t;

int dfs(int u, int flow)
{
    if (u == t)
    {
        ans += flow * dist[u];
        return flow;
    }
    sta[u] = true;
    inpath[u] = true;
    int res = 0;
    int i = hs[u];
    while (i)
    {
        int v = line[i];
        if (!inpath[v])
        {
            int rest = flow - res;
            rest = min(capa[i], rest);

            int gap = dist[u] + cost[i] - dist[v];
            f[v] = rest ? min(f[v], gap) : f[v];

            if (rest && !gap)
            {
                int tmp = dfs(v, rest);
                res += tmp;
                capa[i] -= tmp;
                capa[i ^ 1] += tmp;
            }
            if (res == flow)
                break;
        }
        i = nex[i];
        hs[u] = i;
    }
    inpath[u] = false;
    return res;
}

pair<int , int> zkw(int lim, int n)
{
    ans = 0;
    int flow = 0;
    mem(dist);
    mem(inpath);
    while (1)
    {
        REP(i, n)
            f[i] = INF;
        mem(sta);
        memcpy(hs, en, sizeof(en));

        flow += dfs(s, lim - flow);
        if (flow == lim)
            break;

        int tmp = INF;
        REP(i, n)
            if (!sta[i])
                tmp = min(tmp, f[i]);
        if (tmp == INF)
            break;
        REP(i, n)
            if (!sta[i])
                dist[i] += tmp;
    }
    if (flow == lim)
        return make_pair(flow, ans);
    else
        return make_pair(-1, -1);
}
