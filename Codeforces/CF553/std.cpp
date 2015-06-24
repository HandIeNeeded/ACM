#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 510
#define MAXM 7010
#define INF 0x3f3f3f3f
int first[MAXD], e, next[MAXM], v[MAXM], flow[MAXM];
int N, M, K, S, T, d[MAXD], q[MAXD], work[MAXD], mark[MAXD], vis[MAXD];
struct List
{
    int id, mark;
}list[MAXD];
struct Edge
{
    int x, y;
}edge[MAXM];
void init()
{
    int i;
    scanf("%d%d", &N, &M);
    for(i = 0; i < M; i ++)
        scanf("%d%d", &edge[i].x, &edge[i].y);
    scanf("%d", &K);
    for(i = 0; i < K; i ++)
        scanf("%d%d", &list[i].id, &list[i].mark);    
}
void add(int x, int y, int z)
{
    v[e] = y, flow[e] = z;
    next[e] = first[x], first[x] = e ++;    
}
void build(int cur)
{
    int i;
    memset(first, -1, sizeof(first[0]) * (T + 1));
    e = 0;
    for(i = 0; i < M; i ++)
        add(edge[i].x, edge[i].y, 1), add(edge[i].y, edge[i].x, 1);
    for(i = 0; i < K; i ++)
    {
        if(list[i].mark & 1 << cur)
            add(S, list[i].id, INF), add(list[i].id, S, 0);
        else
            add(list[i].id, T, INF), add(T, list[i].id, 0);
    }
}
int bfs()
{
    int i, j, rear = 0;
    memset(d, -1, sizeof(d[0]) * (T + 1));
    d[S] = 0, q[rear ++] = S;
    for(i = 0; i < rear; i ++)
        for(j = first[q[i]]; j != -1; j = next[j])
            if(flow[j] && d[v[j]] == -1)
            {
                d[v[j]] = d[q[i]] + 1, q[rear ++] = v[j];
                if(v[j] == T)
                    return 1;
            }
    return 0;    
}
int dfs(int cur, int a)
{
    if(cur == T)
        return a;
    for(int &i = work[cur]; i != -1; i = next[i])
        if(flow[i] && d[v[i]] == d[cur] + 1)
            if(int t = dfs(v[i], std::min(a, flow[i])))
            {
                flow[i] -= t, flow[i ^ 1] += t;
                return t;
            }
    return 0;
}
int dinic()
{
    int ans = 0;
    while(bfs())
    {
        memcpy(work, first, sizeof(first[0]) * (T + 1));
		ans += dfs(S, INF);
    }
    return ans;
}
void DFS(int cur, int k)
{
    int i;
    vis[cur] = 1;
    mark[cur] |= 1 << k;
    for(i = first[cur]; i != -1; i = next[i])
        if(!vis[v[i]] && flow[i])
            DFS(v[i], k);
}
void solve()
{
    int i;
    long long ans = 0;
    S = 0, T = N + 1;
    memset(mark, 0, sizeof(mark[0]) * (T + 1));
    for(i = 0; i < 31; i ++)
    {
        build(i);
        ans += dinic() * (1ll << i);
        memset(vis, 0, sizeof(vis[0]) * (T + 1));
        DFS(S, i);
    }
    //for(i = 1; i <= N; i ++)
    //    printf("%d\n", mark[i]);
	ans = 0;
	for (i = 0; i < M; i ++) {
		ans += mark[edge[i].x] ^ mark[edge[i].y];
	}
	ans <<= 1;
	printf("%lld\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        init();
        solve();    
    }
    return 0;    
}
