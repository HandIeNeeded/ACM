#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int mid = (n + 1) / 2, ans = 0;
    if (n & 1) {
        ans = min(a[mid] - a[1], a[n] - a[mid]);
    }
    else {
        ans = min(a[mid + 1] - a[1], a[n] - a[mid]);
    }
    cout << ans << endl;


    return 0;
}


