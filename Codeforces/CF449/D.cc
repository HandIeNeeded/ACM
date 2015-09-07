#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = (1 << 20) + 5;
const int MO = 1e9 + 7;
int a[N], cnt[N], pw[N] = {1};

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) pw[i] = pw[i - 1], add(pw[i], pw[i]);
    REPP(i, 1, n) scanf("%d", a + i), cnt[a[i]]++;
    REP(i, 20) {
        REP(j, 1 << 20) {
            if ((j & (1 << i)) == 0) {
                cnt[j] += cnt[j + (1 << i)];
            }
        }
    }
    int ans = 0;
    REP(i, 1 << 20) {
        if (__builtin_parity(i)) {
            add(ans, MO - pw[cnt[i]]);
        }
        else {
            add(ans, pw[cnt[i]]);
        }
    }
    cout << ans << endl;

    return 0;
}

