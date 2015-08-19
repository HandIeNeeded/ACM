#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int M = 100005;

struct Edge{
	int x, y, val, id;
}e[M];
int n, m;
LL sum[N];
bool use[M];
vector<int> id[N];
int degree[N], tmp[N], val[M];

bool cmp(int i, int j) {
	return degree[i] > degree[j];
}

bool cmp2(int i, int j) {
	return sum[e[i].x ^ e[i].y ^ 1] > sum[e[j].x ^ e[j].y ^ 1];
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("flights.in", "r", stdin);
	freopen("flights.out", "w", stdout);
	
	while (cin >> n >> m, n | m) {
		REPP(i, 1, m) use[i] = 0;
		REPP(i, 1, n) degree[i] = sum[i] = 0;
		REPP(i, 1, n) id[i].clear();
		REPP(i, 1, m) {
			int x, y;
			cin >> x >> y;
			e[i] = {x, y, 0, i};
			degree[x]++, degree[y]++;
			if (x != 1 && y != 1) {
				id[y].push_back(i);
				id[x].push_back(i);
			}
			else {
				id[1].push_back(i);
			}
		}
		REPP(i, 1, n) tmp[i] = i;
		sort(tmp + 2, tmp + n + 1, cmp);
		int now = m - n + 1;
		REPP(ii, 2, n) {
			int i = tmp[ii];
			REP(j, id[i].size()) {
				if (!use[id[i][j]]) {
					sum[i] += now;
					sum[e[id[i][j]].x ^ i ^ e[id[i][j]].y] += now;
					val[id[i][j]] = now--;
					use[id[i][j]] = 1;
				}
			}
		}
		sort(id[1].begin(), id[1].end(), cmp2);
		now = m;
		//REP(i, id[1].size()) {
		//	cout << id[1][i] << ' ' << (e[id[1][i]].x ^ e[id[1][i]].y ^ 1) << endl;
		//}
		REP(i, id[1].size()) {
			val[id[1][i]] = now--;
		}
		cout << "Yes" << endl;
		REPP(i, 1, m) {
			cout << val[i] << " \n"[i == m];
		}
	}
    return 0;
}

