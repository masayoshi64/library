---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/convolution/FFT.cpp\"\n// namespace FastFourierTransform\
    \ {\n// using real = long double;\n\n// struct C {\n//     real x, y;\n\n//  \
    \   C() : x(0), y(0) {}\n\n//     C(real x, real y) : x(x), y(y) {}\n\n//    \
    \ inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }\n\n// \
    \    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }\n\n\
    //     inline C operator*(const C &c) const {\n//         return C(x * c.x - y\
    \ * c.y, x * c.y + y * c.x);\n//     }\n\n//     inline C conj() const { return\
    \ C(x, -y); }\n// };\n\n// const real PI = acosl(-1);\n// int base = 1;\n// vector<C>\
    \ rts = {{0, 0}, {1, 0}};\n// vector<int> rev = {0, 1};\n\n// void ensure_base(int\
    \ nbase) {\n//     if (nbase <= base) return;\n//     rev.resize(1 << nbase);\n\
    //     rts.resize(1 << nbase);\n//     for (int i = 0; i < (1 << nbase); i++)\
    \ {\n//         rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n//  \
    \   }\n//     while (base < nbase) {\n//         real angle = PI * 2.0 / (1 <<\
    \ (base + 1));\n//         for (int i = 1 << (base - 1); i < (1 << base); i++)\
    \ {\n//             rts[i << 1] = rts[i];\n//             real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n//             rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\n//         }\n//         ++base;\n//     }\n// }\n\n// void\
    \ fft(vector<C> &a, int n) {\n//     assert((n & (n - 1)) == 0);\n//     int zeros\
    \ = __builtin_ctz(n);\n//     ensure_base(zeros);\n//     int shift = base - zeros;\n\
    //     for (int i = 0; i < n; i++) {\n//         if (i < (rev[i] >> shift)) {\n\
    //             swap(a[i], a[rev[i] >> shift]);\n//         }\n//     }\n//   \
    \  for (int k = 1; k < n; k <<= 1) {\n//         for (int i = 0; i < n; i += 2\
    \ * k) {\n//             for (int j = 0; j < k; j++) {\n//                 C z\
    \ = a[i + j + k] * rts[j + k];\n//                 a[i + j + k] = a[i + j] - z;\n\
    //                 a[i + j] = a[i + j] + z;\n//             }\n//         }\n\
    //     }\n// }\n\n// vector<int64_t> multiply(const vector<int> &a, const vector<int>\
    \ &b) {\n//     int need = (int)a.size() + (int)b.size() - 1;\n//     int nbase\
    \ = 1;\n//     while ((1 << nbase) < need) nbase++;\n//     ensure_base(nbase);\n\
    //     int sz = 1 << nbase;\n//     vector<C> fa(sz);\n//     for (int i = 0;\
    \ i < sz; i++) {\n//         int x = (i < (int)a.size() ? a[i] : 0);\n//     \
    \    int y = (i < (int)b.size() ? b[i] : 0);\n//         fa[i] = C(x, y);\n//\
    \     }\n//     fft(fa, sz);\n//     C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5,\
    \ 0);\n//     for (int i = 0; i <= (sz >> 1); i++) {\n//         int j = (sz -\
    \ i) & (sz - 1);\n//         C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) *\
    \ r;\n//         fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n//   \
    \      fa[i] = z;\n//     }\n//     for (int i = 0; i < (sz >> 1); i++) {\n//\
    \         C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n//         C A1 = (fa[i] -\
    \ fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];\n//         fa[i] = A0 + A1 * s;\n\
    //     }\n//     fft(fa, sz >> 1);\n//     vector<int64_t> ret(need);\n//    \
    \ for (int i = 0; i < need; i++) {\n//         ret[i] = llround(i & 1 ? fa[i >>\
    \ 1].y : fa[i >> 1].x);\n//     }\n//     return ret;\n// }\n// };  // namespace\
    \ FastFourierTransform\n// #include \"library/convolution/NTT.cpp\"\n// #include\
    \ \"library/mod/modint.cpp\"\n// template <typename Mint>\n// struct FFT {\n//\
    \     constexpr int mod0 = 1045430273;\n//     constexpr int mod1 = 1051721729;\n\
    //     constexpr int mod2 = 1053818881;\n//     using mint0 = modint<mod0>;\n\
    //     using mint1 = modint<mod1>;\n//     using mint2 = modint<mod2>;\n//   \
    \  NTT<mint0> ntt0;\n//     NTT<mint1> ntt1;\n//     NTT<mint2> ntt2;\n//    \
    \ vector<Mint> multiply(const vector<int> &x, const vector<int> &y) {\n//    \
    \     auto d0 = ntt0.multiply(x, y);\n//         auto d1 = ntt1.multiply(x, y);\n\
    //         auto d2 = ntt2.multiply(x, y);\n//         int n = d0.size();\n// \
    \        vector<Mint> res(n);\n//         static const mint1 r01 = mint1(mint0.get_mod()).inv();\n\
    //         static const mint2 r02 = mint2(mint0.get_mod()).inv();\n//        \
    \ static const mint2 r12 = mint2(mint1.get_mod()).inv();\n//         static const\
    \ mint2 r02r12 = r02 * r12;\n//         static const Mint w1 = Mint(mint0.get_mod());\n\
    //         static const Mint w2 = w1 * Mint(mint1.get_mod());\n//         rep(i,\
    \ n) {\n//             ull a = d0[i].v;\n//             ull b = (d1[i].v + mint1.get_mod()\
    \ - a) * r01.v %\n//             mint1.get_mod(); ull c = ((d2[i].v + mint2.get_mod()\
    \ - a) *\n//             r02r12.v +\n//                      (mint2.get_mod()\
    \ - b) * r12.v) %\n//                     mint2.get_mod();\n//             res[i].v\
    \ = (a + b * w1.v + c * w2.v) % Mint.get_mod();\n//         }\n//         return\
    \ res;\n//     }\n// };\n\n// template <class mint>\n// void inplace_fmt(vector<mint>\
    \ &f, bool inv) {\n//     const int n = f.size();\n//     static vector<mint>\
    \ g, ig, p2;\n//     if (g.size() == 0) {\n//         rep(i, 30) {\n//       \
    \      mint w = -mint::root().pow(((mint::mod - 1) >> (i + 2)) * 3);\n//     \
    \        g.pb(w);\n//             ig.pb(w.inv());\n//             p2.pb(mint(1\
    \ << i).inv());\n//         }\n//     }\n//     static constexpr uint mod2 = mint::mod\
    \ * 2;\n//     if (!inv) {\n//         int b = n;\n//         if (b >>= 1) { \
    \ // input:[0,mod)\n//             rep(i, b) {\n//                 uint x = f[i\
    \ + b].x;\n//                 f[i + b].x = f[i].x + mint::mod - x;\n//       \
    \          f[i].x += x;\n//             }\n//         }\n//         if (b >>=\
    \ 1) {  // input:[0,mod*2)\n//             mint p = 1;\n//             for (int\
    \ i = 0, k = 0; i < n; i += b * 2) {\n//                 rep(j, i, i + b) {\n\
    //                     uint x = (f[j + b] * p).x;\n//                     f[j\
    \ + b].x = f[j].x + mint::mod - x;\n//                     f[j].x += x;\n//  \
    \               }\n//                 p *= g[__builtin_ctz(++k)];\n//        \
    \     }\n//         }\n//         while (b) {\n//             if (b >>= 1) { \
    \ // input:[0,mod*3)\n//                 mint p = 1;\n//                 for (int\
    \ i = 0, k = 0; i < n; i += b * 2) {\n//                     rep(j, i, i + b)\
    \ {\n//                         uint x = (f[j + b] * p).x;\n//               \
    \          f[j + b].x = f[j].x + mint::mod - x;\n//                         f[j].x\
    \ += x;\n//                     }\n//                     p *= g[__builtin_ctz(++k)];\n\
    //                 }\n//             }\n//             if (b >>= 1) {  // input:[0,mod*4)\n\
    //                 mint p = 1;\n//                 for (int i = 0, k = 0; i <\
    \ n; i += b * 2) {\n//                     rep(j, i, i + b) {\n//            \
    \             uint x = (f[j + b] * p).x;\n//                         f[j].x =\
    \ (f[j].x < mod2 ? f[j].x : f[j].x - mod2);\n//                         f[j +\
    \ b].x = f[j].x + mint::mod - x;\n//                         f[j].x += x;\n//\
    \                     }\n//                     p *= g[__builtin_ctz(++k)];\n\
    //                 }\n//             }\n//         }\n//     } else {\n//    \
    \     int b = 1;\n//         if (b < n / 2) {  // input:[0,mod)\n//          \
    \   mint p = 1;\n//             for (int i = 0, k = 0; i < n; i += b * 2) {\n\
    //                 rep(j, i, i + b) {\n//                     ull x = f[j].v +\
    \ mint::mod - f[j + b].v;\n//                     f[j].v += f[j + b].v;\n//  \
    \                   f[j + b].v = x * p.v % mint::mod;\n//                 }\n\
    //                 p *= ig[__builtin_ctz(++k)];\n//             }\n//        \
    \     b <<= 1;\n//         }\n//         for (; b < n / 2; b <<= 1) {  // input:[0,mod*2)\n\
    //             mint p = 1;\n//             for (int i = 0, k = 0; i < n; i +=\
    \ b * 2) {\n//                 rep(j, i, i + b / 2) {\n//                    \
    \ ull x = f[j].v + mod2 - f[j + b].v;\n//                     f[j].v += f[j +\
    \ b].v;\n//                     f[j].v = (f[j].v) < mod2 ? f[j].v : f[j].v - mod2;\n\
    //                     f[j + b].v = x * p.v % mint::mod;\n//                 }\n\
    //                 rep(j, i + b / 2, i + b) {\n//                     ull x =\
    \ f[j].v + mod2 - f[j + b].v;\n//                     f[j].v += f[j + b].v;\n\
    //                     // f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;\n//       \
    \              f[j + b].v = x * p.v % mint::mod;\n//                 }\n//   \
    \              p *= ig[__builtin_ctz(++k)];\n//             }\n//         }\n\
    //         if (b < n) {  // input:[0,mod*2)\n//             rep(i, b) {\n//  \
    \               uint x = f[i + b].v;\n//                 f[i + b].v = f[i].v +\
    \ mod2 - x;\n//                 f[i].v += x;\n//             }\n//         }\n\
    //         int lg = 1;\n//         int tmp = n;\n//         while (tmp > 1) lg\
    \ *= 2, tmp /= 2;\n//         mint z = p2[lg];\n//         rep(i, n) f[i] *= z;\n\
    //     }\n// }\n// template <class mint>\n// vector<mint> multiply(vector<mint>\
    \ x, const vector<mint> &y,\n//                       bool same = false) {\n//\
    \     int n = x.size() + y.size() - 1;\n//     int s = 1;\n//     while (s < n)\
    \ s *= 2;\n//     x.resize(s);\n//     inplace_fmt(x, false);\n//     if (!same)\
    \ {\n//         vector<mint> z(s);\n//         rep(i, y.size()) z[i] = y[i];\n\
    //         inplace_fmt(z, false);\n//         rep(i, s) x[i] *= z[i];\n//    \
    \ } else {\n//         rep(i, s) x[i] *= x[i];\n//     }\n//     inplace_fmt(x,\
    \ true);\n//     x.resize(n);\n//     return x;\n// }\n\ntemplate <int mod>\n\
    vector<int> multiply(vector<int> &a, vector<int> &b) {\n    using mint = modint<mod>;\n\
    \    using mint1 = modint<167772161>;\n    using mint2 = modint<469762049>;\n\
    \    using mint3 = modint<595591169>;\n    NTT<mint1> ntt1;\n    NTT<mint2> ntt2;\n\
    \    NTT<mint3> ntt3;\n    vector<mint1> a1(begin(a), end(a)), b1(begin(b), end(b));\n\
    \    vector<mint2> a2(begin(a), end(a)), b2(begin(b), end(b));\n    vector<mint3>\
    \ a3(begin(a), end(a)), b3(begin(b), end(b));\n    auto x = ntt1.multiply(a1,\
    \ b1);\n    auto y = ntt2.multiply(a2, b2);\n    auto z = ntt3.multiply(a3, b3);\n\
    \    const int m1 = 167772161, m2 = 469762049, m3 = 595591169;\n    const auto\
    \ m1_inv_m2 = mint2(m1).inverse().get();\n    const auto m12_inv_m3 = (mint3(m1)\
    \ * m2).inverse().get();\n    const auto m12_mod = (mint(m1) * m2).get();\n  \
    \  vector<int> ret(x.size());\n    for (int i = 0; i < x.size(); i++) {\n    \
    \    auto v1 = ((mint2(y[i]) + m2 - x[i].get()) * m1_inv_m2).get();\n        auto\
    \ v2 =\n            ((z[i] + m3 - x[i].get() - mint3(m1) * v1) * m12_inv_m3).get();\n\
    \        ret[i] = (mint(x[i].get()) + mint(m1) * v1 + mint(m12_mod) * v2).get();\n\
    \    }\n    return ret;\n}\n"
  code: "// namespace FastFourierTransform {\n// using real = long double;\n\n// struct\
    \ C {\n//     real x, y;\n\n//     C() : x(0), y(0) {}\n\n//     C(real x, real\
    \ y) : x(x), y(y) {}\n\n//     inline C operator+(const C &c) const { return C(x\
    \ + c.x, y + c.y); }\n\n//     inline C operator-(const C &c) const { return C(x\
    \ - c.x, y - c.y); }\n\n//     inline C operator*(const C &c) const {\n//    \
    \     return C(x * c.x - y * c.y, x * c.y + y * c.x);\n//     }\n\n//     inline\
    \ C conj() const { return C(x, -y); }\n// };\n\n// const real PI = acosl(-1);\n\
    // int base = 1;\n// vector<C> rts = {{0, 0}, {1, 0}};\n// vector<int> rev = {0,\
    \ 1};\n\n// void ensure_base(int nbase) {\n//     if (nbase <= base) return;\n\
    //     rev.resize(1 << nbase);\n//     rts.resize(1 << nbase);\n//     for (int\
    \ i = 0; i < (1 << nbase); i++) {\n//         rev[i] = (rev[i >> 1] >> 1) + ((i\
    \ & 1) << (nbase - 1));\n//     }\n//     while (base < nbase) {\n//         real\
    \ angle = PI * 2.0 / (1 << (base + 1));\n//         for (int i = 1 << (base -\
    \ 1); i < (1 << base); i++) {\n//             rts[i << 1] = rts[i];\n//      \
    \       real angle_i = angle * (2 * i + 1 - (1 << base));\n//             rts[(i\
    \ << 1) + 1] = C(cos(angle_i), sin(angle_i));\n//         }\n//         ++base;\n\
    //     }\n// }\n\n// void fft(vector<C> &a, int n) {\n//     assert((n & (n -\
    \ 1)) == 0);\n//     int zeros = __builtin_ctz(n);\n//     ensure_base(zeros);\n\
    //     int shift = base - zeros;\n//     for (int i = 0; i < n; i++) {\n//   \
    \      if (i < (rev[i] >> shift)) {\n//             swap(a[i], a[rev[i] >> shift]);\n\
    //         }\n//     }\n//     for (int k = 1; k < n; k <<= 1) {\n//         for\
    \ (int i = 0; i < n; i += 2 * k) {\n//             for (int j = 0; j < k; j++)\
    \ {\n//                 C z = a[i + j + k] * rts[j + k];\n//                 a[i\
    \ + j + k] = a[i + j] - z;\n//                 a[i + j] = a[i + j] + z;\n//  \
    \           }\n//         }\n//     }\n// }\n\n// vector<int64_t> multiply(const\
    \ vector<int> &a, const vector<int> &b) {\n//     int need = (int)a.size() + (int)b.size()\
    \ - 1;\n//     int nbase = 1;\n//     while ((1 << nbase) < need) nbase++;\n//\
    \     ensure_base(nbase);\n//     int sz = 1 << nbase;\n//     vector<C> fa(sz);\n\
    //     for (int i = 0; i < sz; i++) {\n//         int x = (i < (int)a.size() ?\
    \ a[i] : 0);\n//         int y = (i < (int)b.size() ? b[i] : 0);\n//         fa[i]\
    \ = C(x, y);\n//     }\n//     fft(fa, sz);\n//     C r(0, -0.25 / (sz >> 1)),\
    \ s(0, 1), t(0.5, 0);\n//     for (int i = 0; i <= (sz >> 1); i++) {\n//     \
    \    int j = (sz - i) & (sz - 1);\n//         C z = (fa[j] * fa[j] - (fa[i] *\
    \ fa[i]).conj()) * r;\n//         fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\n//         fa[i] = z;\n//     }\n//     for (int i = 0; i < (sz >> 1);\
    \ i++) {\n//         C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n//         C A1\
    \ = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];\n//         fa[i] =\
    \ A0 + A1 * s;\n//     }\n//     fft(fa, sz >> 1);\n//     vector<int64_t> ret(need);\n\
    //     for (int i = 0; i < need; i++) {\n//         ret[i] = llround(i & 1 ? fa[i\
    \ >> 1].y : fa[i >> 1].x);\n//     }\n//     return ret;\n// }\n// };  // namespace\
    \ FastFourierTransform\n// #include \"library/convolution/NTT.cpp\"\n// #include\
    \ \"library/mod/modint.cpp\"\n// template <typename Mint>\n// struct FFT {\n//\
    \     constexpr int mod0 = 1045430273;\n//     constexpr int mod1 = 1051721729;\n\
    //     constexpr int mod2 = 1053818881;\n//     using mint0 = modint<mod0>;\n\
    //     using mint1 = modint<mod1>;\n//     using mint2 = modint<mod2>;\n//   \
    \  NTT<mint0> ntt0;\n//     NTT<mint1> ntt1;\n//     NTT<mint2> ntt2;\n//    \
    \ vector<Mint> multiply(const vector<int> &x, const vector<int> &y) {\n//    \
    \     auto d0 = ntt0.multiply(x, y);\n//         auto d1 = ntt1.multiply(x, y);\n\
    //         auto d2 = ntt2.multiply(x, y);\n//         int n = d0.size();\n// \
    \        vector<Mint> res(n);\n//         static const mint1 r01 = mint1(mint0.get_mod()).inv();\n\
    //         static const mint2 r02 = mint2(mint0.get_mod()).inv();\n//        \
    \ static const mint2 r12 = mint2(mint1.get_mod()).inv();\n//         static const\
    \ mint2 r02r12 = r02 * r12;\n//         static const Mint w1 = Mint(mint0.get_mod());\n\
    //         static const Mint w2 = w1 * Mint(mint1.get_mod());\n//         rep(i,\
    \ n) {\n//             ull a = d0[i].v;\n//             ull b = (d1[i].v + mint1.get_mod()\
    \ - a) * r01.v %\n//             mint1.get_mod(); ull c = ((d2[i].v + mint2.get_mod()\
    \ - a) *\n//             r02r12.v +\n//                      (mint2.get_mod()\
    \ - b) * r12.v) %\n//                     mint2.get_mod();\n//             res[i].v\
    \ = (a + b * w1.v + c * w2.v) % Mint.get_mod();\n//         }\n//         return\
    \ res;\n//     }\n// };\n\n// template <class mint>\n// void inplace_fmt(vector<mint>\
    \ &f, bool inv) {\n//     const int n = f.size();\n//     static vector<mint>\
    \ g, ig, p2;\n//     if (g.size() == 0) {\n//         rep(i, 30) {\n//       \
    \      mint w = -mint::root().pow(((mint::mod - 1) >> (i + 2)) * 3);\n//     \
    \        g.pb(w);\n//             ig.pb(w.inv());\n//             p2.pb(mint(1\
    \ << i).inv());\n//         }\n//     }\n//     static constexpr uint mod2 = mint::mod\
    \ * 2;\n//     if (!inv) {\n//         int b = n;\n//         if (b >>= 1) { \
    \ // input:[0,mod)\n//             rep(i, b) {\n//                 uint x = f[i\
    \ + b].x;\n//                 f[i + b].x = f[i].x + mint::mod - x;\n//       \
    \          f[i].x += x;\n//             }\n//         }\n//         if (b >>=\
    \ 1) {  // input:[0,mod*2)\n//             mint p = 1;\n//             for (int\
    \ i = 0, k = 0; i < n; i += b * 2) {\n//                 rep(j, i, i + b) {\n\
    //                     uint x = (f[j + b] * p).x;\n//                     f[j\
    \ + b].x = f[j].x + mint::mod - x;\n//                     f[j].x += x;\n//  \
    \               }\n//                 p *= g[__builtin_ctz(++k)];\n//        \
    \     }\n//         }\n//         while (b) {\n//             if (b >>= 1) { \
    \ // input:[0,mod*3)\n//                 mint p = 1;\n//                 for (int\
    \ i = 0, k = 0; i < n; i += b * 2) {\n//                     rep(j, i, i + b)\
    \ {\n//                         uint x = (f[j + b] * p).x;\n//               \
    \          f[j + b].x = f[j].x + mint::mod - x;\n//                         f[j].x\
    \ += x;\n//                     }\n//                     p *= g[__builtin_ctz(++k)];\n\
    //                 }\n//             }\n//             if (b >>= 1) {  // input:[0,mod*4)\n\
    //                 mint p = 1;\n//                 for (int i = 0, k = 0; i <\
    \ n; i += b * 2) {\n//                     rep(j, i, i + b) {\n//            \
    \             uint x = (f[j + b] * p).x;\n//                         f[j].x =\
    \ (f[j].x < mod2 ? f[j].x : f[j].x - mod2);\n//                         f[j +\
    \ b].x = f[j].x + mint::mod - x;\n//                         f[j].x += x;\n//\
    \                     }\n//                     p *= g[__builtin_ctz(++k)];\n\
    //                 }\n//             }\n//         }\n//     } else {\n//    \
    \     int b = 1;\n//         if (b < n / 2) {  // input:[0,mod)\n//          \
    \   mint p = 1;\n//             for (int i = 0, k = 0; i < n; i += b * 2) {\n\
    //                 rep(j, i, i + b) {\n//                     ull x = f[j].v +\
    \ mint::mod - f[j + b].v;\n//                     f[j].v += f[j + b].v;\n//  \
    \                   f[j + b].v = x * p.v % mint::mod;\n//                 }\n\
    //                 p *= ig[__builtin_ctz(++k)];\n//             }\n//        \
    \     b <<= 1;\n//         }\n//         for (; b < n / 2; b <<= 1) {  // input:[0,mod*2)\n\
    //             mint p = 1;\n//             for (int i = 0, k = 0; i < n; i +=\
    \ b * 2) {\n//                 rep(j, i, i + b / 2) {\n//                    \
    \ ull x = f[j].v + mod2 - f[j + b].v;\n//                     f[j].v += f[j +\
    \ b].v;\n//                     f[j].v = (f[j].v) < mod2 ? f[j].v : f[j].v - mod2;\n\
    //                     f[j + b].v = x * p.v % mint::mod;\n//                 }\n\
    //                 rep(j, i + b / 2, i + b) {\n//                     ull x =\
    \ f[j].v + mod2 - f[j + b].v;\n//                     f[j].v += f[j + b].v;\n\
    //                     // f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;\n//       \
    \              f[j + b].v = x * p.v % mint::mod;\n//                 }\n//   \
    \              p *= ig[__builtin_ctz(++k)];\n//             }\n//         }\n\
    //         if (b < n) {  // input:[0,mod*2)\n//             rep(i, b) {\n//  \
    \               uint x = f[i + b].v;\n//                 f[i + b].v = f[i].v +\
    \ mod2 - x;\n//                 f[i].v += x;\n//             }\n//         }\n\
    //         int lg = 1;\n//         int tmp = n;\n//         while (tmp > 1) lg\
    \ *= 2, tmp /= 2;\n//         mint z = p2[lg];\n//         rep(i, n) f[i] *= z;\n\
    //     }\n// }\n// template <class mint>\n// vector<mint> multiply(vector<mint>\
    \ x, const vector<mint> &y,\n//                       bool same = false) {\n//\
    \     int n = x.size() + y.size() - 1;\n//     int s = 1;\n//     while (s < n)\
    \ s *= 2;\n//     x.resize(s);\n//     inplace_fmt(x, false);\n//     if (!same)\
    \ {\n//         vector<mint> z(s);\n//         rep(i, y.size()) z[i] = y[i];\n\
    //         inplace_fmt(z, false);\n//         rep(i, s) x[i] *= z[i];\n//    \
    \ } else {\n//         rep(i, s) x[i] *= x[i];\n//     }\n//     inplace_fmt(x,\
    \ true);\n//     x.resize(n);\n//     return x;\n// }\n\ntemplate <int mod>\n\
    vector<int> multiply(vector<int> &a, vector<int> &b) {\n    using mint = modint<mod>;\n\
    \    using mint1 = modint<167772161>;\n    using mint2 = modint<469762049>;\n\
    \    using mint3 = modint<595591169>;\n    NTT<mint1> ntt1;\n    NTT<mint2> ntt2;\n\
    \    NTT<mint3> ntt3;\n    vector<mint1> a1(begin(a), end(a)), b1(begin(b), end(b));\n\
    \    vector<mint2> a2(begin(a), end(a)), b2(begin(b), end(b));\n    vector<mint3>\
    \ a3(begin(a), end(a)), b3(begin(b), end(b));\n    auto x = ntt1.multiply(a1,\
    \ b1);\n    auto y = ntt2.multiply(a2, b2);\n    auto z = ntt3.multiply(a3, b3);\n\
    \    const int m1 = 167772161, m2 = 469762049, m3 = 595591169;\n    const auto\
    \ m1_inv_m2 = mint2(m1).inverse().get();\n    const auto m12_inv_m3 = (mint3(m1)\
    \ * m2).inverse().get();\n    const auto m12_mod = (mint(m1) * m2).get();\n  \
    \  vector<int> ret(x.size());\n    for (int i = 0; i < x.size(); i++) {\n    \
    \    auto v1 = ((mint2(y[i]) + m2 - x[i].get()) * m1_inv_m2).get();\n        auto\
    \ v2 =\n            ((z[i] + m3 - x[i].get() - mint3(m1) * v1) * m12_inv_m3).get();\n\
    \        ret[i] = (mint(x[i].get()) + mint(m1) * v1 + mint(m12_mod) * v2).get();\n\
    \    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/FFT.cpp
  requiredBy: []
  timestamp: '2020-11-19 00:26:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-convolution_mod_1000000007.test.cpp
documentation_of: library/convolution/FFT.cpp
layout: document
redirect_from:
- /library/library/convolution/FFT.cpp
- /library/library/convolution/FFT.cpp.html
title: library/convolution/FFT.cpp
---
