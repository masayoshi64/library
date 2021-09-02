---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: grid bfs
    links: []
  bundledCode: "#line 2 \"library/graph/distance/grid_bfs.cpp\"\n/**\n * @brief grid\
    \ bfs\n */\ntemplate <typename T>\nvector<vector<int>> grid_bfs(vector<T> &s,\
    \ T start, const T &wall = \"#\", int dir_num = 4) {\n    const int vx[] = {0,\
    \ 1, 0, -1, 1, 1, -1, -1}, vy[] = {1, 0, -1, 0, 1, -1, 1, -1};\n    vector<vector<int>>\
    \ min_cost(s.size(), vector<int>(s[0].size(), -1));\n    queue<pair<int, int>>\
    \ que;\n    for (int i = 0; i < s.size(); i++) {\n        for (int j = 0; j <\
    \ s[i].size(); j++) {\n            if (s[i][j] == start) {\n                que.emplace(i,\
    \ j);\n                min_cost[i][j] = 0;\n            }\n        }\n    }\n\
    \    while (!que.empty()) {\n        auto p = que.front();\n        que.pop();\n\
    \        for (int i = 0; i < dir_num; i++) {\n            int ny = p.first + vy[i],\
    \ nx = p.second + vx[i];\n            if (nx < 0 || ny < 0 || nx >= s[0].size()\
    \ || ny >= s.size()) continue;\n            if (min_cost[ny][nx] != -1) continue;\n\
    \            if (wall.find(s[ny][nx]) != string::npos) continue;\n           \
    \ min_cost[ny][nx] = min_cost[p.first][p.second] + 1;\n            que.emplace(ny,\
    \ nx);\n        }\n    }\n    return min_cost;\n}\n"
  code: "#pragma once\n/**\n * @brief grid bfs\n */\ntemplate <typename T>\nvector<vector<int>>\
    \ grid_bfs(vector<T> &s, T start, const T &wall = \"#\", int dir_num = 4) {\n\
    \    const int vx[] = {0, 1, 0, -1, 1, 1, -1, -1}, vy[] = {1, 0, -1, 0, 1, -1,\
    \ 1, -1};\n    vector<vector<int>> min_cost(s.size(), vector<int>(s[0].size(),\
    \ -1));\n    queue<pair<int, int>> que;\n    for (int i = 0; i < s.size(); i++)\
    \ {\n        for (int j = 0; j < s[i].size(); j++) {\n            if (s[i][j]\
    \ == start) {\n                que.emplace(i, j);\n                min_cost[i][j]\
    \ = 0;\n            }\n        }\n    }\n    while (!que.empty()) {\n        auto\
    \ p = que.front();\n        que.pop();\n        for (int i = 0; i < dir_num; i++)\
    \ {\n            int ny = p.first + vy[i], nx = p.second + vx[i];\n          \
    \  if (nx < 0 || ny < 0 || nx >= s[0].size() || ny >= s.size()) continue;\n  \
    \          if (min_cost[ny][nx] != -1) continue;\n            if (wall.find(s[ny][nx])\
    \ != string::npos) continue;\n            min_cost[ny][nx] = min_cost[p.first][p.second]\
    \ + 1;\n            que.emplace(ny, nx);\n        }\n    }\n    return min_cost;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/grid_bfs.cpp
  requiredBy: []
  timestamp: '2021-09-01 22:02:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/grid_bfs.cpp
layout: document
redirect_from:
- /library/library/graph/distance/grid_bfs.cpp
- /library/library/graph/distance/grid_bfs.cpp.html
title: grid bfs
---
