#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char s[N], r[N];

int main() {

    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s%s", s, r);
        int a = strlen(s), b = strlen(r);
        int i = 0, j = 0;
        int bad = 0;
        while(i < a && j < b && r[j] == r[j + 1]) {
            if (s[i] != s[i + 1]) {
                bad = 1;
                break;
            }
            i++, j++;
        }
        if (s[i] != r[j]) bad = 1;
        if (bad) {
            puts("No");
            continue;
        }
        while (j < b && i < a) {
            while (j < b && s[i] != r[j]) j++;
            if (j == b) break;
            i++, j++;
        }
        if (i == a) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    return 0;
}
