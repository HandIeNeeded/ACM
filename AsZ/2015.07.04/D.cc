#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;

pair<int, int> p[N];
int bit[N], vis[N];
int A, B;

void dfs(int x, int now, int dep) {
	if (now > dep) return;
	if (x > 1 && x % 2) {
		if (bit[now - 1]) {
			p[x] = {A, A};
		}
		else {
			p[x] = {B, B};
		}
		return ;
	}
	else {
		dfs(2 * now + 3, now + 1, dep);
		dfs(2 * now + 2, now + 1, dep);
		p[x].first = 2 * now + 3;
		p[x].second = 2 * now + 2;
	}
}

void go(int a, int b) {
	A = 2 * b, B = 2 * b + 1;
	REPP(i, 1, b - 1) {
		p[i].first = 2 * i;
		p[i].second = 2 * i + 1;
	}
	REPP(i, b, 2 * b - 1) {
		if (i - b + 1 <= a) {
			p[i].first = p[i].second = A;
		}
		else {
			p[i].first = p[i].second = B;
		}
	}
	cout << 2 * b + 1 << endl;
	REPP(i, 1, 2 * b - 1) {
		cout << p[i].first << ' ' << p[i].second << endl;
	}
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("drunkard.in", "r", stdin);
	freopen("drunkard.out", "w", stdout);
	int a, b;
	while (cin >> a >> b, a | b) {
		int d = __gcd(a, b);
		a /= d, b /= d;
		if ((b & (b - 1)) == 0) {
			go(a, b);
			continue;
		}
		//cout << a << ' ' << b << endl;
		MST(bit, 0), MST(vis, -1);
		int now = 0;
		while (1) {
			if (vis[a] >= 0) break;
			vis[a] = now;
			a <<= 1;
			bit[now++] = a / b;
			a %= b;
		}
		int start = vis[a], length = now - start;
		int tot = 2 * start + length + 2;
		A = tot - 1, B = tot;
		//REP(i, now) {
		//	cout << bit[i];
		//}
		//cout << endl;
		//cout << start << ' ' << length << endl;
		int flag = start > 0;
		dfs(1, 0, start);
		int rt = start ? start << 1 : 1;
		int node = rt + 1;
		//cout << "r" << ' ' << rt << ' ' << node << endl;
		for (int i = start, j = 0; i < now; i++, j++) {
			int id;
			if (i == now - 1) {
				id = node++ + flag;
				p[id].first = rt;
			}
			else if (i == start) {
				p[rt].first = node + flag;
				p[rt].second = bit[i] ? A : B;
				continue;
			}
			else {
				id = node++ + flag;
				p[id].first = id + 1;
			}
			if (bit[i]) {
				p[id].second = A;
			}
			else {
				p[id].second = B;
			}
		}
		cout << tot << endl;
		REPP(i, 1, tot - 2) {
			cout << p[i].first << ' ' << p[i].second << endl;
		}
	}

    return 0;
}

