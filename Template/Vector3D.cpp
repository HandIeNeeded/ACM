const int N = 4;
const double pi = acos(-1);

Matrix Init_scale(double a, double b, double c) {
    Matrix ans;
    ans[0][0] = a, ans[1][1] = b, ans[2][2] = c, ans[3][3] = 1.0;
    return ans;
}

Matrix Init_trans(double a, double b, double c) {
    Matrix ans(1);
    ans[3][0] = a, ans[3][1] = b, ans[3][2] = c;
    return ans;
}

double sqr(double x) { return x * x; }

Matrix Init_rotate(double a, double b, double c, double d) {
    d = d * pi / 180.0;//0-360
    double norm = sqrt(sqr(a) + sqr(b) +sqr(c));
    double x = a / norm, y = b / norm, z = c / norm, cosd = cos(d), sind = sin(d);
    Matrix ans;
    ans[0][0] = cosd + (1 - cosd) * sqr(x);
    ans[1][0] = (1 - cosd) * x * y - sind * z;
    ans[2][0] = (1 - cosd) * x * z + sind * y;
    ans[0][1] = (1 - cosd) * y * x + sind * z;
    ans[1][1] = cosd + (1 - cosd) * sqr(y);
    ans[2][1] = (1 - cosd) * y * z - sind * x;
    ans[0][2] = (1 - cosd) * z * x - sind * y;
    ans[1][2] = (1 - cosd) * z * y + sind * x;
    ans[2][2] = cosd + (1 - cosd) * sqr(z);
    ans[3][3] = 1.0;
    return ans;
}
