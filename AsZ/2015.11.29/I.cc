#include <bits/stdc++.h>
#include <ext/hash_map>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)


using namespace std;
using namespace __gnu_cxx;

const int N = 1e6 + 5;
int a[N];


int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif


    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    REP(i, n) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        if ((j - i) % k) {
            cout << a[i] << endl;
            return 0;
        }
        i = j - 1;
    }
    return 0;
}


