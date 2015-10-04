#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

map<string, int> cnt;
map<pair<string, string>, int> couple;
set<string> magic;

void modify(string &s) {
    int now = s.size() - 1;
    while (now >= 0 && !isalpha(s[now])) {
        now--;
    }
    s = s.substr(0, now + 1);
    reverse(s.begin(), s.end());
    now = s.size() - 1;
    while (now >= 0 && !isalpha(s[now])) {
        now--;
    }
    s = s.substr(0, now + 1);
    reverse(s.begin(), s.end());
    //cout << s << " hehe" << endl;
    REP(i, s.size()) s[i] = tolower(s[i]);
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif

    ios :: sync_with_stdio(0);

    int n, m, q;
    cin >> n;
    string buffer;
    vector<string> word;
    getline(cin, buffer);
    REPP(i, 1, n) {
        getline(cin, buffer);
        REP(i, buffer.size()) {
            if (!isalpha(buffer[i])) {
                buffer[i] = ' ';
            }
            else buffer[i] = tolower(buffer[i]);
        }
        //cout << buffer << endl;
        stringstream sin(buffer);
        string w;
        while (sin >> w) {
            //modify(w);
            if (w.size()) {
                word.push_back(w);
            }
        }
    }

    cin >> m;
    REP(i, m) {
        string tmp;
        cin >> tmp;
        magic.insert(tmp);
    }

    vector<string> use;
    REP(i, word.size()) {
        if (!magic.count(word[i])) {
            use.push_back(word[i]);
            cnt[word[i]]++;
        }
    }
    //REP(i, use.size()) {
    //    cout << use[i] << ' ';
    //}
    //cout << endl;
    //cout << "hehe" << endl;
    for (int i = 1; i < int(use.size()); i++) {
        string a = use[i], b = use[i - 1];
        if (a < b) swap(a, b);
        couple[make_pair(a, b)]++;
    }

    cin >> q;
    REP(i, q) {
        string a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        assert(cnt.count(a) && cnt.count(b));
        cout << fixed << setprecision(15) << 1.0 * use.size() * use.size() * couple[make_pair(a, b)] / (1.0 * cnt[a] * cnt[b]  * (use.size() - 1)) << endl;
    }

    return 0;
}


