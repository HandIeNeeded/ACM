#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

const int N = 1000;

int x[N], gap[N], sa[N], id[N][N];
std::vector <std::pair <int, int> > pairs[N * N];

bool compare(int i, int j)
{
	int k = 0;
	while (gap[i + k] == gap[j + k]) {
		k ++;
	}
	return gap[i + k] < gap[j + k];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++ i) {
		scanf("%d", x + i);
		x[i] --;
	}
	for (int i = 0; i + 1 < m; ++ i) {
		gap[i] = x[i + 1] - x[i];
		sa[i] = i;
	}
	gap[m - 1] = -1;
	std::sort(sa, sa + m - 1, compare);
	for (int i = 0; i < m; ++ i) {
		id[i][i] = 0;
	}
	int kind = 1;
	for (int ii = 0; ii < m - 1; ++ ii) {
		int i = sa[ii];
		int j = ii ? sa[ii - 1] : -1;
		bool equal = j != -1;
		for (int k = i + 1; k < m; ++ k) {
			if (j != -1 && equal) {
				equal &= gap[k - 1] == gap[j + k - i - 1];
			}
			id[i][k] = equal ? id[j][j + k - i] : kind ++;
		}
	}
	for (int i = 0; i < m; ++ i) {
		int left = x[i] - (i ? x[i - 1] : -1) - 1;
		for (int j = i; j < m; ++ j) {
			int right = (j == m - 1 ? n : x[j + 1]) - x[j] - 1;
			pairs[id[i][j]].push_back(std::make_pair(left, right));
		}
	}
	long long result = std::max(x[0], n - 1 - x[m - 1]);
	for (int i = 0; i + 1 < m; ++ i) {
		result = std::max(result, x[i + 1] - x[i] - 1LL);
	}
	for (int i = 0; i < kind; ++ i) {
		std::vector <std::pair <int, int> > &ps = pairs[i];
		std::sort(ps.begin(), ps.end());
		std::vector <std::pair <int, int> > stack;
		for (int j = 0; j < (int)ps.size(); ++ j) {
			while (!stack.empty() && stack.back().second <= ps[j].second) {
				stack.pop_back();
			}
			stack.push_back(ps[j]);
		}
		for (int j = 0; j < (int)stack.size(); ++ j) {
			long long last = j ? stack[j - 1].first : -1;
			result += (stack[j].first - last) * (stack[j].second + 1LL);
		}
	}
	std::cout << result << std::endl;
	return 0;
}
