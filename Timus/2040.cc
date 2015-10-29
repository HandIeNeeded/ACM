#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 5e6 + 5;
const int C = 2;

struct PT{
	struct Node{
		int ch[C], suffix, length;
	}bar[N];
	int foo, null, last, odd, even, n;
	char s[N];

	void init() {
		odd = 1, even = last = odd + 1, foo = even + 1;
		bar[odd].suffix = bar[even].suffix = 1;
		bar[odd].length = -1, bar[even].length = 0;
		n = 0;
	}

	int New_Node(int x) {
		bar[foo].length = x;
		return foo++;
	}

	int get(int p) {
		while (n - bar[p].length - 2 < 0 || s[n - bar[p].length - 2] != s[n - 1]) p = bar[p].suffix;
		return p;
	}

	bool add(char c) {
		n++;
		int p = get(last);
		int x = c - 'a';
		if (!bar[p].ch[x]) {
			last = New_Node(bar[p].length + 2);
			if (bar[last].length == 1) {
				bar[last].suffix = 2;
			}
			else {
				bar[last].suffix = bar[get(bar[p].suffix)].ch[x];
			}
			bar[p].ch[x] = last;
			return 1;
		}
		else {
			last = bar[p].ch[x];
			return 0;
		}
	}
}PT;

int main() {
	ios :: sync_with_stdio(0);
	PT.init();
	cin >> PT.s;
	int i = 0;
	while (PT.s[i]) {
	//REP(i, n) {
		PT.add(PT.s[i]) ? putchar('1') : putchar('0');
		i++;
	}
	return 0;
}
