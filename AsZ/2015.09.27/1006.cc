#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(), (a).end()
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e5 + 5;
int prefix[N], suffix[N], a[N], tot;
vector<int> number;

void update(int x, int d) {
    while (x <= tot) {
        prefix[x] = max(prefix[x], d);
        x += LB(x);
    }
}

int query(int x) {
    if (x <= 0) return 0;
    int ans = 0;
    while (x) {
        ans = max(ans, prefix[x]);
        x -= LB(x);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1, sum = 0;
    scanf("%d", &t);
    while (t--) {
        number.clear();
        int n, l;
        scanf("%d%d", &n, &l);
        assert(n <= 1e5 && n >= 1 && l >= 0 && l <= n);
        sum += n;
        REPP(i, 1, n) {
            scanf("%d", a + i);
            number.push_back(a[i]);
        }
        sort(ALL(number));
        number.resize(unique(ALL(number)) - number.begin());
        tot = number.size();
        REPP(i, 1, n) a[i] = lower_bound(ALL(number), a[i]) - number.begin() + 1;
        REPP(i, 1, tot) prefix[i] = 0;
        vector<int> tmp;
        suffix[n + 1] = 0;
        a[n + 1] = tot + 1;
        for (int i = n; i >= 1; i--) {
            int pos = lower_bound(ALL(tmp), N - a[i]) - tmp.begin();
            suffix[i] = pos + 1;
            if (pos == int(tmp.size())) {
                tmp.push_back(N - a[i]);
            }
            else {
                tmp[pos] = N - a[i];
            }
        }
        tmp.clear();
        int ans = suffix[l + 1];
        REPP(i, 1, n - l) {
            int pos = lower_bound(ALL(tmp), a[i]) - tmp.begin();
            if (pos == int(tmp.size())) {
                update(a[i], pos + 1);
                tmp.push_back(a[i]);
            }
            else {
                update(a[i], pos + 1);
                tmp[pos] = a[i];
            }
            ans = max(ans, suffix[i + l + 1] + query(a[i + l + 1] - 1));
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    assert(sum <= 5e5);
    return 0;
}

