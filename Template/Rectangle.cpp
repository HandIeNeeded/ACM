struct rectangle{
    int a, b, c, d;
};

struct line{
    int x, up, down, ty;
};

const int N = 65; //N 线段树的长度,因为离散化的缘故是矩形个数的3倍
int sum[N << 2], cnt[N << 2];
int ql, qr, qd, tot, cnt; //tot是竖线的总量, cnt是矩形的个数
vector<int> num; //num是离散化用的数组
line l[2 * N];
rectangle p[N];

void maintain(int x, int l, int r) {
    if (cnt[x]) {
        sum[x] = num[r] - num[l - 1];
    }
    else {
        if (l == r) sum[x] = 0;
        else {
            sum[x] = sum[L] + sum[R];
        }
    }
}

void build(int x, int l, int r) {
    if (l == r) {
        sum[x] = cnt[x] = 0;
    }
    else {
        build(LC), build(RC);
        sum[x] = cnt[x] = 0;
    }
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        cnt[x] += qd;
        maintain(x, l, r);
    }
    else {
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        maintain(x, l, r);	
    }
}


bool cmp(const line &a, const line &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.ty > b.ty;
}

int solve() {
    tot = 0;
    REP(i, cnt) {
        l[tot++] = (line) { p[i].a, p[i].b + 1, p[i].d, 1 };
        l[tot++] = (line) { p[i].c, p[i].b + 1, p[i].d, -1 };
        num.push_back(p[i].b + 1);
        num.push_back(p[i].d);
        num.push_back(p[i].d + 1);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    sort(l, l + tot, cmp);
    REP(i, tot) {
        l[i].up = lower_bound(num.begin(), num.end(), l[i].up) - num.begin() + 1;
        l[i].down = lower_bound(num.begin(), num.end(), l[i].down) - num.begin() + 1;
    }
    int n = num.size() - 1;
    build(1, 1, n);
    int ans = 0;
    REP(i, tot) {
        if (i) {
            ans += sum[1] * (l[i].x - l[i - 1].x); //可能需要LL
        }
        ql = l[i].up, qr = l[i].down, qd = l[i].ty;
        update(1, 1, n);
    }
    num.clear(); //清空离散化的数组
    return ans;
}

