#include <bits/stdc++.h>

#define N 110

using namespace std;

struct Sta
{
    int ox, oy, ot, dir;
    Sta(int ox = 0, int oy = 0, int ot = 0, int dir = 0) : ox(ox), oy(oy), ot(ot), dir(dir) {}
};

priority_queue< pair <int , int> , vector< pair <int , int> > , greater< pair <int , int> > > drop;
vector<Sta> sta;
int a[N][N], R, C;
int ox[N], oy[N];
int nex[4][N][N];

bool inside(int x, int y)
{
    if (x >= 0 && x < R)
        if (y >= 0 && y < C)
            return true;
    return false;
}

void explode(int x, int y, int ti)
{
    a[x][y] = -ti;
    for (int d = 0; d < 4; d++)
    {
        int nx = x, ny = y;
        if (d & 1)
        {
            while (inside(nex[d][nx][ny], ny) && a[nx][ny] <= 0)
                nx = nex[d][nx][ny];
            if (a[nx][ny] <= 0)
                continue;
            sta.push_back(Sta(x, y, ti, d));
            drop.push(make_pair(abs(nx - x) + ti, sta.size()));
        } else
        {
            while (inside(nx, nex[d][nx][ny]) && a[nx][ny] <= 0)
                ny = nex[d][nx][ny];
            if (a[nx][ny] <= 0)
                continue;
            sta.push_back(Sta(x, y, ti, d));
            drop.push(make_pair(abs(ny - y) + ti, sta.size()));
        }
    }
}

int main()
{
    freopen("J.in", "r", stdin);
    int n, T;
    while (scanf("%d %d %d %d", &R, &C, &n, &T) != EOF)
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                a[i][j] = 0;
        for (int i = 0; i < n; i++)
        {
            int z;
            scanf("%d %d %d", &ox[i], &oy[i], &z);
            ox[i]--, oy[i]--;
            a[ox[i]][oy[i]] = z;
        }
        for (int i = 0; i < R; i++)
        {
            nex[0][i][0] = -1;
            for (int j = 1; j < C; j++)
                if (a[i][j - 1])
                    nex[0][i][j] = j - 1;
                else
                    nex[0][i][j] = nex[0][i][j - 1];
            nex[2][i][n - 1] = n;
            for (int j = n - 2; j >= 0; j--)
                if (a[i][j + 1])
                    nex[2][i][j] = j + 1;
                else
                    nex[2][i][j] = nex[2][i][j + 1];
        }
        for (int j = 0; j < C; j++)
        {
            nex[1][0][j] = -1;
            for (int i = 1; i < R; i++)
                if (a[i - 1][j])
                    nex[1][i][j] = i - 1;
                else
                    nex[1][i][j] = nex[1][i - 1][j];
            nex[3][n - 1][j] = -1;
            for (int i = n - 2; i >= 0; i--)
                if (a[i + 1][j])
                    nex[3][i][j] = i + 1;
                else
                    nex[3][i][j] = nex[3][i + 1][j];
        }
//        for (int i = 0; i < R; i++)
//            for (int j = 0; j < C; j++)
//                printf("%d%c", nex[3][i][j], " \n"[j == C - 1]);
        int fx, fy;
        scanf("%d %d", &fx, &fy);
        while (drop.size())
            drop.pop();
        sta.clear();
        int ti = 0;
        explode(fx - 1, fy - 1, ti);
        while (drop.size())
        {
            ti = drop.top().first;
            while (ti <= T && drop.top().first == ti)
            {
                int k = drop.top().second;
                drop.pop();
                int ox = sta[k].ox, oy = sta[k].oy;
                int ot = sta[k].ot, dir = sta[k].dir;
                int nx = ox, ny = oy, nt = ot;
                if (dir & 1)
                    while (inside(nx, ny) && abs(nex[dir][nx][ny] - ox) < ti - ot)
                        nx = nex[dir][nx][ny];
                else
                    while (inside(nx, ny) && abs(nex[dir][nx][ny] - oy) < ti - ot)
                        ny = nex[dir][nx][ny];
                if (inside(nx, ny))
                {
                    if (a[nx][ny] <= 0)
                    {
                        if (dir & 1)
                        {
                            while (inside(nx, ny) && a[nx][ny] <= 0)
                            {
                                nt += abs(nex[dir][nx][ny] - nx);
                                nx = nex[dir][nx][ny];
                            }
                            if (inside(nx, ny))
                            {
                                drop.push(make_pair(nt, k));
                                continue;
                            }
                        } else
                        {
                            while (inside(nx, ny) && a[nx][ny] <= 0)
                            {
                                nt += abs(nex[dir][nx][ny] - ny);
                                ny = nex[dir][nx][ny];
                            }
                            if (inside(nx, ny))
                            {
                                drop.push(make_pair(nt, k));
                                continue;
                            }
                        }
                    } else
                        a[nx][ny]++;
                } else
                    continue;
            }
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (a[i][j] > 4)
                        explode(i, j, ti);
        }
        for (int i = 0; i < n; i++)
            if (a[ox[i]][oy[i]] < 0)
                printf("0 %d\n", -a[ox[i]][oy[i]]);
            else
                printf("1 %d\n", a[ox[i]][oy[i]]);
    }
    return 0;
}
