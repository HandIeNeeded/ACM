#include <bits/stdc++.h>
#define MAXN 1234

using namespace std;

int a[MAXN], b[MAXN];

int random(int x) {
    return abs(rand()) % x;
}

int ok = 0;

void qsort(int l, int r) {
    if (ok) return ;
    if (l >= r) return ;
    int mid = random(r - l + 1) + l;
    int pl = l, pr = r;
    string st;
    for (int i = l; i <= r; ++i)
        if (i != mid)
        {
            cout << 1;
            cout << ' ' << a[i] << ' ' << a[mid] << endl;
            cout.flush();
            if (!(cin >> st)) {
                ok = 1;
                return ;
            }
            if (st == "YES") b[pl++] = a[i];
            else b[pr--] = a[i];
        }
    b[pl] = a[mid];
    for (int i = l; i <= r; ++i)
        a[i] = b[i];
    qsort(l, pl - 1);
    qsort(pr + 1, r);
}

int main() {
   // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    qsort(1, n);
    cout << 0;
    for (int i = 1; i <= n; ++i)
        cout << ' ' << (ok ? 0 : a[i]);
    cout << endl;
    cout.flush();
    return 0;
}
