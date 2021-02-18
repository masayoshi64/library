---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/convert_base.cpp\"\ntemplate <typename T>\n\
    vector<T> convert_base(T x, T b) {\n    vector<T> ret;\n    T t = 1, k = abs(b);\n\
    \    while (x) {\n        ret.emplace_back((x * t) % k);\n        if (ret.back()\
    \ < 0) ret.back() += k;\n        x -= ret.back() * t;\n        x /= k;\n     \
    \   t *= b / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n}\n"
  code: "template <typename T>\nvector<T> convert_base(T x, T b) {\n    vector<T>\
    \ ret;\n    T t = 1, k = abs(b);\n    while (x) {\n        ret.emplace_back((x\
    \ * t) % k);\n        if (ret.back() < 0) ret.back() += k;\n        x -= ret.back()\
    \ * t;\n        x /= k;\n        t *= b / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n\
    \    reverse(begin(ret), end(ret));\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/math/convert_base.cpp
  requiredBy: []
  timestamp: '2020-12-18 23:34:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/convert_base.cpp
layout: document
redirect_from:
- /library/library/math/convert_base.cpp
- /library/library/math/convert_base.cpp.html
title: library/math/convert_base.cpp
---
