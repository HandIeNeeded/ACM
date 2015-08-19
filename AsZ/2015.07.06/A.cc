#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 2e5 + 5;

LL k;
int ans[N], n;

int main() {
	while (scanf("%d%lld", &n, &k), n) {
		int now = 1;
		while (n > 63) {
			ans[now] = now;
			now++, n--;
		}
		int num = now;
		while (now <= n) {
			int start = 0;
			LL tot = bit, bit = 1LL << (n - now - 1);
			while (tot < k && bit) {
				bit >>= 1;
				tot += bit;
				start++;
			}
			num += start;
			REP(i, start) {
				ans[now++] = num;
				num--;
			}
			num += start;


		}
		REPP(i, 1, n) {
			printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}

