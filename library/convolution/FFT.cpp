template <int mod>
vector<int> multiply(vector<int> &a, vector<int> &b) {
    using mint = modint<mod>;
    using mint1 = modint<167772161>;
    using mint2 = modint<469762049>;
    using mint3 = modint<595591169>;
    NTT<mint1> ntt1;
    NTT<mint2> ntt2;
    NTT<mint3> ntt3;
    vector<mint1> a1(begin(a), end(a)), b1(begin(b), end(b));
    vector<mint2> a2(begin(a), end(a)), b2(begin(b), end(b));
    vector<mint3> a3(begin(a), end(a)), b3(begin(b), end(b));
    auto x = ntt1.multiply(a1, b1);
    auto y = ntt2.multiply(a2, b2);
    auto z = ntt3.multiply(a3, b3);
    const int m1 = 167772161, m2 = 469762049, m3 = 595591169;
    const auto m1_inv_m2 = mint2(m1).inverse().get();
    const auto m12_inv_m3 = (mint3(m1) * m2).inverse().get();
    const auto m12_mod = (mint(m1) * m2).get();
    vector<int> ret(x.size());
    for (int i = 0; i < x.size(); i++) {
        auto v1 = ((mint2(y[i]) + m2 - x[i].get()) * m1_inv_m2).get();
        auto v2 =
            ((z[i] + m3 - x[i].get() - mint3(m1) * v1) * m12_inv_m3).get();
        ret[i] = (mint(x[i].get()) + mint(m1) * v1 + mint(m12_mod) * v2).get();
    }
    return ret;
}