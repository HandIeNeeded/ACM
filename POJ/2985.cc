#include <cstdio>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 2e5 + 5;

int f[N], cnt[N], n, m;

struct Fenwick{
	int s[N];

	void add(int x, int d) {
		while (x < N) {
			s[x] += d;
			x += LB(x);
		}
	}

	int get_kth(int x) {
		int ans = 0, cnt = 0;
		for (int i = 20; i >= 0; i--) {
			ans += 1 << i;
			if (ans >= N || cnt + s[ans] >= x) ans -= 1 << i;
			else cnt += s[ans];
		}
		return ans + 1;
	}
}tree;

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	REPP(i, 1, n) f[i] = i, cnt[i] = 1;
	tree.add(1, n);
	int tot = n;
	REPP(i, 1, m) {
		int type, x, y;
		scanf("%d", &type);
		if (type) {
			scanf("%d", &x);
			printf("%d\n", tree.get_kth(tot - x + 1));
		}
		else {
			scanf("%d%d", &x, &y);
			int tx = find(x), ty = find(y);
			if (tx != ty) {
				tree.add(cnt[tx], -1);
				tree.add(cnt[ty], -1);
				cnt[ty] += cnt[tx];
				tree.add(cnt[ty], 1);
				f[tx] = ty;
				tot--;
			}
		}
	}
	return 0;
}
