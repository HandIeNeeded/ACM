#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

vector<int> num;
int a[N], head[N], pre[N], pos[N];

struct Node{
	int l, r, cnt;
}p[N * 20];

int New_Node() {
	p[node].l = p[node].r = p[node].cnt = 0;
	return node++;
}

void update(int &now, int pre, int l, int r, int num) {
	p[now] = New_Node();
	if (l == r) {
		p[now].cnt = p[pre].cnt + 1;
		return ;
	}
	int mid = (l + r) >> 1;
	if (num <= mid) {
		update(p[now].l, p[pre].l, l, mid, num);
		p[now].r = p[pre].r;
	}
	else {
		update(p[now].r, p[pre].r, mid + 1, r, num);
		p[now].l = p[pre].l;
	}
	p[now].cnt = p[p[now].l].cnt + p[p[now].r].cnt;
}

int query(int now, int pre, int l, int r) {
	if (


}

int main() {
	ios :: sync_with_stdio(0);
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	scanf("%d", &n);
	REPP(i, 1, n) {
		scanf("%d", a + i);
		num.push_back(a[i]);
	}
	sort(ALL(num));
	num.resize(unique(ALL(num)) - num.begin());
	tot = num.size();
	REPP(i, 1, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
	head[0] = New_Node();
	REPP(i, 1, n) head[i] = update(head[i], head[i - 1], 1, tot, a[i]);
	scanf("%d", &m);
	REPP(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y += x - 1;
	}

	return 0;
}

