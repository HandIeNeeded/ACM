#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 18

using namespace std;

int n;

void pans(string l, string r)
{
	if (l == r)
	{
		cout << l << endl;
		return ;
	}
	cout << l << '-';
    int lenL = l.length();
    int lenR = r.length();
    REPP(i, lenL + 1, lenR)
		l = "0" + l;
    REP(i, lenR)
		if (l[i] != r[i])
		{
			REPP(j, i, lenR - 1)
				cout << r[j];
			break;
		}
	cout << endl;
}

long long change(string l)
{
	long long tmp = 0;
	int len = l.length();
	for (int i = 0; i <= len - 1; ++i)
		tmp = tmp * 10LL + l[i] - '0';
	return tmp;
}

int comOnlyOne(string l, string r)
{
    long long u = change(l);
    long long v = change(r);
	return u + 1 == v;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int task = 0;
	for (;;)
	{
		cin >> n;
		if (n == 0) break;
		task++;
		cout << "Case " << task << ':' << endl;
		string last;
		cin >> last;
		string t = last;
		int flag = 0;
        REPP(i, 2, n)
        {
			string now;
			cin >> now;
			if (comOnlyOne(t, now))
			{
				t = now;
			} else
			{
				flag = 1;
                pans(last, t);
                flag = i - 1;
                last = t = now;
			}
        }
        if (flag != n) pans(last, t);
		cout << endl;
	}


	return 0;
}
