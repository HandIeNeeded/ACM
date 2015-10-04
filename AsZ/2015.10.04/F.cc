#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;
vector<int> edge[N];
double cap[N], val[N];
int order[N], degree[N], out[N];
int n, m;

void Sort() {
    int now = 0;
    REPP(i, 1, n) if (degree[i] == 0) {
        order[now++] = i;
    }
    int head = 0;
    while (head < now) {
        int x = order[head++];
        REP(i, edge[x].size()) {
            int y = edge[x][i];
            degree[y]--;
            if (degree[y] == 0) {
                order[now++] = y;
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        cap[i] = x, val[i] = y;
    }
    REPP(i, 1, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        degree[y]++, out[x]++;
    }
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    val[x] += y;
    Sort();
    //cout << "hehe" << endl;
    REPP(i, 1, n) assert(degree[i] == 0);
    REP(j, n) {
        //cout << order[j] << ' ';
        int i = order[j];
        if (val[i] > cap[i]) {
            double more = (val[i] - cap[i]) / out[i];
            val[i] = cap[i];
            REP(j, edge[i].size()) {
                val[edge[i][j]] += more;
            }
        }
    }
    //cout << endl;
    printf("%.10f\n", val[z]);

    return 0;
}


