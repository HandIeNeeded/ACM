#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>

using namespace std;

const int N = 15e4 + 4;

struct cmp{
    bool operator () (const PII &a, const PII &b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    }
};
priority_queue<PII, vector<PII>, cmp> q;
string s[N];
int val[N];
map<string, int> mp;
int ans[N];
char str[N];

PII p[N];

int main() {
#ifdef HOME
    freopen("1.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int k, m, Q;
        mp.clear();
        scanf("%d%d%d", &k, &m, &Q);
        while (q.size()) q.pop();
        REPP(i, 1, k) {
            int x;
            scanf("%s%d", str, &x);
            mp[string(str)] = i;
            s[i] = string(str);
            val[i] = x;
        }
        int now = 1;
        int tot = 0;
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            p[i] = {x, y};
        }
        sort(p + 1, p + m + 1);
        REPP(i, 1, m) {
            int x = p[i].first, y = p[i].second;
            while (now <= x && now <= k) {
                q.push({val[now], now});
                now++;
            }
            REP(i, y) {
                if (q.size()) {
                    ans[++tot] = q.top().second;
                    q.pop();
                }
            }
        }
        while (now <= k) q.push({val[now], now}), now++;
        while (q.size()) {
            ans[++tot] = q.top().second;
            q.pop();
        }
        //REPP(i, 1, k) {
        //    cout << ans[i] << ' ';
        //}
        //cout << endl;
        REPP(i, 1, Q) {
            int x;
            scanf("%d", &x);
            printf("%s%c", s[ans[x]].c_str(), " \n"[i == Q]);
        }
    }

    return 0;
}

