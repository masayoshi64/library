---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/distance/warshall_floyd.cpp\"\ntemplate <typename\
    \ T>\nvoid warshall_floyd(vector<vector<T>> &g) {\n    const auto TINF = numeric_limits<T>::max();\n\
    \    for (int k = 0; k < g.size(); k++) {\n        for (int i = 0; i < g.size();\
    \ i++) {\n            for (int j = 0; j < g.size(); j++) {\n                if\
    \ (g[i][k] == TINF || g[k][j] == TINF) continue;\n                g[i][j] = min(g[i][j],\
    \ g[i][k] + g[k][j]);\n            }\n        }\n    }\n}\n"
  code: "template <typename T>\nvoid warshall_floyd(vector<vector<T>> &g) {\n    const\
    \ auto TINF = numeric_limits<T>::max();\n    for (int k = 0; k < g.size(); k++)\
    \ {\n        for (int i = 0; i < g.size(); i++) {\n            for (int j = 0;\
    \ j < g.size(); j++) {\n                if (g[i][k] == TINF || g[k][j] == TINF)\
    \ continue;\n                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);\n    \
    \        }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2020-11-20 20:19:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/warshall_floyd.cpp
layout: document
redirect_from:
- /library/library/graph/distance/warshall_floyd.cpp
- /library/library/graph/distance/warshall_floyd.cpp.html
title: library/graph/distance/warshall_floyd.cpp
---
