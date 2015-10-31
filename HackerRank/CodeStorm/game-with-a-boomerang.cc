#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

map<LL, LL> mp;

void solve(LL n) {
    if (n <= 2) return 1;
    if (mp.count(n)) return mp[n];
    if (n & 1) {
        mp[n] = solve(n - 1) + 1;
    }
    else {
        LL tmp = solve(n / 2);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
    }

    return 0;
}


