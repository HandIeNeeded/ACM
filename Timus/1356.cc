#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e5 + 5;
int p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

bool test(int x) {
    for (int i = 0; i < tot && p[i] * p[i] <= x; i++) {
        if (x % p[i] == 0) return 0;
    }
    return 1;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    prime();

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> ans;
        if (test(n)) {
            ans.push_back(n);
        }
        else if (n == 4) {
            REP(i, 2) ans.push_back(2);
        }
        else if (n & 1) {
            int tmp = n;
            while (tmp >= 2 && !test(tmp)) tmp--;
            ans.push_back(tmp);
            n -= tmp;
            if (test(n)) {
                ans.push_back(n);
            }
            else {
                REPP(i, 2, n - 2) if (test(i) && test(n - i)) {
                    ans.push_back(i);
                    ans.push_back(n - i);
                    break;
                }
            }
        }
        else {
            REPP(i, 2, n - 2) if (test(i) && test(n - i)) {
                ans.push_back(i);
                ans.push_back(n -i);
                break;
            }
        }
        REP(i, ans.size()) {
            printf("%d%c", ans[i], " \n"[i == int(ans.size() - 1)]);
        }
    }

    return 0;
}

