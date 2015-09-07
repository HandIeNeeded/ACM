#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int MO = 100;
const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];

map<deque<pair<int, int> >, int> shape[9];
int g[100][100], cnt[10];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int mp[111][111];

void modify(deque<pair<int, int> > &snake) {
    int n = snake.size();
    REPP(i, 1, n - 1) {
        snake[i].first -= snake[0].first;
        snake[i].second -= snake[0].second;
    }
    snake[0] = make_pair(0, 0);
}

deque<pair<int, int> > q;
void dfs(int now, int x, int y) {
    if (now > 8) return ;
    q.push_front(make_pair(x, y));
    g[x + 10][y + 10] = 1;
    deque<pair<int, int> > tmp = q;
    modify(tmp);
    shape[now][tmp] = cnt[now]++;
    REP(i, 4) {
        int tx = x + dx[i], ty = y + dy[i];
        if (!g[tx + 10][ty + 10]) {
            dfs(now + 1, tx, ty);
        }
    }
    g[x + 10][y + 10] = 0;
    q.pop_front();
}

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());

    dfs(1, 0, 0);
    //REPP(i, 1, 8) {
    //    cout << cnt[i] << ' ' ;
    //}
    //cout << endl;

    int L = 20;
    int n = L, m = L, l = 5, k = 20;
    cout << n << ' ' << m << ' ' << l << endl;
    int r = rand() % cnt[l];
    auto it = shape[l].begin();
    REP(i, r) it++;
    deque<pair<int, int> > tmp = it->first;
    //REP(i, tmp.size()) {
    //    cout << tmp[i].first << ' ' << tmp[i].second << endl;
    //}
    //cout << "hehe" << endl;
    int notready = 1;
    int x, y;
    while (notready) {
        x = rand() % n + 1, y = rand() % m + 1;
        int bad = 0;
        REP(i, tmp.size()) {
            if (x + tmp[i].first < 1 || x + tmp[i].first > n) {
                bad = 1;
                break;
            }
            if (y + tmp[i].second < 1 || y + tmp[i].second > m) {
                bad = 1;
                break;
            }
        }
        notready = bad;
    }
    REP(i, l) {
        cout << x + tmp[i].first << ' ' << y + tmp[i].second << endl;
        mp[x + tmp[i].first][y + tmp[i].second] = i + 1;
    }
    //REPP(i, 1, n) {
    //    REPP(j, 1, m) {
    //        cout << mp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    mp[1][1] = 1;
    cout << k << endl;
    REP(i, k) {
        notready = 1;
        while (notready) {
            x = rand() % n + 1, y = rand() % m + 1;
            if (!mp[x][y]) {
                notready = 0;
            }
        }
        cout << x << ' ' << y << endl;
    }
    cout << "0 0 0" << endl;
    

	return 0;
}

