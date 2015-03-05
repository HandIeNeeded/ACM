#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
string s;

int main() {
	ios :: sync_with_stdio(0);
	cin >> s;
	int n = s.size();
	int mx = n + 1;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I') {
			pos++;
		}
		else {
			break;
		}
	}
	if (pos == n) {
		REP(i, n + 1) {
			cout << i + 1 << " \n"[i == n];
		}
		return 0;
	}
	else {
		int start = mx - pos; 
		mx -= pos, mx--;
		REP(i, pos) {
			cout << start + i << ' ';
		}
		cout << start + pos;
		int now = pos;
		if (pos == 0) pos++;
		while (now < n) {
			int a = 0, b = 0;
			while (now < n && s[now] == 'D') {
				now++;
				a++;
			}
			while (now < n && s[now] == 'I') {
				now++;
				b++;
			}
			int start = mx - (a + b) + 1;
			int en = mx;
			REPP(i, 1, a - 1) {
				cout << ' ' << en--;
			}
			cout << ' ' << start++;
			REPP(i, 1, b) {
				cout << ' ' << start++;
			}
			mx -= (a + b);
		}
		cout << endl;
	}

	return 0;
}

