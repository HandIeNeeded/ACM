#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

map<string, vector<string>> mp;

const string bmail = "bmail.com";

string get(string s) {
    string res;
    string suffix;
    int pos = s.find('@');
    //cout << s << ' ' << pos << endl;
    assert(pos != string :: npos);
    suffix = s.substr(pos + 1);
    REP(i, suffix.size()) if (isalpha(suffix[i])) {
        suffix[i] = tolower(suffix[i]);
    }
    string prefix;
    if (suffix == bmail) {
        int key = s.find('+');
        if (key == string :: npos) key = pos;
        REP(i, key) {
            if (s[i] == '.') continue;
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            }
            prefix += s[i];
        }
        prefix += '@';
    }
    else {
        REP(i, pos + 1) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            }
            prefix += s[i];
        }
    }
    return prefix + suffix;
}

const int N = 105;
char s[N];

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        scanf("%s", s);
        string tmp = string(s);
        //cout << "hehe" << ' ' << s << endl;
        tmp = get(tmp);
        //cout << tmp << endl;
        mp[tmp].push_back(string(s));
    }
    printf("%d\n", int(mp.size()));
    //cout << mp.size() << endl;
    for (auto &now: mp) {
        printf("%d", int(now.second.size()));
        for (auto &str: now.second) {
            printf(" %s", str.c_str());
        }
        puts("");
    }
    return 0;
}


