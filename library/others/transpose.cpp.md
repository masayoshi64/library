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
  bundledCode: "#line 1 \"library/others/transpose.cpp\"\ntemplate <typename T>\n\
    vector<vector<T>> transpose(vector<vector<T>>& vv) {\n    int n = vv.size();\n\
    \    int m = vv[0].size();\n    vector<vector<T>> res(m, vector<T>(m));\n    for\
    \ (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n         \
    \   res[j][i] = vv[i][j];\n        }\n    }\n    return res;\n}\n"
  code: "template <typename T>\nvector<vector<T>> transpose(vector<vector<T>>& vv)\
    \ {\n    int n = vv.size();\n    int m = vv[0].size();\n    vector<vector<T>>\
    \ res(m, vector<T>(m));\n    for (int i = 0; i < n; i++) {\n        for (int j\
    \ = 0; j < m; j++) {\n            res[j][i] = vv[i][j];\n        }\n    }\n  \
    \  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/others/transpose.cpp
  requiredBy: []
  timestamp: '2023-09-23 22:24:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/others/transpose.cpp
layout: document
redirect_from:
- /library/library/others/transpose.cpp
- /library/library/others/transpose.cpp.html
title: library/others/transpose.cpp
---
