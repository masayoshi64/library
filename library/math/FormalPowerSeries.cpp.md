---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/FFT.cpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.cpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: library/mod/modint.cpp
    title: library/mod/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yuki-FPS.power.test.cpp
    title: verify/yuki-FPS.power.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/FormalPowerSeries
    document_title: Formal Power Series
    links:
    - https://ei1333.github.io/library/math/fps/formal-power-series.cpp
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
    \        }\n        return ret;\n    }\n};\n#line 4 \"library/math/FormalPowerSeries.cpp\"\
    \n\n/**\n * @brief Formal Power Series\n * @see https://ei1333.github.io/library/math/fps/formal-power-series.cpp\n\
    \ * @arg modint<mod>, fft (has a method 'multiply')\n * @docs docs/FormalPowerSeries\n\
    \ */\nstruct MULT\n{\n};\ntemplate <typename T, auto &fft>\nstruct FormalPowerSeries\
    \ : vector<T>\n{\n    using vector<T>::vector;\n    using P = FormalPowerSeries;\n\
    \n    P pre(int deg) const\n    {\n        return P(begin(*this), begin(*this)\
    \ + min((int)this->size(), deg));\n    }\n\n    P rev(int deg = -1) const\n  \
    \  {\n        P ret(*this);\n        if (deg != -1)\n            ret.resize(deg,\
    \ T(0));\n        reverse(begin(ret), end(ret));\n        return ret;\n    }\n\
    \n    void shrink()\n    {\n        while (this->size() && this->back() == T(0))\n\
    \            this->pop_back();\n    }\n\n    P operator+(const P &r) const { return\
    \ P(*this) += r; }\n\n    P operator+(const T &v) const { return P(*this) += v;\
    \ }\n\n    P operator-(const P &r) const { return P(*this) -= r; }\n\n    P operator-(const\
    \ T &v) const { return P(*this) -= v; }\n\n    P operator*(const P &r) const {\
    \ return P(*this) *= r; }\n\n    P operator*(const T &v) const { return P(*this)\
    \ *= v; }\n\n    P operator/(const P &r) const { return P(*this) /= r; }\n\n \
    \   P operator%(const P &r) const { return P(*this) %= r; }\n\n    P &operator+=(const\
    \ P &r)\n    {\n        if (r.size() > this->size())\n            this->resize(r.size());\n\
    \        for (int i = 0; i < r.size(); i++)\n            (*this)[i] += r[i];\n\
    \        return *this;\n    }\n\n    P &operator-=(const P &r)\n    {\n      \
    \  if (r.size() > this->size())\n            this->resize(r.size());\n       \
    \ for (int i = 0; i < r.size(); i++)\n            (*this)[i] -= r[i];\n      \
    \  return *this;\n    }\n\n    P &operator*=(const P &r)\n    {\n        if (this->empty()\
    \ || r.empty())\n        {\n            this->clear();\n            return *this;\n\
    \        }\n        auto ret = fft.multiply(*this, r);\n        return *this =\
    \ {begin(ret), end(ret)};\n    }\n\n    P &operator/=(const P &r)\n    {\n   \
    \     if (this->size() < r.size())\n        {\n            this->clear();\n  \
    \          return *this;\n        }\n        int n = this->size() - r.size() +\
    \ 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P &operator%=(const P &r)\n    {\n        return *this -= *this\
    \ / r * r;\n    }\n\n    pair<P, P> div_mod(const P &r)\n    {\n        P q =\
    \ *this / r;\n        return make_pair(q, *this - q * r);\n    }\n\n    P operator-()\
    \ const\n    {\n        P ret(this->size());\n        for (int i = 0; i < this->size();\
    \ i++)\n            ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    P\
    \ &operator+=(const T &r)\n    {\n        if (this->empty())\n            this->resize(1);\n\
    \        (*this)[0] += r;\n        return *this;\n    }\n\n    P &operator-=(const\
    \ T &r)\n    {\n        if (this->empty())\n            this->resize(1);\n   \
    \     (*this)[0] -= r;\n        return *this;\n    }\n\n    P &operator*=(const\
    \ T &v)\n    {\n        for (int i = 0; i < this->size(); i++)\n            (*this)[i]\
    \ *= v;\n        return *this;\n    }\n\n    P dot(P r) const\n    {\n       \
    \ P ret(min(this->size(), r.size()));\n        for (int i = 0; i < ret.size();\
    \ i++)\n            ret[i] = (*this)[i] * r[i];\n        return ret;\n    }\n\n\
    \    P operator>>(int sz) const\n    {\n        if (this->size() <= sz)\n    \
    \        return {};\n        P ret(*this);\n        ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n        return ret;\n    }\n\n    P operator<<(int sz) const\n    {\n\
    \        P ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n        return\
    \ ret;\n    }\n\n    T operator()(T x) const\n    {\n        T r = 0, w = 1;\n\
    \        for (auto &v : *this)\n        {\n            r += w * v;\n         \
    \   w *= x;\n        }\n        return r;\n    }\n\n    P diff() const\n    {\n\
    \        const int n = (int)this->size();\n        P ret(max(0, n - 1));\n   \
    \     for (int i = 1; i < n; i++)\n            ret[i - 1] = (*this)[i] * T(i);\n\
    \        return ret;\n    }\n\n    P integral() const\n    {\n        const int\
    \ n = (int)this->size();\n        P ret(n + 1);\n        ret[0] = T(0);\n    \
    \    for (int i = 0; i < n; i++)\n            ret[i + 1] = (*this)[i] / T(i +\
    \ 1);\n        return ret;\n    }\n\n    // F(0) must not be 0\n    P inv(int\
    \ deg = -1) const\n    {\n        assert(((*this)[0]) != T(0));\n        const\
    \ int n = (int)this->size();\n        if (deg == -1)\n            deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\n\
    \        {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n\
    \        }\n        return ret.pre(deg);\n    }\n\n    // F(0) must be 1\n   \
    \ P log(int deg = -1) const\n    {\n        assert((*this)[0] == T(1));\n    \
    \    const int n = (int)this->size();\n        if (deg == -1)\n            deg\
    \ = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    P sqrt(\n        int deg = -1, const function<T(T)> &get_sqrt =\
    \ [](T)\n                      { return T(1); }) const\n    {\n        const int\
    \ n = (int)this->size();\n        if (deg == -1)\n            deg = n;\n     \
    \   if ((*this)[0] == T(0))\n        {\n            for (int i = 1; i < n; i++)\n\
    \            {\n                if ((*this)[i] != T(0))\n                {\n \
    \                   if (i & 1)\n                        return {};\n         \
    \           if (deg - i / 2 <= 0)\n                        break;\n          \
    \          auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n            \
    \        if (ret.empty())\n                        return {};\n              \
    \      ret = ret << (i / 2);\n                    if (ret.size() < deg)\n    \
    \                    ret.resize(deg, T(0));\n                    return ret;\n\
    \                }\n            }\n            return P(deg, 0);\n        }\n\
    \        auto sqr = T(get_sqrt((*this)[0]));\n        if (sqr * sqr != (*this)[0])\n\
    \            return {};\n        P ret{sqr};\n        T inv2 = T(1) / T(2);\n\
    \        for (int i = 1; i < deg; i <<= 1)\n        {\n            ret = (ret\
    \ + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    P sqrt(const function<T(T)> &get_sqrt, int deg = -1) const\n   \
    \ {\n        return sqrt(deg, get_sqrt);\n    }\n\n    // F(0) must be 0\n   \
    \ P exp(int deg = -1) const\n    {\n        if (deg == -1)\n            deg =\
    \ this->size();\n        assert((*this)[0] == T(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1)\n            deg = n;\n        P ret({T(1)});\n      \
    \  for (int i = 1; i < deg; i <<= 1)\n        {\n            ret = (ret * (pre(i\
    \ << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    P pow(int64_t k, int deg = -1) const\n    {\n        const int n\
    \ = (int)this->size();\n        if (deg == -1)\n            deg = n;\n       \
    \ for (int i = 0; i < n; i++)\n        {\n            if ((*this)[i] != T(0))\n\
    \            {\n                T rev = T(1) / (*this)[i];\n                P\
    \ ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n      \
    \          if (i * k > deg)\n                    return P(deg, T(0));\n      \
    \          ret = (ret << (i * k)).pre(deg);\n                if (ret.size() <\
    \ deg)\n                    ret.resize(deg, T(0));\n                return ret;\n\
    \            }\n        }\n        return *this;\n    }\n\n    P mod_pow(int64_t\
    \ k, P g) const\n    {\n        P modinv = g.rev().inv();\n        auto get_div\
    \ = [&](P base)\n        {\n            if (base.size() < g.size())\n        \
    \    {\n                base.clear();\n                return base;\n        \
    \    }\n            int n = base.size() - g.size() + 1;\n            return (base.rev().pre(n)\
    \ * modinv.pre(n)).pre(n).rev(n);\n        };\n        P x(*this), ret{1};\n \
    \       while (k > 0)\n        {\n            if (k & 1)\n            {\n    \
    \            ret *= x;\n                ret -= get_div(ret) * g;\n           \
    \     ret.shrink();\n            }\n            x *= x;\n            x -= get_div(x)\
    \ * g;\n            x.shrink();\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    P taylor_shift(T c) const\n    {\n        int n = (int)this->size();\n\
    \        vector<T> fact(n), rfact(n);\n        fact[0] = rfact[0] = T(1);\n  \
    \      for (int i = 1; i < n; i++)\n            fact[i] = fact[i - 1] * T(i);\n\
    \        rfact[n - 1] = T(1) / fact[n - 1];\n        for (int i = n - 1; i > 1;\
    \ i--)\n            rfact[i - 1] = rfact[i] * T(i);\n        P p(*this);\n   \
    \     for (int i = 0; i < n; i++)\n            p[i] *= fact[i];\n        p = p.rev();\n\
    \        P bs(n, T(1));\n        for (int i = 1; i < n; i++)\n            bs[i]\
    \ = bs[i - 1] * c * rfact[i] * fact[i - 1];\n        p = (p * bs).pre(n);\n  \
    \      p = p.rev();\n        for (int i = 0; i < n; i++)\n            p[i] *=\
    \ rfact[i];\n        return p;\n    }\n};\n"
  code: "#pragma once\n#include \"library/mod/modint.cpp\"\n#include \"library/convolution/FFT.cpp\"\
    \n\n/**\n * @brief Formal Power Series\n * @see https://ei1333.github.io/library/math/fps/formal-power-series.cpp\n\
    \ * @arg modint<mod>, fft (has a method 'multiply')\n * @docs docs/FormalPowerSeries\n\
    \ */\nstruct MULT\n{\n};\ntemplate <typename T, auto &fft>\nstruct FormalPowerSeries\
    \ : vector<T>\n{\n    using vector<T>::vector;\n    using P = FormalPowerSeries;\n\
    \n    P pre(int deg) const\n    {\n        return P(begin(*this), begin(*this)\
    \ + min((int)this->size(), deg));\n    }\n\n    P rev(int deg = -1) const\n  \
    \  {\n        P ret(*this);\n        if (deg != -1)\n            ret.resize(deg,\
    \ T(0));\n        reverse(begin(ret), end(ret));\n        return ret;\n    }\n\
    \n    void shrink()\n    {\n        while (this->size() && this->back() == T(0))\n\
    \            this->pop_back();\n    }\n\n    P operator+(const P &r) const { return\
    \ P(*this) += r; }\n\n    P operator+(const T &v) const { return P(*this) += v;\
    \ }\n\n    P operator-(const P &r) const { return P(*this) -= r; }\n\n    P operator-(const\
    \ T &v) const { return P(*this) -= v; }\n\n    P operator*(const P &r) const {\
    \ return P(*this) *= r; }\n\n    P operator*(const T &v) const { return P(*this)\
    \ *= v; }\n\n    P operator/(const P &r) const { return P(*this) /= r; }\n\n \
    \   P operator%(const P &r) const { return P(*this) %= r; }\n\n    P &operator+=(const\
    \ P &r)\n    {\n        if (r.size() > this->size())\n            this->resize(r.size());\n\
    \        for (int i = 0; i < r.size(); i++)\n            (*this)[i] += r[i];\n\
    \        return *this;\n    }\n\n    P &operator-=(const P &r)\n    {\n      \
    \  if (r.size() > this->size())\n            this->resize(r.size());\n       \
    \ for (int i = 0; i < r.size(); i++)\n            (*this)[i] -= r[i];\n      \
    \  return *this;\n    }\n\n    P &operator*=(const P &r)\n    {\n        if (this->empty()\
    \ || r.empty())\n        {\n            this->clear();\n            return *this;\n\
    \        }\n        auto ret = fft.multiply(*this, r);\n        return *this =\
    \ {begin(ret), end(ret)};\n    }\n\n    P &operator/=(const P &r)\n    {\n   \
    \     if (this->size() < r.size())\n        {\n            this->clear();\n  \
    \          return *this;\n        }\n        int n = this->size() - r.size() +\
    \ 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P &operator%=(const P &r)\n    {\n        return *this -= *this\
    \ / r * r;\n    }\n\n    pair<P, P> div_mod(const P &r)\n    {\n        P q =\
    \ *this / r;\n        return make_pair(q, *this - q * r);\n    }\n\n    P operator-()\
    \ const\n    {\n        P ret(this->size());\n        for (int i = 0; i < this->size();\
    \ i++)\n            ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    P\
    \ &operator+=(const T &r)\n    {\n        if (this->empty())\n            this->resize(1);\n\
    \        (*this)[0] += r;\n        return *this;\n    }\n\n    P &operator-=(const\
    \ T &r)\n    {\n        if (this->empty())\n            this->resize(1);\n   \
    \     (*this)[0] -= r;\n        return *this;\n    }\n\n    P &operator*=(const\
    \ T &v)\n    {\n        for (int i = 0; i < this->size(); i++)\n            (*this)[i]\
    \ *= v;\n        return *this;\n    }\n\n    P dot(P r) const\n    {\n       \
    \ P ret(min(this->size(), r.size()));\n        for (int i = 0; i < ret.size();\
    \ i++)\n            ret[i] = (*this)[i] * r[i];\n        return ret;\n    }\n\n\
    \    P operator>>(int sz) const\n    {\n        if (this->size() <= sz)\n    \
    \        return {};\n        P ret(*this);\n        ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n        return ret;\n    }\n\n    P operator<<(int sz) const\n    {\n\
    \        P ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n        return\
    \ ret;\n    }\n\n    T operator()(T x) const\n    {\n        T r = 0, w = 1;\n\
    \        for (auto &v : *this)\n        {\n            r += w * v;\n         \
    \   w *= x;\n        }\n        return r;\n    }\n\n    P diff() const\n    {\n\
    \        const int n = (int)this->size();\n        P ret(max(0, n - 1));\n   \
    \     for (int i = 1; i < n; i++)\n            ret[i - 1] = (*this)[i] * T(i);\n\
    \        return ret;\n    }\n\n    P integral() const\n    {\n        const int\
    \ n = (int)this->size();\n        P ret(n + 1);\n        ret[0] = T(0);\n    \
    \    for (int i = 0; i < n; i++)\n            ret[i + 1] = (*this)[i] / T(i +\
    \ 1);\n        return ret;\n    }\n\n    // F(0) must not be 0\n    P inv(int\
    \ deg = -1) const\n    {\n        assert(((*this)[0]) != T(0));\n        const\
    \ int n = (int)this->size();\n        if (deg == -1)\n            deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\n\
    \        {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n\
    \        }\n        return ret.pre(deg);\n    }\n\n    // F(0) must be 1\n   \
    \ P log(int deg = -1) const\n    {\n        assert((*this)[0] == T(1));\n    \
    \    const int n = (int)this->size();\n        if (deg == -1)\n            deg\
    \ = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    P sqrt(\n        int deg = -1, const function<T(T)> &get_sqrt =\
    \ [](T)\n                      { return T(1); }) const\n    {\n        const int\
    \ n = (int)this->size();\n        if (deg == -1)\n            deg = n;\n     \
    \   if ((*this)[0] == T(0))\n        {\n            for (int i = 1; i < n; i++)\n\
    \            {\n                if ((*this)[i] != T(0))\n                {\n \
    \                   if (i & 1)\n                        return {};\n         \
    \           if (deg - i / 2 <= 0)\n                        break;\n          \
    \          auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n            \
    \        if (ret.empty())\n                        return {};\n              \
    \      ret = ret << (i / 2);\n                    if (ret.size() < deg)\n    \
    \                    ret.resize(deg, T(0));\n                    return ret;\n\
    \                }\n            }\n            return P(deg, 0);\n        }\n\
    \        auto sqr = T(get_sqrt((*this)[0]));\n        if (sqr * sqr != (*this)[0])\n\
    \            return {};\n        P ret{sqr};\n        T inv2 = T(1) / T(2);\n\
    \        for (int i = 1; i < deg; i <<= 1)\n        {\n            ret = (ret\
    \ + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    P sqrt(const function<T(T)> &get_sqrt, int deg = -1) const\n   \
    \ {\n        return sqrt(deg, get_sqrt);\n    }\n\n    // F(0) must be 0\n   \
    \ P exp(int deg = -1) const\n    {\n        if (deg == -1)\n            deg =\
    \ this->size();\n        assert((*this)[0] == T(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1)\n            deg = n;\n        P ret({T(1)});\n      \
    \  for (int i = 1; i < deg; i <<= 1)\n        {\n            ret = (ret * (pre(i\
    \ << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    P pow(int64_t k, int deg = -1) const\n    {\n        const int n\
    \ = (int)this->size();\n        if (deg == -1)\n            deg = n;\n       \
    \ for (int i = 0; i < n; i++)\n        {\n            if ((*this)[i] != T(0))\n\
    \            {\n                T rev = T(1) / (*this)[i];\n                P\
    \ ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n      \
    \          if (i * k > deg)\n                    return P(deg, T(0));\n      \
    \          ret = (ret << (i * k)).pre(deg);\n                if (ret.size() <\
    \ deg)\n                    ret.resize(deg, T(0));\n                return ret;\n\
    \            }\n        }\n        return *this;\n    }\n\n    P mod_pow(int64_t\
    \ k, P g) const\n    {\n        P modinv = g.rev().inv();\n        auto get_div\
    \ = [&](P base)\n        {\n            if (base.size() < g.size())\n        \
    \    {\n                base.clear();\n                return base;\n        \
    \    }\n            int n = base.size() - g.size() + 1;\n            return (base.rev().pre(n)\
    \ * modinv.pre(n)).pre(n).rev(n);\n        };\n        P x(*this), ret{1};\n \
    \       while (k > 0)\n        {\n            if (k & 1)\n            {\n    \
    \            ret *= x;\n                ret -= get_div(ret) * g;\n           \
    \     ret.shrink();\n            }\n            x *= x;\n            x -= get_div(x)\
    \ * g;\n            x.shrink();\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    P taylor_shift(T c) const\n    {\n        int n = (int)this->size();\n\
    \        vector<T> fact(n), rfact(n);\n        fact[0] = rfact[0] = T(1);\n  \
    \      for (int i = 1; i < n; i++)\n            fact[i] = fact[i - 1] * T(i);\n\
    \        rfact[n - 1] = T(1) / fact[n - 1];\n        for (int i = n - 1; i > 1;\
    \ i--)\n            rfact[i - 1] = rfact[i] * T(i);\n        P p(*this);\n   \
    \     for (int i = 0; i < n; i++)\n            p[i] *= fact[i];\n        p = p.rev();\n\
    \        P bs(n, T(1));\n        for (int i = 1; i < n; i++)\n            bs[i]\
    \ = bs[i - 1] * c * rfact[i] * fact[i - 1];\n        p = (p * bs).pre(n);\n  \
    \      p = p.rev();\n        for (int i = 0; i < n; i++)\n            p[i] *=\
    \ rfact[i];\n        return p;\n    }\n};\n"
  dependsOn:
  - library/mod/modint.cpp
  - library/convolution/FFT.cpp
  - library/convolution/NTT.cpp
  isVerificationFile: false
  path: library/math/FormalPowerSeries.cpp
  requiredBy: []
  timestamp: '2021-08-26 18:08:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki-FPS.power.test.cpp
documentation_of: library/math/FormalPowerSeries.cpp
layout: document
redirect_from:
- /library/library/math/FormalPowerSeries.cpp
- /library/library/math/FormalPowerSeries.cpp.html
title: Formal Power Series
---
