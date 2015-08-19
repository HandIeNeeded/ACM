#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define T3 tuple<LL, LL, LL>
#define T4 tuple<LL, LL, LL, LL>

using namespace std;

LL A, B, C;
map<T3, T4> mp;

void sort(LL &A, LL &B, LL &C) {
	if (A < B) swap(A, B);
	if (A < C) swap(A, C);
	if (B < C) swap(B, C);
}

LL test(LL A, LL B) {
	return max(B, A / 2);
}

T4 dfs(T3 now) {
	if (mp.count(now)) return mp[now];
	LL A, B, C;
	tie(A, B, C) = now;
	//cout << "hehe " << A << ' ' << B << ' ' << C << endl;
	if (A + B + C < 3) {
		return make_tuple(0, 0, 0, 0);
	}
	T4 resA, resB;
	//secure A
	tie(A, B, C) = now;
	if (2 * C >= A) {
		B = 1;
		A--;
		sort(A, B, C);
		resA = dfs(make_tuple(A, B, C));
	}
	else {
		B = A / 2;
		A -= B;
		sort(A, B, C);
		resA = dfs(make_tuple(A, B, C));
	}
	//secure B C
	tie(A, B, C) = now;
	if (2 * C >= B) {
		A = B - 1;
		B = 1;
		sort(A, B, C);
		resB = dfs(make_tuple(A, B, C));
	}
	else {
		A = B / 2;
		B -= A;
		sort(A, B, C);
		resB = dfs(make_tuple(A, B, C));
	}

	LL D1 = get<3>(resA), D2 = get<3>(resB), D;
	tie(A, B, C) = now;
	T4 ans;
	if (D1 == D2) {
		D = A;
		if (2 * C >= B) {
			A = B - 1;
			B = 1;
			sort(A, B, C);
			ans = make_tuple(A, B, C, D);
		}
		else {
			A = B / 2;
			B -= A;
			sort(A, B, C);
			ans = make_tuple(A, B, C, D);
		}
	}
	else {
		D = B;
		if (2 * C >= A) {
			B = 1;
			A--;
			sort(A, B, C);
			ans = make_tuple(A, B, C, D);
		}
		else {
			B = A / 2;
			A -= B;
			sort(A, B, C);
			ans = make_tuple(A, B, C, D);
		}
	}
	return mp[now] = ans;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("eating.in", "r", stdin);
	freopen("eating.out", "w", stdout);
	int ca = 1;
	vector<LL> ans;
	//LL A, B, C, D;
	//REPP(i, 1, 5) {
	//	REPP(j, 1, 5) {
	//		REPP(k, 1, 5) {
	//			tie(A, B, C, D) = dfs(make_tuple(i, j, k));
	//			cout << "i j k " << i << ' ' << j << ' ' << k << " A B C D " << A << ' ' << B << ' ' << C << ' ' << D << endl;
	//		}
	//	}
	//}
	while (cin >> A >> B >> C, A | B | C) {
		sort(A, B, C);
		T4 res = dfs(make_tuple(A, B, C));
		LL D = get<3>(res);
		ans.clear();
		while (D) {
			ans.push_back(D);
			tie(A, B, C, D) = res;
			res = dfs(make_tuple(A, B, C));
			D = get<3>(res);
		}
		cout << "Case #" << ca++ << ":" << endl << ans.size() << endl;
		REP(i, ans.size()) {
			cout << ans[i] << " \n"[i == int(ans.size() - 1)];
		}
	}
	return 0;
}

