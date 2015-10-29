#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;

int sg[2][2][N], sg1[2][N], sg2[N];
int vis[N * 10000];

void init() {
	int now = 0;
	sg[0][0][0] = sg[1][1][0] = 0, sg[0][0][1] = sg[1][1][1] = 1;
	sg[0][1][0] = sg[1][0][0] = sg[0][1][1] = sg[1][0][1] = 0;
	REPP(length, 2, 100) {
		REP(left, 2) {
			REP(right, 2) {
				now++;
				REPP(pos, 1, length) {
					if (pos == 1) {
						vis[sg[left ^ 1][right][length - 1]] = now;
					}
					else if (pos == length) {
						vis[sg[left][right ^ 1][length - 1]] = now;
					}
					else {
						REP(col, 2) {
							vis[sg[left][col][pos - 1] ^ sg[col][right][length - pos]] = now;
						}
					}
				}
				int &ans = sg[left][right][length];
				while (ans <= N * 10000 && vis[ans] == now) ans++;
			}
		}
	}
	sg1[0][0] = sg1[1][0] = 0;
	REPP(length, 1, 100) {
		REP(end, 2) {
			now++;
			REPP(pos, 1, length) {
				if (pos == length) {
					vis[sg1[end ^ 1][length - 1]] = now;
				}
				else {
					REP(col, 2) {
						vis[sg1[col][pos - 1] ^ sg[col][end][length - pos]] = now;
					}
				}
			}
			int &ans = sg1[end][length];
			while (ans <= N * 10000 && vis[ans] == now) ans++;
		}
	}
	sg2[0] = 0;
	REPP(length, 1, 100) {
		now++;
		REPP(pos, 1, length) {
			REP(col, 2) {
				vis[sg1[col][pos - 1] ^ sg1[col][length - pos]] = now;
			}
		}
		int &ans = sg2[length];
		while (ans <= N * 10000 && vis[ans] == now) ans++;
	}
}

int get(int left, int right, int length) {
	return left ^ right ^ 1;
}

int get1(int end, int length) {
	return length;
}

int get2(int length) {
	return length & 1;
}

int main() {
	string s;
	init();
	//REPP(i, 0, 100) {
	//	cout << i << ' ';
	//	REP(left, 2) {
	//		REP(right, 2) {
	//			cout << sg[left][right][i] << ' ';
	//		}
	//	}
	//	cout << endl;
	//}
	//REPP(i, 0, 100) {
	//	cout << i << ' ';
	//	REP(end, 2) {
	//		cout << sg1[end][i] << ' ';
	//	}
	//	cout << endl;
	//}
	//REPP(i, 0, 100) {
	//	cout << i << ' ' << sg2[i] << endl;
	//}
	int n;
	cin >> n >> s;
	int ans = 0;
	int left = 0, right = n - 1, L = 0, R = 0;
	while (left < n && s[left] == '0') left++;
	while (right >= 0 && s[right] == '0') right--;
	L = left, R = n - right - 1;
	if (L == n) {
		//ans = sg2[n];
		ans = get2(n);
	}
	else {
		s = s.substr(left, right - left + 1);
		n = s.size();
		//ans = sg1[s[0] - '1'][L] ^ sg1[s.back() - '1'][R];
		ans = get1(s[0] - '1', L) ^ get1(s[s.size() - 1] - '1', R);
		REP(i, n) {
			if (s[i] != '0') {
				left = s[i] - '1';
				continue;
			}
			int j = i;
			while (j < n && s[j] == '0') j++;
			right = s[j] - '1';
			ans ^= get(left, right, j - i);
			i = j - 1;
		}
	}
	if (ans) {
		cout << "FIRST" << endl;
	}
	else {
		cout << "SECOND" << endl;
	}
    return 0;
}
