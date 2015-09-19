#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
vector<pair<int, int>> s[1005];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        s[x / 1000].push_back({y, i});
    }
    REP(i, 1001) {
        sort(s[i].begin(), s[i].end());
        if (i & 1) {
            reverse(s[i].begin(), s[i].end());
        }
        for (auto &x: s[i]) {
            cout << x.second << ' ';
        }
    }
    cout << endl;


    return 0;
}

