#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
pair<LL, LL> p[N];
int pre[N];
LL mx[N];

int main() {
    ios::sync_with_stdio(0);
    int n, L, R;
    cin >> n >> L >> R;
    REPP(i, 1, n) {
        LL x, y;
        cin >> x >> y;
        LL up = x * L + y, down = x * R + y;
        p[i] = {up, down};
    }
    sort(p + 1, p + n + 1);
    REPP(i, 1, n) pre[i] = i - 1;
    REPP(i, 0, n) mx[i] = -1LL << 60;
    REPP(i, 1, n) {
        if (p[i].first == p[i - 1].first) {
            pre[i] = pre[pre[i - 1]];
        }
        mx[i] = max(mx[i - 1], p[i].second);
    }
    REPP(i, 1, n) {
        if (p[i].second < mx[pre[i]]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}


