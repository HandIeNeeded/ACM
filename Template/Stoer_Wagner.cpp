//O(N^3) 无向图 无负权

#define N 555
int vis[N];
int wet[N];//weight all edge weight connect i from set A
int combine[N]; //has been merged or not
int mp[N][N]; //map nodes 0based (starts from 0)
 
int S, T, minCut, n;

void search() {
	int Max, tmp;
	MST(vis, 0), MST(wet, 0);
	S = T = -1;
	REP(i, n) {
		Max = -INF;
		REP(j, n) {
			if (!combine[j] && !vis[j] && wet[j] > Max) {
				tmp = j;
				Max = wet[j];
			}
		}
		if (T == tmp) return ;
		S = T, T = tmp;
		minCut = Max;
		vis[tmp] = 1;
		REP(j, n) {
			if (!combine[j] && !vis[j]) {
				wet[j] += mp[tmp][j];
			}
		}
	}
}

int Stoer_Wagner() {
	MST(combine, 0);
	int ans = INF;
	REP(i, n - 1) {
		search();
		if (minCut < ans) ans = minCut;
		if (ans == 0) return 0;
		combine[T] = 1;
		REP(j, n) if (!combine[j]) {
			mp[S][j] += mp[T][j];
			mp[j][S] += mp[j][T];
		}
	}
	return ans;
}
