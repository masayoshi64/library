---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/FPS.power.test.cpp
    title: verify/FPS.power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod.test.cpp
    title: verify/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/FormalPowerSeries.cpp\"\ntemplate <typename\
    \ T>\nstruct FormalPowerSeries : vector<T> {\n    using vector<T>::vector;\n \
    \   using P = FormalPowerSeries;\n\n    using MULT = function<P(P, P)>;\n\n  \
    \  static MULT& get_mult() {\n        static MULT mult = nullptr;\n        return\
    \ mult;\n    }\n\n    static void set_fft(MULT f) { get_mult() = f; }\n\n    //\
    \ \u672B\u5C3E\u306E0\u3092\u6D88\u3059\n    void shrink() {\n        while (this->size()\
    \ && this->back() == T(0)) this->pop_back();\n    }\n\n    P operator+(const P&\
    \ r) const { return P(*this) += r; }\n\n    P operator+(const T& v) const { return\
    \ P(*this) += v; }\n\n    P operator-(const P& r) const { return P(*this) -= r;\
    \ }\n\n    P operator-(const T& v) const { return P(*this) -= v; }\n\n    P operator*(const\
    \ P& r) const { return P(*this) *= r; }\n\n    P operator*(const T& v) const {\
    \ return P(*this) *= v; }\n\n    P operator/(const P& r) const { return P(*this)\
    \ /= r; }\n\n    P operator%(const P& r) const { return P(*this) %= r; }\n\n \
    \   P& operator+=(const P& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n\n    P& operator+=(const T& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    P& operator-=(const P& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    P& operator-=(const T& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        shrink();\n        return\
    \ *this;\n    }\n\n    P& operator*=(const T& v) {\n        const int n = (int)this->size();\n\
    \        for (int k = 0; k < n; k++) (*this)[k] *= v;\n        return *this;\n\
    \    }\n\n    P& operator*=(const P& r) {\n        if (this->empty() || r.empty())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  assert(get_mult() != nullptr);\n        return *this = get_mult()(*this, r);\n\
    \    }\n\n    P& operator%=(const P& r) { return *this -= *this / r * r; }\n\n\
    \    P operator-() const {\n        P ret(this->size());\n        for (int i =\
    \ 0; i < this->size(); i++) ret[i] = -(*this)[i];\n        return ret;\n    }\n\
    \n    P& operator/=(const P& r) {\n        if (this->size() < r.size()) {\n  \
    \          this->clear();\n            return *this;\n        }\n        int n\
    \ = this->size() - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P pre(int sz) const {\n        return P(begin(*this), begin(*this)\
    \ + min((int)this->size(), sz));\n    }\n\n    // f/x^sz\n    P operator>>(int\
    \ sz) const {\n        if (this->size() <= sz) return {};\n        P ret(*this);\n\
    \        ret.erase(ret.begin(), ret.begin() + sz);\n        return ret;\n    }\n\
    \n    // f*x^sz\n    P operator<<(int sz) const {\n        P ret(*this);\n   \
    \     ret.insert(ret.begin(), sz, T(0));\n        return ret;\n    }\n\n    //\
    \ \u53CD\u8EE2\n    P rev(int deg = -1) const {\n        P ret(*this);\n     \
    \   if (deg != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n\
    \        return ret;\n    }\n\n    //\u5FAE\u5206\n    P diff() const {\n    \
    \    const int n = (int)this->size();\n        P ret(max(0, n - 1));\n       \
    \ for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    // \u7A4D\u5206\n    P integral() const {\n        const\
    \ int n = (int)this->size();\n        P ret(n + 1);\n        ret[0] = T(0);\n\
    \        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);\n   \
    \     return ret;\n    }\n\n    // 1/f\u306Edeg\u9805\n    // F(0) must not be\
    \ 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // F(0) must be 1\n    P\
    \ log(int deg = -1) const {\n        assert((*this)[0] == 1);\n        const int\
    \ n = (int)this->size();\n        if (deg == -1) deg = n;\n        return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n    }\n\n    P sqrt(int deg = -1)\
    \ const {\n        const int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n\n        if ((*this)[0] == T(0)) {\n            for (int i = 1; i < n;\
    \ i++) {\n                if ((*this)[i] != T(0)) {\n                    if (i\
    \ & 1) return {};\n                    if (deg - i / 2 <= 0) break;\n        \
    \            auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);\n         \
    \           if (ret.size() < deg) ret.resize(deg, T(0));\n                   \
    \ return ret;\n                }\n            }\n            return P(deg, 0);\n\
    \        }\n\n        P ret({T(1)});\n        T inv2 = T(1) / T(2);\n        for\
    \ (int i = 1; i < deg; i <<= 1) {\n            ret = (ret + pre(i << 1) * ret.inv(i\
    \ << 1)) * inv2;\n        }\n        return ret.pre(deg);\n    }\n\n    // F(0)\
    \ must be 0\n    P exp(int deg = -1) const {\n        assert((*this)[0] == T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1)});\n        for (int i = 1; i < deg; i <<= 1) {\n        \
    \    ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n     \
    \   }\n        return ret.pre(deg);\n    }\n\n    P pow(int64_t k, int deg = -1)\
    \ const {\n        const int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i] != T(0))\
    \ {\n                T rev = T(1) / (*this)[i];\n                P C(*this * rev);\n\
    \                P D(n - i);\n                for (int j = i; j < n; j++) D[j\
    \ - i] = C[j];\n                D = (D.log() * k).exp() * (*this)[i].pow(k);\n\
    \                P E(deg);\n                if (i * k > deg) return E;\n     \
    \           auto S = i * k;\n                for (int j = 0; j + S < deg && j\
    \ < D.size(); j++)\n                    E[j + S] = D[j];\n                return\
    \ E;\n            }\n        }\n        return *this;\n    }\n\n    //\u4EE3\u5165\
    \n    T eval(T x) const {\n        T r = 0, w = 1;\n        for (auto& v : *this)\
    \ {\n            r += w * v;\n            w *= x;\n        }\n        return r;\n\
    \    }\n};\n\n// NTT<mint> ntt;\n// FPS mult_ntt(const FPS::P& a, const FPS::P&\
    \ b) {\n//     auto ret = ntt.multiply(a, b);\n//     return FPS::P(ret.begin(),\
    \ ret.end());\n// }\n// FPS mult(const FPS::P& a, const FPS::P& b) {\n//     FPS\
    \ c(a.size() + b.size() - 1);\n//     rep(i, a.size()) rep(j, b.size()) { c[i\
    \ + j] += a[i] * b[j]; }\n//     return c;\n// }\n"
  code: "template <typename T>\nstruct FormalPowerSeries : vector<T> {\n    using\
    \ vector<T>::vector;\n    using P = FormalPowerSeries;\n\n    using MULT = function<P(P,\
    \ P)>;\n\n    static MULT& get_mult() {\n        static MULT mult = nullptr;\n\
    \        return mult;\n    }\n\n    static void set_fft(MULT f) { get_mult() =\
    \ f; }\n\n    // \u672B\u5C3E\u306E0\u3092\u6D88\u3059\n    void shrink() {\n\
    \        while (this->size() && this->back() == T(0)) this->pop_back();\n    }\n\
    \n    P operator+(const P& r) const { return P(*this) += r; }\n\n    P operator+(const\
    \ T& v) const { return P(*this) += v; }\n\n    P operator-(const P& r) const {\
    \ return P(*this) -= r; }\n\n    P operator-(const T& v) const { return P(*this)\
    \ -= v; }\n\n    P operator*(const P& r) const { return P(*this) *= r; }\n\n \
    \   P operator*(const T& v) const { return P(*this) *= v; }\n\n    P operator/(const\
    \ P& r) const { return P(*this) /= r; }\n\n    P operator%(const P& r) const {\
    \ return P(*this) %= r; }\n\n    P& operator+=(const P& r) {\n        if (r.size()\
    \ > this->size()) this->resize(r.size());\n        for (int i = 0; i < r.size();\
    \ i++) (*this)[i] += r[i];\n        return *this;\n    }\n\n    P& operator+=(const\
    \ T& r) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] +=\
    \ r;\n        return *this;\n    }\n\n    P& operator-=(const P& r) {\n      \
    \  if (r.size() > this->size()) this->resize(r.size());\n        for (int i =\
    \ 0; i < r.size(); i++) (*this)[i] -= r[i];\n        shrink();\n        return\
    \ *this;\n    }\n\n    P& operator-=(const T& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        shrink();\n        return\
    \ *this;\n    }\n\n    P& operator*=(const T& v) {\n        const int n = (int)this->size();\n\
    \        for (int k = 0; k < n; k++) (*this)[k] *= v;\n        return *this;\n\
    \    }\n\n    P& operator*=(const P& r) {\n        if (this->empty() || r.empty())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  assert(get_mult() != nullptr);\n        return *this = get_mult()(*this, r);\n\
    \    }\n\n    P& operator%=(const P& r) { return *this -= *this / r * r; }\n\n\
    \    P operator-() const {\n        P ret(this->size());\n        for (int i =\
    \ 0; i < this->size(); i++) ret[i] = -(*this)[i];\n        return ret;\n    }\n\
    \n    P& operator/=(const P& r) {\n        if (this->size() < r.size()) {\n  \
    \          this->clear();\n            return *this;\n        }\n        int n\
    \ = this->size() - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P pre(int sz) const {\n        return P(begin(*this), begin(*this)\
    \ + min((int)this->size(), sz));\n    }\n\n    // f/x^sz\n    P operator>>(int\
    \ sz) const {\n        if (this->size() <= sz) return {};\n        P ret(*this);\n\
    \        ret.erase(ret.begin(), ret.begin() + sz);\n        return ret;\n    }\n\
    \n    // f*x^sz\n    P operator<<(int sz) const {\n        P ret(*this);\n   \
    \     ret.insert(ret.begin(), sz, T(0));\n        return ret;\n    }\n\n    //\
    \ \u53CD\u8EE2\n    P rev(int deg = -1) const {\n        P ret(*this);\n     \
    \   if (deg != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n\
    \        return ret;\n    }\n\n    //\u5FAE\u5206\n    P diff() const {\n    \
    \    const int n = (int)this->size();\n        P ret(max(0, n - 1));\n       \
    \ for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    // \u7A4D\u5206\n    P integral() const {\n        const\
    \ int n = (int)this->size();\n        P ret(n + 1);\n        ret[0] = T(0);\n\
    \        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);\n   \
    \     return ret;\n    }\n\n    // 1/f\u306Edeg\u9805\n    // F(0) must not be\
    \ 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // F(0) must be 1\n    P\
    \ log(int deg = -1) const {\n        assert((*this)[0] == 1);\n        const int\
    \ n = (int)this->size();\n        if (deg == -1) deg = n;\n        return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n    }\n\n    P sqrt(int deg = -1)\
    \ const {\n        const int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n\n        if ((*this)[0] == T(0)) {\n            for (int i = 1; i < n;\
    \ i++) {\n                if ((*this)[i] != T(0)) {\n                    if (i\
    \ & 1) return {};\n                    if (deg - i / 2 <= 0) break;\n        \
    \            auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);\n         \
    \           if (ret.size() < deg) ret.resize(deg, T(0));\n                   \
    \ return ret;\n                }\n            }\n            return P(deg, 0);\n\
    \        }\n\n        P ret({T(1)});\n        T inv2 = T(1) / T(2);\n        for\
    \ (int i = 1; i < deg; i <<= 1) {\n            ret = (ret + pre(i << 1) * ret.inv(i\
    \ << 1)) * inv2;\n        }\n        return ret.pre(deg);\n    }\n\n    // F(0)\
    \ must be 0\n    P exp(int deg = -1) const {\n        assert((*this)[0] == T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1)});\n        for (int i = 1; i < deg; i <<= 1) {\n        \
    \    ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n     \
    \   }\n        return ret.pre(deg);\n    }\n\n    P pow(int64_t k, int deg = -1)\
    \ const {\n        const int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i] != T(0))\
    \ {\n                T rev = T(1) / (*this)[i];\n                P C(*this * rev);\n\
    \                P D(n - i);\n                for (int j = i; j < n; j++) D[j\
    \ - i] = C[j];\n                D = (D.log() * k).exp() * (*this)[i].pow(k);\n\
    \                P E(deg);\n                if (i * k > deg) return E;\n     \
    \           auto S = i * k;\n                for (int j = 0; j + S < deg && j\
    \ < D.size(); j++)\n                    E[j + S] = D[j];\n                return\
    \ E;\n            }\n        }\n        return *this;\n    }\n\n    //\u4EE3\u5165\
    \n    T eval(T x) const {\n        T r = 0, w = 1;\n        for (auto& v : *this)\
    \ {\n            r += w * v;\n            w *= x;\n        }\n        return r;\n\
    \    }\n};\n\n// NTT<mint> ntt;\n// FPS mult_ntt(const FPS::P& a, const FPS::P&\
    \ b) {\n//     auto ret = ntt.multiply(a, b);\n//     return FPS::P(ret.begin(),\
    \ ret.end());\n// }\n// FPS mult(const FPS::P& a, const FPS::P& b) {\n//     FPS\
    \ c(a.size() + b.size() - 1);\n//     rep(i, a.size()) rep(j, b.size()) { c[i\
    \ + j] += a[i] * b[j]; }\n//     return c;\n// }"
  dependsOn: []
  isVerificationFile: false
  path: library/math/FormalPowerSeries.cpp
  requiredBy: []
  timestamp: '2020-11-18 22:08:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-convolution_mod_1000000007.test.cpp
  - verify/FPS.power.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
documentation_of: library/math/FormalPowerSeries.cpp
layout: document
redirect_from:
- /library/library/math/FormalPowerSeries.cpp
- /library/library/math/FormalPowerSeries.cpp.html
title: library/math/FormalPowerSeries.cpp
---
