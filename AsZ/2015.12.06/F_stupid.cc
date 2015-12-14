#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 30;
int pw[N];

bool good(int x, int binary) {
    int dep = 32 - __builtin_clz(binary);
    //cout << dep << ' ' << binary << endl;
    return x % pw[dep] == binary;
}

void dfs(int now, int b, int limit, int dep) {
    if (dep == limit) {
        if (now && good(now, b)) {
            cout << now << endl;
        }
        return ;
    }
    dfs(now * 10, b * 2, limit, dep + 1);
    dfs(now * 10 + 1, b * 2 + 1,  limit, dep + 1);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    pw[0] = 1;
    REPP(i, 1, N - 1) pw[i] = pw[i - 1] << 1;
    REPP(i, 1, 10) {
        cout << "dep: " << i << "*************************************" << endl;
        dfs(0, 0, i, 0);
    }

    return 0;
}

