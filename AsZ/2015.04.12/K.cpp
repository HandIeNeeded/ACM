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

const int N = 1e5 + 5;
pair<int, int> p[N];

void init() {
	int a, b;
	srand(time(0) % clock());
	a = rand() % 100 + 1, b = rand() % 100 + 1;
	int d = __gcd(a, b);
	a /= d, b /= d;
	long long A = a, B = b;
	set<int> num;
	num.insert(a), num.insert(b);
	cout << a << ' ' << b << ' ';
	int cnt = 0;
	while (cnt < 10) {
		int pre = num.size();
		int c = abs(a - b);
		cout << c << ' ';
		num.insert(abs(a - b));
		a = b, b = c;
		if ((int) num.size() == pre) cnt++;
		else cnt = 0;
	}
	cout << endl;
	cout << "ans : " << num.size() << endl;
	int tot = 0;
	long long ans = 0;
	while (A % B) {
		long long k = A / B, t = A % B;
		p[tot++] = {A, B};
		ans += k; 
		A = B, B = t;
	}
	ans += A / B;
	ans += 2;
	cout << "myans : " << ans - 1 << endl;
	assert(ans - 1 == int(num.size()));
}

int main() {
	ios :: sync_with_stdio(0);
	long long A, B;
	int t, ca = 1;
	//while (1) init();
	cin >> t;
	while (t--) {
		cout << "Case #" << ca++ << ": ";
		cin >> A >> B;
		if (A == 0 && B == 0) {
			cout << 1 << endl;
		}
		else if (A == 0 || B == 0) {
			cout << 2 << endl;
		}
		else {
			long long ans = 0;
			long long d = __gcd(A, B);
			int tot = 0;
			A /= d, B /= d;
			while (A % B) {
				long long k = A / B, t = A % B;
				p[tot++] = {A, B};
				ans += k; 
				A = B, B = t;
			}
			ans += A / B;
			ans += 2;
			cout << ans - 1 << endl;
		}
	}


	return 0;
}

