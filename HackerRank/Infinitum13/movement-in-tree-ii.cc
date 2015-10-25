#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int MO = 1e9 + 7;

int d, h, k;

int pow_mod(int a, int b, int mod = MO) {
    a %= mod; 
    if (a < 0) a += mod;
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

int calc(int x, int n) {
    int sqr = 1LL * d * d % MO;
    int ans = pow_mod(sqr, n) - 1;
    ans = 1LL * ans * pow_mod(sqr - 1, MO - 2) % MO;
    ans = 1LL * ans * x % MO;
    return ans;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &d, &k, &h);
        int sqr = 1LL * d * d % MO;
        int ans = 0;
        if (k & 1) {
            ans = calc(d, (k + 1) / 2);
            ans = 1LL * ans * pow_mod(d, MO - 2) % MO;
            ans = 1LL * ans * (d + 1) % MO;
            if (k > h) {
                if ((k - h) & 1) {
                    add(ans, MO - calc(1, (k - h + 1) / 2));
                }
                else {
                    add(ans, MO - calc(d, (k - h + 1) / 2));
                }
            }
        }
        else {
            //add 1 at last
            ans = calc(sqr, (k + 1) / 2);
            ans = 1LL * ans * pow_mod(d, MO - 2) % MO;
            ans = 1LL * ans * (d + 1) % MO;
            if (k > h) {
                if ((k - h) & 1) {
                    add(ans, MO - calc(1, (k - h + 1) / 2));
                }
                else {
                    add(ans, MO - calc(d, (k - h + 1) / 2));
                }
            }
            add(ans, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

