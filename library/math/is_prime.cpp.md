---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/math/pollard.cpp
    title: factorization(pollard)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj-NTL_1_A.test.cpp
    title: verify/aoj-NTL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/is_prime.md
    document_title: is_prime(miller-rabin)
    links:
    - http://miller-rabin.appspot.com/
  bundledCode: "#line 1 \"library/math/is_prime.cpp\"\n/**\n * @brief is_prime(miller-rabin)\n\
    \ * @docs docs/is_prime.md\n */\n// codeforces\u3067\u306F__int128\u304C\u4F7F\
    \u3048\u306A\u3044\u306E\u3067\u6D88\u3059\u3053\u3068\n// http://miller-rabin.appspot.com/\n\
    bool is_prime(ll n) {\n    if (n <= 1) return false;\n    if (n == 2) return true;\n\
    \    if (n % 2 == 0) return false;\n    ll d = n - 1;\n    while (d % 2 == 0)\
    \ d /= 2;\n    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n        a %= n;\n        if (a == 0) return true;\n        ll t = d;\n  \
    \      ll y = modpow(a, t, n);\n        while (t != n - 1 && y != 1 && y != n\
    \ - 1) {\n            y = __int128_t(y) * y % n;\n            t <<= 1;\n     \
    \   }\n        if (y != n - 1 && t % 2 == 0) {\n            return false;\n  \
    \      }\n    }\n    return true;\n}\n"
  code: "/**\n * @brief is_prime(miller-rabin)\n * @docs docs/is_prime.md\n */\n//\
    \ codeforces\u3067\u306F__int128\u304C\u4F7F\u3048\u306A\u3044\u306E\u3067\u6D88\
    \u3059\u3053\u3068\n// http://miller-rabin.appspot.com/\nbool is_prime(ll n) {\n\
    \    if (n <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 ==\
    \ 0) return false;\n    ll d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    for\
    \ (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n        a %=\
    \ n;\n        if (a == 0) return true;\n        ll t = d;\n        ll y = modpow(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = __int128_t(y) * y % n;\n            t <<= 1;\n        }\n        if (y !=\
    \ n - 1 && t % 2 == 0) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/math/is_prime.cpp
  requiredBy:
  - library/math/pollard.cpp
  timestamp: '2020-11-15 12:33:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj-NTL_1_A.test.cpp
documentation_of: library/math/is_prime.cpp
layout: document
redirect_from:
- /library/library/math/is_prime.cpp
- /library/library/math/is_prime.cpp.html
title: is_prime(miller-rabin)
---
