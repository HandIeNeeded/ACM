#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

vector<int> A, B;
map<vector<int>, vector<int> > mp;
int n;

vector<int> get(vector<int> &a) {
	A.clear();
	REP(i, a.size()) {
		REPP(j, i + 1, a.size() - 1) {
			A.push_back(a[i] + a[j]);
		}
	}
	sort(A.begin(), A.end());
	return A;
}

bool dfs(vector<int> &a, int now, int dep) {
	if (dep == n) {
		vector<int> tmp = get(a);
		if (mp.count(tmp)) {
			for (auto &x: a) {
				cout << x << ' ';
			}
			cout << endl;
			for (auto &x: mp[tmp]) {
				cout << x << ' ';
			}
			cout << endl;
			return 1;
		}
		mp[tmp] = a;
		return 0;
	}
	else {
		REPP(i, now + 1, 30) {
			a.push_back(i);
			if (dfs(a, i, dep + 1)) return 1;
			a.pop_back();
		}
		return 0;
	}
}

const int N = 1005;
int a[2][N] = {{1}, {2}};

void go(int n) {
	int mx = 2;
	int cnt = __builtin_ctz(n);
	REP(i, cnt) {
		for (int j = (1 << i); j < (1 << (i + 1)); j++) {
			a[0][j] = mx + 1 + a[1][j - (1 << i)];
			a[1][j] = mx + 1 + a[0][j - (1 << i)];
		}
		mx = max(a[0][(1 << (i + 1)) - 1], a[1][(1 << (i + 1)) - 1]);
	}
	REP(i, 2) {
		REP(j, n) {
			cout << a[i][j] << " \n"[j == n - 1];
		}
	}
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("analogous.in", "r", stdin);
	freopen("analogous.out", "w", stdout);
	//while (cin >> n) {
	//	mp.clear();
	//	B.clear();
	//	if (!dfs(B, 0, 0)) {
	//		cout << "hehe" << endl;
	//	}
	//}
	while (cin >> n, n) {
		if ((n & (n - 1)) == 0) {
			cout << "Yes" << endl;
			go(n);
		}
		else {
			cout << "No" << endl;
		}
	}

    return 0;
}

