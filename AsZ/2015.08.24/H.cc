#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

LL calc(int x) {
    return 1LL * x * (x + 1) / 2;
}

int a[N];

bool test(int len, int left, int tot) {
    return 1LL * len * (left - len) + len + calc(left - len) >= tot;
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    int tot;
    while (scanf("%d", &tot) > 0) {
        if (tot <= int(1e5)) {
            printf("%d\n", tot);
            REPP(i, 1, tot) {
                printf("%d%c", 1, " \n"[i == tot]);
            }
            continue;
        }
        int n = int(sqrt(2 * tot + 0.5)) + 1;
        if (calc(n - 1) >= tot) n--;
        assert(calc(n) >= tot);
        int length = n, ans = -1;
        for (int n = length; n <= length + 1; n++) {
            REPP(i, 1, n) a[i] = i;
            int left = n;
            REPP(i, 1, n) {
                int tmp = a[i];
                int len = 1;
                while (len <= left && test(len, left, tot)) {
                    a[i + len - 1] = tmp;
                    len++;
                }
                int a = len - 1, b = left - a;
                tot -= a + a * b;
                i += a - 1;
                left -= a;
            }
            if (tot == 0) {
                ans = n;
                break;
            }
        }
        printf("%d\n", ans);
        REPP(i, 1, ans) {
            printf("%d%c", a[i], " \n"[i == ans]);
        }
    }

    return 0;
}

