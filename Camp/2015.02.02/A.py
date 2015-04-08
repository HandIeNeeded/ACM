n = int(raw_input());
ans, now = 0, 1;
while n > 0:
	k = (n + 1) / 2;
	if n % 2 == 1:
		st = max(k - 1, 1);
		if now:
			ans += (n - st + 1);
		n = k - 2;
	else :
		if now:
			ans += k + 1;
		n = k - 1;
	now ^= 1;
print ans;
