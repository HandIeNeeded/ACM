#include <bits/stdc++.h>
#define MAXN 1123456

using namespace std;

int a[MAXN], b[MAXN], suma[MAXN], sumb[MAXN], sumAll[MAXN];

int com(int u, int v) {
    return sumAll[u] < sumAll[v];
}

int main() {
    freopen("kabaleo.in", "r", stdin);

#ifndef HOME
    freopen("kabaleo.out", "w", stdout);
#endif
    int n, p, c, h;
    scanf("%d%d%d%d", &n, &p, &c, &h);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        suma[a[i]]++;
    }
    for (int i = 1; i <= p; ++i) {
        scanf("%d", &b[i]);
        if (i != 1) sumb[b[i]]++;
    }

    if (sumb[h]) = 1;
    if (suma[h]) sumb[h] = 0;
    for (int i = 1; i <= c; ++i)
        if (i != h && sumb[i])
            sumb[h] = 0;


    if (sumb[h] == 1) {
        if (n == 1) {
            printf("1\n1\n");
        } else printf("0\n");
        return 0;
    }


    for (int i = 1; i <= c; ++i) {
        lab[i] = i;
        sumAll[i] = suma[i] + sumb[i];
    }

    sort(lab + 1, lab + c + 1, com);

    vector <int> vec;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {

        sumAll[a[i]]--;

        //work;


        sumAll[a[i]]++;
    }
    int tot = vec.size();
    printf("%d\n", tot);
    for (int i = 0; i < tot; ++i)
        printf("%d%c\n", vec[i], " \n"[i == tot - 1]);
    //normal
    //
    return 0;
}
