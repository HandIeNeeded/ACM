#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        LL k;
        scanf("%d%lld", &n, &k);
        LL mx = 1LL * n * (n + 1) / 2, mi = -mx + 2;
        if (k < mi || k > mx || (k - mx) & 1) {
            puts("NO");
            continue;
        }
        puts("YES");
    }

    return 0;
}


