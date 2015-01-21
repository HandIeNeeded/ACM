#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)

using namespace std;

const int N = 100005;

multiset<pair<int, int> > s;
pair<int, int> p[N];

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REP(i, n) {
			cin >> p[i].first >> p[i].second;
		}
		s.clear();
		if (ca > 1) cout << endl;
		cout << "Case #" << ca++ << ":" << endl;
		REP(i, n) {
			auto pos = s.lower_bound(p[i]);
			if (pos == s.begin() || (--pos) -> second > p[i].second) 
				s.insert(p[i]);
			pos = s.upper_bound(p[i]);
			while (pos != s.end() && pos -> second > p[i].second) {
				s.erase(pos++);
			}
			cout << s.size() << endl;
		}
	}

	return 0;
}

