#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 105;
int b[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    ios :: sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        REPP(i, 1, n) cin >> b[i];
        int a = 0, b = 0;//0 1
        REPP(i, 1, n) {
            if (::b[i]) {
                tie(a, b) = make_pair(a, min(a, b));
            }
            else {
                tie(a, b) = make_pair(b, min(a, b) + 1);
            }
        }
        cout << min(a, b) << endl;
    }

    return 0;
}


