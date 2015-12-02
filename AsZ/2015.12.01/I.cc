#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
pair<int, int> a[N], b[N];

bool cmpa(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first || (a.first == b.first && a.second > b.second);
}

bool cmpb(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = make_pair(x, y);
        }
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            b[i] = make_pair(x, y);
        }
        sort(a + 1, a + n + 1, cmpa);
        sort(b + 1, b + m + 1, cmpb);
        multiset<int> s;
        int now = 1;
        //first atk second def
        int bad = 0;
        int alive = 0;
        REPP(i, 1, m) {
            while (now <= n && a[now].first >= b[i].second) {
                s.insert(a[now].second);
                now++;
            }
            if (!s.size()) {
                bad = 1;
                break;
            }
            auto it = s.upper_bound(b[i].first);
            if (it == s.end()) {
                s.erase(s.begin());
            }
            else {
                alive++;
                s.erase(it);
            }
        }
        int ans = alive + n - now + 1 + s.size();
        if (bad) ans = -1;
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}

