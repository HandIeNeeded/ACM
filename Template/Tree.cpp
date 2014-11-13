//包括了求树的重心，以及树的最小表示（有根树，任选的时候我们可以以重心为根，然后就可以判同构了）

struct tree{
	int son[N], dm[N];//儿子节点数，断开该节点后子连通块的节点数最大值
	int fi[N], en[N << 1], ne[N << 1], tot;
	int n;//节点数

	void Init(int x) {//初始化
		mem(son), mem(dm);
		mem(fi), tot = 0;
		n = x;
	}

	void add(int x, int y) {
		ne[++tot] = fi[x], fi[x] = tot, en[tot] = y;
	}

	void dfs1(int x, int p) {//树DP
		for (int go = fi[x]; go; go = ne[go]) {
			if (en[go] != p) {
				dfs1(en[go], x);
				son[x] += son[en[go]];
				dm[x] = max(dm[x], son[en[go]]);
			}
		}
		son[x]++;
	}

	void dfs2(int x, int p) {//树DP
		for (int go = fi[x]; go; go = ne[go]) {
			if (en[go] != p) {
				int y = en[go];
				dm[y] = max(n - son[y], dm[y]);
				dfs2(y, x);
			}
		}
	}

	void get_weg(vector<int>& w) {//得到重心，最多两个
		dfs1(1, 0);
		dfs2(1, 0);
		int mi = INF;
		REPP(i, 1, n) {
			if (dm[i] < mi) {
				mi = dm[i];
				w.clear();
				w.push_back(i);
			}
			else if (dm[i] == mi) w.push_back(i);
		}
	}

	string get_str(int x, int p) {//最小表示的括号序列
		int good = 0;
		vector<string> tmp;
		for (int go = fi[x]; go; go = ne[go]) {
			if (en[go] != p) {
				good = 1;
				tmp.push_back(get_str(en[go], x));
			}
		}
		if (!good) return (string) "()";
		else {
			sort(ALL(tmp));//排序
			string ans;
			REP(i, SZ(tmp)) ans += tmp[i];
			ans = '(' + ans + ')';
			return ans;
		}
	}
}t[2];
