#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset((a), (b), sizeof(a))
#define MAXN 2012345

using namespace std;

struct node
{
	long long sum;
	int lazy;
}g[MAXN * 4];

int a[MAXN], t, h;

void update(int x)
{
	for (x >>= 1; x; x >>= 1)
	{
        g[x].sum = 0;
        if (g[x << 1].lazy == 0) g[x].sum += g[x << 1].sum;
        if (g[x << 1 ^ 1].lazy == 0) g[x].sum += g[x << 1 ^ 1].sum;
	}
}

void pushDown(int tt)
{
	for (int i = h; i >= 1; --i)
	{
		int x = tt >> i;
		if (g[x].lazy)
		{
			g[x << 1].lazy = 1;
			g[x << 1].sum = 0;
			g[x << 1 ^ 1].lazy = 1;
			g[x << 1 ^ 1].sum = 0;
		}

	}
}

void changeDecPoint(int x, long long value)
{
	x += t;
	pushDown(x);
	g[x].sum -= value;
    update(x);
}

void changeInteviewZero(int l, int r)
{
	if (l > r) return ;
	l += t - 1, r += t + 1;
    pushDown(l);
    pushDown(r);
    int ll = l, rr = r;
    for (; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
		if (!(l & 1))
		{
			g[l + 1].lazy = 1;
			g[l + 1].sum = 0;
		}
		if (r & 1)
		{
			g[r - 1].lazy = 1;
			g[r - 1].sum = 0;
		}
    }
    update(ll);
    update(rr);
}

long long ask(int l, int r)
{
	if (l > r) return 0;
	l += t - 1, r += t + 1;
	pushDown(l);
	pushDown(r);
	long long tmp = 0;
    for (; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
		if (!(l & 1)) tmp += g[l + 1].sum;
		if (r & 1) tmp += g[r - 1].sum;
    }
    return tmp;
}

void cutDown(int L, int R, long long value)
{
	int l = L, r = R;
	for (; l < r; )
	{
		int mid = (l + r + 1) >> 1;
		long long tmp = ask(mid, R);
		if (tmp >= value) l = mid;
		else r = mid - 1;
	}
    long long tmp = value - ask(l + 1, R);
    changeInteviewZero(l + 1, R);
    changeDecPoint(l, tmp);
}

int main()
{
	//freopen("G.in", "r", stdin);
	int n, k, minA = 1;
	scanf("%d%d", &n, &k);
	REPP(i, 1, n)
	{
		scanf("%d", &a[i]);
		minA = min(minA, a[i]);
	}
	MST(g, 0);
    for (t = 1, h = 0; t <= n + 2; t <<= 1, h++);
	REPP(i, 1, n)
		g[i + t].sum = a[i] - minA;
    for (int i = t - 1; i >= 1; --i)
		g[i].sum = g[i << 1].sum + g[i << 1 ^ 1].sum;

	long long ans = 0;
	for (int i = k; i <= n; ++i)
	{
        long long now = ask(i - k + 1, i);
		now += 1LL * minA * k + 1;
		if (now <= 0) continue;
        ans += now;
        cutDown(i - k + 1, i, now);
	}
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
    {
		pushDown(i + t);
		//if (g[i + t].lazy == 0)
		cout << g[i + t].sum + minA;
		//else cout << minA;
        if (i < n) cout << " ";
        else cout << endl;
    }
	return 0;
}
