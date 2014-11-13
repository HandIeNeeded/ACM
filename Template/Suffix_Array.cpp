//倍增 O(nlogn)
//对于一个或多个（需要连接几个字符串的时候）在每个字符串后加一个未出现过的标记字符，且要保证两两不同，比如'#'(35), '@'('A'-1), '['('Z'+1), '`'('a'-1), '{'('z'+1)
//转化成数字做最简单啦。
//'A'(65) 'a'(97)

const int N = 100005;

struct Suffix_Array {
	int s[N];
	int sa[N], t1[N], t2[N], c[N], n; // n 字符串长度 sa 后缀数组
	//sa[i] 排名是i的后缀的序号（从0开始标号，第零个是我们添加的字符的后缀，这是对于只有一个字符串说的，显然是n，sa[0] = n）
	
	void Init(int x) { //x = SL(s) + 1 or etc;
		n = x;
		//s[n]要比所有出现的字符（or数字）小，但是大于0，比如'#'，或者数字的时候1
		getsa(256);
		gethg();
		//所有初始化数组已经写在函数里面，没有必要另外memset了。
	}

	void getsa(int m) { // m 字符集大小
		int *x = t1, *y = t2;
		mem(c);
		REP(i, n) c[x[i] = s[i]]++; //这里反正都是转化成 int 做
		REPP(i, 1, m - 1) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
		for(int k = 1; k <= n; k <<= 1) {
			int p = 0;
			for (int i = n - k; i < n; ++i) y[p++] = i;
			REP(i, n) if (sa[i] >= k) y[p++] = sa[i] - k;
			REP(i, m) c[i] = 0;
			REP(i, n) c[x[y[i]]]++;
			REPP(i, 1, m - 1) c[i] += c[i - 1];
			for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
			swap(x, y);
			p = 1; x[sa[0]] = 0;
			REPP(i, 1, n - 1) {
				x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
			}
			if (p >= n) break;
			m = p;
		}
	}

	int r[N], hg[N]; // rank[], height[]
	
	//rank[i] 第i个后缀在后缀数组里面的排名，（反函数的关系）
	//height[i] sa[i]和sa[i-1]的最长公共前缀，hg[0] = 0, hg[1] = 0;

	void gethg(){
		REP(i, n) r[sa[i]] = i;
		int k = 0;
		REP(i, n) {
			if (k) k--;
			int j = sa[r[i] - 1];
			while (s[i + k] == s[j + k]) k++;
			hg[r[i]] = k;
		}
	}

	void output(){
		REP(i, n) cout << sa[i] << ' ';//n比原长大一
		cout << endl;
		REP(i, n) cout << hg[i] << ' ';
		cout << endl;
	}
}SA;

// DC3

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[N],wb[N],wv[N],wss[N]; //看不懂 反正开这么大就够了

int c0(int *r,int a,int b) {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}

int c12(int k,int *r,int a,int b){
	if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
	else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}

void sort(int *r,int *a,int *b,int n,int m){
	int i;
	for(i=0;i<n;i++) wv[i]=r[a[i]];
	for(i=0;i<m;i++) wss[i]=0;
	for(i=0;i<n;i++) wss[wv[i]]++;
	for(i=1;i<m;i++) wss[i]+=wss[i-1];
	for(i=n-1;i>=0;i--) b[--wss[wv[i]]]=a[i];
	return;
}

int r[3 * N], sa[3 * N]; // 三倍大小

void dc3(int *r,int *sa,int n,int m){ //长度，字符集大小
	int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
	r[n]=r[n+1]=0;
	for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
	sort(r+2,wa,wb,tbc,m);
	sort(r+1,wb,wa,tbc,m);
	sort(r,wa,wb,tbc,m);
	for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
	rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
	if(p<tbc) dc3(rn,san,tbc,p);
	else for(i=0;i<tbc;i++) san[rn[i]]=i;
	for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
	if(n%3==1) wb[ta++]=n-1;
	sort(r,wb,wa,ta,m);
	for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
	for(i=0,j=0,p=0;i<ta && j<tbc;p++)
	sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
	for(;i<ta;p++) sa[p]=wa[i++];
	for(;j<tbc;p++) sa[p]=wb[j++];
	return;
}

int hg[N]; // height[]

void gethg(){
	REP(i, n) r[sa[i]] = i;
	int k = 0;
	REP(i, n) {
		if (k) k--;
		int j = sa[r[i] - 1];
		while (s[i + k] == s[j + k]) k++;
		hg[r[i]] = k;
	}
}


