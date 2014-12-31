#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<set>
#include<vector>
#include<iomanip>
#include<cctype>
#include<string>
#include<memory>
#include<map>
#include<sstream>
#pragma warning (disable : 4996)
#define mem(a) memset(a, 0, sizeof(a))
#define sl(a) strlen(a)
#define LL long long
#define dou double
const int Mod = 1000000007;
const int N = 100005;
using namespace std;

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w",stdout);*/
	LL re, n, m, i, j, k, st, en, cnt;
	cin >> n;
	st = -1, en = 1000000015;
	while (1){
		if (st + 1 >= en) break;
		m = (st + en) >> 1;
		cnt = 0;
		 k = m;
		while (k){
			cnt += k / 5; k /= 5;
		}
		if (cnt >= n) en = m;
		else st = m;
		//cout << cnt << endl;
	}
	//cout << st << endl;
	cnt = 0, k = en;
	while (en){
		cnt += en / 5; en /= 5;
	}
	if (cnt == n) cout << k << endl;
	else cout << "No solution\n";

	return 0;
}

