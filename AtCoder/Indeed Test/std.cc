#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 5;
const int M = 1e5 + 5;

int vis[N];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) {
        int x, y;
        cin >> x >> y;
        while (y) {
            if (vis[x]) {
                x++;
            }
            else {
                vis[x] = 1;
                y--;
                x++;
            }
        }
        cout << x - 1 << endl;
    }

    return 0;
}

