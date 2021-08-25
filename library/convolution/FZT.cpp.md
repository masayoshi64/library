---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/FZT.test.cpp
    title: verify/FZT.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/FZT.md
    document_title: Fast Zeta Transform
    links: []
  bundledCode: "#line 1 \"library/convolution/FZT.cpp\"\n/**\n * @brief Fast Zeta\
    \ Transform\n * @docs docs/FZT.md\n * @details \u5168\u3066\u306E\u90E8\u5206\u96C6\
    \u5408$T_i$\u306B\u3064\u3044\u3066$\\sum_{S \\subset T_i}f(S)$\u3092\u8A08\u7B97\
    \n */\ntemplate <typename T>\nvector<T> FZT(vector<T> f)\n{\n    int N = 0;\n\
    \    int tmp = f.size();\n    while (tmp > 1)\n        N++, tmp /= 2;\n    for\
    \ (int j = 0; j < N; j++)\n    {\n        for (int i = 0; i < (1 << N); i++)\n\
    \        {\n            if (i & (1 << j))\n            {\n                f[i]\
    \ += f[i & ~(1 << j)];\n            }\n        }\n    }\n    return f;\n}\n"
  code: "/**\n * @brief Fast Zeta Transform\n * @docs docs/FZT.md\n * @details \u5168\
    \u3066\u306E\u90E8\u5206\u96C6\u5408$T_i$\u306B\u3064\u3044\u3066$\\sum_{S \\\
    subset T_i}f(S)$\u3092\u8A08\u7B97\n */\ntemplate <typename T>\nvector<T> FZT(vector<T>\
    \ f)\n{\n    int N = 0;\n    int tmp = f.size();\n    while (tmp > 1)\n      \
    \  N++, tmp /= 2;\n    for (int j = 0; j < N; j++)\n    {\n        for (int i\
    \ = 0; i < (1 << N); i++)\n        {\n            if (i & (1 << j))\n        \
    \    {\n                f[i] += f[i & ~(1 << j)];\n            }\n        }\n\
    \    }\n    return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/FZT.cpp
  requiredBy: []
  timestamp: '2021-08-25 10:21:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/FZT.test.cpp
documentation_of: library/convolution/FZT.cpp
layout: document
redirect_from:
- /library/library/convolution/FZT.cpp
- /library/library/convolution/FZT.cpp.html
title: Fast Zeta Transform
---
## メモ
- 包除原理を高速に計算するために$f[S] = (-1)^{|S|}cnt[S]$とする場合が多い
## FZT
```c++
g = FZT(f);
```
$$
g[T] = \sum_{S \subset T}f[S]
$$
が計算できる。
$f[S] = (-1)^{|S|}cnt[S]$なら
$$
g[S] = \sum_{T \subset S}(-1)^{|S|}cnt[S]
$$
だから包除原理そのもの
