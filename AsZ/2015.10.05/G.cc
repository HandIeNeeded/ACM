#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define double long double

using namespace std;

const int N = 55;

double p[N], q[N], dp[N], A[N], B[N];//p right q left
int n, k;

double solve(int a, int b) {
    //step 1: get a first then b
    
    dp[a] = 1.0, dp[b] = 0.0;
    A[1] = 0.0, B[1] = dp[1];
    A[2] = 1.0, B[2] = 0.0;//dp[i] = A[i] * dp[2] + B[i];
    REPP(i, 2, n - 2) {
        A[i + 1] = (A[i] - A[i - 1] * q[i]) / p[i];
        B[i + 1] = (B[i] - B[i - 1] * q[i]) / p[i];
    }
    //dp[n - 1] = A[n - 1] * dp[2] + B[n - 1];
    //since in fact we know the possibility exists, so no worry about A[n - 1] = 0;
    dp[2] = (dp[n - 1] - B[n - 1]) / A[n - 1];
    REPP(i, 3, n - 2) {
        dp[i] = A[i] * dp[2] + B[i];
    }
    double key = dp[k];
    cout << "key : " << key << endl;

    //step 2: get b first then n
    if (a == 1) {
        dp[b] = 1.0;
        dp[n] = 0.0;
        A[0] = 0.0, B[0] = dp[n]; //treat 0 as n
        A[1] = 1.0, B[1] = 0.0; //dp[i] = A[i] * dp[1] + B[i];
        REPP(i, 1, n - 2) {
            A[i + 1] = (A[i] - A[i - 1] * q[i]) / p[i];
            B[i + 1] = (B[i] - B[i - 1] * q[i]) / p[i];
        }
        dp[1] = (dp[n - 1] - B[n - 1]) / A[n - 1];
    }
    else {
        dp[b] = 1.0;
        dp[n] = 0.0;
        A[n] = 0.0, B[n] = dp[n];
        A[n - 1] = 1.0, B[n - 1] = 0.0;
        for (int i = n - 1; i >= 2; i--) {
            A[i - 1] = (A[i] - A[i + 1] * p[i]) / q[i];
            B[i - 1] = (B[i] - B[i + 1] * p[i]) / q[i];
        }
        dp[n - 1] = (dp[1] - B[1]) / A[1];
    }
    return key * dp[a];
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    //REPP(i, 1, n - 1) scanf("%Lf", p + i), q[i] = 1.0 - p[i];
    REPP(i, 1, n - 1) cin >> p[i], q[i] = 1.0 - p[i];
    //REPP(i, 1, n - 1) {
    //    cout << i << ' ' << p[i] << ' ' << q[i] << endl;
    //}
    double ans = 0;
    ans += solve(1, n - 1);
    cout << ans << endl;
    ans += solve(n - 1, 1);
    cout << ans << endl;
    //printf("%.10Lf\n", ans);
    return 0;
}

