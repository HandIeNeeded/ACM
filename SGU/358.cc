#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
	vector<int> a[3], b;
	REP(i, 3) {
		REP(j, 3) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
		sort(a[i].begin(), a[i].end());
		b.push_back(a[i][1]);
	}
	sort(b.begin(), b.end());
	cout << b[1] << endl;

    return 0;
}

