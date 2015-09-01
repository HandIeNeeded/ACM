#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
int num[N];
int vis[N];

int get(int a, int b, char c) {
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    return -1;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int n;

    while (scanf("%d", &n) > 0) {
        int now = n;
        REPP(i, 1, n) num[i] = n;
        REPP(i, 1, 2 * n) vis[i] = 0;
        REPP(i, 1, n - 1) {
            int a, b;
            char c;
            scanf("%d %c %d", &a, &c, &b);
            vis[a]++, vis[b]++;
            num[++now] = get(num[a], num[b], c);
        }
        int bad = 0;
        if (num[2 * n - 1] != 24) {
            bad = 1;    
        }
        REPP(i, 1, 2 * n - 1) {
            if (abs(num[i]) > int(1e9)) {
                bad = 1;
                break;
            }
        }
        REPP(i, 1, 2 * n - 2) {
            if (vis[i] != 1) {
                bad = 1;
                break;
            }
        }
        assert(bad == 0);
        cout << "AC" << endl;
    }

    return 0;
}

