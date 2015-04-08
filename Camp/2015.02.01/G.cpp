#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int MO = 42424243;
const int MOD = 1000000007;
int pos[N], n, m;
int cnt[N];
pair<unsigned int, unsigned int> has[N];

int init() {
	int mx = 0;
	REPP(i, 1, m + 1) {
		cnt[i] = pos[i] - pos[i - 1] - 1;
		mx = max(mx, cnt[i]);
	}
	return mx;
}

unsigned int pow_mod(uint x, int y) {
	unsigned int ans = 1;
	while (y) {
		if (y & 1) ans = ans * x;
		x = x * x;
		y >>= 1;
	}
	return ans;
}

map<pair<unsigned int, unsigned int>, int> mp;
vector<pair<int, int> > v[N * N];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int main() {
	scanf("%d%d", &n, &m);
	REPP(i, 1, m) {
		scanf("%d", pos + i);
	}
	pos[m + 1] = n + 1;
	REPP(i, 1, m) has[i] = {1, 1};
	long long ans = 0;
	ans = init();
	int tot = 0;
	REPP(j, 1, m) {
		REPP(i, 1, m) if (i + j - 1 <= m) {
			if (!mp.count(has[i])) {
				mp[has[i]] = tot++;
			}
			int id = mp[has[i]];
			v[id].push_back({cnt[i] + 1, cnt[i + j] + 1});
		}
		REPP(i, 1, m) if (i + j <= m) {
			int en = i + j;
			has[i].first *= pow_mod(MO, pos[en] - pos[en - 1]);
			has[i].first++;
			has[i].second *= pow_mod(MOD, pos[en] - pos[en - 1]);
			has[i].second++;
		}
	}
	REP(i, tot) {
		sort(v[i].begin(), v[i].end(), cmp);
		int w = 0, h = 2000000000;
		REP(j, v[i].size()) {
			int x = v[i][j].first, y = v[i][j].second;
			if (y < h) {
				if (x > w) {
					ans += 1LL * (x - w) * y;
					h = y;
					w = x;
				}
			}
			if (x > w) {
				ans += 1LL * (x - w) * y;
				w = x;
			}
		}
	}
	printf("%lld\n", ans);

	return 0;
}
