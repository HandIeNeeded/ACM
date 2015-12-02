#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int a[N];

int solve(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 0;
    if (x == 3) return 1;
    if (x == 4) return 2;
    if (x & 1) return 0;
    int z = solve(x / 2);
    if (z == 0) return 1;
    if (z == 1) return 2;
    if (z == 2) return 1;
    assert(0);
    return -1;
}

int get(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x & 1) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    k &= 1;
    REPP(i, 1, n) cin >> a[i];
    if (k) {
        int ans = 0;
        REPP(i, 1, n) ans ^= solve(a[i]);
        ans ? puts("Kevin") : puts("Nicky");
    }
    else {
        int ans = 0;
        REPP(i, 1, n) ans ^= get(a[i]);
        ans ? puts("Kevin") : puts("Nicky");
    }
    return 0;
}

