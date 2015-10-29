#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        unsigned int d, a, b, ans = 0;
        scanf("%u%u%u", &d, &a, &b);
        REP(i, 32) {
            if ((d & (1u << i)) == 0) {
                unsigned int tmp = d | (1u << i);
                tmp >>= i;
                tmp <<= i;
                int cnt = __builtin_popcount(tmp);
                if (cnt > b) continue;
                if (cnt >= a && cnt <= b) {
                    ans = tmp;
                    break;
                }
                if (cnt < a && i >= (a - cnt)) {
                    ans = tmp | ((1 << (a - cnt)) - 1);
                    break;
                }
            }
        }
        printf("Case #%d: %u\n", ca++, ans);
    }
    return 0;
}

