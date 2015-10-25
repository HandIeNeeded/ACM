#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == 0 || b == 0) {
            puts("First");
            continue;
        }
        else {
            if ((a + b - 2) & 1) {
                puts("First");
            }
            else {
                puts("Second");
            }
        }
    }


    return 0;
}

