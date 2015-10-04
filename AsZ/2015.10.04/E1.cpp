#include <bits/stdc++.h>
#define MAXN 11234

using namespace std;

double a[MAXN];

double esp = 1e-7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int lim = 1 << n;
    int ansCnt = 0;
    double ans = -1;
    for (int i = 0; i < lim; ++i) {
        double tmp = 1;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt++;
                tmp *= a[j + 1];
            }
        }
        if (cnt == 0) tmp = 0;
        if (tmp >= ans - esp) {
            if (tmp >= ans + esp) ansCnt = cnt;
            else if (cnt <= ansCnt) ansCnt = cnt;
            ans = tmp;
        }
    }
    printf("%d %.3lf\n", ansCnt, ans);
    return 0;
}
