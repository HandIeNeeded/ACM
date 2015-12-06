#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
    freopen("fragmentation.in", "r", stdin);
#ifndef HOME
    freopen("fragmentation.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        scanf("%d", a + i);
    }
    int ans = 0;
    vector<int> num;
    a[n + 1] = 0;
    REPP(i, 1, n) {
        int j = i;
        while (a[j + 1] >= a[j]) j++;
        ans++;
        num.push_back(j + 1 - i);
        i = j;
    }
    printf("%d\n", ans);
    REP(i, num.size()) {
        printf("%d%c", num[i], " \n"[i == int(num.size()) - 1]);
    }


    return 0;
}


