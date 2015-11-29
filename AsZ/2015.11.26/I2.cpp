#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

const int MAXN = 200;
const int MAXM = 200;
const int MOD = 1000000007;

int dp[MAXN + 1][MAXM + 20][50];
int N, M;
vector<pair<int, int> > go[50];

void update(int &a, int b) {
    a += b;
    if (a >= MOD)   a -= MOD;
}

//将状态转化为整数
int trans(int i, int j, int k) {
    return 25 * i + 5 * j + k;
}

//计算连续的三种牌个数是(a,b,c)个时转移到的状态
vector<pair<pair<int, int>, int> > to(int a, int b, int c) {
    int bound = min(a, min(b, c));
    vector<pair<pair<int, int>, int> > ret;
    for (int i = 0; i <= bound; ++ i) {
        ret.push_back(make_pair(make_pair(b - i, c - i), 3 * i));
    }
    return ret;
}

//计算转移状态
vector<pair<int, int> > calGo(int i, int j, int k) {
    vector<pair<int, int> > ret;
    if (i & 1) {
        //已经取了一对
        vector<pair<pair<int, int>, int> > st1, st2;
        st1 = to(j, k, 4);
        //取相同的三个为一组
        st2 = to(j, k, 1);
        for (auto p : st2) {
            p.second += 3;
            st1.push_back(p);
        }
        sort(st1.begin(), st1.end());
        st1.erase(unique(st1.begin(), st1.end()), st1.end());
        for (auto p : st1) {
            ret.push_back(make_pair(trans(1, p.first.first, p.first.second), p.second));
        }
        return ret;
    } else {
        vector<pair<pair<int, int>, int> > st1, st2, st3;
        st1 = to(j, k, 4);
        //取相同的三个为一组
        st2 = to(j, k, 1);
        for (auto p : st2) {
            p.second += 3;
            st1.push_back(p);
        }
        sort(st1.begin(), st1.end());
        st1.erase(unique(st1.begin(), st1.end()), st1.end());
        for (auto p : st1) {
            ret.push_back(make_pair(trans(0, p.first.first, p.first.second), p.second));
        }
        //取一对
        st3 = to(j, k, 2);
        for (auto p : st3) {
            ret.push_back(make_pair(trans(1, p.first.first, p.first.second), p.second + 2));
        }
        return ret;
    }
}

void init() {
    for (int i = 0; i < 2; ++ i) {
        for (int j = 0; j <= 4; ++ j) {
            for (int k = 0; k <= 4; ++ k) {
                go[trans(i, j, k)] = calGo(i, j, k);
            }
        }
    }
}

void solve() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; ++ i) {
        for (int j = 0; j <= M; ++ j) {
            for (int k = 0; k < 50; ++ k) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++ i) {
        set<pair<int, int> > finalState;
        vector<pair<pair<int, int>, pair<int, int> > > validateState;
        for (int j = 0; j <= M; ++ j) {
            for (int st = 0; st < 50; ++ st) {
                if (dp[i][j][st] == 0)  continue;
                for (int k = 0; k < (int)go[st].size(); ++ k) {
                    pair<int, int> cur = go[st][k];
                    
                    /*
                    if (cur.first % 5 == 4 || cur.first % 5 == 0) {
                        update(dp[i + 1][j + cur.second][cur.first], dp[i][j][st]);
                    } else {
                        pair<int, int> toState = make_pair(j + cur.second, cur.first);
                        if (!finalState.count(toState)) {
                            finalState.insert(toState);
                            validateState.push_back(make_pair(toState, make_pair(j, st)));
                        }
                    }
                    */
                    update(dp[i + 1][j + cur.second][cur.first], dp[i][j][st]);
                }
            }
        }
        /*
        for (auto st : validateState) {
            update(dp[i + 1][st.first.first][st.first.second], dp[i][st.second.first][st.second.second]);
        }
        */
    }
    
    int ans = 0;
    for (int i = 25; i < 50; ++ i) {
        update(ans, dp[N][M][i]);
    }
    printf("%d\n", ans);
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++ kase) {
        solve();
    }
    return 0;
}

