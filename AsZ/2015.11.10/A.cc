#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    LL n;
    cin >> n;
    n--;
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i * i != n) {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto &x: ans) {
        cout << x << ' ';
    }
    return 0;
}


