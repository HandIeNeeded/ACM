#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 505;
const int L = 2005;
int dp[N][L], node, n;
char s[N], str[N][10], r[L];
map<string, int> mp;
vector<int> edge[N];

void init() {
    node = 1;
    mp.clear();
}

bool vis[N];

void calc(int x) {
    REPP(i, 1, n) {
        int length = strlen(str[x]);
        int now = i, pos = 0;
        while (pos < length && now <= n) {
            while (pos < length && str[x][pos] != r[now]) pos++;
            if (pos == length) break;
            pos++, now++;
        }
        dp[x][i] = now - i;
    }
    dp[x][n + 1] = 0;
}

void dfs(int x) {
    if (vis[x]) return ;
    vis[x] = 1;
    if (!edge[x].size()) {
        calc(x);
        //cout << x << ": " << str[x] << endl;
        //REPP(i, 1, n) {
        //    cout << dp[x][i] << ' ';
        //}
        //cout << endl;
    }
    else {
        for (auto &y: edge[x]) {
            dfs(y);
        }
        int a = edge[x][0], b = edge[x][1];
        REPP(i, 1, n) {
            dp[x][i] = dp[a][i] + dp[b][dp[a][i] + i];
        }
        dp[x][n + 1] = 0;
        //cout << x << ": " << str[x] << endl;
        //REPP(i, 1, n) {
        //    cout << dp[x][i] << ' ';
        //}
        //cout << endl;
    }
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d", &n);
        REPP(i, 1, n) edge[i].clear(), vis[i] = 0;
        gets(s);
        REP(i, n) {
            gets(s);
            //puts(s);
            string buffer(s);
            stringstream sin(buffer);
            auto pos = buffer.find('+');
            if (pos == string :: npos) {
                string tmp;
                sin >> tmp;
                if (!mp.count(tmp)) {
                    mp[tmp] = node++;
                }
                int x = mp[tmp];
                sin >> tmp >> str[x];
                //cout << x << ' ' << str[x] << endl;
            }
            else {
                string tmp;
                string now;
                sin >> now;
                if (!mp.count(now)) {
                    mp[now] = node++;
                }
                int x = mp[now];
                REP(i, 4) {
                    sin >> tmp;
                    if (i & 1) {
                        if (!mp.count(tmp)) {
                            mp[tmp] = node++;
                        }
                        edge[x].push_back(mp[tmp]);
                    }
                }
            }
        }
        assert(node - 1 <= n);
        scanf("%s", s);
        int start = mp[s];
        scanf("%s", r + 1);
        n = strlen(r + 1);
        dfs(start);
        if (dp[start][1] == n) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}
