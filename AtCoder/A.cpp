#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0;i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long
 
using namespace std;
 
vector<int> number[6];
int pw[10] = {1};
 
void solve(int n) {
	if (n == 1) {
		REP(i, 10) {
			number[n].push_back(i);
		}
		return ;
	}
	else {
		solve(n - 1);
		REP(d, 10) {
			if (d & 1) {
				for (int i = number[n - 1].size() - 1; i >= 0; --i) {
					number[n].push_back(number[n - 1][i] + d * pw[n - 1]);
				}
			}
			else {
				REP(i, number[n - 1].size()) {
					number[n].push_back(number[n - 1][i] + d * pw[n - 1]);
				}
			}
		}
		return ;
	}
}
 
int main() {
	ios :: sync_with_stdio(0);
	int n;
	REPP(i, 1, 6) {
		pw[i] = pw[i - 1] * 10;
	}
	cin >> n;
	solve(n);
	cout << number[n].size() - 1 << endl;
	REP(i, number[n].size()) {
		cout << setw(n) << setfill('0') << number[n][i] << endl;
	}
	
	return 0;
}
