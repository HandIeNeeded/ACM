#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
const int MO = 1e9 + 7;
int sum[N];
map<int, int> mp[N];

#define PII pair<long long, int>
#define ALL(a) (a).begin(), (a).end()

struct Edge{
	PII head, tail;
}edge[N];

vector<Edge> p[N];

int pow_mod(int x, long long y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("F.in", "r", stdin);
	vector<long long> num;
	long long n;
	int m, k;
	cin >> n >> m >> k;
	num.push_back(0);
	REPP(i, 1, k) {
		long long x, z;
		int y, w;
		cin >> x >> y >> z >> w;
		edge[i] = (Edge) {{x, y}, {z, w}};
		if (x > 0) num.push_back(x - 1);
		num.push_back(x);
		num.push_back(z);
	}
	num.push_back(n);
	num.push_back(n + 1);
	sort(ALL(num));
	num.resize(unique(ALL(num)) - num.begin());
	REPP(i, 1, k) {
		int pos = lower_bound(ALL(num), edge[i].tail.first) - num.begin();
		p[pos].push_back(edge[i]);
	}
	int tot = num.size() - 1;
	//cout << tot << endl;
	//REP(i, tot + 1) {
	//	cout << num[i] << ' ';
	//}
	//cout << endl;
	sum[0] = 1;
	int invm = pow_mod(m, MO - 2);
	REPP(i, 1, tot) {
		sum[i] = 1LL * sum[i - 1] * pow_mod(m, num[i] - num[i - 1]) % MO;
		int tmps = 1LL * sum[i] * invm % MO;
		int inc = 0;
		REP(j, p[i].size()) {
			Edge tmp = p[i][j];
			int x = lower_bound(ALL(num), tmp.head.first) - num.begin();
			int y = tmp.head.second;
			int z = i;
			int w = tmp.tail.second;
			if (!mp[z][w]) mp[z][w] = tmps;
			if (x == 0) {
				add(inc, 1);
				add(mp[z][w], 1);
			}
			else {
				int ways = 0;
				if (!mp[x][y]) ways = sum[x - 1];
				else {
					ways = mp[x][y];
				}
				add(mp[z][w], ways);
				add(inc, ways);
			}
		}
		add(sum[i], inc);
	}
	int ans = 0;
	if (!mp[tot][0]) ans = sum[tot - 1];
	else ans = mp[tot][0];
	cout << ans << endl;

	return 0;
}
