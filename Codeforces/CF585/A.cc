#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 4005;
int v[N], d[N], vis[N];
LL p[N];

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    REPP(i, 1, n) cin >> v[i] >> d[i] >> p[i];
    vector<int> ans;
    REPP(i, 1, n) {
        if (vis[i]) continue;
        if (p[i] >= 0) {
            ans.push_back(i);
            for (int j = i + 1, k = v[i]; j <= n && k; j++) if (!vis[j]) {
                p[j] -= k;
                k--;
            }
        }
        LL minus = 0;
        REPP(j, i + 1, n) if (!vis[j]) {
            p[j] -= minus;
            if (p[j] < 0) {
                vis[j] = 1;
                minus += d[j];
            }
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}

