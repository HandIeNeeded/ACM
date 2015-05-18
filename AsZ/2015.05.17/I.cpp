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

const int N = 105;
int dp[N][N][4];
char s[N], r[N];
char mp[4][N], str[5] = "ACGT";

int get(char c) {
    REP(i, 4) if (str[i] == c) return i;
    return -1;
}

int main() {
    ios :: sync_with_stdio(0);
    cin >> s + 1 >> r + 1;
    int n = strlen(s + 1);
    REP(i, 4) {
        REPP(j, 1, n) {
            mp[i][j] = str[(get(s[j]) + i) & 3];
        }
    }
    //REP(i, 4) {
    //    cout << mp[i] + 1 << endl;
    //}
    REPP(i, 1, n) {
        if (s[i] == r[i]) {
            REPP(k, 1, 3) dp[i][i][k] = 1;
            dp[i][i][0] = 0;
        }
        else {
            REP(k, 4) dp[i][i][k] = 1;
        }
    }

    return 0;
}


