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
int a[N], n;
int vis[N], dp[N];

int dijkstra() {
    REPP(i, 1, n) dp[i] = a[i];
    priority_queue<PII, vector<PII>, greater<PII> > q;
    REPP(i, 0, n + 1) {
        q.push({dp[i], i});
    }
    int ans = 0;
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        ans = max(ans, dp[x]);
        REP(i, edge[x].size()) {
            int y = edge[x][i];
            if (dp[y] > dp[x] + 1) {
                dp[y] = dp[x] + 1;
                q.push({dp[y], y});
            }
        }
    }
    return ans;
}

int main() {
	ios :: sync_with_stdio(0);
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    REPP(i, 1, n) {
        edge[i].push_back(i + 1);
        edge[i].push_back(i - 1);
    }
    edge[0].push_back(1);
    edge[n + 1].push_back(n);
    cout << dijkstra() << endl;


	return 0;
}
