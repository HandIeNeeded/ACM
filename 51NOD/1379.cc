#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 50;
const int MO = 1e9 + 7;
int fib[N];

int pow_mod(int a, LL b, int mod = MO) {
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

const double key = (1.0 + sqrt(5)) / 2.0;

LL get(LL n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    double k = (n * log(key) - 0.5 * log(5)) / log(2);
    return (LL) k;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    fib[0] = 0, fib[1] = 1;
    REPP(i, 2, 40) fib[i] = fib[i - 1] + fib[i - 2];
    REPP(i, 1, 40) fib[i] |= fib[i - 1];
    //REPP(i, 1, 40) {
    //    cout << i << ' ' << fib[i] << endl;
    //}
    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
        if (n <= 30) {
            printf("%d\n", fib[n]);
            continue;
        }
        LL x = get(n);
        printf("%d\n", pow_mod(2, x + 1) - 1);
    }

    return 0;
}


