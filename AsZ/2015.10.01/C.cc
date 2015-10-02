#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5e6 + 5;
char s[N], r[N];
int fail[N], pre[N], state[N], n, m;

void getFail() {
    fail[0] = fail[1] = 0;
    REPP(i, 1, n - 1) {
        int j = fail[i];
        while (j && s[j] != s[i]) j = fail[j];
        fail[i + 1] = s[j] == s[i] ? j + 1 : 0;
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%s", s) > 0) {
        scanf("%s", r);
        n = strlen(s), m = strlen(r);
        //puts(s), puts(r);
        getFail();
        REP(i, m + 1) pre[i] = i - 1;
        int now = 0;
        REP(i, m) {
            if (r[i] == s[now]) now++;
            else {
                while (now && r[i] != s[now]) now = fail[now];
                now = r[i] == s[now] ? now + 1 : 0;
            }
            //cout << "i now: " << i << ' ' << now << endl;
            state[i] = now;
            if (now == n) {
                int k = i;
                REP(j, n) {
                //cout << "k: " << k << endl;
                    k = pre[k];
                }
                pre[i + 1] = k;
                //cout << "k: " << k << endl;
                now = state[k];
            }
        }
        int length = 0;
        int pos = m;
        while (pre[pos] >= 0) {
            pos = pre[pos];
            s[length++] = r[pos];
        }
        reverse(s, s + length);
        s[length] = 0;
        puts(s);
    }

    return 0;
}


