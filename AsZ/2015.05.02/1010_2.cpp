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
#define MAXN 1010

using namespace std;

long long a[MAXN], L[MAXN], R[MAXN], ansi[MAXN];

const double INF = 5e18;
//const long long INF =

long long gcd(long long a, long long b)
{
	if (!a || !b) return a + b;
	return gcd(b, b % a);// should be a % b
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N, Q;
		cin >> N >> Q;
		for (int i = 1; i <= N; ++i)
			a[i] = 1;
		int ok = 1;
		for (int i = 1; i <= Q; ++i)
		{
			cin >> L[i] >> R[i] >> ansi[i];
            for (int j = L[i]; j <= R[i] && ok; ++j)
			{
				long long tmp = gcd(ansi[i], a[j]);
				double lim = 1.0 * (a[j] / tmp) * ansi[i];
				if (lim >= INF)
				{
					ok = 0;
					break;
				}
                a[j] = a[j] / tmp * ansi[i];
			}
		}

        for (int i = 1; i <= Q && ok; ++i)
        {
            long long tmpGcd = a[L[i]];
            for (int j = L[i] + 1; j <= R[i]; ++j)
				tmpGcd = gcd(tmpGcd, a[j]);
            if (tmpGcd != ansi[i]) ok = 0;
        }

        if (ok)
			for (int i = 1; i <= N; ++i)
			{
				cout << a[i];
				if (i == N) cout <<endl;
				else cout << ' ';
			}
		else cout << "Stupid BrotherK!" << endl;

	}
	return 0;
}

