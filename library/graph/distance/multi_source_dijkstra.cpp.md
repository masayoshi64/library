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
  bundledCode: "#line 1 \"library/graph/distance/multi_source_dijkstra.cpp\"\n// dijkstra\
    \ start from v in s\ntemplate <typename T>\nvector<T> multi_source_dijkstra(Graph<T>\
    \ &g, vector<int> &s) {\n    const auto Inf = numeric_limits<T>::max();\n    vector<T>\
    \ dist(g.size(), Inf);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi,\
    \ vector<Pi>, greater<Pi> > que;\n    for (int ss : s) dist[ss] = 0, que.emplace(dist[ss],\
    \ ss);\n    while (!que.empty()) {\n        T cost;\n        int idx;\n      \
    \  tie(cost, idx) = que.top();\n        que.pop();\n        if (dist[idx] < cost)\
    \ continue;\n        for (auto &e : g[idx]) {\n            auto next_cost = cost\
    \ + e.cost;\n            if (dist[e.to] <= next_cost) continue;\n            dist[e.to]\
    \ = next_cost;\n            que.emplace(dist[e.to], e.to);\n        }\n    }\n\
    \    return dist;\n}\n"
  code: "// dijkstra start from v in s\ntemplate <typename T>\nvector<T> multi_source_dijkstra(Graph<T>\
    \ &g, vector<int> &s) {\n    const auto Inf = numeric_limits<T>::max();\n    vector<T>\
    \ dist(g.size(), Inf);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi,\
    \ vector<Pi>, greater<Pi> > que;\n    for (int ss : s) dist[ss] = 0, que.emplace(dist[ss],\
    \ ss);\n    while (!que.empty()) {\n        T cost;\n        int idx;\n      \
    \  tie(cost, idx) = que.top();\n        que.pop();\n        if (dist[idx] < cost)\
    \ continue;\n        for (auto &e : g[idx]) {\n            auto next_cost = cost\
    \ + e.cost;\n            if (dist[e.to] <= next_cost) continue;\n            dist[e.to]\
    \ = next_cost;\n            que.emplace(dist[e.to], e.to);\n        }\n    }\n\
    \    return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/multi_source_dijkstra.cpp
  requiredBy: []
  timestamp: '2020-11-22 22:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/multi_source_dijkstra.cpp
layout: document
redirect_from:
- /library/library/graph/distance/multi_source_dijkstra.cpp
- /library/library/graph/distance/multi_source_dijkstra.cpp.html
title: library/graph/distance/multi_source_dijkstra.cpp
---
