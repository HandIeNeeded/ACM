#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
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

const int N = 205;
const int M = 3e5;

string s[N], sub[M];
map<string, int> mp;
int in[M], n, id;
bool sg[M];

void go_topo() {
	queue<int> q;
	REP(i, id) sg[i] = 1;
	REP(i, n) {
		//cout << s[i] << endl;
		sg[mp[s[i]]] = 0;
		q.push(mp[s[i]]);
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		sg[x] = !sg[x];
		//cout << x << ' ' << sg[x] << endl;
		if (x == 0) break;
		else {
			string tmp = sub[x];
			int y = mp[tmp.substr(1)];
			sg[y] &= sg[x], in[y]--;
			if (in[y] == 0) {
				q.push(y);
			}
			if (tmp.size() > 1) {
				tmp.pop_back();
				y = mp[tmp];
				sg[y] &= sg[x], in[y]--;
				if (in[y] == 0) {
					q.push(y);
				}
			}
		}
	}
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	mp[""] = id++;
	REP(i, n) {
		cin >> s[i];
		REP(j, s[i].size()) {
			REPP(k, j, s[i].size() - 1) {
				string tmp = s[i].substr(j, k - j + 1);
				if (!mp.count(tmp)) {
					sub[id] = tmp;
					mp[tmp] = id++;
				}
			}
		}
	}
	for (auto &now: mp) {
		if (now.second) {
			string tmp = now.first;
			in[mp[tmp.substr(1)]]++;
			if (tmp.size() > 1) {
				tmp.pop_back();
				in[mp[tmp]]++;
			}
		}
	}
	go_topo();
	if (sg[0]) {
		cout << "First" << endl;
		REPP(i, 33, 126) {
			string tmp;
			tmp += char(i);
			if (mp.count(tmp) && sg[mp[tmp]] == 0) {
				cout << char(i);
			}
		}
		cout << endl;
	}
	else {
		cout << "Second" << endl;
	}
    return 0;
}
