#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int inf = 2e9;

int a[3], b[3];
LL area = 0;

LL get(int i, int j) {
    int w = abs(a[i] - a[j]), h = abs(b[i] - b[j]);
    return __gcd(w, h);
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        REP(i, 3) {
            cin >> a[i] >> b[i];
        }
        area = 0;
        REP(i, 3) {
            int j = (i + 1) % 3;
            area += 1LL * a[i] * b[j] - 1LL * a[j] * b[i];
        }
        area = abs(area);
        area += 2;
        LL cnt = 0;
        cnt = get(0, 1) + get(1, 2) + get(2, 0);
        //cout << area << ' ' << cnt << endl;
        assert(((area - cnt) & 1) == 0);
        cout << (area - cnt) / 2 << endl;
    }

    return 0;
}


