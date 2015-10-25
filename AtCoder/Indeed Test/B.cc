#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int cnt[N];

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    REPP(i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = -1;
    REPP(i, 0, m) if (cnt[i] * 2 > n) {
        ans = i;
    }
    if (ans >= 0) {
        cout << ans << endl;
    }
    else {
        cout << "?" << endl;
    }

    return 0;
}


