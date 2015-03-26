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

vector<pair<int, pair<int, int> > > v[26];
const int N = 1e5 + 5;
char s[N];

int main() {
	//freopen("M.in", "r", stdin);
	ios :: sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	getchar();
	int dep = 0;
	REPP(row, 1, n) {
		gets(s);
		int len = strlen(s);
		REP(i, len) {
			if (s[i] == ' ') continue;
			else if (s[i] == '{') {
				dep++;
			}
			else if (s[i] == '}') {
				REP(j, 26) if (v[j].size() && (int) v[j].back().first == dep) {
					v[j].pop_back();
				}
				dep--;
			}
			else {
				int x = s[i] - 'a';
				if (v[x].size()) {
					int a, b;
					tie(a, b) = v[x].back().second;
					cout << row << ':' << i + 1 << ':' << ' ' << "warning: shadowed declaration of " << char(x + 'a') << ','
						 << " the shadowed position is " << a << ':' << b + 1 << endl;
				}
				v[x].push_back({dep, {row, i}});
			}
		}
	}

	return 0;
}

