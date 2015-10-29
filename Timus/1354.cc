#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e4 + 5;
const int C = 128;

namespace PT{
	struct Node{
		Node *ch[C], *suffix;
		int length;
	}bar[N], *foo, *null, *last, *odd, *even;
	char s[N];
	int n, cnt;

	void init() {
		odd = bar, even = last = odd + 1, foo = even + 1;
		MST(odd->ch, 0), MST(even->ch, 0);
		odd->suffix = even->suffix = odd;
		odd->length = -1, even->length = 0;
		n = cnt = 0;
	}

	Node* New_Node(int x) {
		MST(foo->ch, 0), foo->length = x;
		return foo++;
	}

	Node* get(Node *p) {
		while (n - p->length - 2 < 0 || s[n - p->length - 2] != s[n - 1]) p = p->suffix;
		return p;
	}

	bool add(char c) {
		s[n++] = c;
		Node *p = get(last);
		int x = c;
		if (!p->ch[x]) {
			last = New_Node(p->length + 2);
			if (last->length == 1) {
				last->suffix = even;
			}
			else {
				last->suffix = get(p->suffix)->ch[x];
			}
			p->ch[x] = last;
			cnt++;
			return 1;

		}
		else {
			last = p->ch[x];
			return 0;
		}
	}
};

char s[N];

int main() {
	ios :: sync_with_stdio(0);
	cin >> s;
	int n = strlen(s);
	PT::init();
	REP(i, n) {
		PT::add(s[i]);
	}
	cout << s;
	if (PT::last->length == n) PT::last = PT::last->suffix;
	for (int i = n - PT::last->length - 1; i >= 0; i--) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}
