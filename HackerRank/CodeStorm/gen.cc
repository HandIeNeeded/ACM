#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = rand() % 100 + 2;
        int m = rand() % (n - 1) + 1;
        vector<int> a;
        REP(i, m) {
            a.push_back(rand() % n + 1);
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        m = a.size();
        cout << n << ' ' << m;
        REP(i, m) {
            cout << ' ' << a[i];
        }
        cout << endl;
    }
	return 0;
}

