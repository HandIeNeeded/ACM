#include <iostream>
#include <set>
#include <cstdio>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int x, y, n, h1, h2;
int a[N];

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    cin >> n >> x >> y >> h1 >> h2;
    //cout << n << ' ' << x << ' ' << y << ' ' << h1 << ' ' << h2 << endl;
    REPP(i, 1, n) {
        cin >> a[i];
    }
    set<int> s;
    int win = 0, round = 0, damage = 0;
    int ans = 0;
    REPP(i, 1, n) {
        round++;
        damage += x;
        ans = max(ans, damage);
        h2 -= x;
        if (h2 <= 0) {
            win = 1;
            break;
        }
        h1 -= a[i];
        if (h1 <= 0) {
            while (h1 <= 0) {
                set<int> :: iterator it = s.end();
                if (it == s.begin()) break;
                it--;
                int tmp = *it;
                if (tmp >= y) {
                    damage -= x;
                    h2 += x;
                    h1 += tmp;
                    s.erase(it);
                }
                else {
                    it = s.begin();
                    damage -= x;
                    h2 += x;
                    h1 += y;
                    s.erase(it);
                }
            }
            if (h1 > 0) {
                s.insert(a[i]);
                h1 += a[i];
                i--;
            }
            else break;
        }
    }
    if (win) {
        cout << "Win" << endl << round << endl;
    }
    else {
        cout << "Lose" << endl << ans << endl;
    }
    return 0;
}

