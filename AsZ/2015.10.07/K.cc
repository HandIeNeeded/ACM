#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

struct point{
    LL x, y;
}p[4];

point operator - (const point &a, const point &b) {
    return (point) {a.x - b.x, a.y - b.y};
}

LL det(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

LL dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

LL sqr(LL x) {
    return x * x;
}

LL dis(const point &a, const point &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

bool equal() {
    return dis(p[0], p[1]) == dis(p[1], p[2]) && dis(p[1], p[2]) == dis(p[2], p[3]) && 
        dis(p[2], p[3]) == dis(p[3], p[0]) && dis(p[3], p[0]) == dis(p[0], p[1]);
}

bool parallel() {
    point a = p[1] - p[0], b = p[3] - p[2];
    point c = p[2] - p[1], d = p[0] - p[3];
    return det(a, b) == 0 && det(c, d) == 0;
}

bool right() {
    point a = p[1] - p[0], b = p[3] - p[2];
    point c = p[2] - p[1], d = p[0] - p[3];
    return dot(a, c) == 0 && dot(a, d) == 0 && dot(b, c) == 0 && dot(b, d) == 0;
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        REP(i, 4) {
            scanf("%lld%lld\n", &p[i].x, &p[i].y);
        }
        printf("Case #%d: ", ca++);
        if (equal()) {
            //square
            if (right() && parallel()) {
                puts("Square");
            }
            //diamond
            else {
                puts("Diamond");
            }
        }
        else {
            if (parallel()) {
                if (right()) {
                    puts("Rectangle");
                }
                else {
                    puts("Parallelogram");
                }
            }
            else {
                puts("Others");
            }
        }
    }
    return 0;
}


