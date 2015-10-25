#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    REPP(i, 1, n) cin >> a[i];
    REPP(i, 1, m) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int now = n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = m; i >= 1; i--) {
        while (now >= 1 && a[now] >= b[i]) {
            q.push(a[now]);
            now--;
        }
        if (!q.size()) {
            cout << "NO" << endl;
            return 0;
        }
        q.pop();
    }
    cout << "YES" << endl;


    return 0;
}


