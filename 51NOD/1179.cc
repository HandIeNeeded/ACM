#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 5;
int cnt[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        int x;
        scanf("%d", &x);
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                cnt[i]++;
                if (i * i != x) cnt[x / i]++;
            }
        }
    }
    int ans = 0;
    for (int i = N - 1; i >= 1; i--) if (cnt[i] >= 2) {
        ans = i;
        break;
    }
    cout << ans << endl;


    return 0;
}


