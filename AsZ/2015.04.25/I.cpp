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
#define LL long long

using namespace std;

string s;

LL get(string s) {
	LL ans = 0;
	REP(i, s.size()) {
		ans = 10 * ans + s[i] - '0';
	}
	return ans;
}

LL pow_mod(LL x, int y) {
	LL ans = 1;
	REP(i, y) ans *= x;
	return ans;
}

LL lcm(LL x, LL y) {
	return x / __gcd(x, y) * y;
}

int main() {
	//freopen("I.in", "r", stdin);
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		cin >> s;
		s = '0' + s;
		string p1, p2;
		LL a, b;
		int pos = s.find('.');
		if (pos == (string :: npos)) {
			a = get(s), b = 1;
		}
		else {
			p1 = s.substr(0, pos);
			p2 = s.substr(pos + 1);
			//cout << p1 << ' ' << p2 << endl;
			pos = p2.find('(');
			if (pos == (string :: npos)) {
				a = get(p2), b = pow_mod(10LL, p2.size());
				LL dd = __gcd(a, b);
				a /= dd, b /= dd;
			}
			else {
				string p3 = p2.substr(pos + 1), p4 = p2.substr(0, pos);
				p3.pop_back();
				//cout << p3 << ' ' << p4 << endl;
				a = get(p3), b = pow_mod(10LL, p3.size()) - 1;
				LL dd = __gcd(a, b);
				a /= dd, b /= dd;
				if (p4.size()) {
					b *= pow_mod(10LL, p4.size());
					dd = __gcd(a, b);
					a /= dd, b /= dd;
					//cout << a << ' ' << b << endl;
					LL c = get(p4), d = pow_mod(10LL, p4.size());
					LL dd = __gcd(c, d);
					c /= dd, d /= dd;
					//cout << c << ' ' << d << endl;
					LL aa = a, bb = b;
					dd = __gcd(b, d);
					b = lcm(b, d);
					a = d / dd * aa + bb / dd * c;
				}
				dd = __gcd(a, b);
				a /= dd, b /= dd;
			}
			a += get(p1) * b;
		}
		cout << "Case #" << ca++ << ": " << a << '/' << b << endl;
	}

	return 0;
}

