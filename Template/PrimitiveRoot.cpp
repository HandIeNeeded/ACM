struct Root{
    //p^k, 2*p^k, 2, 4
    int phi, g, p;
    vector<int> fac;

    void getfac(int phi) {
        fac.clear();
        for (int i = 2; i * i <= phi; i ++) {//prime
            if (phi % i == 0) {
                fac.push_back(i);
                while (phi % i == 0) {
                    phi /= i;
                }
            }
        }
        if (phi > 1) fac.push_back(phi);//important
    }

    int primitive_root(int x) {
        p = x, phi = p - 1, getfac(phi);
        REPP(i, 1, phi) {
            bool bad = 0;
            REP(j, fac.size()) {
                if (pow_mod(i, phi / fac[j], p) == 1) {
                    bad = 1;
                    break;
                }
            }
            if (!bad) return g = i;
        }
        return -1;
    }
}go;

