#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

LL calc(int x) {
    return 1LL * x * (x + 1) / 2;
}

int a[N];

bool test(int len, int left, int tot) {
    return 1LL * len * (left - len) + len + calc(left - len) >= tot;
}

int main() {
#ifdef HOME
    //freopen("H.in", "r", stdin);
#endif

    int tot;
    while (scanf("%d", &tot) > 0) {
        int n = int(sqrt(2 * tot + 0.5)) + 1;
        if (calc(n - 1) >= tot) n--;
        assert(calc(n) >= tot);
        REPP(i, 1, n) a[i] = i;
        int left = n;
        REPP(i, 1, n) {
            int tmp = a[i];
            int len = 1;
            while (len <= left && test(len, left, tot)) {
                a[i + len - 1] = tmp;
                len++;
            }
            int a = len - 1, b = left - a;
            tot -= a + a * b;
            //cout << "xixi" << tot << ' ' << a << ' ' << b << endl;
            i += a - 1;
            left -= a;
        }
        //cout << "hehe" << endl;
        printf("%d\n", n);
        REPP(i, 1, n) {
            printf("%d%c", a[i], " \n"[i == n]);
        }
    }


    return 0;
}


