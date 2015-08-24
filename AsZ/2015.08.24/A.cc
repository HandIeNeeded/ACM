#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

bool test(int x) {
    bool vis[10] = {0};
    while (x) {
        if (vis[x % 10]) return 0;
        vis[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int cnt[100005];

void init() {
    REPP(i, 1, 100000) {
        cnt[i] = cnt[i - 1] + test(i);
    }
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", cnt[b] - cnt[a - 1]);
    }


    return 0;
}

