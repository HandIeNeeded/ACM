#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)

using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t, ca = 1;
	cin >> t;
	while (t--) {
		string number;
		cin >> number;
		int n = number.size();
		int minn = stoi(number), maxx = stoi(number);
		REP(i, n) {
			REPP(j, i + 1, n - 1) {
				if (i == 0 && number[j] == '0') continue;
				string tmp = number;
				swap(tmp[i], tmp[j]);
				minn = min(minn, stoi(tmp));
				maxx = max(maxx, stoi(tmp));
			}
		}
		cout << "Case #" << ca++ << ": " << minn << ' ' << maxx << endl;
	}
	return 0;
}
