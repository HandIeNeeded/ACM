#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const string oper = "+-*/";
const string flag[7] = {"&nbsp;", "<sup>", "</sup>", "<sub>", "</sub>", "<i>", "</i>"};

bool good(char c) {
	return oper.find(c) != string :: npos;
}

void modify(string &s) {
	string ans, res;
	istringstream sin(s);
	while (sin >> ans) {
		res += ans;
	}
	s = res;
}

string solve(string &s) {
	vector<char> op;
	string ans;
	op.push_back('(');
	int pos = 0, n = s.size();
	while (pos < n) {
		if (s[pos] == '$' || isspace(s[pos])) {
			;
		}
		else if (s[pos] == '(' || s[pos] == '{') {
			if (s[pos] == '(') ans += '(';
			op.push_back(s[pos]);
		}
		else if (s[pos] == ')') {
			ans += ')';
			op.pop_back();//'('
		}
		else if (s[pos] == '}') {
			op.pop_back();//'{'
			if (op.back() == '^') ans += flag[2];
			else ans += flag[4];
			op.pop_back();//'^' || '_'
		}
		else if (good(s[pos])) {
			ans += flag[0] + s[pos] + flag[0];
		}
		else if (s[pos] == '^' || s[pos] == '_') {
			op.push_back(s[pos]);
			if (s[pos] == '^') {
				ans += flag[1];
			}
			else {
				ans += flag[3];
			}
		}
		else {
			if (isalpha(s[pos])) {
				string tmp;
				while (pos < n && isalpha(s[pos])) tmp += s[pos++];
				pos--;
				ans += flag[5] + tmp + flag[6];
			}
			else {
				string num;
				while (isdigit(s[pos])) {
					num += s[pos++];
				}
				ans += num;
				pos--;
			}
			if (op.back() == '^' || op.back() == '_') {
				if (op.back() == '^') {
					ans += flag[2];
				}
				else {
					ans += flag[4];
				}
				op.pop_back();
			}
		}
		pos++;
	}
	return ans;
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("340.in", "r", stdin);
	string s;
	while (getline(cin, s)) {
		modify(s);
		//cout << s << endl;
		cout << solve(s) << endl;
	}
    return 0;
}

