#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1000;
const int M = 2000;
int tr[N][2], val[N], node, A, B, a[N];

template<int N, int M, typename Type>
struct MaxFlow{
	int edge, source, sink;
	int lvl[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1];
	Type cap[M << 1];
	const Type INF = 0x3f3f3f3f;
	
	void init(int S, int T) {
		source = S, sink = T;
		edge = 1, MST(fi, 0);
	}

	void _add(int x, int y, Type z) {
		ne[++edge] = fi[x]; fi[x] = edge; en[edge] = y; cap[edge] = z;
	}

	void add(int x, int y, Type z) {
		_add(x, y, z);
		_add(y, x, 0);
	}
	
	bool bfs() {
		queue<int> q;
        MST(lvl, 0);
		q.push(source), lvl[source] = 1;
		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !lvl[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
			}
		}
		return lvl[sink];
	}

	Type dfs(Type x, Type flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		Type ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, (Type) cap[go]))) > 0) {
				ans += tmp, flow -= tmp;
				cap[go] -= tmp, cap[go ^ 1] += tmp;
				if (flow == 0) {
					return ans;
				}
			}
		}
		return ans;
	}

	Type dinic() {
		Type ans = 0;
		while (bfs()) {
            memcpy(cur, fi, sizeof(fi));
			ans += dfs(source, INF);
		}	
		return ans;
	}
};
MaxFlow<N, M, int> flow;

int Node() {
    MST(tr[node], 0), val[node] = 0;
    return node++;
}

void init() {
    node = 0;
    A = Node(), B = Node();
    flow.init(A, B);
}

void addEdge(int a, int b, int type, int cost = flow.INF) {
    if (!type) swap(a, b);
    int find = 0;
    for (int go = flow.fi[a]; go; go = flow.ne[go]) {
        if (go & 1) {
            continue;
        }
        if (flow.en[go] == b) {
            find = 1;
            flow.cap[go] = min(flow.cap[go], cost);
            break;
        }
    }
    if (!find) flow.add(a, b, cost);
}

void insert(char *s, int now, int type, int cost) {
    int pre = now;
    while (*s) {
        int x = *s++ - '0';
        if (!tr[now][x]) {
            tr[now][x] = Node();
            if (*s) addEdge(now, tr[now][x], type);
        }
        pre = now;
        now = tr[now][x];
    }
    val[now] = 1;
    addEdge(pre, now, type, cost);
}

int find(int now, int* d) {
    int ans = 0;
    REP(i, 8) {
        int x = d[i];
        if (!tr[now][x]) return ans;
        now = tr[now][x];
        if (val[now]) ans = now;
    }
    if (ans) return ans;
    return -1;
}

bool find(int num) {
    static int digit[10];
    int len = 0;
    if (num == 0) {
        digit[len++] = 0;
    }
    while (num) {
        digit[len++] = num & 1;
        num >>= 1;
    }
    while (len < 8) digit[len++] = 0;
    int pos1 = find(B, digit);
    reverse(digit, digit + 8);
    int pos2 = find(A, digit);
    assert(pos1 >= 0 && pos2 >= 0);
    if (pos1 && pos2) {
        flow.add(node++, pos1, flow.INF);
        flow.add(pos2, node - 1, flow.INF);
    }
    else if (pos1) {
        flow.add(node++, pos1, flow.INF);
        flow.add(A, node - 1, flow.INF);
    }
    else if (pos2) {
        flow.add(pos2, node++, flow.INF);
        flow.add(node - 1, B, flow.INF);
    }
    return pos1 || pos2;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) scanf("%d", a + i);
        init();
        REPP(i, 1, m) {
            static char type[2], str[9];
            static int cost;
            scanf("%s %s %d", type, str, &cost);
            if (type[0] == 'P') {
                insert(str, A, 1, cost);
            }
            else {
                int n = strlen(str);
                reverse(str, str + n);
                insert(str, B, 0, cost);
            }
        }
        int bad = 0;
        REPP(i, 1, n) {
            if (!find(a[i])) {
                bad = 1;
                break;
            }
        }
        printf("Case #%d: ", ca++);
        if (bad) {
            puts("-1");
        }
        else {
            printf("%d\n", flow.dinic());
        }
    }
    return 0;
}
