char s[N], t[N];
int ls, lt; //s 待匹配 t 模板串
int f[N];

int getfail(){
	int i, j;
	f[0] = f[1] = 0;
	for (i = 1; i < lt; ++i){
		j = f[i];
		while (j && t[j] != t[i]) j = f[j];
		f[i + 1] = t[j] == t[i] ? j + 1 : 0; 
	}
}

int KMP(){
	int i, j;
	for (i = j = 0; i < ls; ++i){
		while(j && s[i] != t[j]) j = f[j];
		if (s[i] == t[j]) {
			j++;
			if (j == lt) return 1;
		} 
	}
	return 0;
}
