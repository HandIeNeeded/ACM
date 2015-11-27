#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
vector<LL> val[N];
vector<tuple<int, int, LL>> circle;
int vis[N], now, cnt;
LL num[N], a[N];

void dfs(int x, LL z = 0) {
    //cout << x << endl;
    vis[x] = now, num[x] = z;
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y < x && vis[y] == now) continue;
        if (vis[y] == now) {
            circle.push_back(make_tuple(x, y, val[x][i]));
        }
        else {
            dfs(y, z ^ val[x][i]);
        }
    }
}

int Gauss() {
    int n = cnt;
    LL bit = 1LL << 60;
    int rank = 1;
    REP(turn, 60) {
        bit >>= 1;
        int find = 0;
        REPP(i, rank, n) {
            if (a[i] & bit) {
                find = 1;
                swap(a[rank], a[i]);
                break;
            }
        }
        if (!find) continue;
        REPP(i, 1, n) {
            if (i != rank && (a[i] & bit)) {
                a[i] ^= a[rank];
            }
        }
        rank++;
    }
    rank--;
    return rank;
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) edge[i].clear(), val[i].clear();
        REPP(i, 1, m) {
            int x, y;
            LL z;
            scanf("%d%d%lld", &x, &y, &z);
            edge[x].push_back(y), val[x].push_back(z);
            edge[y].push_back(x), val[y].push_back(z);
        }
        now++;
        circle.clear();
        dfs(1);
        //REPP(i, 1, n) {
        //    cout << i << ' ' << num[i] << endl;
        //}
        cnt = 0;
        for (auto &now: circle) {
            int x, y;
            LL z;
            tie(x, y, z) = now;
            a[++cnt] = num[x] ^ num[y] ^ z;
            //cout << x << ' ' << y << ' ' << z << ' ' << a[cnt] << endl;
        }
        int rank = Gauss();
        //cout << "rank: " << rank << endl;
        LL ans = 0;
        REPP(i, 1, rank) ans ^= a[i];
        printf("Case #%d: %lld\n", ca++, ans);
    }
    return 0;
}

