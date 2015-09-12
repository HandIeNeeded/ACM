#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int MO = 1e9 + 7;
int C[N][N];
int dp[N][N][2], a[N], b[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void init() {
    REP(i, N) C[i][i] = C[i][0] = 1;
    REPP(i, 1, N - 1) {
        REPP(j, 1, i - 1) {
            C[i][j] = C[i - 1][j];
            add(C[i][j], C[i - 1][j - 1]);
        }
    }
}

char s[100005];
string str = "*.^!";

void trans(int l, int mid, int r) {
    int x = mid - l + 1, y = r - mid;
    if (b[mid] == 0) {
        add(dp[l][r][0], 1LL * dp[l][mid][1] % MO * dp[mid + 1][r][0] % MO);
        add(dp[l][r][0], 1LL * dp[l][mid][0] % MO * dp[mid + 1][r][1] % MO);
        add(dp[l][r][1], 1LL * dp[l][mid][1] % MO * dp[mid + 1][r][1] % MO);
    }
    else if (b[mid] == 1) {
        add(dp[l][r][1], 1LL * dp[l][mid][0] % MO * dp[mid + 1][r][0] % MO);
    }
    else if (b[mid] == 2) {
        add(dp[l][r][0], 1LL * dp[l][mid][0] % MO * dp[mid + 1][r][0] % MO);
    }
    else {
        add(dp[l][r][0], 1LL * dp[l][mid][1] % MO * dp[mid + 1][r][0] % MO);
        add(dp[l][r][0], 1LL * dp[l][mid][0] % MO * dp[mid + 1][r][1] % MO);
        add(dp[l][r][0], 1LL * dp[l][mid][1] % MO * dp[mid + 1][r][1] % MO);
        add(dp[l][r][1], 1LL * dp[l][mid][0] % MO * dp[mid + 1][r][0] % MO);
    }
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    init();

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int l = strlen(s);
        int n = 0;
        REP(i, l) {
            int type = isdigit(s[i]);
            a[++n] = type;
            while (i < l && str.find(s[i]) == string::npos) i++;
            if (s[i]) {
                b[n] = str.find(s[i]);
            }
        }
        n--;
        REPP(i, 1, n + 1) {
            REPP(j, 1, n + 1) {
                REP(k, 2) {
                    dp[i][j][k] = 0;
                }
            }
        }
        //cout << "hehe" << n << endl;
        //REPP(i, 1, n + 1) {
        //    cout << a[i] << ' ';
        //}
        //cout << endl;
        //REPP(i, 1, n) {
        //    cout << b[i] << ' ';
        //}
        //cout << endl;
        REPP(i, 1, n + 1) dp[i][i][a[i]] = 1;
        REPP(k, 1, n) {
            REPP(i, 1, n + 1) {
                int j = i + k;
                if (j > n + 1) break;
                REPP(mid, i, j - 1) {
                    trans(i, mid, j);
                }
            }
        }
        int ans = dp[1][n + 1][0];
        add(ans, dp[1][n + 1][1]);
        printf("%d\n", ans);
    }

    return 0;
}

