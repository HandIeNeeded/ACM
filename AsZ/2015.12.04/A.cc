#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;
int a[N];

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    if (n < 3) {
        puts("0");
        return 0;
    }
    int x = *max_element(a + 1, a + n + 1);
    int tot = 0;
    REPP(i, 1, n) tot += a[i];
    cout << min(tot / 3, tot - x) << endl;
    return 0;
}


