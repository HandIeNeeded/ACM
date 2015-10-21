#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int C = 26;

struct AC{
    int tr[N][C], cnt[N], node;

    int Node() {
        MST(tr[node], 0), cnt[node] = 0;
        return node++;
    }

    void insert(char *s) {
        int now = 0;
        while (*s) {
            int x = *s++ - 'a';
            if (!tr[now][x]) tr[now][x] = Node();
            now = tr[now][x];
        }
        cnt[now]++;
    }

    void build() {
        queue<int> q;
        REP(i, C) {
            if (tr[0][i]) {
                q.push(tr[0][i]);
                fail[tr[0][i]] = 0;
            }
        }
        while (q.size()) {
            int x = q.front(); q.pop();
            REP(i, C) {
                int &y = tr[x][i];
                if (!y) {
                    y = tr[fail[x]][i];
                    continue;
                }
                fail[y] = tr[fail[x]][i];
                q.push(y);
            }
        }
    }

    int find(char *s) {
        int now = 0;
        while (*s) {
            int x = *s++ - 'a';
            now = tr[now][x];
        }
        return ans;
    }
}AC;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    return 0;
}

