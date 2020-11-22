---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/snippets/dfs_grid.cpp\"\nvector<int> dx = {0, 1,\
    \ 0, -1};\nvector<int> dy = {1, 0, -1, 0};\nmat<char> grid;\nmat<int> dist;\n\
    rep(x, h) {\n    rep(y, w) {\n        rep(d, 4) {\n            int nx = x + dx[d];\n\
    \            int ny = y + dy[d];\n            if (0 <= nx && nx < h && 0 <= ny\
    \ && ny < w && grid[nx][ny] == '.') {\n                dist[nx][ny] = dist[x][y];\n\
    \            }\n        }\n    }\n}\n"
  code: "vector<int> dx = {0, 1, 0, -1};\nvector<int> dy = {1, 0, -1, 0};\nmat<char>\
    \ grid;\nmat<int> dist;\nrep(x, h) {\n    rep(y, w) {\n        rep(d, 4) {\n \
    \           int nx = x + dx[d];\n            int ny = y + dy[d];\n           \
    \ if (0 <= nx && nx < h && 0 <= ny && ny < w && grid[nx][ny] == '.') {\n     \
    \           dist[nx][ny] = dist[x][y];\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/snippets/dfs_grid.cpp
  requiredBy: []
  timestamp: '2020-11-22 22:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/snippets/dfs_grid.cpp
layout: document
redirect_from:
- /library/library/snippets/dfs_grid.cpp
- /library/library/snippets/dfs_grid.cpp.html
title: library/snippets/dfs_grid.cpp
---
