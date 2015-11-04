#include <cstdio>
#include <cstring>

const int MX = 100005;
char s[MX], t[MX];
int m, n;

bool test() {
	int i, j;
	
	for (j = 1; j < n; j++) {
		if (t[j] != t[0]) break;
	}
	for (i = 0; i < j; i++) {
		if (s[i] != t[i]) return 0;
	}
	while (i < m) {
		for (; j < n; j++) {
			if (t[j] == s[i]) break;
		}
		if (j == n) return 0;
		i++, j++;
	}
	return 1;
}

int main() {
	int tc;
	
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", s, t);
		m = strlen(s), n = strlen(t);
		puts(test() ? "Yes" : "No");
	}
	return 0;
}
