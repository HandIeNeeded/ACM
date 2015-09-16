#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
int mp[N][N];

void paint(int x, int y, int num, int type) {
    REP(i, 2) {
        REP(j, 2) {
            if ((i << 1 | j) == type) continue;
            mp[x + i][y + j] = num;
        }
    }
}



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    return 0;
}

