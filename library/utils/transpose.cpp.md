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
  bundledCode: "#line 1 \"library/utils/transpose.cpp\"\ntemplate <typename T>\nvector<vector<T>>\
    \ transpose(vector<vector<T>>& vv) {\n    int n = vv.size();\n    int m = vv[0].size();\n\
    \    vector<vector<T>> res(m, vector<T>(m));\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j = 0; j < m; j++) {\n            res[j][i] = vv[i][j];\n\
    \        }\n    }\n    return res;\n}\n"
  code: "template <typename T>\nvector<vector<T>> transpose(vector<vector<T>>& vv)\
    \ {\n    int n = vv.size();\n    int m = vv[0].size();\n    vector<vector<T>>\
    \ res(m, vector<T>(m));\n    for (int i = 0; i < n; i++) {\n        for (int j\
    \ = 0; j < m; j++) {\n            res[j][i] = vv[i][j];\n        }\n    }\n  \
    \  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/utils/transpose.cpp
  requiredBy: []
  timestamp: '2021-02-18 11:48:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/utils/transpose.cpp
layout: document
redirect_from:
- /library/library/utils/transpose.cpp
- /library/library/utils/transpose.cpp.html
title: library/utils/transpose.cpp
---
