#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5;
int x[N], y[N];

bool good(int p) {
    int sum = 0;
    REP(i, 4) if (i != p) sum += x[i] * y[i];
    int q = -1;
    REP(i, 4) if (i != p) {
        REP(k, 2) {
            swap(x[i], y[i]);
            if (sum % x[i] == 0) {
                q = i;
                int w = x[i], h = sum / w - y[i];
                vector<int> id;
                REP(j, 4) if (j != p && j != q) {
                    id.push_back(j);
                }
                int a = id[0], b = id[1];
                if (x[a] * y[a] + x[b] * y[b] != sum - x[i] * y[i]) continue;
                if ((x[a] == w || y[a] == w) && (x[b] == w || y[b] == w)) return 1;
                if (x[a] + x[b] == w && y[a] == h && y[b] == h) return 1;
                if (x[a] + y[b] == w && y[a] == h && x[b] == h) return 1;
                if (y[a] + x[b] == w && x[a] == h && y[b] == h) return 1;
                if (y[a] + y[b] == w && x[a] == h && x[b] == h) return 1;
            }
        }
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        REP(i, 4) {
            scanf("%d%d", x + i, y + i);
        }
        int find = 0;
        REP(i, 4) {
            if (good(i)) {
                find = 1;
                break;
            }
        }
        find ? puts("Yes") : puts("No");
    }

    return 0;
}


