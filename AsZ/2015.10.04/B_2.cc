#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 206;
int start[N], time[N], a[N], b[N], tot;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int n, A, B;
    scanf("%d%d%d", &n, &A, &B);
    REPP(i, 1, n) scanf("%d", a + i);
    REPP(i, 1, n) scanf("%d", b + i);
    int cnt = 0;
    vector<int> now;
    REPP(i, 1, n) {
        if (a[i] || b[i]) {
            int need = a[i] + b[i];
            while (cnt < need) {
                time[tot] = A;
                now.push_back(tot);
                start[tot++] = i;
                cnt++;
            }
            if (a[i]) {

            }

        }
    }
    cout << tot << endl;
    return 0;
}

