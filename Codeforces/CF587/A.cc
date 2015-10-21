#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e6 + 5;
int cnt[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    int x;
    REPP(i, 1, n) scanf("%d", &x), cnt[x]++;
    int ans = 0;
    REPP(i, 0, 1100000) {
        ans += cnt[i] & 1;
        cnt[i + 1] += cnt[i] >> 1;
    }
    cout << ans << endl;


    return 0;
}


