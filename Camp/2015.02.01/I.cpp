#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<long long, int> 

using namespace std;

const int N = 2e5 + 5;
int a[N];

struct cmp{
	bool operator () (const PII &x, const PII &y) {
		return x.first + a[x.second] > y.first + a[y.second];
	}
};

int main() {
	//freopen("I.in", "r", stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	long long sum = 0;
	vector<long long> ans;
	REPP(i, 1, n) {
		scanf("%d", a + i);
		if (a[i] < 0) {
			sum += a[i];
			a[i] = -a[i];
		}
	}
	sort(a + 1, a + n + 1);
	priority_queue<PII, vector<PII>, cmp> q;
	q.push({0, 1});
	ans.push_back(0);
	while (q.size()) {
		long long sum = q.top().first;
		int pos = q.top().second;
		ans.push_back(sum + a[pos]);
		if ((int) ans.size() > k) break;
		if (pos + 1 <= n) {
			q.push({sum, pos + 1});
			q.push({sum + a[pos], pos + 1});
		}
		q.pop();
	}
	int flag = 0;
	int cnt = 0;
	REP(i, ans.size()) {
		if (cnt == k) break;
		if (ans[i] != -sum || flag) {
			printf("%lld\n", ans[i] + sum);
			cnt++;
		}
		else flag = 1;
	}

	return 0;
}
