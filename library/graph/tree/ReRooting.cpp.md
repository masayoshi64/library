---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-1595.test.cpp
    title: verify/aoj-1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/tree/ReRooting.cpp\"\ntemplate <typename T>\n\
    struct ReRooting {\n    using F = function<T(T, int)>;  // apply to a child dp\
    \ value:function dp,\n                                    // child index to value\n\
    \    using F2 = function<T(T, T)>;   // apply to get parent dp values\n    int\
    \ V;\n    vector<vector<int>> E;  // graph\n    vector<vector<T>> dp;\n    //\
    \ dp_v = g(merge(f(dp_c1,c1), f(dp_c2,c2), ..., f(dp_ck,ck)) , v)\n    F f, g;\n\
    \    F2 merge;  // merge children values\n    T mi;      // identity of merge\n\
    \n    ReRooting(\n        int V_, F f_, F2 merge_, T mi_, F g_ = [](T a, int b)\
    \ { return a; })\n        : V(V_), f(f_), merge(merge_), mi(mi_), g(g_) {\n  \
    \      E.resize(V);\n        dp.resize(V);\n    }\n\n    void add_edge(int a,\
    \ int b) {\n        E[a].push_back(b);\n        E[b].push_back(a);\n    }\n\n\
    \    T dfs1(int p, int v) {\n        T res = mi;\n        for (int i = 0; i <\
    \ E[v].size(); ++i) {\n            if (E[v][i] == p) continue;\n            dp[v][i]\
    \ = dfs1(v, E[v][i]);\n            res = merge(res, f(dp[v][i], E[v][i]));\n \
    \       }\n        return g(res, v);\n    }\n\n    void dfs2(int p, int v, T add)\
    \ {\n        for (int i = 0; i < E[v].size(); ++i) {\n            if (E[v][i]\
    \ == p) {\n                dp[v][i] = add;\n                break;\n         \
    \   }\n        }\n\n        vector<T> pL(E[v].size() + 1), pR(E[v].size() + 1);\n\
    \        pL[0] = mi;\n        for (int i = 0; i < E[v].size(); ++i)\n        \
    \    pL[i + 1] = merge(pL[i], f(dp[v][i], E[v][i]));\n        pR[E[v].size()]\
    \ = mi;\n        for (int i = E[v].size(); i > 0; --i)\n            pR[i - 1]\
    \ = merge(pR[i], f(dp[v][i - 1], E[v][i - 1]));\n\n        for (int i = 0; i <\
    \ E[v].size(); ++i) {\n            if (E[v][i] == p) continue;\n            T\
    \ val = merge(pL[i], pR[i + 1]);\n            dfs2(v, E[v][i], g(val, v));\n \
    \       }\n    }\n    // build rerooting\n    void build(int root = 0) {\n   \
    \     for (int i = 0; i < V; ++i) dp[i].resize(E[i].size());\n        dfs1(-1,\
    \ root);\n        dfs2(-1, root, mi);\n    }\n    // answer for root v\n    T\
    \ query(int v) {\n        T ans = mi;\n        for (int i = 0; i < E[v].size();\
    \ ++i) {\n            ans = merge(ans, f(dp[v][i], E[v][i]));\n        }\n   \
    \     return g(ans, v);\n    }\n};\n"
  code: "template <typename T>\nstruct ReRooting {\n    using F = function<T(T, int)>;\
    \  // apply to a child dp value:function dp,\n                               \
    \     // child index to value\n    using F2 = function<T(T, T)>;   // apply to\
    \ get parent dp values\n    int V;\n    vector<vector<int>> E;  // graph\n   \
    \ vector<vector<T>> dp;\n    // dp_v = g(merge(f(dp_c1,c1), f(dp_c2,c2), ...,\
    \ f(dp_ck,ck)) , v)\n    F f, g;\n    F2 merge;  // merge children values\n  \
    \  T mi;      // identity of merge\n\n    ReRooting(\n        int V_, F f_, F2\
    \ merge_, T mi_, F g_ = [](T a, int b) { return a; })\n        : V(V_), f(f_),\
    \ merge(merge_), mi(mi_), g(g_) {\n        E.resize(V);\n        dp.resize(V);\n\
    \    }\n\n    void add_edge(int a, int b) {\n        E[a].push_back(b);\n    \
    \    E[b].push_back(a);\n    }\n\n    T dfs1(int p, int v) {\n        T res =\
    \ mi;\n        for (int i = 0; i < E[v].size(); ++i) {\n            if (E[v][i]\
    \ == p) continue;\n            dp[v][i] = dfs1(v, E[v][i]);\n            res =\
    \ merge(res, f(dp[v][i], E[v][i]));\n        }\n        return g(res, v);\n  \
    \  }\n\n    void dfs2(int p, int v, T add) {\n        for (int i = 0; i < E[v].size();\
    \ ++i) {\n            if (E[v][i] == p) {\n                dp[v][i] = add;\n \
    \               break;\n            }\n        }\n\n        vector<T> pL(E[v].size()\
    \ + 1), pR(E[v].size() + 1);\n        pL[0] = mi;\n        for (int i = 0; i <\
    \ E[v].size(); ++i)\n            pL[i + 1] = merge(pL[i], f(dp[v][i], E[v][i]));\n\
    \        pR[E[v].size()] = mi;\n        for (int i = E[v].size(); i > 0; --i)\n\
    \            pR[i - 1] = merge(pR[i], f(dp[v][i - 1], E[v][i - 1]));\n\n     \
    \   for (int i = 0; i < E[v].size(); ++i) {\n            if (E[v][i] == p) continue;\n\
    \            T val = merge(pL[i], pR[i + 1]);\n            dfs2(v, E[v][i], g(val,\
    \ v));\n        }\n    }\n    // build rerooting\n    void build(int root = 0)\
    \ {\n        for (int i = 0; i < V; ++i) dp[i].resize(E[i].size());\n        dfs1(-1,\
    \ root);\n        dfs2(-1, root, mi);\n    }\n    // answer for root v\n    T\
    \ query(int v) {\n        T ans = mi;\n        for (int i = 0; i < E[v].size();\
    \ ++i) {\n            ans = merge(ans, f(dp[v][i], E[v][i]));\n        }\n   \
    \     return g(ans, v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/tree/ReRooting.cpp
  requiredBy: []
  timestamp: '2020-11-19 12:41:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-1595.test.cpp
documentation_of: library/graph/tree/ReRooting.cpp
layout: document
redirect_from:
- /library/library/graph/tree/ReRooting.cpp
- /library/library/graph/tree/ReRooting.cpp.html
title: library/graph/tree/ReRooting.cpp
---
