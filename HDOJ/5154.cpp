#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int M = 10005;

int fi[N], en[M << 1], ne[M << 1], edge;
int in[N];

void add(int x, int y) {
    ne[++edge] = fi[x];
    fi[x] = edge;
    en[edge] = y;
}

int vis[N], flag;

int main() {
    ios :: sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m) {
        REPP(i, 1, m) {
            int x, y;
            cin >> x >> y;
            add(x, y);
            in[y]++;
        }
        queue<int> q;
        REPP(i, 1, n) {
            if (in[i]  == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int go = fi[x]; go; go = ne[go]) {
                int y = en[go];
                in[y]--;
                if (in[y] == 0) {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
        flag = 0;
        REPP(i, 1, n) {
            if (!vis[i]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
        MST(fi, 0), edge = 0;
        MST(vis, 0), MST(in, 0);
    }

    return 0;
}
