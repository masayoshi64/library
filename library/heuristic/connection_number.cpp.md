---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9023\u7D50\u6570: \u5468\u56F29\u30DE\u30B9\u306E\u3046\u3061\
      \u5024\u304Cc\u3067\u3042\u308B\u3088\u3046\u306A\u9023\u7D50\u6210\u5206\u306E\
      \u6570\uFF0E1\u306A\u3089\u9023\u7D50"
    links: []
  bundledCode: "#line 1 \"library/heuristic/connection_number.cpp\"\n/**\n * @brief\
    \ \u9023\u7D50\u6570: \u5468\u56F29\u30DE\u30B9\u306E\u3046\u3061\u5024\u304C\
    c\u3067\u3042\u308B\u3088\u3046\u306A\u9023\u7D50\u6210\u5206\u306E\u6570\uFF0E\
    1\u306A\u3089\u9023\u7D50\n */\n\nll connection_number(mat<ll>& grid, ll x, ll\
    \ y, ll c){\n    ll h = grid.size();\n    ll w = grid[0].size();\n    vl val;\n\
    \    rep(nx, x - 1, x + 2){\n        rep(ny, y - 1, y + 2){\n            if(nx\
    \ < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] != c){\n               \
    \ val.pb(0);\n            }else{\n                val.pb(1);\n            }\n\
    \        }\n    }\n    ll res = val[1] + val[3] + val[5] + val[7] \n         \
    \   - val[0] * val[1] * val[3]\n            - val[1] * val[2] * val[5]\n     \
    \       - val[3] * val[6] * val[7]\n            - val[5] * val[7] * val[8];\n\
    \    return res;\n}\n"
  code: "/**\n * @brief \u9023\u7D50\u6570: \u5468\u56F29\u30DE\u30B9\u306E\u3046\u3061\
    \u5024\u304Cc\u3067\u3042\u308B\u3088\u3046\u306A\u9023\u7D50\u6210\u5206\u306E\
    \u6570\uFF0E1\u306A\u3089\u9023\u7D50\n */\n\nll connection_number(mat<ll>& grid,\
    \ ll x, ll y, ll c){\n    ll h = grid.size();\n    ll w = grid[0].size();\n  \
    \  vl val;\n    rep(nx, x - 1, x + 2){\n        rep(ny, y - 1, y + 2){\n     \
    \       if(nx < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] != c){\n   \
    \             val.pb(0);\n            }else{\n                val.pb(1);\n   \
    \         }\n        }\n    }\n    ll res = val[1] + val[3] + val[5] + val[7]\
    \ \n            - val[0] * val[1] * val[3]\n            - val[1] * val[2] * val[5]\n\
    \            - val[3] * val[6] * val[7]\n            - val[5] * val[7] * val[8];\n\
    \    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/heuristic/connection_number.cpp
  requiredBy: []
  timestamp: '2023-10-01 20:19:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/heuristic/connection_number.cpp
layout: document
redirect_from:
- /library/library/heuristic/connection_number.cpp
- /library/library/heuristic/connection_number.cpp.html
title: "\u9023\u7D50\u6570: \u5468\u56F29\u30DE\u30B9\u306E\u3046\u3061\u5024\u304C\
  c\u3067\u3042\u308B\u3088\u3046\u306A\u9023\u7D50\u6210\u5206\u306E\u6570\uFF0E\
  1\u306A\u3089\u9023\u7D50"
---
