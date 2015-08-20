#include <bits/stdc++.h>

using namespace std;

const long long oo = (long long) 1e18;
long long ans;

typedef long long ll;

ll dfs(ll L, ll R)
{
    if (R > ans) return oo;
    if (L == 0) return R;
    if (L < 0) return oo;
  //  cout << R;
	if (R - L + 1 > L + 1)
		return oo;
    ll nl, nr, tmp = oo;
    //lson
	nl = L;
		//a
	nr = R * 2 - nl;
	if (nr > nl)
		tmp = min(tmp, dfs(nl, nr));
	nr++;
	if (nr > nl)
		tmp = min(tmp, dfs(nl, nr));

	//rson
	nr = R;
	nl = 2 * (L - 1) - nr;
	if (nr > nl)
		tmp = min(tmp, dfs(nl, nr));
	nl ++;
	if (nr > nl)
	tmp = min(tmp, dfs(nl, nr));
	return tmp;
}

int main()
{
	//freopen("H.in", "r", stdin);
	int L, R;
	for (; scanf("%d%d", &L, &R) != EOF;)
	{
		ans = oo;
		ans = dfs(1LL * L, 1LL * R);
		if (ans == oo)
			cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
