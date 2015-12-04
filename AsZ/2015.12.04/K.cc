#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int K = 2e5;
const int L = (1 << 16) - 1;
const int MO = (1u << 31) - 1;
int a[K], b[K], c[K];

int merge(int n, int m) {
    memcpy(c, a, sizeof(a));
    int x = 0, y = 0, z = 0;
    while (z < K && (x < n || y < m)) {
        if (x == n) {
            a[z] = c[y];
            z++, y++;
        }
        else if (y == m) {
            a[z] = b[x];
            z++, x++;
        }
        else {
            if (b[x] > c[y]) {
                a[z] = b[x];
                z++, x++;
            }
            else {
                a[z] = c[y];
                z++, y++;
            }
        }
    }
    return z;
}

int cnt[L + 5], tmp[K];

void radixSort(int n) {
    //every number being divided into two parts, first 16 digits, last 16 digits
    //radix sort, radix == 2

    memset(cnt, 0, sizeof(cnt));
    REP(i, n) cnt[b[i] & L]++;
    for (int i = L; i >= 0; i--) cnt[i] += cnt[i + 1];
    REP(i, n) {
        int x = b[i] & L;
        tmp[cnt[x + 1]] = b[i];
        cnt[x + 1]++;
    }

    memset(cnt, 0, sizeof(cnt));
    REP(i, n) cnt[tmp[i] >> 16]++;
    for (int i = L; i >= 0; i--) cnt[i] += cnt[i + 1];
    REP(i, n) {
        int x = tmp[i] >> 16;
        b[cnt[x + 1]] = tmp[i];
        cnt[x + 1]++;
    }
}

int A, B, C;

static inline int calc(int M, int N) {
    return (M * A + N * B + C) & MO;
}

inline bool cmp(const int &a, const int &b) {
    return a > b;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    cerr << MO << endl;

    int n, k, M, N;
    cin >> n >> k;
    cin >> M >> N >> A >> B >> C;
    int turn = (n + K - 1) / K;
    REP(i, k) a[i] = -1;
    REP(i, turn) {
        int m = K;
        if (i == turn - 1) m = n - i * K;
        REP(j, m) {
            if (j == 0) b[0] = calc(M, N);
            else if (j == 1) b[1] = calc(N, b[0]);
            else b[j] = calc(b[j - 2], b[j - 1]);
        }
        M = b[m - 2], N = b[m - 1];
        //sort(b, b + m); in the reverse order
        //sort(b, b + m, cmp);
        //sort(b, b + m);
        //reverse(b, b + m);
        radixSort(m);
        merge(k, k);
    }
    REP(i, k) {
        printf("%d%c", a[i], " \n"[i == k - 1]);
    }
    return 0;
}


