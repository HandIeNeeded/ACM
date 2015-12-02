#include <bits/stdc++.h>
#define MAXM 301234

using namespace std;

typedef int arrayM[MAXM];

int num, fam[20];
arrayM fir, e, nxt, c, vis, di;
int bfee, K, comLoc, N, M, d[17][17];

const int INF = 2e8;

void link(int u, int v, int cost) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, c[num] = cost;
}

deque <int> deq;
void spfa(int pos, int label) {
    for (int i = 1; i <= N; ++i) {
        di[i] = INF;
        vis[i] = 0;
    }
    di[label] = 0;
    vis[label] = 1;
    deq.push_back(label);
    for (; !deq.empty(); ) {
        int u = deq.front();
        vis[u] = 0;
        deq.pop_front();
        for (int p = fir[u]; p; p = nxt[p]) {
            int v = e[p];
            if (di[v] > di[u] + c[p]) {
                di[v] = di[u] + c[p];
                if (!vis[v]) {
                    deq.push_back(v);
                    vis[v] = 1;
                }
            }
        }
    }

    for (int i = 0; i <= K; ++i)
        d[pos][i] = di[fam[i]];
}

void getMin(long long &u, long long v) {
    if (v < u) u = v;
}

long long dp[1 << 17][17][6];

void dphaha() {
    memset(dp, 0x3f, sizeof(dp));
    long long ans = dp[0][0][0];
    for (int i = 0; i < K; ++i)
        dp[1 << i][i][1] = bfee + d[K][i];

    int lim = 1 << K;
    for (int sta = 1; sta < lim; ++sta)
        for (int j = 0; j < K; ++j)
            if (sta & (1 << j)) {
                for (int h = 0; h < K; ++h)
                    if (!(sta & (1 << h)))
                        for (int carCnt = 1; carCnt <= 4; ++carCnt) {
                            int nsta = sta | (1 << h);
                            getMin(dp[nsta][h][1], dp[sta][j][carCnt] + bfee + d[K][h]);
                            if (carCnt < 4) getMin(dp[nsta][h][carCnt + 1], dp[sta][j][carCnt] + d[j][h]);
                        }
            }
    for (int i = 0; i < K; ++i)
        for (int j = 1; j <= 4; ++j)
            getMin(ans, dp[lim - 1][i][j]);
    cout << ans << endl;
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif // HOME
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int dir, u, v, cost;
        scanf("%d%d%d%d", &dir, &u, &v, &cost);
        link(u, v, cost);
        if (dir == 2) link(v, u, cost);
    }
    scanf("%d", &bfee);
    scanf("%d", &comLoc);
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &fam[i]);
        if (fam[i] == comLoc) {
            --K;
            --i;
        }
    }

    fam[K] = comLoc;

    for (int i = 0; i <= K; ++i)
        spfa(i, fam[i]);

    dphaha();

    return 0;
}

