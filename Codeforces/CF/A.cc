#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
int cnt[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    REPP(i, 1, m) {
        int ans = -1, id = 0;
        REPP(j, 1, n) {
            int x;
            cin >> x;
            if (x > ans) {
                ans = x;
                id = j;
            }
        }
        cnt[id]++;
    }
    int ans = -1, id = 0;
    REPP(i, 1, n) {
        if (cnt[i] > ans) {
            ans = cnt[i];
            id = i;
        }
    }
    cout << id << endl;

    return 0;
}
