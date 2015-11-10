#include <bits/stdc++.h>

using namespace std;

double sqr(double x)
{
    return x * x;
}

int main()
{
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    double t1, h1, t2, h2;
    scanf("%lf %lf %lf %lf", &h1, &t1, &h2, &t2);

    double a = h1 - h2;
    double b = 2.0 * (t1 * h2 - t2 * h1);
    double c = h1 * sqr(t2) - h2 * sqr(t1);

    double delta = b * b - 4.0 * a * c;
    double x1 = (-b + sqrt(delta)) / (2.0 * a);
    double x2 = (-b - sqrt(delta)) / (2.0 * a);
    double g1 = 2.0 * h1 / sqr(t1 - x1);
    double g2 = 2.0 * h2 / sqr(t1 - x2);

//    printf("%f %f\n", x1, g1);
//    printf("%f %f\n", x2, g2);

    if (x1 <= t1 && x1 <= t2 && x1 > -1e-7 && g1 > -1e-7)
        printf("%f\n", x1);
    else
        printf("%f\n", x2);
    return 0;
}
