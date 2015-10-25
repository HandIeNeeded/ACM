#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 105;
int cnt[N];

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    REPP(i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int avg = n / k;
    int ans = 0;
    REPP(i, 1, k) {
        if (cnt[i] > avg) ans += cnt[i] - avg;
    }
    cout << ans << endl;

    return 0;
}


