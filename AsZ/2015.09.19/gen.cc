#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const int M = 256;
int tmp[N];
char s[3] = "SP";

string get(int x) {
    string ans;
    REP(i, x) {
        ans += char('0' + (rand() & 1));
    }
    return ans;
}

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = 5, m = 5;
        cout << n << ' ' << m << endl;
        REPP(i, 1, n) {
            cout << rand() % 16 << ' ';
        }
        cout << endl;
        REP(i, m) {
            cout << s[rand() & 1] << ' ' << get(rand() % 7 + 2) << ' ' << rand() % 100 + 1 << endl;
        }
    }
	return 0;
}

