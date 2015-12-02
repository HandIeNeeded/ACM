#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int dp[N][2][2][2];//0 1, last one flip or not, has flip or not

void toMax(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    REPP(pos, 1, n) {
        int x = s[pos - 1] - '0', y = x ^ 1;
        //cout << x << ' ' << y << endl;
        //flip
        dp[pos][y][1][1] = max(dp[pos - 1][x][1][1] + 1, dp[pos - 1][x][0][0] + 1);
        REP(i, 2) REP(j, 2) {
            toMax(dp[pos][y][1][1], dp[pos - 1][y][i][j]);
        }

        //not flip
        dp[pos][x][0][0] = max(dp[pos - 1][y][0][0] + 1, dp[pos - 1][x][0][0]);
        toMax(dp[pos][x][0][1], max(dp[pos - 1][y][1][1] + 1, dp[pos - 1][y][0][1] + 1));
        toMax(dp[pos][x][0][1], max(dp[pos - 1][x][0][1], dp[pos - 1][x][1][1]));
        REP(i, 2) REP(j, 2) {
            toMax(dp[pos][y][0][j], dp[pos - 1][y][i][j]);
        }
    }
    int ans = 0;
    REP(i, 2) REP(j, 2) REP(k, 2) toMax(ans, dp[n][i][j][k]);
    cout << ans << endl;
    return 0;
}

