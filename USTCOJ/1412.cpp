#include <bits/stdc++.h> 

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
int degree[N];
char vis[N];

int main() {
	int n;
	ios :: sync_with_stdio(0);

	while(cin >> n, n) {
		REPP(i, 1, n) {
			int cnt = 0;
			cin >> vis;
			REP(j, n) {
				if (vis[j] == '1') {
					cnt++;
				}
			}
			degree[i] = cnt; 
		}
		sort(degree + 1, degree + n + 1);
		bool good = 0;
		REPP(i, 2, n) {
			if (degree[i] == degree[i - 1]) {
				good = 1;
			}
		}
		if (good) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
