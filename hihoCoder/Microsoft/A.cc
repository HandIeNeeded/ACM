#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    string s;
    while (getline(cin, s)) {
        stringstream sin(s);
        string str;
        int first = 0;
        while (sin >> str) {
            REP(i, str.size()) str[i] = tolower(str[i]);
            if (first && isalpha(str[0])) {
                cout << ' ';
            }
            if (first <= 1) {
                str[0] = toupper(str[0]);
                first = 2;
            }
            cout << str;
            if (str.back() == '.') first = 1;
        }
        cout << endl;
    }

    return 0;
}

