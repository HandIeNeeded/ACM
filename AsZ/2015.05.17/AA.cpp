#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAXN 123

using namespace std;


string findUntilBrack()
{
    string st = "";
	for (; ;)
	{
		char ch = getchar();
        if (ch == '{') return st;
        if (ch < 'a' || ch > 'z') continue;
        st += ch;
	}
	return st;
}

struct node
{
    int kind; //1 book, 2 article
} g[MAXN];

string findUntilEqual()
{
    string st = "";
    for (;;)
    {
		char ch = getchar();
		if (ch == '=') return st;
		if (ch < 'a' || ch > 'z') continue;
		st += ch;
    }
    return st;
}

void findUntilBrackR(int tot)
{
    for (;;)
    {
        string st = findUntilEqual();
        if (st == "author")
        {
        } else if (st == "title")
        {
			//
        } else if (st == "journal")
        {
			//
        } else if (st == "year")
        {
			//
        } else if (st == "volume")
        {
         //
        } else if (st == "number")
        {
         //11
        } else if (st == "pages")
        {
         //
        } else if (st == "publisher")
        {
         //1
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("bibtex.in", "r", stdin);
	freopen("bibtex.out", "w", stdout);
	int tot = 0;
    for (;;)
    {
		char ch;
        if ((ch = getchar()) == EOF) break;
        //printf("%c", ch);
		if (ch == '@')
        {
            string st = findUntilBrack();
            cout << st << endl;
        }
        ++tot;
        if (st == "book")
			g[tot].kind = 1;
		else g[tot].kind = 2;

		// finish {

        findUntilBrackR(tot);
    }
    return 0;
}


