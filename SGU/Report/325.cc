#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e6 + 5;
char s[N];
deque<int> pos[26];
int key;

void modify(int &l, int &r) {
	if (l == key) l++;
	if (r == key) r--;
}

struct BIT{
	int s[N];

	void add(int x) {
		while (x < N) {
			s[x] += 1;
			x += LB(x);
		}
	}

	int query(int x) {
		int ans = 0;
		while (x) {
			ans += s[x];
			x -= LB(x);
		}
		return ans;
	}
}t[2];// 0 to left 1 to right

int main() {
    ios :: sync_with_stdio(0);
	cin >> s;
	int n = strlen(s), ans = 0;
	REP(i, n) s[i] -= 'A';
	LL res = 0;
	REP(i, n) ans ^= (1 << s[i]);
	if (ans & (ans - 1)) {
		cout << -1 << endl;
	}
	else {
		key = -1;
		priority_queue<PII> max_index;
		REP(i, n) {
			pos[int(s[i])].push_back(i);
		}
		if (ans) {
			int id = __builtin_ctz(ans);
			key = pos[id][pos[id].size() / 2];
		}
		REP(i, 26) if (pos[i].size() > 1) {
			max_index.push({pos[i].back(), i});
		}
		int left = 0, right = n - 1;
		int head = 0, tail = n - 1;
		while (left < right) {
			modify(left, right);
			int a = max_index.top().second; max_index.pop();
			int x = pos[a].front(), y = pos[a].back();
			res += x - head + t[0].query(n) - t[0].query(x) - t[1].query(x);
			res += tail - y + t[1].query(y) - t[0].query(n) + t[0].query(y);
			t[0].add(x + 1);
			t[1].add(y + 1);
			pos[a].pop_front(), pos[a].pop_back();
			if (pos[a].size() > 1) max_index.push({pos[a].back(), a});
			left++, right--, modify(left, right);
			head++, tail--;
		}
		cout << res << endl;
	}
    return 0;
}
