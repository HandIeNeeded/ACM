#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1006;
char s[N], op[3] = "-+";

int get(int &x) {
    if (s[x] == '-') {
        x++;
        return 0;
    }
    else if (s[x] == '+') {
        x++;
        return 1;
    }
    return 1;
}

string getd(int &now) {
    string ans;
    while (isdigit(s[now])) {
        ans += s[now];
        now++;
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);

    cin >> s;
    int n = strlen(s);
    int now = 0;
    int flag = get(now);
    string ans;
    ans += op[flag];
    while (now < n) {
        if (flag) {
            ans += getd(now);
        }
        else {
            string tmp = getd(now);
            ans += tmp[0];
            if (tmp.size() > 1) {
                int now = 1;
                while (now < int(tmp.size()) && tmp[now] == '0') {
                    ans += op[1];
                    ans += '0';
                    now++;
                }
                if (now < int(tmp.size())) {
                    ans += op[1];
                    ans += tmp.substr(now);
                }
            }
        }
        if (now < n) {
            flag = get(now);
            ans += op[flag];
        }
    }
    cout << ans << endl;


    return 0;
}


