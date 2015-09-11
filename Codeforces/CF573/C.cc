#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define debug(x) cout << #x << "is: " << x << endl

#define FI first
#define SE second
#define VI vector<int>
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define pb push_back
#define pf push_front

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

const int N = 1e5 + 5;
VI edge[N], e[N];
int vis[N], cnt[N], ban[N];

void dfs(int x) {
    cnt[x]--;
    if (edge[x].size() <= 2) {
        ban[x] = vis[x] = 1;
        for (auto &y: edge[x]) {
            if (!vis[y]) {
                dfs(y);
            }
        }
    }
}

bool use[N];

int bfs(int x) {
    queue<int> q;
    q.push(x), use[x] = 1;
    int ans = x;
    while (q.size()) {
        int x = q.front(); q.pop();
        for (auto &y: edge[x]) {
            if (!use[y] && ban[y] != 1) {
                use[y] = 1;
                q.push(y);
                ans = y;
            }
        }
    }
    return ans;
}

bool DFS(int x, int p = 0) {
    int cnt = 0;
    for (auto &y: edge[x]) if (y != p) {
        if (vis[y] != 1 && !ban[y]) {
            if (!DFS(y, x)) return 0;
            cnt++;
        }
    }
    return cnt <= 1;
}

int main() {
	ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    REPP(i, 1, n) cnt[i] = edge[i].size();
    REPP(i, 1, n) if (edge[i].size() == 1) {
        dfs(i);
    }
    //REPP(i, 1, n) {
    //    cout << i << ' ' << cnt[i] << ' ' << vis[i] << endl;
    //}
    //cout << endl;
    REPP(i, 1, n) if (!vis[i] && cnt[i] == 1 && cnt[i] != int(edge[i].size())) {
        ban[i] = 1;
    }
    REPP(i, 1, n) if (edge[i].size() > 3) {
        ban[i] = 0;
    }
    //REPP(i, 1, n) {
    //    cout << i << ' ' << cnt[i] << ' ' << vis[i] << endl;
    //}
    //cout << endl;
    int ans = 1;
    REPP(i, 1, n) if (ban[i] == 0) {
        int start = bfs(i);
        ans &= DFS(start);
        break;
    }
    ans ? puts("Yes") : puts("No");

	return 0;
}
