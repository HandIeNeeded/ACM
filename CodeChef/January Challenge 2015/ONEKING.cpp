#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
using namespace std;
 
const int INF = 0x3f3f3f3f;
const int N = 2005;
vector<int> l[N], r[N];
pair<int, int> p[100005];
bool cancle[100005];
 
int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int mx = -1;
		REPP(i, 1, n) {
			int x, y;
			cin >> x >> y;
			l[x].push_back(i);
			r[y].push_back(i);
			p[i] = make_pair(x, y);
			mx = max(mx, y);
		}
		int ans = 0;
		vector<int> now;
		REPP(i, 0, mx) {
			bool find = 0;
			REP(j, r[i].size()) {
				int x = r[i][j];
				if (cancle[x]) {
					continue;
				}
				else {
					ans++;
					find = 1;
					REP(k, now.size()) {
						int y = now[k];
						cancle[y] = 1;
					}
					REP(k, l[i].size()) {
						int y = l[i][k];
						cancle[y] = 1;
					}
					now.clear();
				}
			}
			if (!find) {
				REP(j, l[i].size()) {
					now.push_back(l[i][j]);
				}
			}
		}
		cout << ans << endl;
		REPP(i, 1, n) cancle[i] = 0;
		REPP(i, 0, mx) l[i].clear(), r[i].clear();
	}
 
	return 0;
}
