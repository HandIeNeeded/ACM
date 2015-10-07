#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e7 + 5;

int mp[20][26], key[20];
char s[N];

int a[] = {
    1, 2, 'o',
    1, 8, 'p',
    1, 12, 'i',
    2, 3, 'n',
    2, 4, 'u',
    3, 1, 'e',
    4, 5, 't',
    5, 6, 'p',
    5, 2, 'o',
    5, 12, 'i',
    6, 7, 'u',
    7, 16, 't',
    8, 9, 'u',
    9, 10, 't',
    10, 11, 'o',
    11, 1, 'n',
    12, 13, 'n',
    13, 12, 'i',
    13, 2, 'o',
    13, 14, 'p',
    14, 15, 'u',
    15, 16, 't',
    16, 17, 'o',
    16, 12, 'i',
    16, 8, 'p',
    17, 18, 'n',
    17, 4, 'u',
    18, 12, 'i',
    18, 2, 'o',
    18, 8, 'p',
    18, 1, 'e'
};

void init() {
    REP(i, 31) {
        int x = a[3 * i], y = a[3 * i + 1], z = a[3 * i + 2];
        mp[x][z - 'a'] = y;
    }
    key[1] = key[5] = key[13] = key[16] = key[18] = 1;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int start = 1;
        char *r = s;
        while (*r) {
            int c = *r++ - 'a';
            start = mp[start][c];
            //cout << start << endl;
            if (start == 0) break;
        }
        key[start] ? puts("YES") : puts("NO");
    }
    return 0;
}
