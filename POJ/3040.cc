#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>

using namespace std;

const int N = 25;
vector<PII> p;
int n, c;

bool cmp(const PII &a, const PII &b) {
    return a.first > b.first;
}

int use[N];

int getOne() {
    int n = p.size();
    int find = 0;
    int tot, cnt, bad;
    for (int mi = n - 1; mi >= 0; mi--) {
        tot = c;
        cnt = 1 << 30;
        bad = 0;
        MST(use, 0);
        REP(i, n) {
            int k;
            if (i == mi) {
                k = (tot + p[i].first - 1) / p[i].first;
                if (k > p[i].second) {
                    bad = 1;
                    break;
                }
                else {
                    use[i] = k, cnt = min(cnt, p[i].second / k);
                    break;
                }
            }
            else {
                k = tot / p[i].first;
                k = min(k, p[i].second);
                tot -= k * p[i].first;
                if (k) {
                    use[i] = k, cnt = min(cnt, p[i].second / k);
                }
                if (tot == 0) {
                    bad = 1;
                    break;
                }
            }
        }
        if (!bad) {
            find = 1;
            break;
        }
    }
    if (!find) return -1;
    REP(i, n) {
        p[i].second -= cnt * use[i];
    }
    return cnt;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &c) > 0) {
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            p.push_back(make_pair(x, y));
        }
        sort(p.begin(), p.end(), cmp);
        int ans = 0;
        int good = 1;
        while (good) {
            int tmp = getOne();
            if (tmp < 0) break;
            ans += tmp;
        }
        printf("%d\n", ans);
    }


    return 0;
}

