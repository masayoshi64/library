---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/math/is_prime.cpp
    title: is_prime(miller-rabin)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj-NTL_1_A.test.cpp
    title: verify/aoj-NTL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: pollard.md
    document_title: factorization(pollard)
    links: []
  bundledCode: "#line 1 \"library/math/pollard.cpp\"\n/**\n * @brief factorization(pollard)\n\
    \ * @docs pollard.md\n */\n#line 1 \"library/math/is_prime.cpp\"\n/**\n * @brief\
    \ is_prime(miller-rabin)\n * @docs docs/is_prime.md\n */\n// codeforces\u3067\u306F\
    __int128\u304C\u4F7F\u3048\u306A\u3044\u306E\u3067\u6D88\u3059\u3053\u3068\n//\
    \ http://miller-rabin.appspot.com/\nbool is_prime(ll n) {\n    if (n <= 1) return\
    \ false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return false;\n  \
    \  ll d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    for (ll a : {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022}) {\n        a %= n;\n        if (a == 0)\
    \ return true;\n        ll t = d;\n        ll y = modpow(a, t, n);\n        while\
    \ (t != n - 1 && y != 1 && y != n - 1) {\n            y = __int128_t(y) * y %\
    \ n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n\
    \            return false;\n        }\n    }\n    return true;\n}\n#line 6 \"\
    library/math/pollard.cpp\"\n// In codeforces, delete __int128 in the second line.\n\
    // about O(N^1/4logN)\nll pollard_single(ll n) {\n    auto f = [&](ll x) { return\
    \ (__int128_t(x) * x + 1) % n; };\n    // auto f = [&](ll x) { return (x * x +\
    \ 1) % n; };\n    if (is_prime(n)) return n;\n    if (n % 2 == 0) return 2;\n\
    \    ll st = 0;\n    while (true) {\n        st = my_rand() % n;\n        ll x\
    \ = st, y = f(x);\n        while (true) {\n            ll p = gcd((y - x + n),\
    \ n);\n            if (p == 0 || p == n) break;\n            if (p != 1) return\
    \ p;\n            x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n\n\
    vl pollard_rec(ll n) {\n    if (n == 1) return {};\n    ll x = pollard_single(n);\n\
    \    if (x == n) return {x};\n    vl a = pollard_rec(x);\n    vl b = pollard_rec(n\
    \ / x);\n    a.insert(a.end(), b.begin(), b.end());\n    return a;\n}\n\nmap<ll,\
    \ int> pollard(ll n) {\n    map<ll, int> res;\n    for (ll a : pollard_rec(n))\
    \ {\n        res[a]++;\n    }\n    return res;\n}\n"
  code: "/**\n * @brief factorization(pollard)\n * @docs pollard.md\n */\n#include\
    \ \"library/math/is_prime.cpp\"\n// In codeforces, delete __int128 in the second\
    \ line.\n// about O(N^1/4logN)\nll pollard_single(ll n) {\n    auto f = [&](ll\
    \ x) { return (__int128_t(x) * x + 1) % n; };\n    // auto f = [&](ll x) { return\
    \ (x * x + 1) % n; };\n    if (is_prime(n)) return n;\n    if (n % 2 == 0) return\
    \ 2;\n    ll st = 0;\n    while (true) {\n        st = my_rand() % n;\n      \
    \  ll x = st, y = f(x);\n        while (true) {\n            ll p = gcd((y - x\
    \ + n), n);\n            if (p == 0 || p == n) break;\n            if (p != 1)\
    \ return p;\n            x = f(x);\n            y = f(f(y));\n        }\n    }\n\
    }\n\nvl pollard_rec(ll n) {\n    if (n == 1) return {};\n    ll x = pollard_single(n);\n\
    \    if (x == n) return {x};\n    vl a = pollard_rec(x);\n    vl b = pollard_rec(n\
    \ / x);\n    a.insert(a.end(), b.begin(), b.end());\n    return a;\n}\n\nmap<ll,\
    \ int> pollard(ll n) {\n    map<ll, int> res;\n    for (ll a : pollard_rec(n))\
    \ {\n        res[a]++;\n    }\n    return res;\n}"
  dependsOn:
  - library/math/is_prime.cpp
  isVerificationFile: false
  path: library/math/pollard.cpp
  requiredBy: []
  timestamp: '2020-11-15 12:33:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj-NTL_1_A.test.cpp
documentation_of: library/math/pollard.cpp
layout: document
redirect_from:
- /library/library/math/pollard.cpp
- /library/library/math/pollard.cpp.html
title: factorization(pollard)
---
