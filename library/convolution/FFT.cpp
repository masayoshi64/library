// namespace FastFourierTransform {
// using real = long double;

// struct C {
//     real x, y;

//     C() : x(0), y(0) {}

//     C(real x, real y) : x(x), y(y) {}

//     inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

//     inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

//     inline C operator*(const C &c) const {
//         return C(x * c.x - y * c.y, x * c.y + y * c.x);
//     }

//     inline C conj() const { return C(x, -y); }
// };

// const real PI = acosl(-1);
// int base = 1;
// vector<C> rts = {{0, 0}, {1, 0}};
// vector<int> rev = {0, 1};

// void ensure_base(int nbase) {
//     if (nbase <= base) return;
//     rev.resize(1 << nbase);
//     rts.resize(1 << nbase);
//     for (int i = 0; i < (1 << nbase); i++) {
//         rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
//     }
//     while (base < nbase) {
//         real angle = PI * 2.0 / (1 << (base + 1));
//         for (int i = 1 << (base - 1); i < (1 << base); i++) {
//             rts[i << 1] = rts[i];
//             real angle_i = angle * (2 * i + 1 - (1 << base));
//             rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
//         }
//         ++base;
//     }
// }

// void fft(vector<C> &a, int n) {
//     assert((n & (n - 1)) == 0);
//     int zeros = __builtin_ctz(n);
//     ensure_base(zeros);
//     int shift = base - zeros;
//     for (int i = 0; i < n; i++) {
//         if (i < (rev[i] >> shift)) {
//             swap(a[i], a[rev[i] >> shift]);
//         }
//     }
//     for (int k = 1; k < n; k <<= 1) {
//         for (int i = 0; i < n; i += 2 * k) {
//             for (int j = 0; j < k; j++) {
//                 C z = a[i + j + k] * rts[j + k];
//                 a[i + j + k] = a[i + j] - z;
//                 a[i + j] = a[i + j] + z;
//             }
//         }
//     }
// }

// vector<int64_t> multiply(const vector<int> &a, const vector<int> &b) {
//     int need = (int)a.size() + (int)b.size() - 1;
//     int nbase = 1;
//     while ((1 << nbase) < need) nbase++;
//     ensure_base(nbase);
//     int sz = 1 << nbase;
//     vector<C> fa(sz);
//     for (int i = 0; i < sz; i++) {
//         int x = (i < (int)a.size() ? a[i] : 0);
//         int y = (i < (int)b.size() ? b[i] : 0);
//         fa[i] = C(x, y);
//     }
//     fft(fa, sz);
//     C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
//     for (int i = 0; i <= (sz >> 1); i++) {
//         int j = (sz - i) & (sz - 1);
//         C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
//         fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
//         fa[i] = z;
//     }
//     for (int i = 0; i < (sz >> 1); i++) {
//         C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
//         C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
//         fa[i] = A0 + A1 * s;
//     }
//     fft(fa, sz >> 1);
//     vector<int64_t> ret(need);
//     for (int i = 0; i < need; i++) {
//         ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
//     }
//     return ret;
// }
// };  // namespace FastFourierTransform
// #include "library/convolution/NTT.cpp"
// #include "library/mod/modint.cpp"
// template <typename Mint>
// struct FFT {
//     constexpr int mod0 = 1045430273;
//     constexpr int mod1 = 1051721729;
//     constexpr int mod2 = 1053818881;
//     using mint0 = modint<mod0>;
//     using mint1 = modint<mod1>;
//     using mint2 = modint<mod2>;
//     NTT<mint0> ntt0;
//     NTT<mint1> ntt1;
//     NTT<mint2> ntt2;
//     vector<Mint> multiply(const vector<int> &x, const vector<int> &y) {
//         auto d0 = ntt0.multiply(x, y);
//         auto d1 = ntt1.multiply(x, y);
//         auto d2 = ntt2.multiply(x, y);
//         int n = d0.size();
//         vector<Mint> res(n);
//         static const mint1 r01 = mint1(mint0.get_mod()).inv();
//         static const mint2 r02 = mint2(mint0.get_mod()).inv();
//         static const mint2 r12 = mint2(mint1.get_mod()).inv();
//         static const mint2 r02r12 = r02 * r12;
//         static const Mint w1 = Mint(mint0.get_mod());
//         static const Mint w2 = w1 * Mint(mint1.get_mod());
//         rep(i, n) {
//             ull a = d0[i].v;
//             ull b = (d1[i].v + mint1.get_mod() - a) * r01.v %
//             mint1.get_mod(); ull c = ((d2[i].v + mint2.get_mod() - a) *
//             r02r12.v +
//                      (mint2.get_mod() - b) * r12.v) %
//                     mint2.get_mod();
//             res[i].v = (a + b * w1.v + c * w2.v) % Mint.get_mod();
//         }
//         return res;
//     }
// };

// template <class mint>
// void inplace_fmt(vector<mint> &f, bool inv) {
//     const int n = f.size();
//     static vector<mint> g, ig, p2;
//     if (g.size() == 0) {
//         rep(i, 30) {
//             mint w = -mint::root().pow(((mint::mod - 1) >> (i + 2)) * 3);
//             g.pb(w);
//             ig.pb(w.inv());
//             p2.pb(mint(1 << i).inv());
//         }
//     }
//     static constexpr uint mod2 = mint::mod * 2;
//     if (!inv) {
//         int b = n;
//         if (b >>= 1) {  // input:[0,mod)
//             rep(i, b) {
//                 uint x = f[i + b].x;
//                 f[i + b].x = f[i].x + mint::mod - x;
//                 f[i].x += x;
//             }
//         }
//         if (b >>= 1) {  // input:[0,mod*2)
//             mint p = 1;
//             for (int i = 0, k = 0; i < n; i += b * 2) {
//                 rep(j, i, i + b) {
//                     uint x = (f[j + b] * p).x;
//                     f[j + b].x = f[j].x + mint::mod - x;
//                     f[j].x += x;
//                 }
//                 p *= g[__builtin_ctz(++k)];
//             }
//         }
//         while (b) {
//             if (b >>= 1) {  // input:[0,mod*3)
//                 mint p = 1;
//                 for (int i = 0, k = 0; i < n; i += b * 2) {
//                     rep(j, i, i + b) {
//                         uint x = (f[j + b] * p).x;
//                         f[j + b].x = f[j].x + mint::mod - x;
//                         f[j].x += x;
//                     }
//                     p *= g[__builtin_ctz(++k)];
//                 }
//             }
//             if (b >>= 1) {  // input:[0,mod*4)
//                 mint p = 1;
//                 for (int i = 0, k = 0; i < n; i += b * 2) {
//                     rep(j, i, i + b) {
//                         uint x = (f[j + b] * p).x;
//                         f[j].x = (f[j].x < mod2 ? f[j].x : f[j].x - mod2);
//                         f[j + b].x = f[j].x + mint::mod - x;
//                         f[j].x += x;
//                     }
//                     p *= g[__builtin_ctz(++k)];
//                 }
//             }
//         }
//     } else {
//         int b = 1;
//         if (b < n / 2) {  // input:[0,mod)
//             mint p = 1;
//             for (int i = 0, k = 0; i < n; i += b * 2) {
//                 rep(j, i, i + b) {
//                     ull x = f[j].v + mint::mod - f[j + b].v;
//                     f[j].v += f[j + b].v;
//                     f[j + b].v = x * p.v % mint::mod;
//                 }
//                 p *= ig[__builtin_ctz(++k)];
//             }
//             b <<= 1;
//         }
//         for (; b < n / 2; b <<= 1) {  // input:[0,mod*2)
//             mint p = 1;
//             for (int i = 0, k = 0; i < n; i += b * 2) {
//                 rep(j, i, i + b / 2) {
//                     ull x = f[j].v + mod2 - f[j + b].v;
//                     f[j].v += f[j + b].v;
//                     f[j].v = (f[j].v) < mod2 ? f[j].v : f[j].v - mod2;
//                     f[j + b].v = x * p.v % mint::mod;
//                 }
//                 rep(j, i + b / 2, i + b) {
//                     ull x = f[j].v + mod2 - f[j + b].v;
//                     f[j].v += f[j + b].v;
//                     // f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
//                     f[j + b].v = x * p.v % mint::mod;
//                 }
//                 p *= ig[__builtin_ctz(++k)];
//             }
//         }
//         if (b < n) {  // input:[0,mod*2)
//             rep(i, b) {
//                 uint x = f[i + b].v;
//                 f[i + b].v = f[i].v + mod2 - x;
//                 f[i].v += x;
//             }
//         }
//         int lg = 1;
//         int tmp = n;
//         while (tmp > 1) lg *= 2, tmp /= 2;
//         mint z = p2[lg];
//         rep(i, n) f[i] *= z;
//     }
// }
// template <class mint>
// vector<mint> multiply(vector<mint> x, const vector<mint> &y,
//                       bool same = false) {
//     int n = x.size() + y.size() - 1;
//     int s = 1;
//     while (s < n) s *= 2;
//     x.resize(s);
//     inplace_fmt(x, false);
//     if (!same) {
//         vector<mint> z(s);
//         rep(i, y.size()) z[i] = y[i];
//         inplace_fmt(z, false);
//         rep(i, s) x[i] *= z[i];
//     } else {
//         rep(i, s) x[i] *= x[i];
//     }
//     inplace_fmt(x, true);
//     x.resize(n);
//     return x;
// }

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