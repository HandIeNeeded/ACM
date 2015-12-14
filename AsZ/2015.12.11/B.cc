#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 10;
int cnt[N], mp[N][N], a[N];
int n, m, k;

int check() {
    REPP(i, 1, k) if (cnt[i]) return 1;
    return 0;
}

bool test() {
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            if (i > 1) if (mp[i][j] == mp[i - 1][j]) return 0;
            if (j > 1) if (mp[i][j] == mp[i][j - 1]) return 0;
        }
    }
    return 1;
}

pair<int, int> path[N * N];

void init() {
    int now = 0;
    for (int i = 2; i <= 25; i += 2) {
        int x = 5, y = i - x;
        REP(j, 5) {
            int nx = x - j, ny = y + j;
            if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5) path[now++] = {nx, ny};
        }
    }
    for (int i = 3; i <= 25; i += 2) {
        int x = 5, y = i - x;
        REP(j, 5) {
            int nx = x - j, ny = y + j;
            if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5) path[now++] = {nx, ny};
        }
    }
}

bool invalid(pair<int, int> a) {
    return a.first > n || a.second > m;
}

void getNext(int &x, int &y) {
    int pos = find(path, path + 25, make_pair(x, y)) - path;
    pos++;
    if (pos == 25) pos = 0;
    while (pos == 25 || invalid(path[pos])) {
        pos++;
        if (pos == 25) pos = 0;
    }
    tie(x, y) = path[pos];
}

int g[N];

void paint(int nx, int ny) {
    int has = 1;
    memcpy(cnt, a, sizeof(a));
    while (has) {
        int x = max_element(cnt + 1, cnt + k + 1) - cnt;
        while (cnt[x]) {
            mp[nx][ny] = x, cnt[x]--;
            //cout << nx << ' ' << ny << ' ' << x << endl;
            getNext(nx, ny);
        }
        has = check();
    }
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif

    init();
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        REPP(i, 1, k) scanf("%d", a + i);
        printf("Case #%d:\n", ca++);
        int mx = *max_element(a + 1, a + k + 1);
        if (mx > (n * m + 1) / 2) {
            puts("NO");
            continue;
        }
        else {
            int find = 0;
            REPP(i, 1, n) {
                REPP(j, 1, m) {
                    int nx = i, ny = j;
                    paint(nx, ny);
                    if (test()) {
                        find = 1;
                        break;
                    }
                }
                if (find) break;
            }
            assert(test());
            puts("YES");
            REPP(i, 1, n) {
                REPP(j, 1, m) {
                    printf("%d%c", mp[i][j], " \n"[j == m]);
                }
            }
        }
    }

    return 0;
}

