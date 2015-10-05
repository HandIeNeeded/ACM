#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

string num, digit;
string op = "+-*/";
int p[N], now;

void dfs(int dep) {
	if (rand() % 3 == 0 || dep == 3) {
        if (now == 4) {
            cout << " X";
        }
        else if (now == 0) {
            cout << rand() % 9 + 1;
        }
        else {
            cout << " " << rand() % 9 + 1;
        }
        now++;
	}
	else {
        dfs(dep + 1);
        dfs(dep + 1);
        cout << " " << op[rand() % 4];
	}
}

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
	//cout << RAND_MAX << endl;
	REPP(i, 'a', 'z') digit += i;
	REPP(i, '0', '9') num += i;
    dfs(0);
	return 0;
}



