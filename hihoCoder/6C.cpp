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

#define EPS 1e-7
#define INF 0x3f3f3f3f
#define LIM (1ll << 60)

using namespace std;

int n, m;

const int N = 100005;
const unsigned LL MOD = 1234567891;
unsigned LL H[N], G[N], pw[N] = {1};

char s[N], r[N];
int ls, lr;

unsigned LL gethash_s(int start, int len) {
	return H[start] - H[start + len] * pw[len];
}	

unsigned LL gethash_r(int start, int len) {
	return G[start] - G[start + len] * pw[len];
}

int findpos(int s1, int s2) {
	int l = 0, r = lr - s2 + 1;
	while (l + 1  < r) {
		int mid = l + r >> 1;
		if (gethash_s(s1, mid) == gethash_r(s2, mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return l;
}	
 
int main(){
	// freopen("cf.in", "r", stdin);
	//freopen("cf.ans", "w", stdout);
	//ios :: sync_with_stdio(false);

	int t, x, y, z, ca = 1;
	int dif;

	REPP(i, 1, N - 1) {
		pw[i] = pw[i - 1] * MOD;
	}
	while (cin >> s >> r) {
		cin >> dif;
		ls = SL(s), lr = SL(r);	
		H[ls] = G[lr] = 0;

		RED(i, ls) {
			H[i] = H[i + 1] * MOD + s[i];
		}
		RED(i, lr) {
			G[i] = G[i + 1] * MOD + r[i];
		}

		int ans = 0;
		REP(i, ls) if (i + lr <= ls){
			int now = 0;
			int s1 = i;
			int s2 = findpos(s1, 0);
			//cout << "ss" << s2 << endl;
			for (int j = 0; j < dif && s2 < lr; ++j) {
				s2++;
				s1 = i + s2;
				if (s2 >= lr) break;
				s2 += findpos(s1, s2);
				//cout << s1 << ' ' << s2 << endl;
			}
			//cout << s2 << endl;
			if (s2 >= lr) {
				ans++;
			}
		} 
		cout << ans << endl;
	}
	
	return 0;
}
