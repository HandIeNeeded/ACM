#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 60

using namespace std;

char t[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 26; ++i) {
        t[i] = 'a' + i;
        t[i + 26] = 'A' + i;
    }
    printf("%d %d %d\n", 2, 2 * n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j)
            printf("%c", t[i]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (j & 1) printf("%c", t[i]);
            else printf("%c", t[j / 2]);
        }
        printf("\n");
    }
    return 0;
}
