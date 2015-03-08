#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 3e4 + 5;
vector<int> num;
int a[N], head[N], node;

struct sgt{
	int l, r, cnt;
}tr[N * 20];

int New_Node() {
	tr[node].l = tr[node].r = tr[node].cnt = 0;
	return node++;
}

void update(int &now, int pre, int num, int l, int r) {
	now = New_Node();
	if (l == r) {
		tr[now].cnt = tr[pre].cnt + 1;
		return ;
	}
	int mid = (l + r) >> 1;
	if (num <= mid) {
		update(tr[now].l, tr[pre].l, num, l, mid);
		tr[now].r = tr[pre].r;
	}
	else {
		update(tr[now].r, tr[pre].r, num, mid + 1, r);
		tr[now].l = tr[pre].l;
	}
	tr[now].cnt = tr[tr[now].l].cnt + tr[tr[now].r].cnt;
}

int query(int now, int pre, int k, int l, int r) {
	if (l == r) {
		return num[l - 1];
	}
	int mid = (l + r) >> 1;
	int tmp = tr[tr[now].l].cnt - tr[tr[pre].l].cnt;
	if (tmp >= k) {
		return query(tr[now].l, tr[pre].l, k, l, mid);
	}
	else {
		return query(tr[now].r, tr[pre].r, k - tmp, mid + 1, r);
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m;
	int flag = 0;
	while (cin >> n >> m) {
		if (flag++) cout << endl;
		num.clear();
		REPP(i, 1, n) {
			cin >> a[i];
			num.push_back(a[i]);
		}
		sort(ALL(num));
		num.resize(unique(ALL(num)) - num.begin());
		int mx = num.size();
		//REP(i, mx) {
		//	cout << num[i] << ' ';
		//}
		//cout << endl;
		REPP(i, 1, n) {
			a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
		}
		node = 0, head[0] = New_Node();
		REPP(i, 1, n) {
			update(head[i], head[i - 1], a[i], 1, mx);
		}
		REPP(i, 1, m) {
			int x;
			cin >> x;
			cout << query(head[x], head[0], i, 1, mx) << endl;
		}
	}

	return 0;
}

