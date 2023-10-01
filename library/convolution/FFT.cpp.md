---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.cpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: library/mod/modint.cpp
    title: library/mod/modint.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/math/FormalPowerSeries.cpp
    title: Formal Power Series
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki-FPS.power.test.cpp
    title: verify/yuki-FPS.power.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/FFT.md
    document_title: Fast Fourier Transform
    links:
    - https://nyaannyaan.github.io/library/ntt/arbitrary-ntt.hpp
  bundledCode: "#line 2 \"library/mod/modint.cpp\"\ntemplate <int Mod>\nstruct modint\n\
    {\n    int x;\n\n    modint() : x(0) {}\n\n    modint(long long y) : x(y >= 0\
    \ ? y % Mod : (Mod - (-y) % Mod) % Mod) {}\n\n    modint &operator+=(const modint\
    \ &p)\n    {\n        if ((x += p.x) >= Mod)\n            x -= Mod;\n        return\
    \ *this;\n    }\n\n    modint &operator-=(const modint &p)\n    {\n        if\
    \ ((x += Mod - p.x) >= Mod)\n            x -= Mod;\n        return *this;\n  \
    \  }\n\n    modint &operator*=(const modint &p)\n    {\n        x = (int)(1LL\
    \ * x * p.x % Mod);\n        return *this;\n    }\n\n    modint &operator/=(const\
    \ modint &p)\n    {\n        *this *= p.inverse();\n        return *this;\n  \
    \  }\n\n    modint operator-() const { return modint(-x); }\n\n    modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n\n    modint operator-(const\
    \ modint &p) const { return modint(*this) -= p; }\n\n    modint operator*(const\
    \ modint &p) const { return modint(*this) *= p; }\n\n    modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n\n    bool operator==(const\
    \ modint &p) const { return x == p.x; }\n\n    bool operator!=(const modint &p)\
    \ const { return x != p.x; }\n\n    modint inverse() const\n    {\n        int\
    \ a = x, b = Mod, u = 1, v = 0, t;\n        while (b > 0)\n        {\n       \
    \     t = a / b;\n            swap(a -= t * b, b);\n            swap(u -= t *\
    \ v, v);\n        }\n        return modint(u);\n    }\n\n    modint pow(int64_t\
    \ n) const\n    {\n        modint ret(1), mul(x);\n        while (n > 0)\n   \
    \     {\n            if (n & 1)\n                ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend ostream &operator<<(ostream &os, const modint &p)\n    {\n        return\
    \ os << p.x;\n    }\n\n    friend istream &operator>>(istream &is, modint &a)\n\
    \    {\n        long long t;\n        is >> t;\n        a = modint<Mod>(t);\n\
    \        return (is);\n    }\n\n    static int get_mod() { return Mod; }\n\n \
    \   constexpr int get() const { return x; }\n};\n#line 2 \"library/convolution/NTT.cpp\"\
    \n/**\n * @brief Number Theoretic Transform\n * @docs docs/NTT.md\n * @param modint\n\
    \ */\ntemplate <typename Mint>\nstruct NTT\n{\nprivate:\n    vector<Mint> root_pow,\
    \ root_pow_inv;\n    int max_base;\n    Mint root; //\u539F\u59CB\u6839\n\n  \
    \  void ntt(vector<Mint> &a)\n    {\n        const int n = a.size();\n       \
    \ assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = n / 2; m >= 1; m >>= 1)\n        {\n            Mint w =\
    \ 1;\n            for (int s = 0, k = 0; s < n; s += 2 * m)\n            {\n \
    \               for (int i = s, j = s + m; i < s + m; ++i, ++j)\n            \
    \    {\n                    auto x = a[i], y = a[j] * w;\n                   \
    \ a[i] = x + y, a[j] = x - y;\n                }\n                w *= root_pow[__builtin_ctz(++k)];\n\
    \            }\n        }\n    }\n\n    void intt(vector<Mint> &a)\n    {\n  \
    \      const int n = a.size();\n        assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n)\
    \ <= max_base);\n        for (int m = 1; m < n; m *= 2)\n        {\n         \
    \   Mint w = 1;\n            for (int s = 0, k = 0; s < n; s += 2 * m)\n     \
    \       {\n                for (int i = s, j = s + m; i < s + m; ++i, ++j)\n \
    \               {\n                    auto x = a[i], y = a[j];\n            \
    \        a[i] = x + y, a[j] = (x - y) * w;\n                }\n              \
    \  w *= root_pow_inv[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n\
    public:\n    NTT()\n    {\n        const unsigned Mod = Mint::get_mod();\n   \
    \     auto tmp = Mod - 1;\n        max_base = 0;\n        while (tmp % 2 == 0)\n\
    \            tmp >>= 1, max_base++;\n        root = 2;\n        while (root.pow((Mod\
    \ - 1) >> 1) == 1)\n            root += 1;\n        root_pow.resize(max_base);\n\
    \        root_pow_inv.resize(max_base);\n        for (int i = 0; i < max_base;\
    \ i++)\n        {\n            root_pow[i] = -root.pow((Mod - 1) >> (i + 2));\n\
    \            root_pow_inv[i] = Mint(1) / root_pow[i];\n        }\n    }\n\n  \
    \  /**\n     * @brief \u7573\u307F\u8FBC\u307F\n     * @param vector<modint<mod>>\n\
    \     */\n    vector<Mint> multiply(vector<Mint> a, vector<Mint> b)\n    {\n \
    \       const int need = a.size() + b.size() - 1;\n        int nbase = 1;\n  \
    \      while ((1 << nbase) < need)\n            nbase++;\n        int sz = 1 <<\
    \ nbase;\n        a.resize(sz, 0);\n        b.resize(sz, 0);\n        ntt(a);\n\
    \        ntt(b);\n        Mint inv_sz = Mint(1) / sz;\n        for (int i = 0;\
    \ i < sz; i++)\n            a[i] *= b[i] * inv_sz;\n        intt(a);\n       \
    \ a.resize(need);\n        return a;\n    }\n};\n#line 4 \"library/convolution/FFT.cpp\"\
    \n/**\n * @brief Fast Fourier Transform\n * @see https://nyaannyaan.github.io/library/ntt/arbitrary-ntt.hpp\n\
    \ * @docs docs/FFT.md\n */\n\ntemplate <typename Mint>\nstruct FFT\n{\nprivate:\n\
    \    using i64 = int64_t;\n    static const int32_t m0 = 167772161;\n    static\
    \ const int32_t m1 = 469762049;\n    static const int32_t m2 = 754974721;\n  \
    \  using mint0 = modint<m0>;\n    using mint1 = modint<m1>;\n    using mint2 =\
    \ modint<m2>;\n    const int32_t r01 = 104391568;\n    const int32_t r02 = 323560596;\n\
    \    const int32_t r12 = 399692502;\n    const int32_t r02r12 = i64(r02) * r12\
    \ % m2;\n    const i64 w1 = m0;\n    const i64 w2 = i64(m0) * m1;\n    template\
    \ <typename T, typename submint>\n\n    vector<submint> mul(const vector<T> &a,\
    \ const vector<T> &b)\n    {\n        static NTT<submint> ntt;\n        vector<submint>\
    \ s(a.size()), t(b.size());\n        for (int i = 0; i < (int)a.size(); ++i)\n\
    \            s[i] = i64(a[i] % submint::get_mod());\n        for (int i = 0; i\
    \ < (int)b.size(); ++i)\n            t[i] = i64(b[i] % submint::get_mod());\n\
    \        return ntt.multiply(s, t);\n    }\n\npublic:\n    FFT()\n    {\n    }\n\
    \n    /**\n     * @brief \u4EFB\u610Fmod\u306B\u3088\u308Bmodint\u306E\u7573\u307F\
    \u8FBC\u307F\n     * @arg vector<modint<mod>>\n     */\n    vector<Mint> multiply(const\
    \ vector<Mint> &x, const vector<Mint> &y)\n    {\n        if (x.size() == 0 &&\
    \ y.size() == 0)\n            return {};\n        if (min<int>(x.size(), y.size())\
    \ < 128)\n        {\n            vector<Mint> ret(x.size() + y.size() - 1);\n\
    \            for (int i = 0; i < (int)x.size(); ++i)\n                for (int\
    \ j = 0; j < (int)y.size(); ++j)\n                    ret[i + j] += x[i] * y[j];\n\
    \            return ret;\n        }\n        vector<int> s(x.size()), t(y.size());\n\
    \        for (int i = 0; i < (int)x.size(); ++i)\n            s[i] = x[i].get();\n\
    \        for (int i = 0; i < (int)y.size(); ++i)\n            t[i] = y[i].get();\n\
    \        auto d0 = mul<int, mint0>(s, t);\n        auto d1 = mul<int, mint1>(s,\
    \ t);\n        auto d2 = mul<int, mint2>(s, t);\n        int n = d0.size();\n\
    \        vector<Mint> ret(n);\n        const Mint W1 = w1;\n        const Mint\
    \ W2 = w2;\n        for (int i = 0; i < n; i++)\n        {\n            int n1\
    \ = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();\n            int b = i64(n1\
    \ + m1 - a) * r01 % m1;\n            int c = (i64(n2 + m2 - a) * r02r12 + i64(m2\
    \ - b) * r12) % m2;\n            ret[i] = W1 * b + W2 * c + a;\n        }\n  \
    \      return ret;\n    }\n\n    /**\n     * @brief int, long long\u7528\u306E\
    \u7573\u307F\u8FBC\u307F\n     * @arg vector<long long>\u3092\u60F3\u5B9A\n  \
    \   */\n    template <typename T>\n    vector<T> multiply_ll(const vector<T> &s,\
    \ const vector<T> &t)\n    {\n        if (s.size() == 0 && t.size() == 0)\n  \
    \          return {};\n        if (min<int>(s.size(), t.size()) < 128)\n     \
    \   {\n            vector<T> ret(s.size() + t.size() - 1);\n            for (int\
    \ i = 0; i < (int)s.size(); ++i)\n                for (int j = 0; j < (int)t.size();\
    \ ++j)\n                    ret[i + j] += i64(s[i]) * t[j];\n            return\
    \ ret;\n        }\n        auto d0 = mul<T, mint0>(s, t);\n        auto d1 = mul<T,\
    \ mint1>(s, t);\n        auto d2 = mul<T, mint2>(s, t);\n        int n = d0.size();\n\
    \        vector<T> ret(n);\n        for (int i = 0; i < n; i++)\n        {\n \
    \           i64 n1 = d1[i].get(), n2 = d2[i].get();\n            i64 a = d0[i].get();\n\
    \            T b = (n1 + m1 - a) * r01 % m1;\n            T c = ((n2 + m2 - a)\
    \ * r02r12 + (m2 - b) * r12) % m2;\n            ret[i] = a + b * w1 + c * w2;\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"library/mod/modint.cpp\"\n#include \"library/convolution/NTT.cpp\"\
    \n/**\n * @brief Fast Fourier Transform\n * @see https://nyaannyaan.github.io/library/ntt/arbitrary-ntt.hpp\n\
    \ * @docs docs/FFT.md\n */\n\ntemplate <typename Mint>\nstruct FFT\n{\nprivate:\n\
    \    using i64 = int64_t;\n    static const int32_t m0 = 167772161;\n    static\
    \ const int32_t m1 = 469762049;\n    static const int32_t m2 = 754974721;\n  \
    \  using mint0 = modint<m0>;\n    using mint1 = modint<m1>;\n    using mint2 =\
    \ modint<m2>;\n    const int32_t r01 = 104391568;\n    const int32_t r02 = 323560596;\n\
    \    const int32_t r12 = 399692502;\n    const int32_t r02r12 = i64(r02) * r12\
    \ % m2;\n    const i64 w1 = m0;\n    const i64 w2 = i64(m0) * m1;\n    template\
    \ <typename T, typename submint>\n\n    vector<submint> mul(const vector<T> &a,\
    \ const vector<T> &b)\n    {\n        static NTT<submint> ntt;\n        vector<submint>\
    \ s(a.size()), t(b.size());\n        for (int i = 0; i < (int)a.size(); ++i)\n\
    \            s[i] = i64(a[i] % submint::get_mod());\n        for (int i = 0; i\
    \ < (int)b.size(); ++i)\n            t[i] = i64(b[i] % submint::get_mod());\n\
    \        return ntt.multiply(s, t);\n    }\n\npublic:\n    FFT()\n    {\n    }\n\
    \n    /**\n     * @brief \u4EFB\u610Fmod\u306B\u3088\u308Bmodint\u306E\u7573\u307F\
    \u8FBC\u307F\n     * @arg vector<modint<mod>>\n     */\n    vector<Mint> multiply(const\
    \ vector<Mint> &x, const vector<Mint> &y)\n    {\n        if (x.size() == 0 &&\
    \ y.size() == 0)\n            return {};\n        if (min<int>(x.size(), y.size())\
    \ < 128)\n        {\n            vector<Mint> ret(x.size() + y.size() - 1);\n\
    \            for (int i = 0; i < (int)x.size(); ++i)\n                for (int\
    \ j = 0; j < (int)y.size(); ++j)\n                    ret[i + j] += x[i] * y[j];\n\
    \            return ret;\n        }\n        vector<int> s(x.size()), t(y.size());\n\
    \        for (int i = 0; i < (int)x.size(); ++i)\n            s[i] = x[i].get();\n\
    \        for (int i = 0; i < (int)y.size(); ++i)\n            t[i] = y[i].get();\n\
    \        auto d0 = mul<int, mint0>(s, t);\n        auto d1 = mul<int, mint1>(s,\
    \ t);\n        auto d2 = mul<int, mint2>(s, t);\n        int n = d0.size();\n\
    \        vector<Mint> ret(n);\n        const Mint W1 = w1;\n        const Mint\
    \ W2 = w2;\n        for (int i = 0; i < n; i++)\n        {\n            int n1\
    \ = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();\n            int b = i64(n1\
    \ + m1 - a) * r01 % m1;\n            int c = (i64(n2 + m2 - a) * r02r12 + i64(m2\
    \ - b) * r12) % m2;\n            ret[i] = W1 * b + W2 * c + a;\n        }\n  \
    \      return ret;\n    }\n\n    /**\n     * @brief int, long long\u7528\u306E\
    \u7573\u307F\u8FBC\u307F\n     * @arg vector<long long>\u3092\u60F3\u5B9A\n  \
    \   */\n    template <typename T>\n    vector<T> multiply_ll(const vector<T> &s,\
    \ const vector<T> &t)\n    {\n        if (s.size() == 0 && t.size() == 0)\n  \
    \          return {};\n        if (min<int>(s.size(), t.size()) < 128)\n     \
    \   {\n            vector<T> ret(s.size() + t.size() - 1);\n            for (int\
    \ i = 0; i < (int)s.size(); ++i)\n                for (int j = 0; j < (int)t.size();\
    \ ++j)\n                    ret[i + j] += i64(s[i]) * t[j];\n            return\
    \ ret;\n        }\n        auto d0 = mul<T, mint0>(s, t);\n        auto d1 = mul<T,\
    \ mint1>(s, t);\n        auto d2 = mul<T, mint2>(s, t);\n        int n = d0.size();\n\
    \        vector<T> ret(n);\n        for (int i = 0; i < n; i++)\n        {\n \
    \           i64 n1 = d1[i].get(), n2 = d2[i].get();\n            i64 a = d0[i].get();\n\
    \            T b = (n1 + m1 - a) * r01 % m1;\n            T c = ((n2 + m2 - a)\
    \ * r02r12 + (m2 - b) * r12) % m2;\n            ret[i] = a + b * w1 + c * w2;\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - library/mod/modint.cpp
  - library/convolution/NTT.cpp
  isVerificationFile: false
  path: library/convolution/FFT.cpp
  requiredBy:
  - library/math/FormalPowerSeries.cpp
  timestamp: '2021-08-26 10:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki-FPS.power.test.cpp
  - verify/yosupo-convolution_mod_1000000007.test.cpp
documentation_of: library/convolution/FFT.cpp
layout: document
redirect_from:
- /library/library/convolution/FFT.cpp
- /library/library/convolution/FFT.cpp.html
title: Fast Fourier Transform
---
## メモ
- fftとは名ばかりでnttを3つのmodで行って復元してる

## 初期化
```c++
FFT fft;
```

## multiply
- 任意mod用
```c++
auto c = fft.multiply(a, b);
```

## multiply_ll
- intやlong long用
- int128も行けると思われる
```c++
auto c = fft.multiply(a, b);
```