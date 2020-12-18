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
  bundledCode: "#line 1 \"library/convolution/FFT.cpp\"\nnamespace FFT {\n\nusing\
    \ i64 = int64_t;\nusing u128 = __uint128_t;\nconstexpr int32_t m0 = 167772161;\n\
    constexpr int32_t m1 = 469762049;\nconstexpr int32_t m2 = 754974721;\nusing mint0\
    \ = modint<m0>;\nusing mint1 = modint<m1>;\nusing mint2 = modint<m2>;\nconstexpr\
    \ int r01 = 104391568;\nconstexpr int r02 = 323560596;\nconstexpr int r12 = 399692502;\n\
    constexpr int r02r12 = i64(r02) * r12 % m2;\nconstexpr i64 w1 = m0;\nconstexpr\
    \ i64 w2 = i64(m0) * m1;\n\ntemplate <typename T, typename submint>\nvector<submint>\
    \ mul(const vector<T>& a, const vector<T>& b) {\n    NTT<submint> ntt;\n    vector<submint>\
    \ s(a.size()), t(b.size());\n    for (int i = 0; i < (int)a.size(); ++i)\n   \
    \     s[i] = i64(a[i] % submint::get_mod());\n    for (int i = 0; i < (int)b.size();\
    \ ++i)\n        t[i] = i64(b[i] % submint::get_mod());\n    return ntt.multiply(s,\
    \ t);\n}\n\ntemplate <typename T>\nvector<int> multiply(const vector<T>& s, const\
    \ vector<T>& t, int Mod) {\n    auto d0 = mul<T, mint0>(s, t);\n    auto d1 =\
    \ mul<T, mint1>(s, t);\n    auto d2 = mul<T, mint2>(s, t);\n    int n = d0.size();\n\
    \    vector<int> ret(n);\n    const int W1 = w1 % Mod;\n    const int W2 = w2\
    \ % Mod;\n    for (int i = 0; i < n; i++) {\n        int n1 = d1[i].get(), n2\
    \ = d2[i].get(), a = d0[i].get();\n        int b = i64(n1 + m1 - a) * r01 % m1;\n\
    \        int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;\n     \
    \   ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) % Mod;\n    }\n    return ret;\n\
    }\ntemplate <typename Mint>\nvector<Mint> multiply(const vector<Mint>& a, const\
    \ vector<Mint>& b) {\n    vector<int> s(a.size()), t(b.size());\n    for (int\
    \ i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();\n    for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = b[i].get();\n    vector<int> u = multiply<int>(s, t, Mint::get_mod());\n\
    \    vector<Mint> ret(u.size());\n    for (int i = 0; i < (int)u.size(); ++i)\
    \ ret[i] = Mint(u[i]);\n    return ret;\n}\n\ntemplate <typename T>\nvector<u128>\
    \ multiply_u128(const vector<T>& s, const vector<T>& t) {\n    auto d0 = mul<T,\
    \ mint0>(s, t);\n    auto d1 = mul<T, mint1>(s, t);\n    auto d2 = mul<T, mint2>(s,\
    \ t);\n    int n = d0.size();\n    vector<u128> ret(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        i64 n1 = d1[i].get(), n2 = d2[i].get();\n        i64 a\
    \ = d0[i].get();\n        u128 b = (n1 + m1 - a) * r01 % m1;\n        u128 c =\
    \ ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;\n        ret[i] = a + b * w1\
    \ + c * w2;\n    }\n    return ret;\n}\n};  // namespace FFT\n"
  code: "namespace FFT {\n\nusing i64 = int64_t;\nusing u128 = __uint128_t;\nconstexpr\
    \ int32_t m0 = 167772161;\nconstexpr int32_t m1 = 469762049;\nconstexpr int32_t\
    \ m2 = 754974721;\nusing mint0 = modint<m0>;\nusing mint1 = modint<m1>;\nusing\
    \ mint2 = modint<m2>;\nconstexpr int r01 = 104391568;\nconstexpr int r02 = 323560596;\n\
    constexpr int r12 = 399692502;\nconstexpr int r02r12 = i64(r02) * r12 % m2;\n\
    constexpr i64 w1 = m0;\nconstexpr i64 w2 = i64(m0) * m1;\n\ntemplate <typename\
    \ T, typename submint>\nvector<submint> mul(const vector<T>& a, const vector<T>&\
    \ b) {\n    NTT<submint> ntt;\n    vector<submint> s(a.size()), t(b.size());\n\
    \    for (int i = 0; i < (int)a.size(); ++i)\n        s[i] = i64(a[i] % submint::get_mod());\n\
    \    for (int i = 0; i < (int)b.size(); ++i)\n        t[i] = i64(b[i] % submint::get_mod());\n\
    \    return ntt.multiply(s, t);\n}\n\ntemplate <typename T>\nvector<int> multiply(const\
    \ vector<T>& s, const vector<T>& t, int Mod) {\n    auto d0 = mul<T, mint0>(s,\
    \ t);\n    auto d1 = mul<T, mint1>(s, t);\n    auto d2 = mul<T, mint2>(s, t);\n\
    \    int n = d0.size();\n    vector<int> ret(n);\n    const int W1 = w1 % Mod;\n\
    \    const int W2 = w2 % Mod;\n    for (int i = 0; i < n; i++) {\n        int\
    \ n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();\n        int b = i64(n1\
    \ + m1 - a) * r01 % m1;\n        int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 -\
    \ b) * r12) % m2;\n        ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) % Mod;\n\
    \    }\n    return ret;\n}\ntemplate <typename Mint>\nvector<Mint> multiply(const\
    \ vector<Mint>& a, const vector<Mint>& b) {\n    vector<int> s(a.size()), t(b.size());\n\
    \    for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();\n    for (int\
    \ i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();\n    vector<int> u = multiply<int>(s,\
    \ t, Mint::get_mod());\n    vector<Mint> ret(u.size());\n    for (int i = 0; i\
    \ < (int)u.size(); ++i) ret[i] = Mint(u[i]);\n    return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<u128> multiply_u128(const vector<T>& s, const vector<T>& t) {\n \
    \   auto d0 = mul<T, mint0>(s, t);\n    auto d1 = mul<T, mint1>(s, t);\n    auto\
    \ d2 = mul<T, mint2>(s, t);\n    int n = d0.size();\n    vector<u128> ret(n);\n\
    \    for (int i = 0; i < n; i++) {\n        i64 n1 = d1[i].get(), n2 = d2[i].get();\n\
    \        i64 a = d0[i].get();\n        u128 b = (n1 + m1 - a) * r01 % m1;\n  \
    \      u128 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;\n        ret[i]\
    \ = a + b * w1 + c * w2;\n    }\n    return ret;\n}\n};  // namespace FFT\n"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/FFT.cpp
  requiredBy: []
  timestamp: '2020-12-18 23:34:41+09:00'
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
