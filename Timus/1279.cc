#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 9e5 + 5;
const int C = 128;

struct AC{
    map<int, int> tr[N];
    int fail[N], dep[N];
    bool good[N];
    int node;

    void init() {
        tr[0].clear();
        fail[0] = good[0] = dep[0] = 0;
        node = 1;
    }

    int NewNode() {
        tr[node].clear();
        good[node] = fail[node] = 0;
        return node++;
    }

    void insert(char *s) {
        int now = 0, pos = 0;
        while (s[pos]) {
            int x = s[pos++];
            if (!tr[now][x]) tr[now][x] = NewNode(), dep[tr[now][x]] = dep[now] + 1;
            now = tr[now][x];
        }
        good[now] = 1;
    }

    void getfail() {
        queue<int> q;
        REP(i, C) {
            if (tr[0][i]) {
                int y = tr[0][i];
                fail[y] = 0;
                q.push(y);
            }
        }

        while (q.size()) {
            int x = q.front(); q.pop();
            REP(i, C) {
                if (!tr[x][i]) {
                    tr[x][i] = tr[fail[x]][i];
                    continue;
                }
                int y = tr[x][i];
                fail[y] = tr[fail[x]][i];
                q.push(y);
            }
        }
    }

    int find(char *s) {
        int now = 0, pos = 0;
        while (s[pos]) {
            int x = s[pos++];
            if (good[now]) return pos - dep[now];
            else now = tr[now][x];
        }
        return -1;
    }
}ac;

char s[100006];

int main() {
    int n;
    scanf("%d", &n);
    ac.init();
    REP(i, n) {
        scanf("%s", s);
        ac.insert(s);
    }
    ac.getfail();
    int m;
    scanf("%d", &m);
    getchar();
    int pass = 1;
    REP(i, m) {
        gets(s);
        int ans = ac.find(s);
        if (ans >= 0) {
            printf("%d %d\n", i + 1, ans);
            pass = 0;
            break;
        }
    }
    if (pass) {
        puts("Passed");
    }
    return 0;
}

