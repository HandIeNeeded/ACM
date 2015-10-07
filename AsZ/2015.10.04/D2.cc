#include <bits/stdc++.h>

#define LL unsigned long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define hash myhash

using namespace std;

const int N = 5e5 + 5;
const LL Base = 1234567891;
char s[N];
int ans[N], L[N], R[N], tmp[N];
LL hash[N];
set<int> s;

bool cmp(int i, int j) {
    return R[i] < R[j];
}

int lcp(int i, int j) {
    int l = 0, r = n - max(i, j) + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        LL h1 = hash[i + mid - 1] - hash[i - 1] * pw[mid];
        LL h2 = hash[j + mid - 1] - hash[j - 1] * pw[mid];
        if (h1 == h2) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    scanf("%s", s);
    int n = strlen(s);
    pw[0] = 1;
    REPP(i, 1, n) pw[i] = pw[i - 1] * Base;
    REPP(i, 1, n) hash[i] = hash[i - 1] * Base + s[i];
    int q;
    scanf("%d", &q);
    REP(i, q) {
        scanf("%d%d", L + i, R + i);
        tmp[i] = i;
    }
    sort(tmp, tmp + q, cmp);
    REP(ii, q) {
        int i = tmp[ii];
        s.insert(i);
        //update the set



        //answer the query
        int jj = ii;
        while (jj < q && R[tmp[jj]] == R[i]) {
            ans[tmp[jj]] = s.lower_bound(L[tmp[jj]]);
            jj++;
        }
    }
    REP(i, q) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

