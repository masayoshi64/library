---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_E.test.cpp
    title: verify/aoj-NTL_1_E.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/extgcd.md
    document_title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5"
    links: []
  bundledCode: "#line 1 \"library/math/extgcd.cpp\"\n/**\n * @brief \u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n * @docs docs/extgcd.md\n\
    \ */\n\n// give the solution which minimize |x|+|y|\ntemplate <typename T>\nT\
    \ extgcd(T a, T b, T &x, T &y) {\n    T d = a;\n    if (b != 0) {\n        d =\
    \ extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x\
    \ = 1;\n        y = 0;\n    }\n    return d;  // gcd(a, b)\n}\n"
  code: "/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\n * @docs docs/extgcd.md\n */\n\n// give the solution which minimize\
    \ |x|+|y|\ntemplate <typename T>\nT extgcd(T a, T b, T &x, T &y) {\n    T d =\
    \ a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a\
    \ / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\
    \  // gcd(a, b)\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/math/extgcd.cpp
  requiredBy: []
  timestamp: '2020-11-20 12:57:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-NTL_1_E.test.cpp
documentation_of: library/math/extgcd.cpp
layout: document
redirect_from:
- /library/library/math/extgcd.cpp
- /library/library/math/extgcd.cpp.html
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
