#include <cstdio>
#include <bitset>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2005;
int sg[N];

int dfs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (sg[n] >= 0) return sg[n];
    bitset<N * 2> vis;
    REPP(i, 1, n) {
        int tmp = 0;
        if (i <= 2) tmp = dfs(n - i - 2);
        else if (i >= n - 2) tmp = dfs(i - 3);
        else tmp = dfs(i - 3) ^ dfs(n - i - 2);
        vis.set(tmp);
    }
    int &ans = sg[n];
    ans = 0;
    while (vis.test(ans)) ans++;
    return ans;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REP(i, n + 1) sg[i] = -1;
    dfs(n) ? puts("1") : puts("2");

    return 0;
}

