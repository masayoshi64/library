---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/connected-components/StronglyConnectedComponents.cpp
    title: library/graph/connected-components/StronglyConnectedComponents.cpp
  - icon: ':x:'
    path: library/graph/graph-template.cpp
    title: library/graph/graph-template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-two_sat.test.cpp
    title: verify/yosupo-two_sat.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \            else\n                add_edge(a, b, c);\n        }\n    }\n};\n\
    #line 2 \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n\ntemplate <typename T = int>\nstruct StronglyConnectedComponents : Graph<T>\
    \ {\n   public:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int>\
    \ comp;            // id of scc\n    Graph<T> dag;                // DAG\n   \
    \ vector<vector<int> > group;  // lists of each scc\n\n    void build() {\n  \
    \      rg = Graph<T>(g.size());\n        // add reversed edges\n        for (int\
    \ i = 0; i < g.size(); i++) {\n            for (auto &e : g[i]) {\n          \
    \      rg.add_directed_edge(e.to, e.from, e.cost);\n            }\n        }\n\
    \        comp.assign(g.size(), -1);\n        used.assign(g.size(), 0);\n     \
    \   // dfs for (not reversed) graph\n        for (int i = 0; i < g.size(); i++)\
    \ dfs(i);\n        reverse(begin(order), end(order));\n        int ptr = 0;\n\
    \        for (int i : order)\n            if (comp[i] == -1) rdfs(i, ptr), ptr++;\n\
    \        dag = Graph<T>(ptr);\n        for (int i = 0; i < g.size(); i++) {\n\
    \            for (auto &e : g[i]) {\n                int x = comp[e.from], y =\
    \ comp[e.to];\n                if (x == y) continue;\n                dag.add_directed_edge(x,\
    \ y, e.cost);\n            }\n        }\n        group.resize(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++) {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n    }\n\n    int operator[](int k) const { return comp[k]; }\n\n \
    \  private:\n    vector<int> order, used;  // order:post order\n    Graph<T> rg;\
    \              // reversed graph\n\n    void dfs(int idx) {\n        if (exchange(used[idx],\
    \ true)) return;\n        for (auto &to : g[idx]) dfs(to);\n        order.push_back(idx);\n\
    \    }\n\n    void rdfs(int idx, int cnt) {\n        if (comp[idx] != -1) return;\n\
    \        comp[idx] = cnt;\n        for (auto &to : rg.g[idx]) rdfs(to, cnt);\n\
    \    }\n};\n#line 2 \"library/graph/connected-components/TwoSat.cpp\"\n\nstruct\
    \ TwoSat : StronglyConnectedComponents<bool> {\n   public:\n    using StronglyConnectedComponents<bool>::g;\n\
    \    using StronglyConnectedComponents<bool>::comp;\n    using StronglyConnectedComponents<bool>::add_edge;\n\
    \    size_t sz;\n\n    explicit TwoSat(size_t v)\n        : sz(v), StronglyConnectedComponents<bool>(v\
    \ + v) {}\n\n    void add_if(int u, int v) {\n        // u -> v <=> !v -> !u\n\
    \        add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n\
    \    }\n\n    void add_or(int u, int v) {\n        // u or v <=> !u -> v\n   \
    \     add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v) {\n       \
    \ // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void set_true(int\
    \ u) {\n        // u <=> !u -> u\n        add_directed_edge(rev(u), u);\n    }\n\
    \n    void set_false(int u) {\n        // !u <=> u -> !u\n        add_directed_edge(u,\
    \ rev(u));\n    }\n\n    inline int rev(int x) {\n        if (x >= sz) return\
    \ x - sz;\n        return x + sz;\n    }\n\n    vector<int> solve() {\n      \
    \  StronglyConnectedComponents<bool>::build();\n        vector<int> ret(sz);\n\
    \        for (int i = 0; i < sz; i++) {\n            if (comp[i] == comp[rev(i)])\
    \ return {};\n            ret[i] = comp[i] > comp[rev(i)];\n        }\n      \
    \  return ret;\n    }\n};\n"
  code: "#include \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n\nstruct TwoSat : StronglyConnectedComponents<bool> {\n   public:\n    using\
    \ StronglyConnectedComponents<bool>::g;\n    using StronglyConnectedComponents<bool>::comp;\n\
    \    using StronglyConnectedComponents<bool>::add_edge;\n    size_t sz;\n\n  \
    \  explicit TwoSat(size_t v)\n        : sz(v), StronglyConnectedComponents<bool>(v\
    \ + v) {}\n\n    void add_if(int u, int v) {\n        // u -> v <=> !v -> !u\n\
    \        add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n\
    \    }\n\n    void add_or(int u, int v) {\n        // u or v <=> !u -> v\n   \
    \     add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v) {\n       \
    \ // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void set_true(int\
    \ u) {\n        // u <=> !u -> u\n        add_directed_edge(rev(u), u);\n    }\n\
    \n    void set_false(int u) {\n        // !u <=> u -> !u\n        add_directed_edge(u,\
    \ rev(u));\n    }\n\n    inline int rev(int x) {\n        if (x >= sz) return\
    \ x - sz;\n        return x + sz;\n    }\n\n    vector<int> solve() {\n      \
    \  StronglyConnectedComponents<bool>::build();\n        vector<int> ret(sz);\n\
    \        for (int i = 0; i < sz; i++) {\n            if (comp[i] == comp[rev(i)])\
    \ return {};\n            ret[i] = comp[i] > comp[rev(i)];\n        }\n      \
    \  return ret;\n    }\n};"
  dependsOn:
  - library/graph/connected-components/StronglyConnectedComponents.cpp
  - library/graph/graph-template.cpp
  isVerificationFile: false
  path: library/graph/connected-components/TwoSat.cpp
  requiredBy: []
  timestamp: '2020-12-15 21:38:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-two_sat.test.cpp
documentation_of: library/graph/connected-components/TwoSat.cpp
layout: document
redirect_from:
- /library/library/graph/connected-components/TwoSat.cpp
- /library/library/graph/connected-components/TwoSat.cpp.html
title: library/graph/connected-components/TwoSat.cpp
---