#include <bits/stdc++.h>
#define MAXN 1123456

using namespace std;

typedef int arrayN[MAXN];
typedef long long arrayNll[MAXN];

arrayN visr, visc;
int cntr, cntc;
long long sumr, sumc;
long long baseSum;

void handleRow(int x, int n) {
    if (visr[x]) {
        cout << 0 << endl;
        return ;
    }

    long long tmp = 1LL * n * x + baseSum;
    tmp -= sumc;
    tmp -= 1LL * cntc * x;
    cout << tmp << endl;


    visr[x] = 1;
    cntr++;
    sumr += x;

}

void handleCol(int x, int n) {
    if (visc[x]) {
        cout << 0 << endl;
        return ;
    }


    long long tmp = 1LL * n * x + baseSum;
    tmp -= sumr;
    tmp -= 1LL * cntr * x;
    cout << tmp << endl;


    visc[x] = 1;
    cntc++;
    sumc += x;
}

int main() {
#ifndef HOME
    freopen("adjustment.out", "w", stdout);
#endif
    freopen("adjustment.in", "r", stdin);
    int n, q;
    scanf("%d%d\n", &n, &q);
    for (int i = 1; i <= n; ++i) {
        visr[i] = visc[i] = 0;
    }
    baseSum = 1LL * (1 + n) * n / 2;
    for (int i = 1; i <= q; ++i) {
        char ch;
        int x;
        scanf("%c %d\n", &ch, &x);
        if (ch == 'R') handleRow(x, n);
        else handleCol(x, n);
    }
    return 0;
}
