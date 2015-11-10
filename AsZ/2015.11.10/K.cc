#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
int in[N], out[N];
vector<int> edge[N];

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[y].push_back(x);
        out[y]++, in[x]++;
    }

    priority_queue<int> q;
    vector<int> ans;
    REPP(i, 1, n) if (in[i] == 0) {
        q.push(i);
    }
    while (q.size()) {
        int x = q.top(); q.pop();
        ans.push_back(x);
        for (auto &y: edge[x]) {
            in[y]--;
            if (in[y] == 0) {
                q.push(y);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto &x: ans) {
        cout << x << ' ';
    }

    return 0;
}


