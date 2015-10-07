#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 40;
const string str1 = "NSBH", str2 = "ESWNrwg";

string name[4] = {"Takakamo Shizuno", "Atarashi Ako", "Matsumi Kuro", "Haramura Nodoka"};

void update(int &x, int y) {
    if (x < y) x = y;
}

struct Person{
    int f[4][10], g[4][10];
    int dp[N][5][5];
    vector<pair<int, int> > tiles;
    int id;

    void init(int x) {
        MST(f, 0), MST(g, 0);
        tiles.clear();
        id = x;
    }

    void Set(int x) {
        memcpy(g, f, sizeof(f));
        REP(i, x) {
            int a = tiles[i].first, b= tiles[i].second;
            g[a][b]++;
        }
    }

    void add(char *s, int round) {
        int x = str1.find(s[1]);
        int y;
        if (x < 3) {
            y = s[0] - '0';
        }
        else {
            y = str2.find(s[0]);
        }
        if (round < 4) {
            f[x][y]++;
        }
        else {
            tiles.push_back(make_pair(x, y));
        }
    }

    //7 pairs
    bool D() {
        int cnt = 0;
        REP(i, 3) {
            REPP(j, 1, 9) {
                if (g[i][j] >= 2) cnt++;
            }
        }
        REP(i, 7) if (g[3][i] >= 2) cnt++;
        return cnt >= 7;
    }

    //13
    bool F() {
        bool good = 1;
        REP(i, 3) {
            good &= g[i][1] && g[i][9];
        }
        bool tmp = 0;
        REP(i, 7) {
            if (g[3][i] == 0) good = 0;
            if (g[3][i] >= 2) tmp = 1;
        }
        good &= tmp;
        return good;
    }

    int go() {
        int ans = 0;
        REP(k, 3) {
            MST(dp, -1);
            REPP(a, 0, g[k][1]) {
                REPP(b, 0, g[k][2]) {
                    dp[2][a][b] = 0;
                }
            }
            if (g[k][1] >= 3) {
                if (g[k][2] >= 3) {
                    dp[2][g[k][1] - 3][g[k][2] - 3] = 2;
                    REPP(i, 0, g[k][2]) dp[2][g[k][1] - 3][i] = 1;
                    REPP(i, 0, g[k][1]) dp[2][i][g[k][2] - 3] = 1;
                }
                else {
                    dp[2][g[k][1] - 3][g[k][2]] = 1;
                }
            }
            else {
                if (g[k][2] >= 3) {
                    REPP(i, 0, g[k][1]) dp[2][i][g[k][2] - 3] = 1;
                }
            }
            REPP(i, 2, 8) {
                REPP(a, 0, 4) {
                    REPP(b, 0, 4) if (dp[i][a][b] >= 0) {
                        //3
                        int x = g[k][i + 1];
                        if (x >= 3) {
                            int add = a && b && x == 4;
                            update(dp[i + 1][b][x - 3], dp[i][a][b] + 1);
                            if (add) update(dp[i + 1][b - 1][0], dp[i][a][b] + 2);
                        }
                        //abc
                        int mi = min(a, b);
                        mi = min(mi, x);
                        REP(j, mi + 1) {
                            update(dp[i + 1][b - j][x - j], dp[i][a][b] + j);
                        }
                    }
                }
            }
            int tmp = 0;
            REPP(i, 2, 9) REPP(a, 0, 4) REPP(b, 0, 4) tmp = max(tmp, dp[i][a][b]);
            ans += tmp;
        }
        //pair
        REP(i, 7) if (g[3][i] >= 3) ans++;
        return ans;
    }

    bool Special() {
        return F() || D();
    }

    bool Normal() {
        REP(i, 4) {
            if (i < 3) {
                REPP(j, 1, 9) {
                    if (g[i][j] >= 2) {
                        g[i][j] -= 2;
                        if (go() >= 4) return 1;
                        g[i][j] += 2;
                    }
                }
            }
            else {
                REP(j, 7) {
                    if (g[i][j] >= 2) {
                        g[i][j] -= 2;
                        if (go() >= 4) return 1;
                        g[i][j] += 2;
                    }
                }
            }
        }
        return 0;
    }

    bool Win() {
        return Special() || Normal();
    }

    pair<int, int> get() {
        int l = 0, r = 22;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            Set(mid);
            if (Win()) r = mid;
            else l = mid;
        }
        return make_pair(r, id);
    }
}p[4];

char buffer[4];

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        REP(i, 4) p[i].init(i);
        REP(i, 34 * 4) {
            scanf("%s", buffer);
            if (i < 12 * 4) {
                int per = i / 4;
                int round = per / 4;
                int who = per % 4;
                p[who].add(buffer, round);
            }
            else if (i < 13 * 4) {
                int who = i - 12 * 4;
                int round = 3;
                p[who].add(buffer, round);
            }
            else {
                int who = i % 4;
                int round = i / 4 - 13 + 4;
                p[who].add(buffer, round);
            }
        }
        pair<int, int> ans = make_pair(22, 4);
        REP(i, 4) {
            pair<int, int> tmp = p[i].get();
            ans = min(ans, tmp);
        }
        if (ans.first == 22) {
            printf("For round %d, a Draw Hand occurs.\n", ca++);
        }
        else {
            printf("For round %d, %s wins at turn %d.\n", ca++, name[ans.second].c_str(), ans.first);
        }
    }
    return 0;
}

