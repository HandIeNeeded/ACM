//获得字符串s的最小表示,会将字符串扩展成2倍长.
//返回值是最小表示的起始位置在原串中的位置
int minrepresent(char *s) {
	int a = 0, b = 1, c = 0;
	int n = strlen(s);
	REP(i, n) s[i + n] = s[i];
	s[n << 1] = 0;
	while (a < n && b < n && c < n) {
		int tmp = s[a + c] - s[b + c];
		if (!tmp) c++;
		else {
			if (tmp > 0) a += c + 1;
			else b += c + 1;
			if (a == b) b++;
			c = 0;
		}
	}
	return min(a, b);
}
