#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == b && a == 0) {
			cout << "Don't Play" << endl;
			continue;
		}
		if (a > b) swap(a, b);
		int x = (a + 1.0) * 2.0 / (1.0 + sqrt(5.0));
		int y = (a + 0.0) * 2.0 / (1.0 + sqrt(5.0));
		if (x == y) {
			cout << "Play" << endl;
		}
		else if (x > y && b == a + x) {
			cout << "Don't Play" << endl;
		}
		else {
			cout << "Play" << endl;
		}
	}
	return 0;
}
