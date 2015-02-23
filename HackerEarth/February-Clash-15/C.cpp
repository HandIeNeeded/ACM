#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 8e6 + 5;

char s[N];

int calc(int n) {
	int a = 0, b = 1, c = 0;
	while (a < n && b < n && c < n) {
		int t = s[a + c] - s[b + c];
		if (t == 0) {
			c++;
		}
		else {
			if (t > 0) {
				b += c + 1;
			}
			else {
				a += c + 1;
			}
			if (a == b) b++;
			c = 0;
		}
	}
	return a;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	if (n == 1) {
		puts(s);
		return 0;
	}
	REP(i, n) {
		s[i + n] = s[i];
	}
	int pos = calc(n);
	REP(i, n) {
		putchar(s[pos + i]);
	}
	putchar('\n');

	return 0;
}
