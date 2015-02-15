const int N = 1005;
const int LEN = 100;
const int Z = 4;

string s = "ATGC";

struct AC_Automation{
	int tr[N * LEN][Z], fail[N * LEN], val[N * LEN];
	int node;

	int New_Node() {
		mem(tr[node]);
		fail[node] = val[node] = 0;
		return node++;
	}

	void Init() {
		node = 0;
		New_Node();
	}

	void insert(char *s, int id) {
		int pos = 0, x, now = 0;
		while (s[pos]) {
			x = str.find(s[pos++]);
			if (!tr[now][x]) {
				tr[now][x] = New_Node();
				val[tr[now][x]] = val[now];
			}
			now = tr[now][x];
		}
		val[now] |= 1 << id;
	}

	void getfail() {
		int x, y;
		queue<int> q;
		REP(i, Z) {
			x = tr[0][i];
			if (x) {
				fail[x] = 0;
				q.push(x);
			}
		}

		while (!q.empty()) {
			x = q.front(); q.pop();
			REP(i, Z) {
				if (!tr[x][i]) {
					tr[x][i] = tr[fail[x]][i];
					continue;
				}
				y = tr[x][i];
				q.push(y);
				fail[y] = tr[fail[x]][i];
			}
		}
	}
}AC;
