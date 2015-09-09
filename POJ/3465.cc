#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int n, x, y, h1, h2;
    while (scanf("%d%d%d%d%d", &n, &x, &y, &h1, &h2) > 0) {
        int mx = 0, atk = 0, win = 0, round = 0;
        multiset<int> s;
        REPP(i, 1, n) scanf("%d", a + i);
        REPP(i, 1, n) {
            round++;
            //beat to death
            if (x >= h2) {
                win = 1;
                break;
            }
            //can't
            int z = a[i];
            mx = max(atk + x, mx);
            atk += x, h1 -= z, h2 -= x;
            s.insert(z);
            if (h1 <= 0) {
                while (h1 <= 0 && s.size()) {
                    h2 += x;
                    int b = *s.rbegin();
                    if (b >= y) {
                        h1 += b;
                        atk -= x;
                        s.erase(--s.end());
                    }
                    else {
                        h1 += y;
                        atk -= x;
                        s.erase(s.begin());
                    }
                }
            }
        }
        if (win) {
            printf("Win\n%d\n", round);
        }
        else {
            printf("Lose\n%d\n", mx);
        }
        return 0;
    }

    return 0;
}

