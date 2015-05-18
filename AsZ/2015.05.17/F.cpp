#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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

long long work(long long l, long long r)
{
	long long pre = l - 1;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (mid - sqrt(mid) <= pre)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

inline double sqr(double x)
{
	return x * x;
}

int main() {
    ios :: sync_with_stdio(0);

	freopen("nim.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	long long n;
	cin >> n;
	long long m = 2;
	while (m < n)
	{
		double tmp = m;
		tmp = sqr((1.0 + sqrt(1 + 4.0 * tmp)) / 2);
//		cout << tmp << endl;
		long long nex = tmp;
//		cout << nex << endl;
		while (nex - sqrt(nex) <= m)
			nex++;
		if (nex < m)
			exit(0);
		m = nex;
//		cout << m << "!" << endl;
	}
	if (m == n)
		printf("LOSE\n");
	else
		printf("WIN\n");

    return 0;
}


