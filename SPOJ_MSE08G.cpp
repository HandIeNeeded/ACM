#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define LL long long
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const LL LIM = 1e12;

vector<LL> A, B;
vector<LL> C[10000];

void bfs() {
	queue<LL> q;
	q.push(0);

	while (q.size()) {
		LL x = q.front(); q.pop();
		if (x) A.push_back(x);
		if (x >= LIM) break;
		if (x * 10 + 4 <= LIM) q.push(x * 10 + 4);
		if (x * 10 + 7 <= LIM) q.push(x * 10 + 7);
	}
}

void getall(int l, int r, vector<LL> &v) {
	if (l == r) {
		v = C[l];
		return ;
	}
	else {
		int mid = l + r >> 1;
		vector<LL> A, B;
		getall(l, mid, A), getall(mid + 1, r, B);
		v = A;
		REP(i, B.size()) {
			v.push_back(B[i]);
		}
		int r = B.size() - 1;
		REP(i, A.size()) {
			REPP(j, 0, r) {
				if (LIM / A[i] < B[j]) {
					r = j - 1;
					break;
				}
				else {
					v.push_back(A[i] * B[j]);
				}
			}
		}
		sort(v.begin(), v.end());
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);
	//freopen("cf.out", "w", stdout);

	bfs();

	REP(i, A.size()) {
		C[i].push_back(A[i]);
		LL now = A[i];
		while (LIM / A[i] >= now) {
			now *= A[i];
			C[i].push_back(now);
		}
	}

	getall(0, A.size() - 1, B);
	B.resize(unique(B.begin(), B.end()) - B.begin());

	int T;
	cin >> T;
	LL a, b;
	while (T--) {
		cin >> a >> b;
		a--;
		int pa = upper_bound(B.begin(), B.end(), a) - B.begin();
		int pb = upper_bound(B.begin(), B.end(), b) - B.begin();
		cout << pb - pa<< endl;
	}

	return 0;
}