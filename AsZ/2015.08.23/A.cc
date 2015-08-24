#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
pair<int, int> p[N];
int a[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            p[i] = make_pair(x, y);
        }
        sort(p + 1, p + n + 1, cmp);
        REPP(i, 1, n) a[i] = p[i].second;
        vector<int> A, B;
        REPP(i, 1, n) {
            int pos = upper_bound(A.begin(), A.end(), a[i]) - A.begin();
            if (pos == A.size()) {
                A.push_back(a[i]);
                continue;
            }
            else {
                int tmp = A[pos];
                A[pos] = a[i];
                pos = upper_bound(B.begin(), B.end(), tmp) - B.begin();
                if (pos == B.size()) {
                    B.push_back(tmp);
                }
                else {
                    B[pos] = tmp;
                }
            }
        }
        printf("%d\n", A.size() + B.size());
    }

    return 0;
}

