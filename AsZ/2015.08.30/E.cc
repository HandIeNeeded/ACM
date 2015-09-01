#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int L = 6e5 + 5;
const int N = 1e5 + 5;
const int C = 26;

struct AC{
    int tr[L][C], fail[L], dp[L], node;
    vector<int> edge[N];

    int New_Node() {
        MST(tr[node], 0), fail[node] = dp[node] = 0;
        edge[node].clear();
        return node++;
    }

    void init() {
        node = 0;
        New_Node();
    }

    void insert(char *s) {
        int now = 0, pos = 0;
        while (s[pos]) {
            int x = s[pos++] - 'a';
            if (!tr[now][x]) tr[now][x] = New_Node();
            now = tr[now][x];
        }
        dp[now]++;
    }

    LL find(const char *s) {
        int now = 0, pos = 0;
        LL ans = 0;
        while (s[pos]) {
            int x = s[pos++] - 'a';
            now = tr[now][x];
            //cout << "go: " << now << endl;
            ans += dp[now];
        }
        return ans;
    }

    void getFail() {
        queue<int> q;
        REP(i, C) {
            if (tr[0][i]) {
                q.push(tr[0][i]);
                fail[tr[0][i]] = 0;
                edge[0].push_back(tr[0][i]);
            }
        }
        while (q.size()) {
            int x = q.front(); q.pop();
            REP(i, C) {
                int y = tr[x][i];
                if (!tr[x][i]) {
                    tr[x][i] = tr[fail[x]][i];
                    continue;
                }
                fail[y] = tr[fail[x]][i];
                edge[fail[x]].push_back(y);
                dp[y] += dp[fail[y]];
                q.push(y);
            }
        }
    }
}AC;

char tmp[N];
string str[N];

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) {
            scanf("%s", tmp);
            str[i] = string(tmp);
        }
        AC.init();
        REP(i, m) {
            scanf("%s", tmp);
            AC.insert(tmp);
        }
        AC.getFail();
        REPP(i, 1, n) {
            printf("%lld\n", AC.find(str[i].c_str()));
        }
    }

    return 0;
}

