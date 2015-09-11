#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

struct List{
    int start, length, type, num;
    int pre, next;
}p[N];

int node;

int Node(int s, int l, int t, int x, int p, int n) {
    ::p[node] = (List) {s, l, t, x, p, n};
    return node++;
}

int merge(int a, int b) {
    p[a].next = p[b].next;
    p[a].length += p[b].length;
    if (p[b].next) p[p[b].next].pre = a;
    return a;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    Node(0, 0, -1, 0, 0, 0);
    int head = Node(0, m, 0, 0, 0, 0);
    int step = head;
    REPP(i, 1, n) {
        int x;
        scanf("%d", &x);
        int find = 0;
        for (int now = head; now; now = p[now].next) {
            if (p[now].type == 0 && p[now].length >= x) {
                find = 1;
                int y = p[now].next;
                if (p[now].length > x) {
                    int left = p[now].length - x;
                    int tmp = Node(p[now].start + x, left, 0, 0, now, y);
                    p[now].next = tmp, p[y].pre = tmp;
                }
                p[now].length = x, p[now].num = i, p[now].type = 1;
                p[p[now].next].pre = now;
                break;
            }
        }
        if (!find) {
            int begin = step;
            while (1) {
                while (p[begin].type == 0) {
                    begin = p[begin].next;
                    if (begin == 0) {
                        begin = head;
                    }
                }
                int b = p[begin].pre, c = p[begin].next;
                p[begin].type = p[begin].num = 0;
                if (p[b].type == p[begin].type) begin = merge(b, begin);
                if (p[c].type == p[begin].type) begin = merge(begin, c);
                if (p[begin].length >= x) {
                    p[begin].type = p[begin].num = 0;
                    int y = p[begin].next;
                    if (p[begin].length > x) {
                        int left = p[begin].length - x;
                        int tmp = Node(p[begin].start + x, left, 0, 0, begin, y);
                        p[begin].next = tmp;
                        p[y].pre = tmp;
                    }
                    p[begin].length = x, p[begin].num = i, p[begin].type = 1;
                    p[p[begin].next].pre = begin;

                    step = p[begin].next;
                    if (step == 0) step = head;
                    break;
                }
                else {
                    begin = p[begin].next;
                    if (begin == 0) {
                        begin = head;
                    }
                }
            }
        }
        //for (int now = head; now; now = p[now].next) {
        //    cout << "(n: " << p[now].num << ','<<"s: " << p[now].start << ',' << "l: " << p[now].length << ')'<< "->";
        //}
        //cout << endl;
    }
    int begin = step;
    while (1) {
        printf("%d %d\n", p[begin].num, p[begin].start);
        begin = p[begin].next;
        if (begin == 0) begin = head;
        if (begin == step) break;
    }

    return 0;
}

