#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;
int a[N];

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    if (n < 3) {
        puts("0");
        return 0;
    }
    int x = a[n], y = a[n - 1], z = 0;
    REPP(i, 1, n - 2) z += a[i];
    if (y > z) {
        cout << z << endl;
    }
    else {
        int k = (y + z) / 2;
        if (x > k) {
            cout << k << endl;
        }
        else {
            cout << (x + y + z) / 3 << endl;
        }
    }
    return 0;
}


