---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_7_A.test.cpp
    title: verify/aoj-GRL_7_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/bipartite-matching.md
    document_title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
    links: []
  bundledCode: "#line 1 \"library/graph/flow/BipartiteMatching.cpp\"\n/**\n * @brief\
    \ \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \n * @docs docs/bipartite-matching.md\n */\nstruct BipartiteMatching {\n    vector<vector<int>\
    \ > graph;\n    vector<int> match, alive, used;\n    int timestamp;\n    int a_size;\n\
    \n    explicit BipartiteMatching(int n)\n        : a_size(-1),\n          graph(n),\n\
    \          alive(n, 1),\n          used(n, 0),\n          match(n, -1),\n    \
    \      timestamp(0) {}\n\n    explicit BipartiteMatching(int n, int m)\n     \
    \   : a_size(n),\n          graph(n + m),\n          alive(n + m, 1),\n      \
    \    used(n + m, 0),\n          match(n + m, -1),\n          timestamp(0) {}\n\
    \n    void add_edge(int u, int v) {\n        if (a_size < 0) {\n            graph[u].push_back(v);\n\
    \            graph[v].push_back(u);\n        } else {\n            graph[u].push_back(v\
    \ + a_size);\n            graph[v + a_size].push_back(u);\n        }\n    }\n\n\
    \    bool augment(int idx) {\n        used[idx] = timestamp;\n        for (auto\
    \ &to : graph[idx]) {\n            int to_match = match[to];\n            if (alive[to]\
    \ == 0) continue;\n            if (to_match == -1 ||\n                (used[to_match]\
    \ != timestamp && augment(to_match))) {\n                match[idx] = to;\n  \
    \              match[to] = idx;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n\n    int matching() {\n        int\
    \ ret = 0;\n        for (int i = 0; i < (int)graph.size(); i++) {\n          \
    \  if (alive[i] == 0) continue;\n            if (match[i] == -1) {\n         \
    \       ++timestamp;\n                ret += augment(i);\n            }\n    \
    \    }\n        return ret;\n    }\n\n    int add_vertex(int idx) {\n        alive[idx]\
    \ = 1;\n        ++timestamp;\n        return augment(idx);\n    }\n\n    int erase_vertex(int\
    \ idx) {\n        alive[idx] = 0;\n        if (match[idx] == -1) {\n         \
    \   return 0;\n        }\n        match[match[idx]] = -1;\n        ++timestamp;\n\
    \        int ret = augment(match[idx]);\n        match[idx] = -1;\n        return\
    \ ret - 1;\n    }\n\n    void output() const {\n        for (int i = 0; i < (int)graph.size();\
    \ i++) {\n            if (i < match[i]) {\n                cout << i << \"-\"\
    \ << match[i] << endl;\n            }\n        }\n    }\n};\n"
  code: "/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0\n * @docs docs/bipartite-matching.md\n */\nstruct BipartiteMatching\
    \ {\n    vector<vector<int> > graph;\n    vector<int> match, alive, used;\n  \
    \  int timestamp;\n    int a_size;\n\n    explicit BipartiteMatching(int n)\n\
    \        : a_size(-1),\n          graph(n),\n          alive(n, 1),\n        \
    \  used(n, 0),\n          match(n, -1),\n          timestamp(0) {}\n\n    explicit\
    \ BipartiteMatching(int n, int m)\n        : a_size(n),\n          graph(n + m),\n\
    \          alive(n + m, 1),\n          used(n + m, 0),\n          match(n + m,\
    \ -1),\n          timestamp(0) {}\n\n    void add_edge(int u, int v) {\n     \
    \   if (a_size < 0) {\n            graph[u].push_back(v);\n            graph[v].push_back(u);\n\
    \        } else {\n            graph[u].push_back(v + a_size);\n            graph[v\
    \ + a_size].push_back(u);\n        }\n    }\n\n    bool augment(int idx) {\n \
    \       used[idx] = timestamp;\n        for (auto &to : graph[idx]) {\n      \
    \      int to_match = match[to];\n            if (alive[to] == 0) continue;\n\
    \            if (to_match == -1 ||\n                (used[to_match] != timestamp\
    \ && augment(to_match))) {\n                match[idx] = to;\n               \
    \ match[to] = idx;\n                return true;\n            }\n        }\n \
    \       return false;\n    }\n\n    int matching() {\n        int ret = 0;\n \
    \       for (int i = 0; i < (int)graph.size(); i++) {\n            if (alive[i]\
    \ == 0) continue;\n            if (match[i] == -1) {\n                ++timestamp;\n\
    \                ret += augment(i);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int add_vertex(int idx) {\n        alive[idx] = 1;\n    \
    \    ++timestamp;\n        return augment(idx);\n    }\n\n    int erase_vertex(int\
    \ idx) {\n        alive[idx] = 0;\n        if (match[idx] == -1) {\n         \
    \   return 0;\n        }\n        match[match[idx]] = -1;\n        ++timestamp;\n\
    \        int ret = augment(match[idx]);\n        match[idx] = -1;\n        return\
    \ ret - 1;\n    }\n\n    void output() const {\n        for (int i = 0; i < (int)graph.size();\
    \ i++) {\n            if (i < match[i]) {\n                cout << i << \"-\"\
    \ << match[i] << endl;\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/flow/BipartiteMatching.cpp
  requiredBy: []
  timestamp: '2020-11-20 12:57:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_7_A.test.cpp
documentation_of: library/graph/flow/BipartiteMatching.cpp
layout: document
redirect_from:
- /library/library/graph/flow/BipartiteMatching.cpp
- /library/library/graph/flow/BipartiteMatching.cpp.html
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
