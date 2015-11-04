#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL inf = 1LL << 61;
const int N = 100010;
int n, m;
int a[N];

struct Tree;
Tree* pool;

struct Data
{
	LL s01, s10, s00, s11;
	Data(LL a = -inf, LL b = -inf, LL c = -inf, LL d = -inf) :s01(a), s10(b), s00(c), s11(d) {
	}
	void init() {
		s01 = s10 = s00 = s11 = -inf;
	}
	LL max_element() {
		return max(max(s01, s10), max(s00, s11));
	}
	void print() {
		printf("01: %I64d   10: %I64d  00: %I64d  11: %I64d\n", s01, s10, s00, s11);
	}
};

inline void checkmax(LL &x, LL y)
{
	if (y > x) {
		x = y;
	}
}
Data operator + (const Data& a, const Data& b)
{
	Data ret;
	ret.s01 = max(a.s00 + b.s11, a.s01 + b.s01);checkmax(ret.s01, a.s01); checkmax(ret.s01, b.s01);
	ret.s00 = max(a.s00 + b.s10, a.s01 + b.s00);checkmax(ret.s00, a.s00); checkmax(ret.s00, b.s00);
	ret.s10 = max(a.s10 + b.s10, a.s11 + b.s00);checkmax(ret.s10, a.s10); checkmax(ret.s10, b.s10);
	ret.s11 = max(a.s10 + b.s11, a.s11 + b.s01);checkmax(ret.s11, a.s11); checkmax(ret.s11, b.s11);
	return ret;
}

struct Tree
{
	int l, r;
	Data data;
	Tree *lson, *rson;
	Tree(int l = 0, int r = 0) : l(l), r(r) {
		data.init();
		if (l == r) {
			if (l & 1) {
				data.s11 = a[l];
			}
			else {
				data.s00 = a[l];
			}
			return;
		}
		int m = l + r >> 1;
		lson = new (pool++) Tree(l, m);
		rson = new (pool++) Tree(m + 1, r);
		merge();
	}
	void merge() {
		data = lson->data + rson->data;
	}
	void insert(int position, int number) {
		if (position < l || position > r) {
			return;
		}
		if (l == r) {
			if (l & 1) {
				data.s11 = number;
			}
			else {
				data.s00 = number;
			}
			return;
		}
		lson->insert(position, number);
		rson->insert(position, number);
		merge();
	}
	Data query(int L, int R) {
		if (L > r || R < l) {
			return Data(-inf, -inf, -inf, -inf);
		}
		if (L <= l && r <= R) {
			return data;
		}
		Data ldata = lson->query(L, R);
		Data rdata = rson->query(L, R);
		return ldata + rdata;
	}
	void print() {
		
		printf("[%d %d] ", l, r);
		data.print();
		if (l == r) {
			return;
		}
		lson->print();
		rson->print();
	}
}node[N * 4];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int op, l, r, position, number;
		pool = node;
		Tree *tree = new(pool++) Tree(0, n - 1);
		//tree->print();
		for (int i = 0; i < m; i++) {
			scanf("%d", &op);
			if (op == 0) {
				scanf("%d%d", &l, &r); l--; r--;
				Data ret = tree->query(l, r);
				printf("%I64d\n", ret.max_element());
			} else {
				scanf("%d%d", &position, &number);
				position--;
				tree->insert(position, number);
			}
		}
	}
	return 0;
}
