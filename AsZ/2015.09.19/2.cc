#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2;
const int C = 96;
const int M = 50000;
int MO;

void add(int &x, int y, int mo = MO) {
	x += y;
	if (x >= mo) x -= mo;
}

int pow_mod(int a, int b, int mo = MO) {
    //cout << "mo: " << mo << endl;
    a %= mo;
    add(a, mo, mo);
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % mo;
		b >>= 1;
		a = 1LL * a * a % mo;
	}
	return ans;
}

bool test() {
    return pow_mod(C, (MO - 1) / 2) == 1;
}

int p[M], vis[M], tot;

void prime() {
    for (int i = 2; i < M; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < M; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

struct Matrix {
	int a[N][N];

	Matrix (bool ident = 0) {
		MST(a, 0);
		if (ident) {
			REP(i, N) a[i][i] = 1;
		}
	}

	int* operator [] (int i){
		return a[i];
	}

	const int* operator [] (int i) const {
		return a[i];
	}
};

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix c;
	REP(i, N) REP(j, N) REP(k, N) {
		add(c[i][j], 1LL * a[i][k] * b[k][j] % MO);
	}
	return c;
}

Matrix pow_mod(Matrix a, int n) {
	Matrix ans(1);
	while (n) {
		if (n & 1) ans = ans * a;
		n >>= 1;
		a = a * a;
	}
	return ans;
}

bool operator == (const Matrix &a, const Matrix &b) {
    REP(i, 2) {
        REP(j, 2) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}

Matrix start, ident;
vector<int> candidate;

void get(int x) {
    //cout << "xixi" << x << endl;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            candidate.push_back(i);
            candidate.push_back(x / i);
        }
    }
}

int getT() {
    candidate.clear();
    if (test()) {
        get(MO - 1);
    }
    else {
        //cout << "xixi" << endl;
        get(MO - 1);
        get(MO + 1);
    }
    sort(candidate.begin(), candidate.end());
    candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());
    for (auto &x: candidate) {
        //cout << x << ' ';
        if (pow_mod(start, x) == ident) {
            return x;
        }
    }
    //cout << endl;
    return -1;
}

void init() {
    int tmp[2][2] = {0, MO - 1, 1, 10};
    REP(i, 2) {
        REP(j, 2) {
            start[i][j] = tmp[i][j];
        }
    }
    //REP(i, 2) {
    //    REP(j, 2) {
    //        cout << start[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    REP(i, 2) ident[i][i] = 1;
}

//a[0] = 2, a[1] = 10, a[2] = 98, a[3] = 970
//a[n + 2] = 10 * a[n + 1] - a[n]

void print(const Matrix &a) {
    REP(i, 2) {
        REP(j, 2) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
#ifdef HOME
    freopen("2.in", "r", stdin);
#endif

    int t, ca = 1;
    prime(); 
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%d", &n, &MO);
        //cout << "n MO: " << n << ' ' << MO << endl;
        init();
        int T = getT();
        assert(T > 0);
        //cout << "T: " << T << endl;
        //cout << 2 << ' ' << n << ' ' << T << endl;
        int reminder = pow_mod(2, n, T);
        //cout << "reminder: " << reminder << endl;
        //Matrix tmp = pow_mod(start, T);
        //print(start);
        Matrix fun = pow_mod(start, reminder);
        //print(fun);
        int ans = 2 * fun[0][1] + 10 * fun[1][1];
        ans %= MO;
        add(ans, MO - 1);
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}

