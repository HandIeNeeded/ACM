#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];

void go(string &r, int ty) {
    if (ty == 1) {
        int x = rand() % 6;
        int y = rand() % 6;
        REP(i, r.size()) {
            if (r[i] == x + '1') {
                r[i] = y + '1';
            }
        }
    }
    else {
        int pos = rand() % r.size();
        int y = rand() % 6;
        r[pos] = '1' + y;
    }
}

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    //cout << t << endl;
    REP(i, t) {
        int n = 110;
        string s, r;
        REP(i, n) {
            s += char('1' + rand() % 6);
        }
        r = s;
        int cnt = rand() % 30 + 5;
        REP(i, cnt) {
            go(r, rand() & 1);
        }
        cout << s << endl << r << endl;
    }
	return 0;
}

