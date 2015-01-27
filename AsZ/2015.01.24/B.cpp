#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 20

using namespace std;

typedef int arrayN[MAXN];

int n, a[MAXN][MAXN];
long long f[MAXN][201234];
string man[MAXN], woman[MAXN];
arrayN matFinalx, matFinaly, match, vis;

int dfs(int x)
{
    REPP(i, 1, n)
		if (a[x][i] && !matFinalx[x] && !matFinaly[i] && !vis[i])
		{
            vis[i] = 1;
            if (!match[i] || dfs(match[i]))
                {
                    match[i] = x;
                    return 1;
                }
		}
	return 0;
}

int hungry()
{
    MST(match, 0);
	int tmp = 0;
    REPP(i, 1, n)
		if (!matFinalx[i])
		{
			MST(vis, 0);
			tmp += dfs(i);
		}
	return tmp;
}

void dfs(int x, int sta)
{
	if (f[x][sta] >= 0) return;
	if (x == 0) return ;
    f[x][sta] = 0;
    REPP(i, 1, n)
		if (a[x][i] && (((1 << (i - 1)) & sta)))
        {
			dfs(x - 1, sta ^ (1 << (i - 1)));
			f[x][sta] += f[x - 1][sta ^ (1 << (i - 1))];
        }
}

void countWay()
{
    MST(f, -1);
    f[0][0] = 1;
    dfs(n, (1 << n) - 1);
}

int main() {
	//ios :: sync_with_stdio(0);
	freopen("B.in", "r", stdin);
	int task;
    cin >> task;
    REPP(t, 1, task)
    {
		cin >> n;
        REPP(i, 1, n)
			cin >> man[i];
		REPP(i, 1, n)
			cin >> woman[i];
		sort(man + 1, man + 1 + n);
		sort(woman + 1, woman + 1 + n);
		MST(a, 0);
		REPP(i, 1, n)
		{
			string st;
			int u, v;
			//cin >> st;
			st = "";
			char ch = getchar();
			for (; ch == ' ' || ch == '\n'; ch = getchar());
            for (;;)
            {
				st += ch;
				ch = getchar();
				if (ch == ':') break;
            }

            REPP(i, 1, n)
				if (man[i]== st)
				{u = i; break;}
			for (;;)
			{
				st = "";
				char ch = getchar();
				for (;ch == ' '; ch = getchar());
				if (ch == '\n') break;
                for (;;)
                {
                    //st.insert(st.length(), 1, ch);
                    st += ch;
					ch = getchar();
					if (ch == ' ' || ch == '\n')
					{
                        REPP(i, 1, n)
							if (woman[i] == st)
                                {v = i; break;}
                        a[u][v] = 1;
						break;
					}
                }
                if (ch == '\n') break;
			}
		}
		/*REPP(i, 1, n) cout << man[i] << ' ';
		cout << endl;
		REPP(i, 1, n) cout << woman[i] << ' ';
		cout << endl;
        REPP(i, 1, n)
        {
			REPP(j, 1, n)
				cout << a[i][j];
			cout << endl;
		}*/

        cout << "Case " << t << ":" << endl;
		countWay();
        if (f[n][(1 << n) - 1] <= 0)
		{
			cout << "No Way\n";
			continue;
		}
		MST(matFinalx, 0);
		MST(matFinaly, 0);
		int matNum = 0;
        REPP(i, 1, n)
            REPP(j, 1, n)
				if (matFinaly[j] == 0 && a[i][j])
				{
                    matFinalx[i] = j;
                    matFinaly[j] = i;
                    if (hungry() == n - i)
                    {
						matNum++;
                    //    cout << matNum;
                        break;
					}
                    matFinaly[j] = 0;
                    matFinalx[i] = 0;
				}

		cout << f[n][(1 << n) - 1] << endl;

        REPP(i, 1, n)
        {
			cout << man[i] << ' ' << woman[matFinalx[i]];
			if (i == n) cout << endl;
			else cout << ' ' ;
		}
    }
	return 0;
}
