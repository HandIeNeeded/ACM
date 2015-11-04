#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

FILE *fp_in;  // judge's input

struct PT {
	int x, y;
};

typedef long long LL;

LL vect(PT p, PT p1, PT p2) {
	return LL(p1.x - p.x) * (p2.y - p.y) - LL(p2.x - p.x) * (p1.y - p.y);
}

const int MX = 200005;
int n, k, m;
PT p[MX], q[MX], r[MX];
int xx[MX], xn;
int id[MX];
PT lo_st[MX], lo_en[MX], hi_st[MX], hi_en[MX];

void build() {
	int i, j, u, v;
	
	for (i = 0; i < m; i++) xx[i] = r[i].x;
	sort(xx, xx + m);
	xn = unique(xx, xx + m) - xx;
	for (i = 0; i < m; i++) id[i] = lower_bound(xx, xx + xn, r[i].x) - xx;
	r[m] = r[0], id[m] = id[0];
	for (i = 0; i < m; i++) {
		u = id[i], v = id[i + 1];
		if (u == v) continue;
		if (u < v) {
			for (j = u; j < v; j++) lo_st[j] = r[i], lo_en[j] = r[i + 1];
		}
		else {
			for (j = v; j < u; j++) hi_st[j] = r[i + 1], hi_en[j] = r[i];
		}
	}
}

bool contain(PT p) {
	int i;
	
	if (p.x < xx[0] || p.x > xx[xn - 1]) return 0;
	i = lower_bound(xx + 1, xx + xn, p.x) - xx - 1;
	if (vect(lo_st[i], lo_en[i], p) <= 0) return 0;
	if (vect(hi_st[i], hi_en[i], p) >= 0) return 0;
	return 1;
}

bool check() {
	int i, j, prv;
	char s[10];
	
	fscanf(fp_in, "%d", &n);
	for (i = 0; i < n; i++) fscanf(fp_in, "%d%d", &p[i].x, &p[i].y);
	fscanf(fp_in, "%d", &k);
	for (i = 0; i < k; i++) fscanf(fp_in, "%d%d", &q[i].x, &q[i].y);
	
	//if (fscanf(fp_out, "%s", s) != 1) return 0;
	if(scanf("%s", s) != 1) return 0;
	if (strcmp(s, "Yes")) return 0;
	//if (fscanf(fp_out, "%d", &m) != 1) return 0;
	if(scanf("%d", &m) != 1) return 0;
	if (!(3 <= m && m <= 2 * k && m <= n)) return 0;
	prv = -1;
	for (i = 0; i < m; i++) {
		//if (fscanf(fp_out, "%d", &j) != 1) return 0;
		if(scanf("%d", &j) != 1) return 0;
		j--;
		if (!(prv <= j && j < n)) return 0;
		r[i] = p[j];
		prv = j;
	}
	build();
	for (i = 0; i < k; i++) {
		if (!contain(q[i])) return 0;
	}
	return 1;
}

int main(int argc, char **argv) {
	fp_in = fopen(argv[1], "r");
	//fp_in = fopen("1003.in", "r");

	int tc;
	for (fscanf(fp_in, "%d", &tc); tc--; ) {
		//printf("%d\n", tc);
		if (!check()){
			puts("WA");
			return 0;
		}
	}
	puts("AC");
	return 0;
}
