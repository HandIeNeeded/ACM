#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5e5 + 5;

int a[N], dp[N], head[N];
bool good[N];

int get(int l, int r) {
    int cnt = 0;
    if (a[l] == a[r]) {
        REPP(i, l, r) cnt += a[i] != a[l];
        REPP(i, l, r) a[i] = a[l];
    }
    else {
        int last = l;
        REPP(i, l, r) if (a[i] == a[l]) last = i, cnt++;
        cnt = last - (l + cnt - 1);
        for (int i = 0, j = l; i < cnt; i++, j++) {
            a[j] = a[l];
        }
        REPP(i, l + cnt, r) {
            a[i] = a[r];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    //freopen("in", "r", stdin);

    int n;
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    a[0] = a[1], a[n + 1] = a[n];
    int ans = 0;
    if (n == 3) {
        if (a[1] == a[3]) {
            ans = a[2] != a[1];
            a[2] = a[1];
        }
        cout << ans << endl;
        REPP(i, 1, n) cout << a[i] << ' ';
        cout << endl;
        return 0;
    }
    int l = 1, r = l + 1;
    REPP(i, 1, n) {
        r = l + 1;
        while (r <= n && a[r] != a[r + 1]) r++;
        ans = max(ans, get(i, r));
        i = r;
        l = i + 1;
        //cout << i << "hehe" << endl;
    }
    cout << ans << endl;
    REPP(i, 1, n) {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}


