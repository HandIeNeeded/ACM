#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int h[N];

bool good(int a, int b, int c) {
    return 1LL * (h[a] - h[b]) * (b - c) < 1LL * (h[b] - h[c]) * (a - b);
}

int main() {
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    REPP(i, 1, n) cin >> h[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        vector<int> q;
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (q.size() == 0) {
                q.push_back(i);
                continue;
            }
            int x = q.back(), y = q[q.size() - 2];
            while (q.size() > 1 && good(i, x, y)) {
                q.pop_back();
                if (q.size() > 1) x = q.back(), y = q[q.size() - 2];
            }
            x = q.back();
            q.push_back(i);
            ans = max(ans, (h[i] - h[x] + (i - x - 1)) / (i - x));
        }
        cout << ans << endl;
    }


    return 0;
}

