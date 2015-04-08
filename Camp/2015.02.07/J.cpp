#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;

char s[N], str[N];
int f[N], val[30], tot, length;
pair<int, int> p[N * 10];

void getfail(char *s) {
	f[0] = f[1] = 0;
	int n = strlen(s);
	REPP(i, 1, n - 1) {
		int j = f[i];
		while (j && s[j] != s[i]) j = f[j];
		f[i + 1] = s[j] == s[i] ? j + 1 : 0;
	}
}

void go(char *s) {
	int now = 0;
	int len = strlen(s); 
	REP(i, length) {
		while (now && s[now] != str[i]) now = f[now];
		if (s[now] == str[i]) {
			now++;
			if (now == len) {
				p[tot++] = {i - len + 1, i};
			}
		}
	}
}

int dp[N], L[N], R[N];
const int INF = 0x3f3f3f3f;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

vector<pair<int, int> > v;

int main() {
	ios :: sync_with_stdio(0);
	freopen("J.in", "r", stdin);
	cin >> str;
	length = strlen(str);
	int n;
	cin >> n;
	REP(i, n) {
		cin >> s;
		getfail(s);
		go(s);
	}
	REP(i, 26) cin >> val[i];
	sort(p, p + tot, cmp);
	pair<int, int> tmp;
	REP(i, tot) {
		if (!v.size()) {
			v.push_back(p[i]);
			tmp = p[i];
		}
		else {
			if (p[i].first >= tmp.first && p[i].second <= tmp.second) {
				v.pop_back();
			}
			v.push_back(p[i]);
			tmp = p[i];
		}
	}
	vector<pair<int, int> > num;
	int tot = v.size();
	//cout << tot << endl;
	//REP(i, tot) {
	//	cout << v[i].first << ' ' << v[i].second << endl;
	//}
	REP(i, tot) {
		num.push_back({v[i].first, 0});
		num.push_back({v[i].second, 1});
	}
	sort(num.begin(), num.end());
	int now = 0;
	REP(i, tot) {
		now = max(now, v[i].first);
		REPP(j, now, v[i].second) {
			L[j] = i + 1;
		}
		now = v[i].second + 1;
	}
	for (int i = tot - 1; i >= 0; i --) {
		now = min(v[i].second, now);
		for (int j = now; j >= v[i].first; j--) {
			R[j] = i + 1;
		}
		now = v[i].first - 1;
	}
	//REP(i, v.back().second + 1) {
	//	cout << i << ' ' << val[str[i] - 'a'] << ' ' << L[i] << ' ' << R[i] << endl;
	//}
	MST(dp, 0x3f);
	dp[0] = 0;
	REP(i, num.size() - 1) {
		int cost = INF;
		bool flag = 0;
		int l = 0, r = 0;
		if (i == 0) {
			now = num[0].first;
		}
		l = L[now], r = R[now];
		int nex = num[i + 1].first;
		if (!num[i + 1].second) {
			nex--;
		}
		REPP(j, now, nex) {
			cost = min(cost, val[str[j] - 'a']);
			if (!L[j] || !R[j]) flag = 1;
		}
		now = nex + 1;
		if (flag) {
			continue;
		}
		else {
			dp[r] = min(dp[r], dp[l - 1] + cost);
		}
	}
	//REP(i, tot + 1) {
	//	cout << i << ' ' << dp[i] << endl;
	//}
	assert(dp[tot] < INF);
	cout << dp[tot] << endl;

	return 0;
}
