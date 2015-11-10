#include <bits/stdc++.h>
#define MAXN 21000
#define MAXM 10123456

using namespace std;
typedef int arrayN[MAXN], arrayM[MAXM];

const int INF = 0x3f3f3f3f;
arrayN q, s, lastPos, ansArr;
arrayN preAns, nxtAns;

struct MinCostFlow{
    arrayN fi, pre, dp, ti;
    arrayM ne, en, cap, cost;
    bool vis[MAXN];
    int source, sink, edge, now;

    void init(int S, int T) {
        source = S, sink = T;
        edge = 1;
        cnt = now = 0;
    }

    void _add(int x, int y, int z, int w) {
        ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
        cap[edge] = z, cost[edge] = w;
    }

    void add(int x, int y, int z, int w) {
        _add(x, y, z, w);
        _add(y, x, 0, -w);
       // cout << x << "<-->" << y << endl;
    }


    int cnt;

    void prt(int x) {
        for (int go = fi[x]; go; go = ne[go]) {
            printf("%d --> %d, cap: %d, cost: %d\n", x, en[go], cap[go], cost[go]);
        }
    }

    bool spfa() {
        ++now;
        //memset(dp, 0x3f, sizeof(dp));
        queue<int> q;
        q.push(source), vis[source] = 1;
        dp[source] = pre[source] = 0;
        dp[sink] = INF;
        ti[source] = now;
     /*   if (cnt == -1) {
            prt(19);
            prt(9);
            prt(8);
            prt(11);
            prt(5);
        }*/
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int go = fi[x]; go; go = ne[go])
                if (cap[go] > 0) {
                    int y = en[go];
                    if ((dp[y] > dp[x] + cost[go]) || ti[y] != now) {
                        dp[y] = dp[x] + cost[go];
                        ti[y] = now;
                        pre[y] = go;
                        if (!vis[y]) {
                            vis[y] = 1;
                            q.push(y);
                        }
                    }
                }
            vis[x] = 0;
        }
        return dp[sink] != INF;
    }

    pair<int, int> mincost() {
        int cost = 0, flow = 0;
        while (spfa()) {
            ++cnt;
            //cout << cnt << ':' << dp[sink] << endl;
            int tmp = INF;
            for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
                tmp = min(tmp, cap[go]);
            }
            for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
                cap[go] -= tmp;
                cap[go ^ 1] += tmp;
              //  cout << en[go ^ 1] << ' ';
            }
            //cout << endl;
            cost += tmp * dp[sink];
            flow += tmp;
        }
        return make_pair(cost, flow);
    }

    void getAns(int n) {
        for (int i = n + 1; i <= n + n; ++i) {
            for (int go = fi[i]; go; go = ne[go])
                if (cap[go ^ 1] > 0){
                int v = en[go];
                if (v >= 1 && v <= n) {
                    preAns[v] = i - n;
                    nxtAns[i - n] = v;
                }
            }
        }
    }

} flow;

vector <int> vec[MAXN];

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif // HOME
    int N, M, K;
    scanf("%d%d%d", &N, &K, &M);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &q[i]);
    int n = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &s[i]);
        for (int j = 1; j <= s[i]; ++j) {
            int x;
            scanf("%d", &x);
            vec[i].push_back(x);
        }
        s[i] += s[i - 1];
    }

    n = s[N];
    int S0 = 2 * n + 1;
    int S = S0 + 1;
    int T = S + 1;
    int SS = T + 1;
    int TT = SS + 1;

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    flow.init(SS, TT);
   // cout << SS << ' ' << TT << endl;
    flow.add(S0, S, K, 0);
    for (int i = 1; i <= n; ++i)
        flow.add(S, i, 1, 0);
    flow.add(T, S0, INF, 0);
    for (int i = 1; i <= n; ++i) {
        flow.add(SS, n + i, 1, 0);
        flow.add(i, TT, 1, 0);
        flow.add(n + i, T, 1, 0);
    }

    memset(lastPos, -1, sizeof(lastPos));
 /*   for (int i = 0; i <= n - 1; ++i)
        printf("%d\n", vec[i]); */
    for (int t = N; t >= 1; --t) {
        int base = s[t - 1];
        for (int j = 1; j <= M; ++j)
            if (lastPos[j] != -1)
            for (int i = 0; i < vec[t].size(); ++i) {
                    int u = base + i + 1 + n;
                    int v = lastPos[j] + 1;
                    int w = q[j];
                    if (vec[t][i] == j) w = 0;
                    flow.add(u, v, 1, w);
            }
        for (int i = 0; i < vec[t].size(); ++i)
            lastPos[vec[t][i]] = i + base;
       // cout << lastPos[6];
    }

    pair <int, int> ans;
    ans = flow.mincost();
    //cout << K << endl;
    printf("%d\n", ans.first);//, ans.second);

    flow.getAns(n);

    int boyCnt = 0;
    for (int i = 1; i <= n; ++i) {
       // cout << preAns[i] << ' ' << nxtAns[i] << endl;
        if (preAns[i] == 0) {
            ++boyCnt;
            for (int tmp = i; tmp; tmp = nxtAns[tmp])
                ansArr[tmp] = boyCnt;
        }
    }
    for (int i = 1; i <= N; ++i) {
        int base = s[i - 1];
        for (int j = 0; j < vec[i].size(); ++j)
            printf("%d%c", ansArr[base + j + 1], " \n"[j == vec[i].size() - 1]);
    }
    return 0;
}

/*
19 20
1
2
3
4
5
2
4
6
1:0
7 12 19
2:0
6 10 19
3:0
4 17 18 16 19
4:0
3 17 18 15 19
5:0
2 17 18 14 19
6:0
1 17 18 13 19
7:1
8 11 19
8:10
5 9 19
4
11 8

*/
