#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 105;
string str[8] = {"author", "title", "journal", "publisher", "year", "volume", "number", "pages"};

struct Name{
    vector<string> name;
};//一个作者的名字

struct Info{
    vector<Name> author;//所有作者
    string title, journal, publisher;
    int year, number, pages, volume, st, ed, type; //book 0, article 1
}p[N];

bool cmp1(const Name &a, const Name &b) {
    int c = min(a.name.size(), b.name.size());
    REP(i, c) {
        if (a.name[i] != b.name[i]) {
            return a.name[i] < b.name[i];
        }
    }
    return int(a.name.size()) == c;
}

bool cmp(const Info &a, const Info &b) {
    int c = min(a.author.size(), b.author.size());
    REP(i, c) {
        int n = a.author[i].name.size(), m = b.author[i].name.size();
        int d = min(n, m);
        REP(j, d) {
            if (a.author[i].name[j] != b.author[i].name[j]) {
                return a.author[i].name[j] < b.author[i].name[j];
            }
        }
        if (n != m) {
            return n < m;
        }
    }
    if (a.author.size() != b.author.size()) {
        return a.author.size() < b.author.size();
    }
    else {
        if (a.title == b.title) {
            return a.volume < b.volume;
        }
        return a.title < b.title;
    }
}

void rotate(Name &a) {
    vector<string> b = a.name;
    REPP(i, 1, a.name.size() - 1) {
        a.name[i] = b[i - 1];
    }
    a.name[0] = b[a.name.size() - 1];
}

void book(Info a){
   REP(i, a.author.size()) {
       int n = a.author[i].name.size();
       cout << a.author[i].name[0] << ' ';
       REPP(j, 1, n - 1) {
           cout << a.author[i].name[j][0] << ".";
           if (j < n - 1) {
               cout << ' ';
           }
       }
       if (i < int(a.author.size()) - 1) {
           cout << ", ";
       }
   }
   cout << " " << a.title;
   if (a.volume != -1) {
       cout << ", Vol. " << a.volume;
   }
   cout << " -- " << a.publisher << ", " << a.year << endl;
}

void article(Info a) {
   REP(i, a.author.size()) {
       int n = a.author[i].name.size();
       cout << a.author[i].name[0] << ' ';
       REPP(j, 1, n - 1) {
           cout << a.author[i].name[j][0] << ".";
           if (j < n - 1) {
               cout << ' ';
           }
       }
       if (i < int(a.author.size()) - 1) {
           cout << ", ";
       }
   }
   cout << " " << a.title << " // " << a.journal;
   if (a.volume != -1) {
       cout << ", " << a.volume;
   }
   if (a.number != -1) {
       cout << " (" << a.number << ")";
   }
   cout << " -- " << a.year;
   if (a.pages != -1) {
       cout << " -- ";
       if (a.pages == 1) {
           cout << "p. " << a.st;
       }
       else {
           cout << "pp. " << a.st << "--" << a.ed;
       }
   }
   cout << endl;
}

int now = 0;

string getword() {
    char c;
    string ans;
    while ((c = getchar()), isspace(c) && c != EOF);
    if (c == EOF) return ans;
    ans += c;
    while ((c = getchar()), !isspace(c) && c != EOF) ans += c;
    //cout << now++ << ' ' << ans << endl;
    return ans;
}

string getstring() {
    char c;
    string ans;
    while ((c = getchar()), isspace(c) && c != EOF);
    if (c == EOF) return ans;
    assert(c == '\"');
    while ((c = getchar()), c != EOF && c != '\"') ans += c;
    assert(c == '\"');
    return ans;
}

string getcomma() {
    char c;
    string ans;
    while ((c = getchar()), isspace(c) && c != EOF);
    if (c == EOF) return ans;
    assert(c == ',' || c == '}');
    ans += c;
    return ans;
}

string getstringfromstring(const string &buf, int &pos) {
    char c;
    string ans;
    while ((c = buf[pos++]), isspace(c) && pos < int(buf.size()));
    if (pos == int(buf.size())) return ans;
    ans += c;
    while ((c = buf[pos]), !isspace(c) && pos < int(buf.size())) ans += c, pos++;
    return ans;
}

int mystoi(string s) {
    int n = s.size(), ans = 0;
    REP(i, n) {
        ans = 10 * ans + s[i] - '0';
    }
    return ans;
}

void print(Name &a) {
    REP(i, a.name.size()) {
        cout << a.name[i] << ' ';
    }
    cout << endl;
}

void print(Info &a) {
    REP(i, a.author.size()) print(a.author[i]);
    cout << "title: " << a.title << endl;
    cout << "journal: " << a.journal << endl;
    cout << "publisher: " << a.publisher << endl;
    cout << "year: " << a.year << endl;
    cout << "volume: " << a.volume << endl;
    cout << "pages: " << a.pages << endl;
    cout << a.st << ' ' << a.ed << endl;
}

Info getInfo() {
    Info ans;
    ans.type = ans.pages = ans.volume = ans.number = -1;
    ans.st = ans.ed = -1;
    string word = getword();
    if (word.size() == 0) return ans;
    assert(word[0] == '@');
    word = word.substr(1);
    assert(word == "book" || word == "article");
    if (word == "book") ans.type = 0;
    else ans.type = 1;
    word = getword();
    assert(word == "{");
    while (word != "}") {
        int find = 0;
        int id = -1;
        word = getword();
        REP(i, 8) {
            if (word == str[i]) {
                id = i;
                find = 1;
                break;
            }
        }
        assert(find);
        word = getword();
        assert(word == "=");
        switch (id) {
            case 0: {
                string buf = getstring();
                //cout << buf << ' ' << "xixi buf" << endl;
                int pos = 0;
                Name tmp;
                while (pos < int(buf.size())) {
                    string tmpname = getstringfromstring(buf, pos);
                    if (tmpname == "and") {
                        ans.author.push_back(tmp);
                        tmp.name.clear();
                    }
                    else {
                        tmp.name.push_back(tmpname);
                    }
                }
                ans.author.push_back(tmp);
                break;
            }
            case 1:
                ans.title = getstring();
                break;
            case 2:
                ans.journal = getstring();
                break;
            case 3:
                ans.publisher = getstring();
                break;
            case 4:
                ans.year = mystoi(getstring());
                break;
            case 5:
                ans.volume = mystoi(getstring());
                break;
            case 6:
                ans.number = mystoi(getstring());
                break;
            case 7: {
                string buf = getstring();
                auto pos = buf.find('-');
                //cout << buf.substr(0, pos) << ' ' << buf.substr(pos + 2) << endl;
                if (pos == string :: npos) {
                    ans.pages = 1;
                    ans.st = ans.ed = mystoi(buf);
                }
                else {
                    ans.st = mystoi(buf.substr(0, pos));
                    ans.ed = mystoi(buf.substr(pos + 2));
                    ans.pages = ans.ed - ans.st + 1;
                }
                break;
            }
            default:
               assert(0);
        }
        word = getcomma();
    }
    //REP(i, ans.author.size()) {
    //    print(ans.author[i]);
    //}
    for (auto &now: ans.author) {
        rotate(now);
    }
    sort(ans.author.begin(), ans.author.end(), cmp1);
    return ans;
}

int main() {
    freopen("bibtex.in", "r", stdin);
    freopen("bibtex.out", "w", stdout);
    ios :: sync_with_stdio(0);
    Info tmp;
    int tot = 0;
    while ((tmp = getInfo()), tmp.type >= 0) {
        p[tot++] = tmp;
    }
    sort(p, p + tot, cmp);
    //REP(i, tot) {
    //    print(p[i]);
    //}
    REP(i, tot) {
        cout << "[" << i + 1 << "] ";
        if (p[i].type) {
            article(p[i]);
        }
        else {
            book(p[i]);
        }
    }
    return 0;
}
