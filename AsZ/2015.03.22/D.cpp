#include <bits/stdc++.h>

using namespace std;

vector< pair<long long , int> > a;
vector<int> num;

bool cmp1(int g, int h)
{
	return a[g].first > a[h].first;
}

bool cmp2(int g, int h)
{
	if (a[g].second > a[h].second)
		return true;
	if (a[g].second < a[h].second)
		return false;
	return a[g].first > a[h].first;
}

int main()
{
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long x;
		int ty;
		cin >> x >> ty;
		a.push_back(make_pair(x, ty));
		num.push_back(i);
	}
	sort(num.begin(), num.end(), cmp1);


	int k = 0;
	long long tot = 0;
	while (k < n && tot < m)
		tot += a[num[k++]].first;
	if (tot < m)
	{
		cout << "Err" << endl;
		return -1;
	}


	sort(num.begin(), num.begin() + k, cmp2);
	sort(num.begin() + k, num.begin() + n, cmp2);
	int l = k - 1, r = k;
	while (l >= 0 && r < n)
	{
		int g = num[l], h = num[r];

		if (a[g].second)
			break;
		if (!a[h].second)
			break;

		long long tmp = a[g].first - a[h].first;
		if (tot - tmp < m)
			break;
		tot -= tmp;
		swap(num[l], num[r]);
		l--, r++;
	}


	int cnt = 0;
	for (int i = 0; i < k; i++)
		if (a[num[i]].second)
			cnt++;
	cout << k << " " << cnt << endl;
	cout << num[0] + 1;
	for (int i = 1; i < k; i++)
		cout << " " << num[i] + 1;
	cout << endl;
	return 0;
}
