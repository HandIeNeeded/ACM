#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

vector<string> word;

bool test(char s) {
	return s == '-';
}

bool test(string s) {
	return s.size() == 1 && s[0] == '-';
}

void modify(string &s) {
	size_t tmp = s.find('-');
	while (tmp != string :: npos) {
		string now = s.substr(0, tmp);
		if (now.size()) {
			word.push_back(now);
		}
		word.push_back("-");
		s = s.substr(tmp + 1);
		tmp = s.find('-');
	}
	if (s.size()) word.push_back(s);
}

void getw(istringstream &sin) {
	string ans;
	while (sin >> ans) {
		modify(ans);
	}
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("324.in", "r", stdin);
	int t;
	string s;
	cin >> t;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		s = s.substr(1, s.size() - 2);
		istringstream sin(s);
		word.clear();
		getw(sin);
		string ans;
		bool bad = 0;
		REP(i, word.size()) {
			int j = i;
			while (j < int(word.size()) && test(word[j])) j++;
			if (j == i) {
				ans += " " + word[i];
			}
			else if (j == i + 1) {
				if (i == 0 || j == int(word.size())) {
					bad = 1;
					break;
				}
				else {
					ans += '-';
					ans += word[j];
					i = j;
				}
			}
			else {
				int cnt = j - i;
				while (cnt > 3) {
					ans += " --";
					cnt -= 2;
				}
				string tmp;
				REP(i, cnt) tmp += '-';
				ans += " " + tmp;
				i = j - 1;
			}
		}
		if (bad) {
			cout << "error" << endl;
		}
		else {
			if (!ans.size()) {
				cout << "\"\"" << endl;
				continue;
			}
			ans = ans.substr(1);
			if (test(ans[0])) ans = " " + ans;
			if (test(ans[ans.size() - 1])) ans += " ";
			ans = "\"" + ans + "\"";
			cout << ans << endl;
		}
	}
    return 0;
}
