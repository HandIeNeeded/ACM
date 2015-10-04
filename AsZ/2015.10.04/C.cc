#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
int a[N];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    int sum = 0;
    REPP(i, 1, n) scanf("%d", a + i);
    REPP(i, 1, n) sum += a[i];
    int ans = 0;
    REPP(i, 1, n) {
        if (n * a[i] > sum) {
            ans++;
        }
    }
    printf("%d\n", ans);



    return 0;
}


