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

vector< pair<long long , long long> > inci;
priority_queue<long long, vector<long long>, greater<int> > fic;

int main() {
    ios :: sync_with_stdio(0);

	freopen("pulp.in", "r", stdin);
//	freopen("pulp.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		long long X = x, Y = y;
		inci.push_back(make_pair(X, Y));
	}
	sort(inci.begin(), inci.end());
//	for (int i = 0; i < n; i++)
//		printf("%d %d\n", inci[i].first, inci[i].second);
	long long ans = 0;
	long long now = inci.front().first;
	fic.push(inci.front().second);
	for (int i = 1; i < n; i++)
	{
		long long nex = inci[i].first;
		while (fic.size() && now + fic.top() <= nex)
		{
			now += fic.top();
			ans += now;
			fic.pop();
		}
		if (fic.size())
		{
			long long tmp = fic.top() - nex + now;
			fic.pop();
			fic.push(tmp);
		}
		fic.push(inci[i].second);
		now = nex;
	}
	while (fic.size())
	{
		now += fic.top();
		ans += now;
		fic.pop();
	}
	cout << ans << endl;;

    return 0;
}



