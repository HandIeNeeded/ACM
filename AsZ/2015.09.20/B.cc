#include <bits/stdc++.h>
#include <ext/rope>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;
using namespace __gnu_cxx;

rope<char> a, clip;
string s;

int main() {
    ios::sync_with_stdio(0);
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        a.clear(), clip.clear();
        int n;
        cin >> n >> s;
        int pos = 0;
        int mode = 0; //0 insert 1 replace
        int copy = 0, mark = 0;
        REP(i, s.size()) {
            if (s[i] == 'L') {
                if (pos) {
                    pos--;
                }
            }
            else if (s[i] == 'R') {
                if (pos < int(a.size())) {
                    pos++;
                }
            }
            else if (s[i] == 'S') {
                //if (copy) {
                    copy = 0;
                //    int tmp = pos;
                //    if (mark > pos) swap(mark, pos);
                //    clip = a.substr(mark, pos - mark);
                //    pos = tmp;
                //}
                mode ^= 1;
            }
            //need check
            else if (s[i] == 'D') {
                if (copy) {
                    if (mark > pos) swap(pos, mark);
                    a.erase(mark, pos - mark);
                    pos -= pos - mark;
                    copy = 0;
                }
                else if (pos < int(a.size())) {
                    a.erase(pos);
                }
            }
            else if (s[i] == 'B') {
                //if (copy) {
                    copy = 0;
                //    int tmp = pos;
                //    if (mark > pos) swap(pos, mark);
                //    clip = a.substr(mark, pos - mark);
                //    pos = tmp;
                //}
                if (pos > 0 && a.size()) {
                    a.erase(pos - 1);
                    pos--;
                }
            }
            else if (s[i] == 'C') {
                if (copy) {
                    int tmp = pos;
                    if (mark > pos) swap(mark, pos);
                    clip = a.substr(mark, pos - mark);
                    pos = tmp;
                }
                else {
                    mark = pos;
                }
                copy ^= 1;
            }
            else if (s[i] == 'V') {
                if (clip.size()) {
                    if (mode && pos + int(clip.size()) < n) {
                        int mx = max(a.size() - pos, clip.size());
                        a.erase(pos, mx);
                        a.insert(pos, clip.begin(), clip.end());
                        pos += clip.size();
                    }
                    else if (!mode && int(a.size()) + int(clip.size()) <= n) {
                        a.insert(pos, clip.begin(), clip.end());
                        pos += clip.size();
                    }
                }
                copy = 0;
            }
            else {
                //if (copy) {
                //    int tmp = pos;
                //    if(mark > pos) swap(pos, mark);
                //    clip = a.substr(mark, pos - mark);
                //    pos = tmp;
                    copy = 0;
                //}
                if (mode) {
                    if (pos < int(a.size()) || int(a.size()) + 1 <= n) {
                        a.replace(pos, s[i]);
                        pos++;
                    }
                }
                else {
                    if (int(a.size()) + 1 <= n) {
                        a.insert(pos, s[i]);
                        pos++;
                    }
                }
            }
            //cout << a << ' ' << pos << ' ' << a[pos] << ' ' << mode << ' ' << clip << endl;
        }
        if (a.size() == 0) {
            cout << "NOTHING" << endl;
        }
        else {
            cout << a << endl;
        }
    }
    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <ext/rope>
using namespace std;
using __gnu_cxx::crope;

const int MAXN = 10010;

char op[MAXN];
crope txt, board;
int T, m, cbeg, pos, mode;

void change(char c) {
    int l = txt.length(), bl = board.length();
    if(c == 'L') {
        pos = max(0, pos - 1);
    } else if(c == 'R') {
        pos = min(l, pos + 1);
    } else if(c == 'S') {
        mode ^= 1;
        cbeg = -1;
    } else if(c == 'D') {
        if(cbeg == -1) {
            if(pos < l) txt.erase(pos, 1);
        } else {
            if(cbeg < pos) txt.erase(cbeg, pos - cbeg);
            if(pos < cbeg) txt.erase(pos, cbeg - pos);
            cbeg = -1;
        }
    } else if(c == 'B') {
        if(pos > 0 && l > 0) {
            txt.erase(pos - 1, 1);
            pos--;
        }
        cbeg = -1;
    } else if(c == 'C') {
        if(cbeg == -1) {
            cbeg = pos;
        } else {
            if(cbeg < pos) board = txt.substr(cbeg, pos - cbeg);
            if(pos < cbeg) board = txt.substr(pos, cbeg - pos);
            if(cbeg == pos) board.clear();
            cbeg = -1;
        }
    } else if(c == 'V') {
        if(mode == 0 && bl + l <= m) {
            txt = txt.substr(0, pos) + board + txt.substr(pos, l - pos);
            pos += bl;
        }
        if(mode == 1 && pos + bl < m) {
            txt.erase(pos, min(bl, l - pos));
            txt = txt.substr(0, pos) + board + txt.substr(pos, l - pos);
            pos += bl;
        }
        cbeg = -1;
    } else {
        if(mode == 0 && l < m) {
            txt = txt.substr(0, pos) + c + txt.substr(pos, l - pos);
            pos++;
        }
        if(mode == 1 && pos < m) {
            if(pos < l) txt.erase(pos, 1);
            txt = txt.substr(0, pos) + c + txt.substr(pos, l - pos);
            pos++;
        }
        cbeg = -1;
    }
    //printf("#debug %c %s\n", c, txt.c_str());
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%s", &m, op);
        txt.clear();
        board.clear();
        cbeg = -1;
        pos = 0;
        mode = 0;
        for(int i = 0; op[i]; ++i)
            change(op[i]);
        if((int)txt.length() == 0) puts("NOTHING");
        else printf("%s\n", txt.c_str());
    }
}
