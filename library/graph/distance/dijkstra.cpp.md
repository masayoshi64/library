---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/distance/dijkstra.cpp\"\ntemplate <typename\
    \ T>\nvector<T> dijkstra(Graph<T> &g, int s) {\n    const auto TINF = numeric_limits<T>::max();\n\
    \    vector<T> dist(g.size(), TINF);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi,\
    \ vector<Pi>, greater<Pi> > que;\n    dist[s] = 0;\n    que.emplace(dist[s], s);\n\
    \    while (!que.empty()) {\n        T cost;\n        int idx;\n        tie(cost,\
    \ idx) = que.top();\n        que.pop();\n        if (dist[idx] < cost) continue;\n\
    \        for (auto &e : g[idx]) {\n            auto next_cost = cost + e.cost;\n\
    \            if (dist[e.to] <= next_cost) continue;\n            dist[e.to] =\
    \ next_cost;\n            que.emplace(dist[e.to], e.to);\n        }\n    }\n \
    \   return dist;\n}\n"
  code: "template <typename T>\nvector<T> dijkstra(Graph<T> &g, int s) {\n    const\
    \ auto TINF = numeric_limits<T>::max();\n    vector<T> dist(g.size(), TINF);\n\
    \n    using Pi = pair<T, int>;\n    priority_queue<Pi, vector<Pi>, greater<Pi>\
    \ > que;\n    dist[s] = 0;\n    que.emplace(dist[s], s);\n    while (!que.empty())\
    \ {\n        T cost;\n        int idx;\n        tie(cost, idx) = que.top();\n\
    \        que.pop();\n        if (dist[idx] < cost) continue;\n        for (auto\
    \ &e : g[idx]) {\n            auto next_cost = cost + e.cost;\n            if\
    \ (dist[e.to] <= next_cost) continue;\n            dist[e.to] = next_cost;\n \
    \           que.emplace(dist[e.to], e.to);\n        }\n    }\n    return dist;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-11-22 22:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/dijkstra.cpp
layout: document
redirect_from:
- /library/library/graph/distance/dijkstra.cpp
- /library/library/graph/distance/dijkstra.cpp.html
title: library/graph/distance/dijkstra.cpp
---
