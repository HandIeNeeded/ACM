#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 10000;
vector<int> f[N];
string str[N];
int ans[N];

void shift(string &s) {
	char c = s[0];
	s = s.substr(1);
	s += c;
}

bool cover(int x, int n) {
	REPP(i, 1, n) {
		if (find(f[x].begin(), f[x].end(), i) == f[x].end()) {
			return 0;
		}
	}
	return 1;
}

void brute_force(int n) {
	int high = __builtin_clz(n);
	bitset<32> tmp(n);
	string s;
	s = tmp.to_string<char, string :: traits_type, string :: allocator_type>();
	s = s.substr(high);
	REP(i, 32 - high) {
		f[n].push_back(stoi(s, nullptr, 2));
		shift(s);
	}
	str[n] = s;
	for (auto &x: f[n - 1]) {
		f[n].push_back(x);
	}
	sort(f[n].begin(), f[n].end());
	f[n].resize(unique(f[n].begin(), f[n].end()) - f[n].begin());
	int &res = ans[n];
	res = n;
	while (cover(res - 1, n)) res--;
	cout << n << '\t' << ans[n] << '\t' << str[n] << "\t\t" << str[ans[n]] << endl;
	//cout << "id ans binary" << endl << n << ' ' << ans[n] << ' ' << str[ans[n]] << endl;
}

const int K = 512;

int main() {
    ios :: sync_with_stdio(0);
	REPP(i, 1, K) {
		brute_force(i);
	}
    return 0;
}

