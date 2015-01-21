#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)

using namespace std;

const int N = 200005;

struct BLOCK{
	deque<int> v;
	long long sum;

	void push_back(int x) {
		sum += x;
		v.push_back(x);
	}
	
	void pop_back() {
		sum -= v.back();
		v.pop_back();
	}

	void push_front(int x) {
		sum += x;
		v.push_front(x);
	}

	void pop_front() {
		sum -= v.front();
		v.pop_front();
	}
}blk[2000];

int a[N], mylist[2][2000], length;

void update(int l, int r) {
	int a = l, b = r;
	if (a & 1) a++;
	if (b & 1) b--;
	a >>= 1, b >>= 1;
	int st = a / length, ed = b / length;
	a %= length, b %= length;
	int d = blk[mylist[1][ed]].v[b];
	int now = st;
	int pos = a;
	if (st == ed) {
		int now = st, pos = a;
		if (l & 1) {
			pos--;
			if (pos < 0) now--, pos = length - 1;
		}
		REPP(i, a, b) {
			int tmp = blk[mylist[0][st]].v[i] - blk[mylist[1][now]].v[pos];
			swap(blk[mylist[0][st]].v[i], blk[mylist[1][now]].v[pos]);
			blk[mylist[0][st]].sum -= tmp;
			blk[mylist[1][now]].sum += tmp;
			pos++;
			if (pos == length) now++, pos = 0;
		}
		return ;
	}
	else {
		REPP(i, st + 1, ed - 1) swap(mylist[0][i], mylist[1][i]);
		REPP(i, a, length - 1) {
			int tmp = blk[mylist[0][st]].v[i] - blk[mylist[1][st]].v[i];
			swap(blk[mylist[0][st]].v[i], blk[mylist[1][st]].v[i]);
			blk[mylist[0][st]].sum -= tmp;
			blk[mylist[1][st]].sum += tmp;
		}
		REPP(i, 0, b) {
			int tmp = blk[mylist[0][ed]].v[i] - blk[mylist[1][ed]].v[i];
			swap(blk[mylist[0][ed]].v[i], blk[mylist[1][ed]].v[i]);
			blk[mylist[0][ed]].sum -= tmp;
			blk[mylist[1][ed]].sum += tmp;
		}
	}
	if (l & 1) {
		pos--;
		if (pos < 0) now--, pos = length - 1;
		int x = blk[mylist[1][now]].v[pos];

		blk[mylist[0][ed]].sum -= d;
		blk[mylist[0][now]].sum += x;
		blk[mylist[0][ed]].v.erase(blk[mylist[0][ed]].v.begin() + b);
		blk[mylist[0][now]].v.insert(blk[mylist[0][now]].v.begin() + pos + 1, x);
		REPP(i, now + 1, ed) {
			blk[mylist[0][i]].push_front(blk[mylist[0][i - 1]].v.back());
			blk[mylist[0][i - 1]].pop_back();
		}

		blk[mylist[1][now]].sum -= x;
		blk[mylist[1][ed]].sum += d;
		blk[mylist[1][now]].v.erase(blk[mylist[1][now]].v.begin() + pos);
		blk[mylist[1][ed]].v.insert(blk[mylist[1][ed]].v.begin() + b + 1, d);
		REPP(i, now, ed - 1) {
			blk[mylist[1][i]].push_back(blk[mylist[1][i + 1]].v.front());
			blk[mylist[1][i + 1]].pop_front();
		}
	}
}

long long query(int l, int r) {
	int a = l, b = r;
	long long ans = 0;
	if (a & 1) a++;
	if (b & 1) b--;
	if (a <= b) {
		a >>= 1, b >>= 1;
		int st = a / length, ed = b / length;
		a %= length, b %= length;
		if (st == ed) {
			REPP(i, a, b) {
				ans += blk[mylist[0][st]].v[i];
			}
		}
		else {
			REPP(i, st + 1, ed - 1) ans += blk[mylist[0][i]].sum;
			REPP(i, a, length - 1) ans += blk[mylist[0][st]].v[i];
			REPP(i, 0, b) ans += blk[mylist[0][ed]].v[i];
		}
	}
	a = l, b = r;
	if (!(a & 1)) a++;
	if (!(b & 1)) b--;
	if (a <= b) {
		a >>= 1, b >>= 1;
		int st = a / length, ed = b / length;
		a %= length, b %= length;
		if (st == ed) {
			REPP(i, a, b) {
				ans += blk[mylist[1][st]].v[i];
			}
		}
		else {
			REPP(i, st + 1, ed - 1) ans += blk[mylist[1][i]].sum;
			REPP(i, a, length - 1) ans += blk[mylist[1][st]].v[i];
			REPP(i, 0, b) ans += blk[mylist[1][ed]].v[i];
		}
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);

	int n, q, ty, l, r;
	cin >> n >> q;
	REP(i, n) {
		cin >> a[i];
	}
	if (n & 1) a[n++] = 0;
	length = (int) sqrt(n / 2 + 0.5);
	int now = 0;
	REP(k, 2) {
		for (int i = k, cnt = 0; i < n; i += 2, cnt++) {
			int limit = min((n - i) / 2 + 1, length);
			REP(j, limit) {
				blk[now].push_back(a[i + 2 * j]);
			}
			i = i + 2 * limit - 2;
			mylist[k][cnt] = now++;
		}
	}
	REP(i, q) {
		cin >> ty >> l >> r;
		l--, r--;
		if (ty == 1) {
			update(l, r);
		}
		else {
			cout << query(l, r) << endl;
		}
	}

	return 0;
}

