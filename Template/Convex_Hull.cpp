vector<Point> Convex_Hull(vector<Point> vertex)
{
    sort(vertex.begin(), vertex.end(), cmp);

    int n = vertex.size();
    vector<Point> C;

    int m;

    REP(i, n)
    {
        while ((m = C.size()) > 1
            && v_mul(C[m - 1] - C[m - 2], vertex[i] - C[m - 2]) < EPS)
                C.pop_back();
        C.PB(vertex[i]);
    }

    int k = C.size();
    RED(i, n - 1)
    {
        while ((m = C.size()) > k
            && v_mul(C[m - 1] - C[m - 2], vertex[i] - C[m - 2]) < EPS)
                C.pop_back();
        C.PB(vertex[i]);
    }
    C.pop_back();

    return C;
}
