---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/convolution/FFT.cpp\"\nstruct ArbitraryNTT\n{\n\
    \    using i64 = int64_t;\n    static const int32_t m0 = 167772161;\n    static\
    \ const int32_t m1 = 469762049;\n    static const int32_t m2 = 754974721;\n  \
    \  using mint0 = MontgomeryModInt<m0>;\n    using mint1 = MontgomeryModInt<m1>;\n\
    \    using mint2 = MontgomeryModInt<m2>;\n    const int32_t r01 = 104391568;\n\
    \    const int32_t r02 = 323560596;\n    const int32_t r12 = 399692502;\n    const\
    \ int32_t r02r12 = i64(r02) * r12 % m2;\n    const i64 w1 = m0;\n    const i64\
    \ w2 = i64(m0) * m1;\n\n    ArbitraryNTT()\n    {\n    }\n    template <typename\
    \ T, typename submint>\n    vector<submint> mul(const vector<T> &a, const vector<T>\
    \ &b)\n    {\n        static NTT<submint> ntt;\n        vector<submint> s(a.size()),\
    \ t(b.size());\n        for (int i = 0; i < (int)a.size(); ++i)\n            s[i]\
    \ = i64(a[i] % submint::get_mod());\n        for (int i = 0; i < (int)b.size();\
    \ ++i)\n            t[i] = i64(b[i] % submint::get_mod());\n        return ntt.multiply(s,\
    \ t);\n    }\n\n    template <typename Mint>\n    vector<mint> multiply(const\
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
    \      return ret;\n    }\n\n    template <typename T>\n    vector<T> multiply_ll(const\
    \ vector<T> &s, const vector<T> &t)\n    {\n        if (s.size() == 0 && t.size()\
    \ == 0)\n            return {};\n        if (min<int>(s.size(), t.size()) < 128)\n\
    \        {\n            vector<T> ret(s.size() + t.size() - 1);\n            for\
    \ (int i = 0; i < (int)s.size(); ++i)\n                for (int j = 0; j < (int)t.size();\
    \ ++j)\n                    ret[i + j] += i64(s[i]) * t[j];\n            return\
    \ ret;\n        }\n        auto d0 = mul<T, mint0>(s, t);\n        auto d1 = mul<T,\
    \ mint1>(s, t);\n        auto d2 = mul<T, mint2>(s, t);\n        int n = d0.size();\n\
    \        vector<T> ret(n);\n        for (int i = 0; i < n; i++)\n        {\n \
    \           i64 n1 = d1[i].get(), n2 = d2[i].get();\n            i64 a = d0[i].get();\n\
    \            T b = (n1 + m1 - a) * r01 % m1;\n            T c = ((n2 + m2 - a)\
    \ * r02r12 + (m2 - b) * r12) % m2;\n            ret[i] = a + b * w1 + c * w2;\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "struct ArbitraryNTT\n{\n    using i64 = int64_t;\n    static const int32_t\
    \ m0 = 167772161;\n    static const int32_t m1 = 469762049;\n    static const\
    \ int32_t m2 = 754974721;\n    using mint0 = MontgomeryModInt<m0>;\n    using\
    \ mint1 = MontgomeryModInt<m1>;\n    using mint2 = MontgomeryModInt<m2>;\n   \
    \ const int32_t r01 = 104391568;\n    const int32_t r02 = 323560596;\n    const\
    \ int32_t r12 = 399692502;\n    const int32_t r02r12 = i64(r02) * r12 % m2;\n\
    \    const i64 w1 = m0;\n    const i64 w2 = i64(m0) * m1;\n\n    ArbitraryNTT()\n\
    \    {\n    }\n    template <typename T, typename submint>\n    vector<submint>\
    \ mul(const vector<T> &a, const vector<T> &b)\n    {\n        static NTT<submint>\
    \ ntt;\n        vector<submint> s(a.size()), t(b.size());\n        for (int i\
    \ = 0; i < (int)a.size(); ++i)\n            s[i] = i64(a[i] % submint::get_mod());\n\
    \        for (int i = 0; i < (int)b.size(); ++i)\n            t[i] = i64(b[i]\
    \ % submint::get_mod());\n        return ntt.multiply(s, t);\n    }\n\n    template\
    \ <typename Mint>\n    vector<mint> multiply(const vector<Mint> &x, const vector<Mint>\
    \ &y)\n    {\n        if (x.size() == 0 && y.size() == 0)\n            return\
    \ {};\n        if (min<int>(x.size(), y.size()) < 128)\n        {\n          \
    \  vector<Mint> ret(x.size() + y.size() - 1);\n            for (int i = 0; i <\
    \ (int)x.size(); ++i)\n                for (int j = 0; j < (int)y.size(); ++j)\n\
    \                    ret[i + j] += x[i] * y[j];\n            return ret;\n   \
    \     }\n        vector<int> s(x.size()), t(y.size());\n        for (int i = 0;\
    \ i < (int)x.size(); ++i)\n            s[i] = x[i].get();\n        for (int i\
    \ = 0; i < (int)y.size(); ++i)\n            t[i] = y[i].get();\n        auto d0\
    \ = mul<int, mint0>(s, t);\n        auto d1 = mul<int, mint1>(s, t);\n       \
    \ auto d2 = mul<int, mint2>(s, t);\n        int n = d0.size();\n        vector<Mint>\
    \ ret(n);\n        const Mint W1 = w1;\n        const Mint W2 = w2;\n        for\
    \ (int i = 0; i < n; i++)\n        {\n            int n1 = d1[i].get(), n2 = d2[i].get(),\
    \ a = d0[i].get();\n            int b = i64(n1 + m1 - a) * r01 % m1;\n       \
    \     int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;\n        \
    \    ret[i] = W1 * b + W2 * c + a;\n        }\n        return ret;\n    }\n\n\
    \    template <typename T>\n    vector<T> multiply_ll(const vector<T> &s, const\
    \ vector<T> &t)\n    {\n        if (s.size() == 0 && t.size() == 0)\n        \
    \    return {};\n        if (min<int>(s.size(), t.size()) < 128)\n        {\n\
    \            vector<T> ret(s.size() + t.size() - 1);\n            for (int i =\
    \ 0; i < (int)s.size(); ++i)\n                for (int j = 0; j < (int)t.size();\
    \ ++j)\n                    ret[i + j] += i64(s[i]) * t[j];\n            return\
    \ ret;\n        }\n        auto d0 = mul<T, mint0>(s, t);\n        auto d1 = mul<T,\
    \ mint1>(s, t);\n        auto d2 = mul<T, mint2>(s, t);\n        int n = d0.size();\n\
    \        vector<T> ret(n);\n        for (int i = 0; i < n; i++)\n        {\n \
    \           i64 n1 = d1[i].get(), n2 = d2[i].get();\n            i64 a = d0[i].get();\n\
    \            T b = (n1 + m1 - a) * r01 % m1;\n            T c = ((n2 + m2 - a)\
    \ * r02r12 + (m2 - b) * r12) % m2;\n            ret[i] = a + b * w1 + c * w2;\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/FFT.cpp
  requiredBy: []
  timestamp: '2021-08-24 20:57:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-convolution_mod_1000000007.test.cpp
documentation_of: library/convolution/FFT.cpp
layout: document
redirect_from:
- /library/library/convolution/FFT.cpp
- /library/library/convolution/FFT.cpp.html
title: library/convolution/FFT.cpp
---
