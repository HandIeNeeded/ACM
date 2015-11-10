#include <bits/stdc++.h>

using namespace std;
const int INF = (int)1e9;

int ask(int x0, int y0, int x1, int y1) {
    cout << x0 << ' ' << y0 << endl;
    cout.flush();
    int t0, t1;
    cin >> t0;
    cout << x1 << ' ' << y1 << endl;
    cin >> t1;
    if (t1 == 1) return 1;
    else return -1;
}

int findX(int y) {
    int l = 0, r = INF;
    if (ask(l, y, l + 1, y) == -1) return 0;
    if (ask(r - 1, y, r, y) == 1) return r;
    for (; l < r; ) {
        int mid = (l + r + 1) >> 1;
        if (ask(mid, y, mid + 1, y) == 1) l = mid;
        else r = mid - 1;
    }
    return l + 1;
}

int findY(int x) {
    int l = 0, r = INF;
    if (ask(x, l, x, l + 1) == -1) return 0;
    if (ask(x, r - 1, x, r) == 1) return r;
    for (; l < r;) {
        int mid = (l + r + 1) >> 1;
        if (ask(x, mid, x, mid + 1) == 1) l = mid;
        else r = mid - 1;
    }
    return l + 1;
}

int main() {
    int x = findX(0);
    int y = findY(x);
    cout << 'A' << ' ' << x << ' ' << y << endl;
    cout.flush();
    return 0;
}
