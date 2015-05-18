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

int main() {
    ios :: sync_with_stdio(0);
	freopen("B.in", "r", stdin);
    scanf("%d", &n);
    f[0][0] = 1;
    f[1][0] = 1;
    f[1][1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		f[i][0] = 2 * (i - 1) * 2 * f[i - 2][0] + 2 * (i - 1) * f[i - 1][1] + f[]
	}
    return 0;
}


