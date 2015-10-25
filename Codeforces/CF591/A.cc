#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int l, a, b;
    cin >> l >> a >> b;
    cout << fixed << setprecision(10) << 1. * l * a / (a + b) << endl;


    return 0;
}


