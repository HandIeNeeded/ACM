#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LB(x) ((x) & (-(x)))
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 2e5 + 5;
int cnt[N], n, s[N], last[N];
int a[N];

void add(int x) {
    while (x <= n) {
        cnt[x] += 1;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += cnt[x];
        x -= LB(x);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> num;
        REPP(i, 1, n) last[i] = cnt[i] = s[i] = 0;
        REPP(i, 1, n) {
            scanf("%d", a + i);
            num.push_back(a[i]);
        }
        sort(ALL(num));
        num.resize(unique(ALL(num)) - num.begin());
        REPP(i, 1, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
        REPP(i, 1, n) {
            s[a[i]]++;
        }
        REPP(i, 1, n) if (s[i] == 1) add(i);
        int bad = 0;
        REPP(i, 1, n) {
            if (last[a[i]]) {
                int pre = last[a[i]];
                int cnt = query(i) - query(pre);
                bad |= cnt == 0;
            }
            last[a[i]] = i;
            if (bad) break;
        }
        bad ? puts("boring") : puts("non-boring");
    }


    return 0;
}


