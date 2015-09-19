#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e6 + 5;
char s[N];

int main() {
#ifdef HOME
    //freopen("6.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s), nn = n;
        int start = 0;
        REP(i, nn) {
            if (s[i] == 'f') {
                s[n++] = 'f';
                start++;
            }
            else {
                s[n] = 0;
                break;
            }
        }
        if (n == 2 * nn) {
            printf("Case #%d: %d\n", ca++, (nn + 1) / 2);
            continue;
        }
        //cout << s << endl;
        int bad = 0;
        int ans = 0;
        for (int i = start; i < n; i++) {
            int j = i + 1;
            while (j < n && s[j] == 'f') j++;
            if (j - i - 1 <= 1) {
                bad = 1;
                break;
            }
            ans++;
            i = j - 1;
        }
        if (bad) {
            ans = -1;
        }
        printf("Case #%d: %d\n", ca++, ans);
    }


    return 0;
}

