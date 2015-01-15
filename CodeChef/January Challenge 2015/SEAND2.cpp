#include <bits/stdc++.h>
 
#define REP(i, a) for(int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
using namespace std;
 
const int N = 105;
int pw[10][1005][N], a[N], b[N], tmp[N], n;
 
void add(int &x, int y, int i) {
	x += y;
	if (x >= a[i]) x -= a[i];
}
 
void init(int len) {
	REP(i, 10) {
		REP(j, n) {
			pw[i][0][j] = i % a[j];
		}
	}
	
	REPP(i, 1, len) {
		REP(j, n) {
			REP(k, 10) {
				pw[k][i][j] = 10 * pw[k][i - 1][j] % a[j];
			}
		}
	}
}
 
int main() {
	ios :: sync_with_stdio(0);
 
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str >> n;
		REP(i, n) cin >> a[i], b[i] = tmp[i] = 0;
		init(str.size());
 
		int cnt = 0, sum = 0;
		REP(k, n) {
			for (int i = 0, j = str.size() - 1; j >= 0; i ++, j --) {
				add(b[k], pw[str[i] - '0'][j][k], k);
			}
			sum += b[k];
		}
 
		clock_t st = clock();
		while (1.0 * (clock() - st) / CLOCKS_PER_SEC < 0.04 && cnt < 10000) {
			int x = rand() % str.size(), y = rand() % str.size();
			if (y == x) {
				y++;
				if (y >= (int) str.size()) y = 0;
			}
			int ans = 0;
			REP(i, n) {
				int d = str.size() - 1 - x;
				tmp[i] = b[i];
				add(tmp[i], pw[str[y] - '0'][d][i], i);
				add(tmp[i], a[i] - pw[str[x] - '0'][d][i], i);
				d = str.size() - 1 - y;
				add(tmp[i], pw[str[x] - '0'][d][i], i);
				add(tmp[i], a[i] - pw[str[y] - '0'][d][i], i);
				ans += tmp[i];
			}
			if (ans < sum) {
				sum = ans;
				swap(str[x], str[y]);
				REP(i, n) b[i] = tmp[i];
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
		cout << str << endl;
	}
	return 0;
}
