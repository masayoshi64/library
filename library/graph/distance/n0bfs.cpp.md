---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/distance/n0bfs.cpp\"\ntemplate <typename T>\n\
    vector<T> n0bfs(const Graph<T> &g, int s) {\n    T max_cost = 0, max_dist + =\
    \ 0;\n    for (auto &es : g.g) {\n        for (auto &e : es) max_cost = max(max_cost,\
    \ e.cost);\n    }\n    ++max_cost;\n    const auto INF = numeric_limits<T>::max();\n\
    \    vector<T> dist(g.size(), INF);\n    vector<queue<int> > ques(max_cost + 1);\n\
    \    dist[s] = 0;\n    ques[0].emplace(s);\n    for (T cost = 0; cost <= max_dist;\
    \ cost++) {\n        auto &que = ques[cost % max_cost];\n        while (!que.empty())\
    \ {\n            int idx = que.front();\n            que.pop();\n            if\
    \ (dist[idx] < cost) continue;\n            for (auto &e : g.g[idx]) {\n     \
    \           auto next_cost = cost + e.cost;\n                if (dist[e.to] <=\
    \ next_cost) continue;\n                dist[e.to] = next_cost;\n            \
    \    max_dist = max(max_dist, dist[e.to]);\n                ques[dist[e.to] %\
    \ max_cost].emplace(e.to);\n            }\n        }\n    }\n    return dist;\n\
    }\n"
  code: "template <typename T>\nvector<T> n0bfs(const Graph<T> &g, int s) {\n    T\
    \ max_cost = 0, max_dist + = 0;\n    for (auto &es : g.g) {\n        for (auto\
    \ &e : es) max_cost = max(max_cost, e.cost);\n    }\n    ++max_cost;\n    const\
    \ auto INF = numeric_limits<T>::max();\n    vector<T> dist(g.size(), INF);\n \
    \   vector<queue<int> > ques(max_cost + 1);\n    dist[s] = 0;\n    ques[0].emplace(s);\n\
    \    for (T cost = 0; cost <= max_dist; cost++) {\n        auto &que = ques[cost\
    \ % max_cost];\n        while (!que.empty()) {\n            int idx = que.front();\n\
    \            que.pop();\n            if (dist[idx] < cost) continue;\n       \
    \     for (auto &e : g.g[idx]) {\n                auto next_cost = cost + e.cost;\n\
    \                if (dist[e.to] <= next_cost) continue;\n                dist[e.to]\
    \ = next_cost;\n                max_dist = max(max_dist, dist[e.to]);\n      \
    \          ques[dist[e.to] % max_cost].emplace(e.to);\n            }\n       \
    \ }\n    }\n    return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/n0bfs.cpp
  requiredBy: []
  timestamp: '2020-11-22 22:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/n0bfs.cpp
layout: document
redirect_from:
- /library/library/graph/distance/n0bfs.cpp
- /library/library/graph/distance/n0bfs.cpp.html
title: library/graph/distance/n0bfs.cpp
---
