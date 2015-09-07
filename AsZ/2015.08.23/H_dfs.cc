#include <cstdio>
#include <bitset>
#include <vector>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int N = 2e4 + 5;
const int M = 1e5 + 5;
bitset<20001> from[N], to[N];
vector<int> edge[N], inv[N];
int In[N], Out[N];
int a[M], b[M];
bool vis[N];

void dfs(int x) {
    from[x][x] = vis[x] = 1;
    for(auto &y: edge[x]) {
        if (!vis[y]) dfs(y);
        from[x] |= from[y];
    }
}

void go(int x) {
    to[x][x] = 1, vis[x] = 0;
    for (auto &y: inv[x]) {
        if (vis[y]) go(y);
        to[x] |= to[y];
    }
}

int in() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}

void out(int x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[10]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    //clock_t st = clock();

    int t;
    //scanf("%d", &t);
    t = in();
    while (t--) {
        int n, m;
        n = in(), m = in();
        //scanf("%d%d", &n, &m);
        REPP(i, 1, n) from[i].reset(), to[i].reset(), edge[i].clear(), inv[i].clear(), In[i] = Out[i] = 0;
        REPP(i, 1, m) {
            int x, y;
            //scanf("%d%d", &x, &y);
            x = in(), y = in();
            edge[x].push_back(y);
            inv[y].push_back(x);
            a[i] = x, b[i] = y;
            In[y]++, Out[x]++;
        }
        REPP(i, 1, n) if (In[i] == 0) {
            dfs(i);
        }
        REPP(i, 1, n) if (Out[i] == 0) {
            go(i);
        }
        int ans = 0;
        REPP(i, 1, m) {
            if ((from[a[i]] & to[b[i]]).count() > 2) {
                ans++;
            }
        }
        out(ans);
        //printf("%d\n", ans);
    }
    //clock_t ed = clock();
    //cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;

    return 0;
}

