---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/StronglyConnectedComponents.cpp
    title: library/graph/connected-components/StronglyConnectedComponents.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/TwoSat.cpp
    title: library/graph/connected-components/TwoSat.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_12_B.test.cpp
    title: verify/aoj-ALDS1_12_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-two_sat.test.cpp
    title: verify/yosupo-two_sat.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/graph-template.cpp\"\ntemplate <typename T\
    \ = int>\nstruct Edge {\n    int from, to;\n    T cost;\n    int idx;\n\n    Edge()\
    \ = default;\n\n    Edge(int from, int to, T cost = 1, int idx = -1)\n       \
    \ : from(from), to(to), cost(cost), idx(idx) {}\n\n    operator int() const {\
    \ return to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T>\
    \ > > g;\n    int es;\n\n    Graph() = default;\n\n    explicit Graph(int n) :\
    \ g(n), es(0) {}\n\n    size_t size() const { return g.size(); }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int a, b;\n            cin >> a >> b;\n            a += padding;\n        \
    \    b += padding;\n            T c = T(1);\n            if (weighted) cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(a, b, c);\n\
    \            else\n                add_edge(a, b, c);\n        }\n    }\n};\n"
  code: "template <typename T = int>\nstruct Edge {\n    int from, to;\n    T cost;\n\
    \    int idx;\n\n    Edge() = default;\n\n    Edge(int from, int to, T cost =\
    \ 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n\n\
    \    operator int() const { return to; }\n};\n\ntemplate <typename T = int>\n\
    struct Graph {\n    vector<vector<Edge<T> > > g;\n    int es;\n\n    Graph() =\
    \ default;\n\n    explicit Graph(int n) : g(n), es(0) {}\n\n    size_t size()\
    \ const { return g.size(); }\n\n    void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\n\
    \    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int a, b;\n            cin >> a >> b;\n            a += padding;\n        \
    \    b += padding;\n            T c = T(1);\n            if (weighted) cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(a, b, c);\n\
    \            else\n                add_edge(a, b, c);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/graph-template.cpp
  requiredBy:
  - library/graph/connected-components/TwoSat.cpp
  - library/graph/connected-components/StronglyConnectedComponents.cpp
  timestamp: '2020-11-19 20:53:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-two_sat.test.cpp
  - verify/aoj-ALDS1_12_B.test.cpp
documentation_of: library/graph/graph-template.cpp
layout: document
redirect_from:
- /library/library/graph/graph-template.cpp
- /library/library/graph/graph-template.cpp.html
title: library/graph/graph-template.cpp
---
