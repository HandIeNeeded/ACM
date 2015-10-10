#include <bits/stdc++.h>

using namespace std;

char str[500], dig[500];

int main()
{
	//freopen("D.in", "r", stdin);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 0; tt < ttt; tt++)
	{
		printf("Case %d:\n", tt + 1);

		scanf("%s", str);
		int len = strlen(str);
		str[len++] = '+';
		str[len++] = 0;
		int mrk = 1, inv = 1;
		int pre = -1;
		vector< pair<int , int> > a;
		vector<int> stk;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '#')
			{
				if (pre == -1)
					pre = i;
			} else
			{
//				printf("%d %d %d\n", mrk, inv, pre);
				if (pre != -1)
				{
					for (int j = pre; j < i; j++)
						a.push_back(make_pair((i - j) * mrk * inv, j));
					pre = -1;
				}
				switch (str[i])
				{
					case '(':
						stk.push_back(mrk);
						inv = inv * mrk;
						mrk = 1;
						break;
					case ')':
						inv = inv * stk.back();
						stk.pop_back();
						mrk = 1;
						break;
					default:
						mrk = str[i] == '+' ? 1 : -1;
				}
			}
		}
		sort(a.begin(), a.end());
		scanf("%s", dig);
		sort(dig, dig + strlen(dig));
		for (int i = 0; i < a.size(); i++)
			str[a[i].second] = dig[i];
//		str[strlen(str) - 1] = 0;
//		printf("%s\n", str);
		int ans = 0;
		stk.clear();
		pre = -1, mrk = 1, inv = 1;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (pre == -1)
					pre = i;
			} else
			{
				if (pre != -1)
				{
					int tmp = 0;
					for (int j = pre; j < i; j++)
					{
						tmp *= 10;
						tmp += str[j] - '0';
					}
					ans += tmp * mrk * inv;
					pre = -1;
				}
				switch (str[i])
				{
					case '(':
						stk.push_back(mrk);
						inv = inv * mrk;
						mrk = 1;
						break;
					case ')':
						inv = inv * stk.back();
						stk.pop_back();
						mrk = 1;
						break;
					default:
						mrk = str[i] == '+' ? 1 : -1;
				}
			}
		}
		str[strlen(str) - 1] = 0;
		printf("%s\n", str);
		printf("%d\n", ans);
	}
	return 0;
}
