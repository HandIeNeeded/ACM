#include <bits/stdc++.h>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

vector<LL> ans;

void modify(LL &x, int ty) {
	if (x & 1) {
		ans.push_back(x);
		int find = 0;
		for (int i = 3; 1LL * i * i <= x; i += 2) {
			if (x % i == 0) {
				find = i;
				break;
			}
		}
		if (find) {
			x += ty * find;
		}
	}
}

bool dfs(LL now, LL target) {
	ans.push_back(now);
	if (now > target || now % 2 || target % 2) {
		return 0;
	}
	else if (now == target) {
		return 1;
	}
	else {
		LL tmp = 1LL << __builtin_ctzll(now);
		if (tmp == now) tmp >>= 1;
		if (target - now < tmp) {
			tmp = 1LL << __builtin_ctzll(target - now);
		}
		return dfs(now + tmp, target);
	}
}

int main() {
    ios :: sync_with_stdio(0);
	LL A, B;
	cin >> A >> B;
	modify(A, 1), modify(B, -1);
	if (dfs(A, B)) {
		sort(ans.begin(), ans.end());
		REP(i, ans.size()) {
			cout << ans[i] << " \n"[i == int(ans.size() - 1)];
		}
	}
	else {
		cout << "Impossible" << endl;
	}

    return 0;
}

