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

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int dp[N], vis[N], now, n;

int bfs(int x) {
    now++;
    queue<int> q;
    REPP(i, 1, n) dp[i] = inf;
    dp[x] = 0, vis[x] = now;
    q.push(x);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (auto &y: edge[x]) {
            if (vis[y] != now) {
                dp[y] = dp[x] + 1, vis[y] = now;
                q.push(y);
            }
        }
    }
    int mx = -1, ans = 0;
    REPP(i, 1, n) if (dp[i] > mx) {
        mx = dp[i];
        ans = i;
    }
    return ans;
}

vector<int> path;
int L[N], R[N];

bool getPath(int now, int pre, int target) {
    L[now] = pre;
    if (now == target) {
        R[now] = 0;
        path.push_back(now);
        return 1;
    }
    for (auto &y: edge[now]) {
        if (y != pre) {
            if (getPath(y, now, target)) {
                R[now] = y;
                path.push_back(now);
                return 1;
            }
        }
    }
    return 0;
}

int tot;

void good(int x, int dep, int p) {
    int cnt = 0;
    for (auto &y: edge[x]) {
        if (y != p) {
            good(y, dep + 1, x);
            cnt++;
        }
    }
    if (dep == 1 && cnt >= 3) 
    if (cnt >= 3) tot++;
    return ;
}

int main() {
	ios :: sync_with_stdio(0);

    cin >> n;
    REPP(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int start = bfs(1);
    int end = bfs(start);
    now++;
    getPath(start, 0, end);
    int can = 0;
    if (path.size() & 1) {
        int x = path[path.size() / 2];
        for (auto &y: edge[x]) {
            good(y, 1, x);
        }
        //cout << "hehe" << endl;
        //cout << L[x] << ' ' << R[x] << endl;
        can = tot < 3;
    }
    else {
        int x = path[path.size() / 2];
        int y = path[path.size() / 2 - 1];
        good(x, y), good(y, x);
        //cout << x << ' ' << y << endl;
        can = tot < 3;
    }
    if (can) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

	return 0;
}

