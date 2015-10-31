#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5000;
int A[N];

int sqr(int x) {
    return x * x;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;
    REP(i, n) cin >> A[i];
    LL a = 0, b = 0, c = 0;
    REP(i, n) {
        REPP(j, i + 1, n - 1) {
            int x = A[i], y = A[j];
            int z = int(sqrt(sqr(x) + sqr(y)));
            if (sqr(x) + sqr(y) == sqr(z)) {
                b += upper_bound(A + j + 1, A + n, z) - lower_bound(A + j + 1, A + n, z);
                a += lower_bound(A + j + 1, A + n, z) - A - (j + 1);
                c += lower_bound(A + j + 1, A + n, x + y) - lower_bound(A + j + 1, A + n, z + 1);
                continue;
            }
            a += lower_bound(A + j + 1, A + n, z + 1) - A - (j + 1);
            c += lower_bound(A + j + 1, A + n, x + y) - lower_bound(A + j + 1, A + n, z + 1);
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}


