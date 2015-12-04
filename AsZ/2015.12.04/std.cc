#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
#ifdef HOME
    //freopen("A.in", "r", stdin);
#endif
    int n;
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    while (1) {
        sort(a + 1, a + n + 1);
        if (a[n - 2] == 0) break;
        ans++;
        a[n - 1]--, a[n]--, a[n - 2]--;
    }
    cout << ans << endl;

    return 0;
}


