#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
const int M = 100005 << 1;
const int INF = 0x3f3f3f3f;

struct Min_cost_Max_flow{
    #define inf 168430090
    int n, st, en, tot;
    int b[M], c[M], w[M], e[M];
    int h[N], pre[N], p[N], d[N];
    queue<int> q;

    void init(int _n,int _st,int _en){
        memset(h, 0, sizeof(h));
        tot = 1;
        st = _st; en = _en;
        n = _n;
    }

    void add(int x,int y,int z,int cost){
        b[++tot] = y; c[tot] = z; w[tot] = cost; e[tot] = h[x]; h[x] = tot;
        b[++tot] = x; c[tot] = 0; w[tot] = -cost; e[tot] = h[y]; h[y] = tot;
    }

    pair<int, int> push_flow(){
        int x = en, flow = inf;
        while (x != st){
            flow = min(flow, c[pre[x]]);
            x = b[pre[x] ^ 1];
        }
        x = en;
        while (x != st){
            c[pre[x]] -= flow; c[pre[x]^1] += flow;
            x = b[pre[x] ^ 1];
        }
        return {flow * d[en], flow};
    }

    int spfa(){
        memset(d, 10, sizeof(d));
        memset(p, 0, sizeof(p));
        q.push(st); p[st] = 1; d[st] = 0;
        while (!q.empty()){
            int x = q.front(); q.pop();
            p[x] = 0;
            for (int go = h[x]; go; go = e[go])
                if (c[go] && d[b[go]] > d[x] + w[go]){
                    d[b[go]] = d[x] + w[go];
                    pre[b[go]] = go;
                    if (p[b[go]] == 0){
                        p[b[go]] = 1;
                        q.push(b[go]);
                    }
                }
        }
        return d[en] < inf;
    }

    pair<int, int> min_cost(){
		pair<int, int> ans, tmp;
        while (spfa()) tmp = push_flow(), ans.first += tmp.first, ans.second += tmp.second;
        return ans;
    }
}flow;
map<int, int> mp;
int tot;
vector<pair<int, int> > edge[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m, x, y, cnt;
	
	cin >> n;
	REPP(i, 1, n) {
		cin >> cnt;
		REP(j, cnt) {
			cin >> x >> y;
			if (!mp.count(x)) {
				mp[x] = ++tot;
			}
			edge[mp[x]].push_back(make_pair(i, y));
		}
	}
	cin >> m;
	multiset<int> s;
	while (m--) {
		s.clear();
		bool bad = 0;
		REP(i, n) {
			cin >> x, s.insert(x);
			if (!mp.count(x)) {
				bad = 1;
				break;
			}
		}
		if (bad) {
			cout << -1 << endl;
			continue;
		}
		int source = 2 * n + 2, sink = 2 * n + 1;
		flow.init(2 * n + 2, source, sink);
		REPP(i, 1, n) {
			flow.add(source, i, 1, 0);
		}
		int clk = 1;
		for (auto it : s) {
			flow.add(clk + n, sink, s.count(it), 0);
			for (auto now : edge[mp[it]]) {
				flow.add(now.first, clk + n, INF, now.second);
			}
			clk++;
		}
		pair<long long, int> ans = flow.min_cost();
		if (ans.second == n) {
			cout << ans.first << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}


