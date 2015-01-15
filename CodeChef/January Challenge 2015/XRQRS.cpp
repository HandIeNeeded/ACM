#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
using namespace std;
 
const int N = (1 << 19) - 1;
const int INF = 0x3f3f3f3f;
 
struct po{
	int cnt, l, r;
}tr[N * 20];
 
int head[N], node, length;
 
int New_Node() {
	tr[node].cnt = tr[node].l = tr[node].r = 0;
	return node++;
}
 
void update(int &now, int pre, int num, int l, int r) {
	now = New_Node();
	if (l == r) {
		tr[now].cnt = tr[pre].cnt + 1;
		return ;
	}
	int mid = (l + r - 1) >> 1;
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
 
int query1(int now, int pre, int num, int dep, int l, int r) {
	if (l == r) {
		return l;
	}
	int mid = (l + r - 1) >> 1;
	if (num & dep) {
		int tmp = tr[tr[now].l].cnt - tr[tr[pre].l].cnt;
		if (tmp) {
			return query1(tr[now].l, tr[pre].l, num, dep >> 1, l, mid);
		}
		else {
			return query1(tr[now].r, tr[pre].r, num, dep >> 1, mid + 1, r);
		}
	}
	else {
		int tmp = tr[tr[now].r].cnt - tr[tr[pre].r].cnt;
		if (tmp) {
			return query1(tr[now].r, tr[pre].r, num, dep >> 1, mid + 1, r);
		}
		else {
			return query1(tr[now].l, tr[pre].l, num, dep >> 1, l, mid);
		}
	}
}
 
int query3(int now, int pre, int num, int l, int r) {
	if (r <= num) {
		return tr[now].cnt - tr[pre].cnt;
	}
	else {
		int mid = (l + r - 1) >> 1;
		int ans = 0;
		if (num > mid) ans += query3(tr[now].r, tr[pre].r, num, mid + 1, r);
		ans += query3(tr[now].l, tr[pre].l, num, l, mid);
		return ans;
	}
}
 
int query4(int now, int pre, int num, int l, int r) {
	if (l == r) {
		return l;
	}
	int mid = (l + r - 1) >> 1;
	int tmp = tr[tr[now].l].cnt - tr[tr[pre].l].cnt;
	if (tmp >= num) {
		return query4(tr[now].l, tr[pre].l, num, l, mid);
	}
	else {
		return query4(tr[now].r, tr[pre].r, num - tmp, mid + 1, r);
	}
}
 
int get() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}
 
void output(int x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[10]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}
 
 
int main() {
	int m;
	m = get();
	New_Node();
	while (m--) {
		int ty, ql, qr, x;
		ty = get();
		if (ty == 0 || ty == 2) {
			x = get();
			if (ty == 0) {
				update(head[length + 1], head[length], x, 1, N);
				length++;
			}
			else {
				length -= x;
			}
		}
		else {
			ql = get(), qr = get(), x = get();
			if (ty == 1) {
				output(query1(head[qr], head[ql - 1], x, 1 << 18, 1, N));
			}
			else if (ty == 3) {
				output(query3(head[qr], head[ql - 1], x, 1, N));
			}
			else {
				output(query4(head[qr], head[ql - 1], x, 1, N));
			}
		}
	}
	return 0;
}
