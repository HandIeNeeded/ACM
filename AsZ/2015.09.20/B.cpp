#include <bits/stdc++.h>
#define MAXN 11234

using namespace std;

int m, tot;
int l[MAXN * 20], r[MAXN * 20];
char g[MAXN * 20];
char tmpSt[MAXN * 20];

struct cpNode
{
    int start;
    int ed;
    int point; // 0 right, 1 left
    int active;
    int lastStart;
    int lastEd;
    int lastPoint;
    void origin()
    {
        start = 0;
        ed = 0;
        point = 0;
        active = 0;
        lastStart = 0;
        lastEd = 0;
    }

    void finish()
    {
        active = 0;
        start = ed = 0;
        point = 0;
        active = 0;
    }

    void moveL()
    {
        if (!start) return ;
        if (!active) return ;
        if (start == ed)
        {
            point = 1;
        }
        ed = l[ed];
    }

    void moveR()
    {
        if (!start) return ;
        if (!active) return ;
        if (start == ed)
        {
            point = 0;
        }
        ed = r[ed];
    }

    void press(int pt)
    {
        if (!active)
        {
            start = pt;
            ed = pt;
            point = 0;
            active = 1;
        } else
        {
            lastEd = ed;
            lastStart = start;
            lastPoint = point;
            finish();
        }
    }

};

struct prtNode
{
    int len;
    int head;
    int pt;
    int ins;
    cpNode cp;
    void deleteLink(int x)
    {
        r[l[x]] = r[x];
        l[r[x]] = l[x];
        len--;
    }

    void addLink(char x)
    {
        if (len >= m) return ;
        ++tot;
        g[tot] = x;
        r[tot] = r[pt];
        l[tot] = pt;
        r[l[tot]] = tot;
        l[r[tot]] = tot;
        len++;
    }
    void origin()
    {
        len = 0;
        head = 1;
        r[head] = 0;
        l[head] = 0;
        pt = head;
        ins = 1;
    }

    void moveL()
    {
        if (pt == head) return ;
        pt = l[pt];
        cp.moveL();
    }

    void moveR()
    {
        if (r[pt] == 0) return ;
        pt = r[pt];
        cp.moveR();
    }

    void del()
    {
        if (cp.active)
        {
            int u = cp.start;
            int v = cp.ed;
            if (cp.point == 1) swap(u, v);
            for (; u != v; )
            {
                int tmp = r[u];
                deleteLink(r[u]);
                u = tmp;
            }
        } else
        {
            if (r[pt]) deleteLink(r[pt]);
        }

        cp.finish();
    }

    void switchIns()
    {
        cp.finish();
        ins = 1 - ins;
    }


    void bac()
    {
        cp.finish();
        if (pt == head) return ;
        int tmp = l[pt];
        deleteLink(pt);
        pt = tmp;
    }

    void cop()
    {
        cp.press(pt);
    }

    void insertt(int u, int v)
    {

        if (u != v)
        {
            int cnt = 0;
            int tm = len;
            for (; u != v; u = r[u])
            {
                tmpSt[++cnt] = g[r[u]];
                ++tm;
                if (tm > m) break;
            }

            for (int i = 1; i <= cnt; ++i)
            {
                if (ins || r[pt] == 0) addLink(tmpSt[i]);
                else g[r[pt]] = tmpSt[i];
                if (r[pt]) pt = r[pt];
            }
        }
    }

    void paste()
    {
        cp.finish();
        int u = cp.lastStart;
        int v = cp.lastEd;
        if (cp.lastPoint == 1) swap(u, v);
        if (u != v)
        {
            if (ins) insertt(u, v);
            else
            {
                int tu = u;
                int cnt = 0;
                int tpt = r[pt];
                for (;tu != v && tpt;)
                {
                    tmpSt[++cnt] = g[r[tu]];
                    tu = r[tu];
                    tpt = r[tpt];
                }
                int tmp = len;
                for (; tu != v; tu = r[tu])
                {
                    tmpSt[++cnt] = g[r[tu]];
                    ++tmp;
                    if (tmp >= m) break;
                }


                for (int i = 1; i <= cnt; ++i)
                {
                    if (r[pt] == 0) addLink(tmpSt[i]);
                    else g[r[pt]] = tmpSt[i];
                    if (r[pt]) pt = r[pt];
                }
            }
        }
    }

    void normal(char ch)
    {
        cp.finish();
        if (ins || r[pt] == 0) addLink(ch);
        else g[r[pt]] = ch;
        if (r[pt]) pt = r[pt];
    }

    void printSt()
    {
        int u = r[head];
        for (; u; u = r[u])
            printf("%c", g[u]);
    }
} prt;

char st[MAXN];

int main()
{
   // freopen("B.in", "r", stdin);
    int T;
    for (scanf("%d\n", &T); T; --T)
    {
        scanf("%d %s\n", &m, st);
        tot = 1;

        prt.cp.origin();
        prt.origin();

        int len = strlen(st);
        for (int i = 0; i < len; ++i)
        {
            if (st[i] == 'L') prt.moveL();
            else if (st[i] == 'R') prt.moveR();
            else if (st[i] == 'S') prt.switchIns();
            else if (st[i] == 'D') prt.del();
            else if (st[i] == 'B') prt.bac();
            else if (st[i] == 'C') prt.cop();
            else if (st[i] == 'V') prt.paste();
            else prt.normal(st[i]);
        }

        if (prt.len == 0) printf("NOTHING\n");
        else
        {
            prt.printSt();
            printf("\n");
        }
    }
    return 0;
}
