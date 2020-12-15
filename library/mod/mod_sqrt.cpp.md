---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/mod/mod_sqrt.cpp\"\ntemplate <typename T>\nT mod_sqrt(const\
    \ T &a, const T &p) {\n    if (a == 0) return 0;\n    if (p == 2) return a;\n\
    \    if (mod_pow(a, (p - 1) >> 1, p) != 1) return -1;\n    T b = 1;\n    while\
    \ (mod_pow(b, (p - 1) >> 1, p) == 1) ++b;\n    T e = 0, m = p - 1;\n    while\
    \ (m % 2 == 0) m >>= 1, ++e;\n    T x = mod_pow(a, (m - 1) >> 1, p);\n    T y\
    \ = a * (x * x % p) % p;\n    (x *= a) %= p;\n    T z = mod_pow(b, m, p);\n  \
    \  while (y != 1) {\n        T j = 0, t = y;\n        while (t != 1) {\n     \
    \       j += 1;\n            (t *= t) %= p;\n        }\n        z = mod_pow(z,\
    \ T(1) << (e - j - 1), p);\n        (x *= z) %= p;\n        (z *= z) %= p;\n \
    \       (y *= z) %= p;\n        e = j;\n    }\n    return x;\n}\n"
  code: "template <typename T>\nT mod_sqrt(const T &a, const T &p) {\n    if (a ==\
    \ 0) return 0;\n    if (p == 2) return a;\n    if (mod_pow(a, (p - 1) >> 1, p)\
    \ != 1) return -1;\n    T b = 1;\n    while (mod_pow(b, (p - 1) >> 1, p) == 1)\
    \ ++b;\n    T e = 0, m = p - 1;\n    while (m % 2 == 0) m >>= 1, ++e;\n    T x\
    \ = mod_pow(a, (m - 1) >> 1, p);\n    T y = a * (x * x % p) % p;\n    (x *= a)\
    \ %= p;\n    T z = mod_pow(b, m, p);\n    while (y != 1) {\n        T j = 0, t\
    \ = y;\n        while (t != 1) {\n            j += 1;\n            (t *= t) %=\
    \ p;\n        }\n        z = mod_pow(z, T(1) << (e - j - 1), p);\n        (x *=\
    \ z) %= p;\n        (z *= z) %= p;\n        (y *= z) %= p;\n        e = j;\n \
    \   }\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/mod_sqrt.cpp
  requiredBy: []
  timestamp: '2020-12-15 21:38:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mod/mod_sqrt.cpp
layout: document
redirect_from:
- /library/library/mod/mod_sqrt.cpp
- /library/library/mod/mod_sqrt.cpp.html
title: library/mod/mod_sqrt.cpp
---
