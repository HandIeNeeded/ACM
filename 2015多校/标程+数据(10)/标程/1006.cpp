#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MOD 2015
#define MX 55
int N, M;
int A[MX][MX], B[MX][MX], t[MX][MX];

void multi(int A[MX][MX], int B[MX][MX], int C[MX][MX]) {
	int i, j, k;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) t[i][j] = 0;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) for (k = 0; k < N; k++) {
		t[i][j] += A[i][k] * B[k][j];
	}
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) C[i][j] = t[i][j] % MOD;
}

int main() {
	int u, T, i, j, k;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &N, &M);
		
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);
		
		for (i = 0; i <= N; i++) B[i][i] = 1;
		A[N][N] = 1;
		for (i = 0; i < N; i++) {
			for (scanf("%d", &k); k--; ) {
				scanf("%d", &u);
				A[i][u - 1]++;
			}
		}
		
		for (i = 0; i < N; i++) A[i][N] = 1;
		N++;
		M--;
		while (M) {
			if (M & 1) multi(B, A, B);
			multi(A, A, A);
			M /= 2;
		}
		
		int ans = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				ans += B[i][j];
			}
		}
		printf("%d\n", ans % MOD);
	}
	return 0;
}
