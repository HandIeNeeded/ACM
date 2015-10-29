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

const int N = 55;
const int M = 25;
const int MO = 1e9 + 7;

char mp[N][M];
int prefix[N][M], suffix[N][M], n, m;
int dp[N][M], cnt[26], op[N][M][26];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int id(char c) {
    if (c == '?') return 26;
    else return c - 'a';
}

void init() {
    REPP(i, 1, m) prefix[0][i] = 1, suffix[n + 1][i] = 26;
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            prefix[i][j] = prefix[i - 1][j];
            if (mp[i][j] == '?') {
                prefix[i][j] = 26LL * prefix[i][j] % MO;
            }
        }
    }
    REPP(j, 1, m) {
        int tot = 0;
        MST(cnt, 0);
        for (int i = n; i >= 1; i--) {
            int x = id(mp[i][j]);
            if (x == 26 || cnt[x]) suffix[i][j] = suffix[i + 1][j];
            else if (!cnt[x]) {
                tot++, cnt[x]++;
                if (tot > 1) suffix[i][j] = 0;
                else suffix[i][j] = 1;
            }
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);
    cin >> n;
    REPP(i, 1, n) cin >> mp[i] + 1;
    m = 0;
    REPP(i, 1, n) m = max(m, strlen(mp[i] + 1));
    init();
    dp[0][0] = 1;
    REPP(i, 1, m) {
        REPP(j, 0, n) {

        }
    }
    cout << dp[n][m] << endl;

    return 0;
}
