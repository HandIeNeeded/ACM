#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

//max score may not advance
LL get1(int n, int m, int a, int b, int c) {
    if (b >= a) {
        return 1LL * b * (n - 1);
    }
    else if (b <= c) {
        if (a == c) {
            return 1LL * a * (n - 1);
        }
        else {
            //a != c
            int x = m + 1, y = n - x;
            LL ans = 1LL * a * y;
            if (x == 2) {
                return ans + c;
            }
            else {
                int k = x / 2;
                if (x & 1) {
                    return ans + 1LL * k * (a + c);
                }
                else {
                    k--;
                    return ans + 1LL * k * (a + c) + c;
                }
            }
        }
    }
    else {
        // a > b > c
        int x = m + 1, y = n - x;
        LL ans = 1LL * a * y;
        if (x == 2) {
            return ans + b;
        }
        else {
            int k = x / 2;
            //same
            if (x & 1) {
                return ans + 1LL * k * max(2 * b, a + c);
            }
            else {
                k--;
                return ans + 1LL * k * max(2 * b, a + c) + b;
            }
        }
    }
}

LL get2(int n, int m, int a, int b, int c) {
    if (b >= a) {
        int x = m - 1, y = n - x;
        LL ans = 1LL * c * x;
        if (y == 2) {
            return ans + a;
        }
        else {
            int k = y / 2;
            if (y & 1) {
                return ans + 1LL * k * (a + c);
            }
            else {
                k--;
                return ans + 1LL * k * (a + c) + a;
            }
        }
    }
    else if (b <= c) {
        return 1LL * b * (n - 1);
    }
    else {
        //a > b > c
        int x = m - 1, y = n - x;
        LL ans = 1LL * c * x;
        if (y == 2) {
            return ans + b;
        }
        else {
            int k = y / 2;
            if (y & 1) {
                return ans + 1LL * k * min(2 * b, a + c);
            }
            else {
                k--;
                return ans + 1LL * k * min(2 * b, a + c) + b;
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, a, b, c;
        scanf("%d%d", &n, &m);
        scanf("%d%d%d", &a, &b, &c);
        if (a < c) swap(a, c);
        printf("Case #%d: %lld %lld\n", ca++, get1(n, m, a, b, c), get2(n, m, a, b, c));
    }
    return 0;
}


