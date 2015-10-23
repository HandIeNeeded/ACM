#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int A, B;
    cin >> A >> B;
    cout << 1LL * A * B / __gcd(A, B) << endl;


    return 0;
}


