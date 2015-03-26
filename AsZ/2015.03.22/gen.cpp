#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 200005;
const int M = 5000;
const int MO = 26;
char s[3] = "QC";
string str[N], q[N];
int a[N], b[N];

int main() {
	ios :: sync_with_stdio(0);
	srand(time(0) % clock());
	//freopen("tmp.in", "w", stdout);

	int n = 50;
	cout << n << endl;
	REPP(i, 1, n) {
		if (i == 1) a[1] = 0;
		else a[i] = rand() % (i - 1) + 1;
		int cnt = rand() % 5;
		cout << a[i] << ' ' << cnt << endl;
		REP(j, cnt) {
			cout << char('a' + rand() % MO) << '=' << char('a' + rand() % 20) << endl;
		}
	}
	int q;
	q = rand() % 20 + 1;
	cout << q << endl;
	REP(i, q) {
		cout << rand() % n + 1 << ' ' << char('a' + rand() % MO) << endl;
	}

	return 0;
}


