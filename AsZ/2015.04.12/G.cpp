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

const int N = 2e5 + 5;
const int C = 26;
char s[N], r[N];

struct Node{
	Node *suffix, *ch[C];
	int len, cnt;
};

struct PT{
	char s[N];
	int n, tot;
	Node bar[N], *foo, *last, *A, *B;
	void init() {
		A = bar, B = bar + 1;
		A->len = -1, B->len = 0;
		A->cnt = B->cnt = 0;
		foo = B + 1, last = B;
		MST(A->ch, 0), MST(B->ch, 0);
		A->suffix = B->suffix = A;
		n = tot = 0;
	}

	Node* New_Node(int x) {
		MST(foo->ch, 0);
		foo->len = x;
		foo->cnt = 0;
		return foo++;
	}

	Node* get(Node* p) {
		while (n - p->len - 2 < 0 || s[n - p->len - 2] != s[n - 1]) p = p->suffix;
		return p;
	}

	bool add(char c) {
		int x = c - 'a'; s[n++] = c;
		Node *p = get(last);
		if (!p->ch[x]) {
			last = New_Node(p->len + 2);
			if (last->len == 1) {
				last->suffix = B;
				last->cnt = 1;
			}
			else {
				last->suffix = get(p->suffix)->ch[x];
				last->cnt = 1;
			}
			p->ch[x] = last;
			return ++tot;
		}
		else {
			last = p->ch[x];
			last->cnt++;
			return 0;
		}
	}

	void prepare() {
		foo--;
		while (foo != B) {
			foo->suffix->cnt += foo->cnt;
			foo--;
		}
		A->cnt = B->cnt = 0;
	}
}S, T;

long long go(Node *a, Node *b) {
	long long ans = 1LL * a->cnt * b->cnt;
	REP(i, 26) if (a->ch[i] && b->ch[i]) ans += go(a->ch[i], b->ch[i]);
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		cin >> s >> r;
		int n = strlen(s);
		S.init();
		REP(i, n) S.add(s[i]);
		n = strlen(r);
		T.init();
		REP(i, n) T.add(r[i]);
		S.prepare(), T.prepare();
		long long ans = 0;
		ans += go(S.A, T.A) + go(S.B, T.B);
		cout << "Case #" << ca++ << ": " << ans << endl;
	}

	return 0;
}

