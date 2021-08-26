---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DPL_5_G.test.cpp
    title: verify/aoj-DPL_5_G.test.cpp
  - icon: ':x:'
    path: verify/yuki-FPS.power.test.cpp
    title: verify/yuki-FPS.power.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/Combination.md
    document_title: Combination(P, C, H, Stirling number, Bell number)
    links: []
  bundledCode: "#line 1 \"library/math/combination.cpp\"\n/**\n * @brief Combination(P,\
    \ C, H, Stirling number, Bell number)\n * @docs docs/Combination.md\n */\ntemplate\
    \ <typename T>\nstruct Combination {\n    vector<T> _fact, _rfact, _inv;\n\n \
    \   Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {\n    \
    \    _fact[0] = _rfact[sz] = _inv[0] = 1;\n        for (int i = 1; i <= sz; i++)\
    \ _fact[i] = _fact[i - 1] * i;\n        _rfact[sz] /= _fact[sz];\n        for\
    \ (int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);\n       \
    \ for (int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];\n    }\n\n\
    \    inline T fact(int k) const { return _fact[k]; }\n\n    inline T rfact(int\
    \ k) const { return _rfact[k]; }\n\n    inline T inv(int k) const { return _inv[k];\
    \ }\n\n    T P(int n, int r) const {\n        if (r < 0 || n < r) return 0;\n\
    \        return fact(n) * rfact(n - r);\n    }\n\n    T C(int p, int q) const\
    \ {\n        if (q < 0 || p < q) return 0;\n        return fact(p) * rfact(q)\
    \ * rfact(p - q);\n    }\n\n    T H(int n, int r) const {\n        if (n < 0 ||\
    \ r < 0) return (0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n\n\
    \    // O(klog(n))\n    // n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u7389\u3092\
    k\u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u5272\u3059\u308B\u5834\u5408\
    \u306E\u6570\uFF08\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u306F1\u4EE5\
    \u4E0A\uFF09\n    T Stirling(int n, int k) {\n        T res = 0;\n        rep(i,\
    \ k + 1) {\n            res += (T)((k - i) % 2 ? -1 : 1) * C(k, i) * mypow<T>(i,\
    \ n);\n        }\n        return res / _fact[k];\n    }\n\n    // O(klog(n))\n\
    \    // n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u7389\u3092k\u500B\u306E\u30B0\
    \u30EB\u30FC\u30D7\u306B\u5206\u5272\u3059\u308B\u5834\u5408\u306E\u6570\uFF08\
    \u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u306F0\u4EE5\u4E0A\uFF09\n  \
    \  // \u3082\u3057\u304F\u306F\u3001k\u500B\u4EE5\u4E0B\u306E\u7389\u306E\u4E00\
    \u500B\u4EE5\u4E0A\u5165\u3063\u305F\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u3051\
    \u308B\u3068\u8003\u3048\u3066\u3082\u3044\u3044\n    T Bell(int n, int k) {\n\
    \        if (n < k) k = n;\n        vector<T> sm(k + 1);\n        sm[0] = 1;\n\
    \        rep(j, 1, k + 1) { sm[j] = sm[j - 1] + (T)(j % 2 ? -1 : 1) / _fact[j];\
    \ }\n        T res = 0;\n        rep(i, k + 1) { res += mypow<T>(i, n) / _fact[i]\
    \ * sm[k - i]; }\n        return res;\n    }\n};\n"
  code: "/**\n * @brief Combination(P, C, H, Stirling number, Bell number)\n * @docs\
    \ docs/Combination.md\n */\ntemplate <typename T>\nstruct Combination {\n    vector<T>\
    \ _fact, _rfact, _inv;\n\n    Combination(int sz) : _fact(sz + 1), _rfact(sz +\
    \ 1), _inv(sz + 1) {\n        _fact[0] = _rfact[sz] = _inv[0] = 1;\n        for\
    \ (int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n        _rfact[sz] /=\
    \ _fact[sz];\n        for (int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i +\
    \ 1] * (i + 1);\n        for (int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i\
    \ - 1];\n    }\n\n    inline T fact(int k) const { return _fact[k]; }\n\n    inline\
    \ T rfact(int k) const { return _rfact[k]; }\n\n    inline T inv(int k) const\
    \ { return _inv[k]; }\n\n    T P(int n, int r) const {\n        if (r < 0 || n\
    \ < r) return 0;\n        return fact(n) * rfact(n - r);\n    }\n\n    T C(int\
    \ p, int q) const {\n        if (q < 0 || p < q) return 0;\n        return fact(p)\
    \ * rfact(q) * rfact(p - q);\n    }\n\n    T H(int n, int r) const {\n       \
    \ if (n < 0 || r < 0) return (0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n\
    \    }\n\n    // O(klog(n))\n    // n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\
    \u7389\u3092k\u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u5272\u3059\u308B\
    \u5834\u5408\u306E\u6570\uFF08\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\
    \u306F1\u4EE5\u4E0A\uFF09\n    T Stirling(int n, int k) {\n        T res = 0;\n\
    \        rep(i, k + 1) {\n            res += (T)((k - i) % 2 ? -1 : 1) * C(k,\
    \ i) * mypow<T>(i, n);\n        }\n        return res / _fact[k];\n    }\n\n \
    \   // O(klog(n))\n    // n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u7389\u3092\
    k\u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u5272\u3059\u308B\u5834\u5408\
    \u306E\u6570\uFF08\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u306F0\u4EE5\
    \u4E0A\uFF09\n    // \u3082\u3057\u304F\u306F\u3001k\u500B\u4EE5\u4E0B\u306E\u7389\
    \u306E\u4E00\u500B\u4EE5\u4E0A\u5165\u3063\u305F\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5206\u3051\u308B\u3068\u8003\u3048\u3066\u3082\u3044\u3044\n    T Bell(int n,\
    \ int k) {\n        if (n < k) k = n;\n        vector<T> sm(k + 1);\n        sm[0]\
    \ = 1;\n        rep(j, 1, k + 1) { sm[j] = sm[j - 1] + (T)(j % 2 ? -1 : 1) / _fact[j];\
    \ }\n        T res = 0;\n        rep(i, k + 1) { res += mypow<T>(i, n) / _fact[i]\
    \ * sm[k - i]; }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/combination.cpp
  requiredBy: []
  timestamp: '2020-11-14 13:31:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj-DPL_5_G.test.cpp
  - verify/yuki-FPS.power.test.cpp
documentation_of: library/math/combination.cpp
layout: document
redirect_from:
- /library/library/math/combination.cpp
- /library/library/math/combination.cpp.html
title: Combination(P, C, H, Stirling number, Bell number)
---
## Stirling
n個の区別できる玉をk個のグループに分割する場合の数（グループのサイズは1以上）
O(klog(n))
## Bell
n個の区別できる玉をk個のグループに分割する場合の数（グループのサイズは0以上）
もしくは、玉を一個以上入ったグループk個以下に分けると考えてもいい
O(klog(n))