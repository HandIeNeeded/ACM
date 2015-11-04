#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
typedef long long LL;
using namespace std;


int calc(bool flag[])
{
    int  ret = 0;
    bool pre = false;
    for(int i = 0; i < 50; i++) {
        if(flag[i]) {
            if(false == pre) {
                pre = true;
                ret ++;
            }
        } else {
            pre = false;
        }
    }
    return ret;
}

int getLeast( vector<string> picture)

{
    int n = picture.size();
    int m = picture[0].length();
    bool flag[55];
    int ret = 0;
    for(int i = 0; i < n; i++) {
        memset(flag, false, sizeof(flag));
        int x = i, y = 0, tot = -1;
        while(x >= 0 && y < m) {
            tot++;
            if(picture[x][y] == 'B' || picture[x][y] == 'G') {
                flag[tot] = true;
            }
            x --;
            y ++;
        }
        ret += calc(flag);
    }
    for(int i = 1; i < m; i++) {
        memset(flag, false, sizeof(flag));
        int x = n - 1, y = i, tot = -1;
        while(x >= 0 && y < m) {
            tot++;
            if(picture[x][y] == 'B' || picture[x][y] == 'G') flag[tot]=true;
            x--;
            y++;
        }
        ret += calc(flag);
    }

    for(int i = 0; i < m; i++) {
        memset(flag, false, sizeof(flag));
        int x = 0, y = m - 1 - i, tot = -1;
        while(x < n && y < m) {
            tot++;
            if(picture[x][y] == 'R' || picture[x][y] == 'G') {
                flag[tot] = true;
            }
            x ++;
            y ++;
        }
        ret += calc(flag);
    }
    for(int i = 1; i < n; i++) {
        memset(flag, false, sizeof(flag));
        int x = i, y = 0, tot = -1;
        while(x < n  && y < m) {
            tot++;
            if(picture[x][y] == 'R' || picture[x][y] == 'G') flag[tot]=true;
            x++;
            y++;
        }
        ret += calc(flag);
    }
    return ret;
} 

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        assert(n <= 50);
        vector<string> picture(n);
        for(int i = 0; i < n; i++) {
            cin >> picture[i];
        }
        printf("%d\n", getLeast(picture));
    }
    return 0;
}

