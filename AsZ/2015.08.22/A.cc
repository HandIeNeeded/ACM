#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long 

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;
int L[N], R[N];
int a[N];
vector<int> pos[N];
void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

LL calc(int x, int L, int R) {
    return 1LL * (R - x) * (x - L) % MO;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int n;
    while (scanf("%d", &n) > 0) {
        REPP(i, 1, n) L[i] = 0, R[i] = n + 1;
        REPP(i, 1, 10000) pos[i].clear();
        REPP(i, 1, n) {
            scanf("%d", a + i);
            pos[a[i]].push_back(i);
        }
        REPP(i, 1, n) {
            for (int j = a[i]; j <= 10000; j += a[i]) {
                REP(k, pos[j].size()) {
                    int x = pos[j][k];
                    if (x > i) {
                        L[x] = max(L[x], i);
                    }
                    else if (x < i) {
                        R[x] = min(R[x], i);
                    }
                }
            }
        }
        //REPP(i, 1, n) {
        //    cout << i << ' ' << L[i] << ' ' << R[i] << endl;
        //}
        int ans = 0;
        REPP(i, 1, n) {
            add(ans, calc(i, L[i], R[i]));
        }
        printf("%d\n", ans);
    }


    return 0;
}

