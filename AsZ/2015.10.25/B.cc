#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 8005;

int dp[N][N];
vector<int> num;
pair<int, int> p[N];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
        num.push_back(x);
        num.push_back(y);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    int tot = num.size();
    REPP(i, 1, n) {
        int x, y;
        tie(x, y) = p[i];
        x = lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
        y = lower_bound(num.begin(), num.end(), y) - num.begin() + 1;
        dp[x][y]++;
    }
    //REPP(i, 1, tot) {
    //    REPP(j, 1, tot) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    for (int i = tot; i >= 1; i--) {
        for (int j = tot; j >= 1; j--) {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1] + dp[i][j] - dp[i + 1][j + 1];
        }
    }
    //REPP(i, 1, tot) {
    //    REPP(j, 1, tot) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    LL ans = -1;
    int x, y;
    REP(i, num.size()) {
        REPP(j, i, num.size() - 1) {
            int a = i + 1, b = j + 1;
            int c = max(a, b);
            int cnt = dp[a][b] + dp[b][a] - dp[c][c];
            if (1LL * num[i] * num[j] * cnt > ans) {
                ans = 1LL * num[i] * num[j] * cnt;
                x = num[i], y = num[j];
            }
        }
    }
    cout << ans << endl;
    cout << x << ' ' << y << endl;

    return 0;
}


