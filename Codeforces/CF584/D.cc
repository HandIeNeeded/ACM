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
    ios::sync_with_stdio(0);
    prime();

    int n;
    cin >> n;
    if (test(n)) {
        cout << 1 << endl << n << endl;
    }
    else {
        int tmp = n - 1;
        while (tmp >= 2 && !test(tmp)) tmp--;
        vector<int> ans;
        ans.push_back(tmp);
        n -= tmp;
        int pos = lower_bound(p, p + tot, n) - p;
        if (p[pos] == n) {
            ans.push_back(n);
        }
        else {
            int find = 0;
            REP(i, pos) {
                REPP(j, i, pos - 1) {
                    if (p[i] + p[j] == n) {
                        ans.push_back(p[i]);
                        ans.push_back(p[j]);
                        find = 1;
                        break;
                    }
                }
                if (find) break;
            }
        }
        cout << ans.size() << endl;
        REP(i, ans.size()) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }


    return 0;
}


