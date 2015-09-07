#include <bits/stdc++.h>

using namespace std;

int indeg[20010], stamp[20010], seq[20010];
std::bitset<20010> reach[20001];
std::vector<int> revEdges[20010], edges[20010];

bool cmp(int u, int v) {
    return stamp[u] > stamp[v];
}

void MAIN() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i) {
        edges[i].clear();
        revEdges[i].clear();
        indeg[i] = 0;
        reach[i].reset();
        reach[i][i] = true;
    }
    for(int i = 0, u, v; i < m; ++ i) {
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        revEdges[v].push_back(u);
        ++ indeg[v];
    }
    std::queue<int> q;
    for(int i = 1; i <= n; ++ i) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    int timestamp = -1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        stamp[now] = ++ timestamp;
        seq[timestamp] = now; 
        for(auto next: edges[now]) {
            if(-- indeg[next] == 0) {
                q.push(next);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= timestamp; ++ i) {
        int now = seq[i];
        std::sort(revEdges[now].begin(), revEdges[now].end(), cmp);
        for(int preNode: revEdges[now]) {
            if(reach[now][preNode]) {
                ++ ans;
            }
            reach[now] |= reach[preNode];
        }
    }
    printf("%d\n", ans);
}

int main() {
    int n;
    clock_t st = clock();
    scanf("%d", &n);
    while(n --) {
        MAIN();
    }
    clock_t ed = clock();
    cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
