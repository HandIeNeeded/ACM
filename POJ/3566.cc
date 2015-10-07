#include <cstdio>
#include <algorithm>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 55;

char mp[N][N][N];
int n;

char id(int x) {
    if (x < 26 ) return 'a' + x;
    return 'A' + x - 26;
}

void paint(int x) {
    char c = id(x);
    REP(i, n) {
        REP(j, n) {
            mp[x][i][j] = c;
        }
    }
    REP(k, x) mp[k][0][x] = c;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    int h, w, l;
    h = w = l = n;
    REP(i, n) {
        paint(i);
    }
    printf("%d %d %d\n", h, l, min(2, n));
    REP(i, n) {
        if (i) puts("");
        REP(j, min(2, n)) {
            puts(mp[i][j]);
        }
    }
    return 0;
}


