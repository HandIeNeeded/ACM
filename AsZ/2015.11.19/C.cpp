#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 30;
char s[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int tot = 0;
    while (scanf("%s", s) > 0) {
        if (s[0] != '*') {
            int n = strlen(s);
            REP(i, n) s[i] = tolower(s[i]);
            cout << "\"" << s << "\", ";
            tot++;
        }
    }
    cout << tot << endl;


    return 0;
}


