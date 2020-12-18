namespace FFT {

using i64 = int64_t;
using u128 = __uint128_t;
constexpr int32_t m0 = 167772161;
constexpr int32_t m1 = 469762049;
constexpr int32_t m2 = 754974721;
using mint0 = modint<m0>;
using mint1 = modint<m1>;
using mint2 = modint<m2>;
constexpr int r01 = 104391568;
constexpr int r02 = 323560596;
constexpr int r12 = 399692502;
constexpr int r02r12 = i64(r02) * r12 % m2;
constexpr i64 w1 = m0;
constexpr i64 w2 = i64(m0) * m1;

template <typename T, typename submint>
vector<submint> mul(const vector<T>& a, const vector<T>& b) {
    NTT<submint> ntt;
    vector<submint> s(a.size()), t(b.size());
    for (int i = 0; i < (int)a.size(); ++i)
        s[i] = i64(a[i] % submint::get_mod());
    for (int i = 0; i < (int)b.size(); ++i)
        t[i] = i64(b[i] % submint::get_mod());
    return ntt.multiply(s, t);
}

template <typename T>
vector<int> multiply(const vector<T>& s, const vector<T>& t, int Mod) {
    auto d0 = mul<T, mint0>(s, t);
    auto d1 = mul<T, mint1>(s, t);
    auto d2 = mul<T, mint2>(s, t);
    int n = d0.size();
    vector<int> ret(n);
    const int W1 = w1 % Mod;
    const int W2 = w2 % Mod;
    for (int i = 0; i < n; i++) {
        int n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();
        int b = i64(n1 + m1 - a) * r01 % m1;
        int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;
        ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) % Mod;
    }
    return ret;
}
template <typename Mint>
vector<Mint> multiply(const vector<Mint>& a, const vector<Mint>& b) {
    vector<int> s(a.size()), t(b.size());
    for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();
    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();
    vector<int> u = multiply<int>(s, t, Mint::get_mod());
    vector<Mint> ret(u.size());
    for (int i = 0; i < (int)u.size(); ++i) ret[i] = Mint(u[i]);
    return ret;
}

template <typename T>
vector<u128> multiply_u128(const vector<T>& s, const vector<T>& t) {
    auto d0 = mul<T, mint0>(s, t);
    auto d1 = mul<T, mint1>(s, t);
    auto d2 = mul<T, mint2>(s, t);
    int n = d0.size();
    vector<u128> ret(n);
    for (int i = 0; i < n; i++) {
        i64 n1 = d1[i].get(), n2 = d2[i].get();
        i64 a = d0[i].get();
        u128 b = (n1 + m1 - a) * r01 % m1;
        u128 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
        ret[i] = a + b * w1 + c * w2;
    }
    return ret;
}
};  // namespace FFT
