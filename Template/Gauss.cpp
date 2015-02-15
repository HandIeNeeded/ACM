struct Matrix{
	double v[N][N];
	Matrix() {MST(v, 0);}
};

void gauss(Matrix& a, int n){
	int i, j ,k, r;
	for (i = 0; i < n; ++i){
		r = i;
		for (j = i + 1; j < n; ++j)
			if (fabs(a.v[j][i]) > fabs(a.v[r][i])) r = j;
		if (r != i) for (j = 0; j <= n; ++j) swap(a.v[r][j], a.v[i][j]);

		for (j = n; j >= i; --j) 
			for (k = i + 1; k < n; ++k) 
				a.v[k][j] -= a.v[k][i] / a.v[i][i] * a.v[i][j];
	}
	for (i = n - 1; i >= 0; --i){
		for (j = i + 1; j < n; ++j){
			a.v[i][n] -= a.v[j][n] * a.v[i][j];
		}
		a.v[i][n] /= a.v[i][i];
	}
}
//运行结束后a.v[i][n]是第i个未知数的值 lrj Page154
//已经加了对精度的优化
