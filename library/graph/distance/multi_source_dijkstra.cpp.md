---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/multi_source_dijkstra.md
    document_title: multi-source dijkstra
    links: []
  bundledCode: "#line 2 \"library/graph/distance/multi_source_dijkstra.cpp\"\n/**\n\
    \ * @brief multi-source dijkstra\n * @docs docs/multi_source_dijkstra.md\n */\n\
    template <typename T>\nvector<T> multi_source_dijkstra(Graph<T> &g, vector<int>\
    \ &s) {\n    const auto Inf = numeric_limits<T>::max();\n    vector<T> dist(g.size(),\
    \ Inf);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi, vector<Pi>, greater<Pi>>\
    \ que;\n    for (int ss : s)\n        dist[ss] = 0, que.emplace(dist[ss], ss);\n\
    \    while (!que.empty()) {\n        T cost;\n        int idx;\n        tie(cost,\
    \ idx) = que.top();\n        que.pop();\n        if (dist[idx] < cost) continue;\n\
    \        for (auto &e : g[idx]) {\n            auto next_cost = cost + e.cost;\n\
    \            if (dist[e.to] <= next_cost) continue;\n            dist[e.to] =\
    \ next_cost;\n            que.emplace(dist[e.to], e.to);\n        }\n    }\n \
    \   return dist;\n}\n"
  code: "#pragma once\n/**\n * @brief multi-source dijkstra\n * @docs docs/multi_source_dijkstra.md\n\
    \ */\ntemplate <typename T>\nvector<T> multi_source_dijkstra(Graph<T> &g, vector<int>\
    \ &s) {\n    const auto Inf = numeric_limits<T>::max();\n    vector<T> dist(g.size(),\
    \ Inf);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi, vector<Pi>, greater<Pi>>\
    \ que;\n    for (int ss : s)\n        dist[ss] = 0, que.emplace(dist[ss], ss);\n\
    \    while (!que.empty()) {\n        T cost;\n        int idx;\n        tie(cost,\
    \ idx) = que.top();\n        que.pop();\n        if (dist[idx] < cost) continue;\n\
    \        for (auto &e : g[idx]) {\n            auto next_cost = cost + e.cost;\n\
    \            if (dist[e.to] <= next_cost) continue;\n            dist[e.to] =\
    \ next_cost;\n            que.emplace(dist[e.to], e.to);\n        }\n    }\n \
    \   return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/multi_source_dijkstra.cpp
  requiredBy: []
  timestamp: '2021-09-01 22:02:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/multi_source_dijkstra.cpp
layout: document
redirect_from:
- /library/library/graph/distance/multi_source_dijkstra.cpp
- /library/library/graph/distance/multi_source_dijkstra.cpp.html
title: multi-source dijkstra
---
## メモ
- あえてライブラリにするまでもない気もする

## 使い方
```c++
vector<int> s;
vector<int> dist = multi_source_dijkstra(g, s);
```
始点が複数ある場合への拡張