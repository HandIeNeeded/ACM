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
            mx = max(atk + x, mx);
            round++;
            if (x >= h2) {
                win = 1;
                break;
            }
            int z = a[i];
            if (z >= h1) {
                if (s.size() == 0) {
                    //heal
                    if (y > z) {
                        h1 += y - z;
                    }
                    continue;
                    //defense = do nothing
                }
                int a = *s.begin(), b = *s.rbegin();
                if (b >= y) {
                    if (b + h1 > z) {
                        h1 += b - z;
                        s.erase(--s.end());
                        s.insert(z);
                    }
                    else {
                        //heal
                        if (y > z) {
                            h1 += y - z;
                        }
                        //defense = do nothing
                    }
                }
                else {
                    if (y + h1 > z) {
                        h1 += y - z;
                        s.erase(s.begin());
                        s.insert(z);
                    }
                    else {
                        //heal
                        if (y > z) {
                            h1 += y - z;
                        }
                        //defense = do nothing
                    }
                }
            }
            else {
                atk += x;
                h2 -= x;
                h1 -= z;
                s.insert(z);
            }
            if (h1 > 0 && h2 <= 0) {
                win = 1;
                break;
            }
        }
        if (win) {
            printf("Win\n%d\n", round);
        }
        else {
            printf("Lose\n%d\n", mx);
        }
    }

    return 0;
}
