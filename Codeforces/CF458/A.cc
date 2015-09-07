#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
string str[2];
int ans[2][N], a, b;

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    REP(i, 2) cin >> str[i];
    int mx = max(str[0].size(), str[1].size());
    for (auto it = str[0].rbegin(); it != str[0].rend(); it++) {
        ans[0][a++] = *it - '0';
    }
    for (auto it = str[1].rbegin(); it != str[1].rend(); it++) {
        ans[1][b++] = *it - '0';
    }
    if (str[0].size() != str[1].size()) {
        REP(j, mx - str[0].size()) ans[0][a++] = 0;
        REP(j, mx - str[1].size()) ans[1][b++] = 0;
    }
    assert(a == mx && b == mx);
    reverse(ans[0], ans[0] + mx);
    reverse(ans[1], ans[1] + mx);
    int r = 0;
    REP(i, mx) {
        int mi = min(ans[0][i], ans[1][i]);
        ans[0][i] -= mi, ans[1][i] -= mi;
        if (ans[0][i] == ans[1][i]) continue;
        if (ans[0][i] > ans[1][i] + 1) {
            r = 1;
            break;
        }
        if (ans[1][i] > ans[0][i] + 1) {
            r = -1;
            break;
        }
        if (ans[0][i] > ans[1][i]) ans[0][i + 1]++, ans[0][i + 2]++;
        if (ans[0][i] < ans[1][i]) ans[1][i + 1]++, ans[1][i + 2]++;
        if (i + 2 >= mx) mx++;
    }
    if (r) {
        r > 0 ? puts(">") : puts("<");
    }
    else {
        if (ans[0][mx] == ans[1][mx]) {
            puts("=");
        }
        else {
            ans[0][mx] > ans[1][mx] ? puts(">") : puts("<");
        }
    }

    return 0;
}

