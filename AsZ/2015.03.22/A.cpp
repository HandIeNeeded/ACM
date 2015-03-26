#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
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

const int N = 1e5 + 5;

struct dsu{
	int f[2][N], color[2][N];
	vector<int> edge[N], num[N];

	void init(int n) {
		REP(i, 2) {
			REPP(j, 1, n) {
				f[i][j] = i;
				color[i][j] = 0;
			}
		}
		REPP(i, 1, n) num[i].clear(), num[i].push_back(i);
	}

	int find(int ty, int x) {
		return f[ty][x] == x ? x : f[ty][x] = find(ty, f[ty][x]);
	}

	bool merge(int ty, int x, int y) {
		int fx = find(ty, x), fy = find(ty, y);
		if (fx != fy) {
			if (color[ty][x] == color[ty][y]) {
				if (num[fx].size() < num[fy].size()) {
					for (auto z : num[fx]) {
						color[ty][z] ^= 1;
					}
				}
				else {
					for (auto z : num[fy]) {
						color[ty][z] ^= 1;
					}
				}
			}
			if (num[fx].size() < num[fy].size()) {
				f[ty][fx] = fy;
				for (auto z: num[fx]) {
					num[fy].push_back(z);
				}
			}
			else {
				f[ty][fy] = fx;
				for (auto z: num[fy]) {
					num[fx].push_back(z);
				}
			}
			return 1;
		}
		else {
			if (color[ty][x] ^ color[ty][y]) return 1;
			else return 0;
		}
	}

	void recover(int x, int y) {

	}
}set;

int main() {
	ios :: sync_with_stdio(0);
	cout << endl;
	vector<int> a;


	return 0;
}
