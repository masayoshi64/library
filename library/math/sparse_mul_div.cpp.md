---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/sparse_mul_div.cpp\"\nvoid mul(FPS& f, int\
    \ n, int expand = true) {\n    if (expand) f.resize(f.size() + n);\n    rrep(i,\
    \ SZ(f)) {\n        if (i - n >= 0) f[i] -= f[i - n];\n    }\n}\n\nvoid div(FPS&\
    \ f, int n) {\n    rep(i, SZ(f)) {\n        if (i + n < SZ(f)) f[i + n] += f[i];\n\
    \    }\n}\n"
  code: "void mul(FPS& f, int n, int expand = true) {\n    if (expand) f.resize(f.size()\
    \ + n);\n    rrep(i, SZ(f)) {\n        if (i - n >= 0) f[i] -= f[i - n];\n   \
    \ }\n}\n\nvoid div(FPS& f, int n) {\n    rep(i, SZ(f)) {\n        if (i + n <\
    \ SZ(f)) f[i + n] += f[i];\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/math/sparse_mul_div.cpp
  requiredBy: []
  timestamp: '2020-12-23 20:37:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/sparse_mul_div.cpp
layout: document
redirect_from:
- /library/library/math/sparse_mul_div.cpp
- /library/library/math/sparse_mul_div.cpp.html
title: library/math/sparse_mul_div.cpp
---
