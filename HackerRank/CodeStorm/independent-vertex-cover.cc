#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;
const int MO = 1e9 + 7;
int a[N], b[N], last[N], n;
vector<int> num;

bool check() {
    int x = inf, y = inf, z = inf;
    for (int i = n; i >= 1; i--) {
        if (a[i] >= y) z = min(a[i], z);
        if (a[i] >= x) y = min(a[i], y);
        x = min(x, a[i]);
    }
    return z == inf;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    cin >> n;
    REPP(i, 1, n) {
        cin >> a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    REPP(i, 1, n) a[i] = lower_bound(num.begin(), num.end(), a[i]) - num.begin() + 1;
    if (check()) {
        for (int i = n; i >= 1; i--) {
            if (i == n) b[i] = a[i];
            else b[i] = min(b[i + 1], a[i]);
        }
        REPP(i, 1, n) last[a[i]] = i;
        int tot = num.size();
        int head = 1, cnt = 1;
        for (int i = 1; i <= tot; i++) {
            if (head > last[i]) continue;
            int mx = 0;
            while (head <= last[i]) {
                mx = max(mx, a[head]);
                head++;
            }
            if (mx < b[last[i] + 1]) {
                cnt++;
            }
            else {
                head--;
                a[head] = mx;
            }
        }
        int ans = 1;
        REP(i, cnt) {
            ans <<= 1;
            if (ans >= MO) ans -= MO;
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}


