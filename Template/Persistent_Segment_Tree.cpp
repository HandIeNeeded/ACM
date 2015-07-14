struct SGT{
	int l, r, cnt;
	SGT(int a = 0, int b = 0, int c = 0) : l(a), r(b), cnt(c) {}
}p[N * 20];

int head[N], n, m, node;

int New_Node() {
	p[node] = SGT();
	return node++;
}

void update(int pre, int &now, int num, int l, int r) {
	now = New_Node();
	if (l == r) {
		p[now].cnt = p[pre].cnt + 1;
	}
	else {
		int mid = l + r >> 1;
		if (num <= mid) {
			update(p[pre].l, p[now].l, num, l, mid);
			p[now].r = p[pre].r;
		}
		else {
			update(p[pre].r, p[now].r, num, mid + 1, r);
			p[now].l = p[pre].l;
		}
		p[now].cnt = p[p[now].l].cnt + p[p[now].r].cnt;
	}
}

int query(int x, int y, int z, int w, int num, int l, int r) {
	if (l == r) {
		return p[x].cnt + p[y].cnt - p[z].cnt - p[w].cnt > 0;
	}
	else {
		int mid = l + r >> 1;
		int tmp = p[x].cnt + p[y].cnt - p[z].cnt - p[w].cnt;
		if (tmp == 0) return 0;
		else {
			if (num <= mid) {
				return query(p[x].l, p[y].l, p[z].l, p[w].l, num, l, mid);
			}
			else {
				return query(p[x].r, p[y].r, p[z].r, p[w].r, num, mid + 1, r);
			}
		}
	}
}
//New_Node() 0号节点作为空节点, head[0] = 1是空树的根, 从1开始标号
//head 每棵线段树的起始点 val　每个节点上存的数字 fa 每个节点的父亲节点
