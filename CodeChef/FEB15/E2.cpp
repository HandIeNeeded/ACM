#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;

int cnt[4][N];
long long ans[4][4][N];
char s[N], a[2], b[2];
char str[5] = "chef";

int get(char c) {
	if (c == 'c') return 0;
	else if (c == 'h') return 1;
	else if (c == 'e') return 2;
	else return 3;
}

void init() {
	int n = strlen(s);
	for (int i = n - 1; i >= 0; i --) {
		int x = get(s[i]);
		REP(j, 4) {
			cnt[j][i] = cnt[j][i + 1] + (j == x);
		}
	}
	REP(i, 4) {
		REP(j, 4) if (i != j) {
			for (int k = n - 1; k >= 0; k--) {
				if (s[k] == str[i]) {
					ans[i][j][k] = cnt[j][k] + ans[i][j][k + 1];
				}
				else {
					ans[i][j][k] = ans[i][j][k + 1];
				}
			}
		}
	}
}

long long getans(int a, int b, int l, int r) {
	long long res = 0;
	res += ans[a][b][l] - ans[a][b][r + 1];
	res -= 1LL * (cnt[a][l] - cnt[a][r + 1]) * cnt[b][r + 1];
	return res;
}

int main() {
	//freopen("E.in", "r", stdin);
	scanf("%s", s);
	init();
	int q;
	scanf("%d", &q);
	while (q--) {
		int ql, qr;
		scanf("%s %s %d %d", a, b, &ql, &qr);
		ql--, qr--;
		int x = get(a[0]), y = get(b[0]);
		printf("%lld\n", getans(x, y, ql, qr));
	}
	return 0;
}
