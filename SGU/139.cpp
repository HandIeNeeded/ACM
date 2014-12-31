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
const int N = 300005;
using namespace std;

struct po{
	int x, y;
}now[20];

void swap(po &a, po &b){
	po tem;
	tem = a; a = b; b = tem;
}

int s[5][5];

int go(void){
	int cnt = 0, i, j, k, t, x, y, tem;
	for (i = 1; i < 16; ++i){
		x = now[i].x, y = now[i].y;
		while (x != (i - 1) / 4){
			while (y != (i - 1) % 4){
				if (y > (i - 1) % 4){
					swap(now[i], now[s[x][y - 1]]);
					if (s[x][y - 1]) cnt++;
					tem = s[x][y];
					s[x][y] = s[x][y - 1];
					s[x][y - 1] = tem;
				}
				else{
					swap(now[i], now[s[x][y + 1]]);
					if (s[x][y + 1]) cnt++;
					tem = s[x][y];
					s[x][y] = s[x][y + 1];
					s[x][y + 1] = tem;
				}
				x = now[i].x, y = now[i].y;
			}
			x = now[i].x, y = now[i].y;
			swap(now[i], now[s[x - 1][y]]);
			if (s[x - 1][y]) cnt++;
			tem = s[x][y];
			s[x][y] = s[x - 1][y];
			s[x- 1][y] = tem;
			x = now[i].x, y = now[i].y;
		}
		x = now[i].x, y = now[i].y;//这里这部不能忘，就是行号本来正确的时候还要调整列号，上一步是行号不对的时候先调整列号
		while (y != (i - 1) % 4){
			if (y > (i - 1) % 4){
					swap(now[i], now[s[x][y - 1]]);
					if (s[x][y - 1]) cnt++;
					tem = s[x][y];
					s[x][y] = s[x][y - 1];
					s[x][y - 1] = tem;
			}
			else{
					swap(now[i], now[s[x][y + 1]]);
					if (s[x][y + 1]) cnt++;
					tem = s[x][y];
					s[x][y] = s[x][y + 1];
					s[x][y + 1] = tem;
			}
			x = now[i].x, y = now[i].y;
		}
	}
	return cnt;
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w",stdout);*/
	int n, i , j, k, cnt =0, x;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j){
			cin >> x; now[x].x = i, now[x].y = j;
			s[i][j] = x;
		}
	cnt = go();
	if (cnt & 1) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}

