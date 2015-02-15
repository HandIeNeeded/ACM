#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

void maintain(int x, int l, int r) {

}

void build(int x, int l, int r) {
	if (l == r) {
		flag[x] = false, val[x] = 0;
	}
	else {
		build(LC), build(RC);
		flag[x] = false, val[x] = 0;
		maintain(x, l, r);
	}
}

void push(int x, int l, int r) {
	flag[L] = flag[R] = 1;
	val[L] += val[x], val[R] += val[x];
	flag[x] = false, val[x] = 0;
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		flag[x] = 1;
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		maintain(x, l, r);
	}
}

void modify(int x, int l, int r) {
	if (l == r) {

	}
	else {
		if (flag[x]) push(x, l, r);
		if (qx <= MID) modify(LC);
		else modify(RC);
		maintain(x, l, r);
	}
}

int qans;

void query(int x, int l, int r) {
	if (ql <= l && qr >= r) {

	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) query(LC);
		if (qr > MID) query(RC);
	}
}

