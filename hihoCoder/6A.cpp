#include <bits/stdc++.h>

#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define MST(a, b) memset(a, b, sizeof(a))

#define SL(a) strlen(a)
#define RS(s) scanf("%s", (s))
#define PI(r) printf("%d\n", (r))
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)

#define L (x << 1)
#define R ((x << 1) | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))

#define EPS 1e-7
#define INF 0x3f3f3f3f
#define LIM (1ll << 60)

using namespace std;

int n, m;
const int N = 205;
string s, tmp, str = "marshtomp", r = "fjxmlhx";

int main(){
	// freopen("cf.in", "r", stdin);
	//freopen("cf.ans", "w", stdout);
	//ios :: sync_with_stdio(false);

	int t, x, y, z, ca = 1;

	while (getline(cin, s) > 0) {
		tmp = s;
		REP(i, s.size()) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				tmp[i] = s[i] - 'A' + 'a';
			}
		}
		string ans;
		REP(i, s.size()) {
			int bad = 0;
			REP(j, 9) {
				if (tmp[i + j] != str[j]) {
					bad = 1;
					break;
				}
			}
			if (bad) {
				ans += s[i];
			}
			else {
				ans += r;
				i += 8;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
