#include <bits/stdc++.h>
#define MAXN 1234

using namespace std;

int a[MAXN], b[MAXN];

bool cmp(int i, int j) {
    cout << 1 << ' ' << i << ' ' << j << endl;
    cout.flush();
    string tmp;
    cin >> tmp;
    return tmp[0] == 'Y';
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    //qsort(1, n);
    stable_sort(a + 1, a + n + 1, cmp);
    cout << 0;
    for (int i = 1; i <= n; ++i)
        cout << ' ' << a[i];
    cout << endl;
    cout.flush();
    return 0;
}
