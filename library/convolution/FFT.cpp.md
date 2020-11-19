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
  bundledCode: "#line 1 \"library/convolution/FFT.cpp\"\ntemplate <int mod>\nvector<int>\
    \ multiply(vector<int> &a, vector<int> &b) {\n    using mint = modint<mod>;\n\
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
  code: "template <int mod>\nvector<int> multiply(vector<int> &a, vector<int> &b)\
    \ {\n    using mint = modint<mod>;\n    using mint1 = modint<167772161>;\n   \
    \ using mint2 = modint<469762049>;\n    using mint3 = modint<595591169>;\n   \
    \ NTT<mint1> ntt1;\n    NTT<mint2> ntt2;\n    NTT<mint3> ntt3;\n    vector<mint1>\
    \ a1(begin(a), end(a)), b1(begin(b), end(b));\n    vector<mint2> a2(begin(a),\
    \ end(a)), b2(begin(b), end(b));\n    vector<mint3> a3(begin(a), end(a)), b3(begin(b),\
    \ end(b));\n    auto x = ntt1.multiply(a1, b1);\n    auto y = ntt2.multiply(a2,\
    \ b2);\n    auto z = ntt3.multiply(a3, b3);\n    const int m1 = 167772161, m2\
    \ = 469762049, m3 = 595591169;\n    const auto m1_inv_m2 = mint2(m1).inverse().get();\n\
    \    const auto m12_inv_m3 = (mint3(m1) * m2).inverse().get();\n    const auto\
    \ m12_mod = (mint(m1) * m2).get();\n    vector<int> ret(x.size());\n    for (int\
    \ i = 0; i < x.size(); i++) {\n        auto v1 = ((mint2(y[i]) + m2 - x[i].get())\
    \ * m1_inv_m2).get();\n        auto v2 =\n            ((z[i] + m3 - x[i].get()\
    \ - mint3(m1) * v1) * m12_inv_m3).get();\n        ret[i] = (mint(x[i].get()) +\
    \ mint(m1) * v1 + mint(m12_mod) * v2).get();\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/FFT.cpp
  requiredBy: []
  timestamp: '2020-11-19 12:41:17+09:00'
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
