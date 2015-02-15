double simpson(double l, double r)
{
    double mid = (l + r) / 2;
    return (r - l) * (F(l) + 4 * F(mid) + F(r)) / 6;
}

double auto_simpson(double l, double r, double prec, double s)
{
    double mid = (l + r) / 2;
    double s1 = simpson(l, mid);
    double s2 = simpson(mid, r);
    if (fabs(s1 + s2 - s) / 15.0 < prec)
        return s1 + s2 + (s1 + s2 - s) / 15;
    return auto_simpson(l, mid, prec / 2, s1) + auto_simpson(mid, r, prec / 2, s2);
}
