#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

LL sqr(int x) {
	return 1LL * x * x;
}

bool good(LL x) {
	int rt = int(sqrt(x + 0.5));
	if (sqr(rt - 1) == x) rt--;
	if (sqr(rt + 1) == x) rt++;
	return sqr(rt) == x;
}

bool good2(LL x) {
	for (int i = 2; 1LL * i * i <= x; i++) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) x /= i, cnt++;
			if (i % 4 == 3 && (cnt & 1)) return 0;
		}
	}
	return x % 4 != 3;
}

bool good4(LL x) {
	while (x % 4 == 0) x /= 4;
	if (x % 8 == 7) return 1;
	return 0;
}

int main() {
    ios :: sync_with_stdio(0);
	LL n;
	cin >> n;
	if (good(n)) {
		cout << 1 << endl;
	}
	else if (good2(n)) {
		cout << 2 << endl;
	}
	else if (good4(n)) {
		cout << 4 << endl;
	}
	else {
		cout << 3 << endl;
	}

    return 0;
}

