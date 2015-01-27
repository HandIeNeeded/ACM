#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int n;

char get(int x, int y)
{
    int tot = 2 * n - 1;
    x %= tot, y %= tot;
    int spaceNum = 0;
    if (x <= n - 1) spaceNum = n - 1 - x;
    else spaceNum = x - (n - 1);
    if (y < spaceNum || (y > 2 * n - 2 - spaceNum))
		return '.';
    int sta = (n - 1) % 26;
    int stapos = spaceNum;
    if (y <= n - 1)
    {
        return (((sta - (y - stapos)) % 26 + 26) % 26) + 'a';
    }
    else
    {
		stapos = 2 * n - 2 - spaceNum;
		return (((sta - (stapos - y)) % 26 + 26) % 26) + 'a' ;
    }
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("A.in", "r", stdin);
	int task = 1;
	for (;;++task)
	{
		int row1, row2, col1, col2;
		scanf("%d%d%d%d%d", &n, &row1, &col1, &row2, &col2);
		if (n == 0) break;
		printf("Case %d:\n", task);
		REPP(i, row1, row2)
		{
			REPP(j, col1, col2)
                printf("%c", get(i, j));
			printf("\n");
		}
	}
	return 0;
}
