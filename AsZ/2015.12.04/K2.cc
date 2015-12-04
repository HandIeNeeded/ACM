#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int MO = (1u << 31) - 1;
const int K = 2e5 + 5;

int a[K << 1];

inline bool cmp(const int &a, const int &b) {
    return a > b;
}

int main() {
#ifdef HOME
    freopen("K2.in", "r", stdin);
#endif

    int n, k, M, N, A, B, C;
    cin >> n >> k >> M >> N >> A >> B >> C;
    int now = 0;
    REP(i, n) {
        int x;
        x = (M * A + N * B + C) & MO;
        M = N, N = x;
        a[now++] = -x;
        if (now == 2 * K) {
            nth_element(a, a + K, a + now);
            now = K;
        }
    }
    sort(a, a + now);
    REP(i, k) {
        printf("%d ", -a[i]);
    }
    return 0;
}


