#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
long long s[N];
int n;

long long calc(int i) {
	return 1LL * (n - i) * (n - i + 1) / 2;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("C.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		long long tmp;
		cin >> n >> tmp;
		REPP(i, 0, n - 1) {
			s[i] = calc(i) + i;
		}
		reverse(s, s + n);
		//REPP(i, 0, n - 1) {
		//	 cout << s[i] << ' ';
		//}
		//cout << endl;
		int pos = upper_bound(s, s + n, tmp) - s - 1;
		cout << n - 1 - pos << endl;
	}

	return 0;
}
