#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 10;
const int C = 26;
char s[N];

namespace PT{
	struct Node{
		Node *ch[C], *suffix;
		int len;
	}bar[N], *foo, *last, *odd, *even;
	char s[N];
	int n, cnt;//cnt = foo - bar = count of palindromes, n the number of char added

	void init() {
		odd = bar, even = odd + 1;
		MST(odd->ch, 0), MST(even->ch, 0);
		odd->suffix = odd, even->suffix = odd;
		odd->len = -1, even->len = 0;
		foo = even + 1, last = even;
		n = 0, cnt = 0;
	}

	Node* New_Node(int x) {
		MST(foo->ch, 0), foo->suffix = NULL;
		foo->len = x;
		return foo++;
	}

	int index(char c) {
		return c - 'a';
	}

	Node* get(Node *p) {
		while (n - p->len - 2 < 0 || s[n - p->len - 2] != s[n - 1]) p = p->suffix;
		return p;
	}

	bool add(char c) {
		int x = index(c); s[n++] = c;
		Node *p = get(last);
		if (!p->ch[x]) {
			last = New_Node(p->len + 2);
			if (last->len == 1) {
				last->suffix = even;
			}
			else last->suffix = get(p->suffix)->ch[x];
			p->ch[x] = last;
			cnt++;
			return 1;
		}
		else {
			last = p->ch[x];
			return 0;
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		cin >> s;
		int n = strlen(s);
		int ans = 0;
		PT::init();
		REP(i, n) {
			ans += PT::add(s[i]);
			//cout << ans << endl;
		}
		cout << "Case #" << ca++ << ": " << PT::cnt << endl;
	}

	return 0;
}

