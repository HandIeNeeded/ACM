#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e6 + 5;
const int M = 5;
int type[N], lvl[N];
vector<int> id[2];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = rand() % M + 1, m = rand() % M + 1;
        REP(i, n) {
            type[i + 1] = rand() & 1;
            id[type[i + 1]].push_back(i + 1);
        }
        if (!id[0].size()) {
            n++;
            type[n] = 0;
            id[0].push_back(n);
        }
        if (!id[1].size()) {
            n++;
            type[n] = 1;
            id[1].push_back(n);
        }
        cout << n << ' ' << m << endl;
        REP(i, n) {
            cout << type[i + 1] << ' ' << (lvl[i + 1] = rand() % 6 + 1) << ' ' << rand() % 2000 << endl;
        }
        REP(i, m) {
            int ty = rand() % 3;
            int L = rand() % 11 + 2;
            vector<int> tmp;
            cout << L;
            tmp.push_back(rand() % 2000);
            tmp.push_back(ty);
            if (ty) {
                if (ty == 1) {
                    tmp.push_back(rand() % (L - 1) + 1);
                }
                else {
                    int x = id[0][rand() % id[0].size()], y = id[1][rand() % id[1].size()];
                    tmp[0] = lvl[x] + lvl[y];
                    assert(tmp[0] <= 12);
                    tmp.push_back(x), tmp.push_back(y);
                }
            }
            REP(i, tmp.size()) {
                cout << ' ' << tmp[i];
            }
            cout << endl;
        }
    }
	return 0;
}

