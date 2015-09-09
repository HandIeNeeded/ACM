#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int L = 8e5 + 5;
const int N = 2e5 + 5;
const int C = 26;

int tr[L][C], idx[L][2], node, tot;
char tmp[L];
vector<int> v[N];
vector<pair<int, int> > pans;

int Node() {
    MST(tr[node], 0);
    return node++;
}

void insert(char *s, int type, int id) {
    int now = 0;
    while (*s) {
        int x = *s++ - 'a';
        if (!tr[now][x]) tr[now][x] = Node();
        now = tr[now][x];
    }
    if (idx[now][type] == 0) {
        idx[now][type] = tot++;
    }
    v[idx[now][type]].push_back(id);
}

int merge(int a, int b) {
    if (v[a].size() < v[b].size()) {
        swap(a, b);
    }
    v[a].insert(v[a].end(), v[b].begin(), v[b].end());
    return a;
}

int ans;

void dfs(int x, int dep = 0) {
    REP(i, C) {
        if (tr[x][i]) {
            dfs(tr[x][i], dep + 1);
            REP(j, 2) idx[x][j] = merge(idx[x][j], idx[tr[x][i]][j]);
        }
    }
    auto &A = v[idx[x][0]];
    auto &B = v[idx[x][1]];
    int length = min(A.size(), B.size());
    ans += length * dep;
    REP(i, length) {
        pans.push_back({A[A.size() - 1 - i], B[B.size() - 1 - i]});
    }
    A.resize(A.size() - length);
    B.resize(B.size() - length);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    Node(), tot++;
    REP(j, 2) {
        REPP(i, 1, n) {
            scanf("%s", tmp);
            insert(tmp, j, i);
        }
    }
    dfs(0);
    printf("%d\n", ans);
    for (auto &x: pans) {
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}

