//LL version
struct po{
	LL x, y;
	po (LL a = 0, LL b = 0) : x(a), y(b) {}
}p[N];

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Attention  sort(p, p + n, cmpxy) first!

inline bool cmpxy(const po &a, const po &b) { //initailly  sort all points using cmpxy
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

inline bool cmpy(const int &a, const int &b) {return p[a].y < p[b].y;}

LL sqr(LL x) {return x * x;}

//return (dis * dis)

LL dis(const int &i, const int &j) { return sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y);} //square of dis

int tmp[N];

LL Closest_Pair(int left, int right) { 
	LL d = LIM; // square of ans
	if (left == right) return d;
	if (left + 1 == right) return dis(left, right);
	int mid = (left + right) >> 1;
	LL  dl = Closest_Pair(left, mid);
	LL dr = Closest_Pair(mid + 1, right);
	d = min(dl, dr);
	int cnt = 0;
	REPP(i, left, right) {
		if (sqr(p[mid].x - p[i].x) <= d) { //square of x
			tmp[cnt++] = i;
		} 
	}
	sort(tmp, tmp + cnt, cmpy);
	REP(i, cnt) {
		for (int j = i + 1; j < cnt && sqr(p[tmp[j]].y - p[tmp[i]].y) < d; ++j) { //square of y and attention !!!!!!!!!!!!!!!!!!!! tmp[i] not i
			LL dd = dis(tmp[i], tmp[j]); // Attention tmp[i] not i !!!!!!!!!!!!!!!!!!!!!!!!! 
			if (d > dd) d = dd;
		}
	}
	return d;
}

//square of dis 
// dis need to change dis function and sqr part

//dou version
struct po{
	dou x, y;
	po (dou a = 0, dou b = 0) : x(a), y(b) {} 
}p[N];

inline bool cmpxy(const po &a, const po &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

inline bool cmpy(const int &i, const int &j) {return p[i].y < p[j].y;} 

dou sqr(dou x) {return x * x;}

dou dis(const int &i, const int &j) {return sqrt(sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y));} 

int tmp[N];

dou Closest_Pair(int left, int right) {
	dou d = 1e100;
	if (left == right) return d;
	if (left + 1 == right) {
		return dis(left, right);
	}
	int mid = (left + right) >> 1;
	dou dl = Closest_Pair(left, mid);
	dou dr = Closest_Pair(mid + 1, right);
	int cnt = 0;
	d = min(dl, dr);
	REPP(i, left, right) {
		if (abs(p[i].x - p[mid].x) <= d) {
			tmp[cnt++] = i;
		}
	} 
	sort(tmp, tmp + cnt, cmpy);
	REP(i, cnt) {
		for (int j = i + 1; j < cnt && p[tmp[j]].y - p[tmp[i]].y < d; ++j) { // !!!!!!!!!!!!!!!!!!!! tmp[i] not i
			dou dd = dis(tmp[i], tmp[j]); // !!!!!!!!!!!!!!!!!
			if (d > dd) d = dd;
		}
	}
	return d;
}

// call sort(p, p + n, cmpxy) first !!!!!!!!!!!!!!!!!!!!!!!!!!!!!


