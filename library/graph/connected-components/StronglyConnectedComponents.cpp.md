---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/TwoSat.cpp
    title: library/graph/connected-components/TwoSat.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-two_sat.test.cpp
    title: verify/yosupo-two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \ntemplate <typename T = int>\nstruct StronglyConnectedComponents : Graph<T>\n\
    {\npublic:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int>\
    \ comp;          // id of scc\n    Graph<T> dag;              // DAG\n    vector<vector<int>>\
    \ group; // lists of each scc\n\n    void build()\n    {\n        rg = Graph<T>(g.size());\n\
    \        // add reversed edges\n        for (int i = 0; i < g.size(); i++)\n \
    \       {\n            for (auto &e : g[i])\n            {\n                rg.add_directed_edge(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        comp.assign(g.size(), -1);\n\
    \        used.assign(g.size(), 0);\n        // dfs for (not reversed) graph\n\
    \        for (int i = 0; i < g.size(); i++)\n            dfs(i);\n        reverse(begin(order),\
    \ end(order));\n        int ptr = 0;\n        for (int i : order)\n          \
    \  if (comp[i] == -1)\n                rdfs(i, ptr), ptr++;\n        dag = Graph<T>(ptr);\n\
    \        for (int i = 0; i < g.size(); i++)\n        {\n            for (auto\
    \ &e : g[i])\n            {\n                int x = comp[e.from], y = comp[e.to];\n\
    \                if (x == y)\n                    continue;\n                dag.add_directed_edge(x,\
    \ y, e.cost);\n            }\n        }\n        group.resize(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++)\n        {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n    }\n\n    int operator[](int k) const { return comp[k]; }\n\nprivate:\n\
    \    vector<int> order, used; // order:post order\n    Graph<T> rg;          \
    \   // reversed graph\n\n    void dfs(int idx)\n    {\n        if (exchange(used[idx],\
    \ true))\n            return;\n        for (auto &to : g[idx])\n            dfs(to);\n\
    \        order.push_back(idx);\n    }\n\n    void rdfs(int idx, int cnt)\n   \
    \ {\n        if (comp[idx] != -1)\n            return;\n        comp[idx] = cnt;\n\
    \        for (auto &to : rg.g[idx])\n            rdfs(to, cnt);\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T = int>\nstruct StronglyConnectedComponents\
    \ : Graph<T>\n{\npublic:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n\
    \    vector<int> comp;          // id of scc\n    Graph<T> dag;              //\
    \ DAG\n    vector<vector<int>> group; // lists of each scc\n\n    void build()\n\
    \    {\n        rg = Graph<T>(g.size());\n        // add reversed edges\n    \
    \    for (int i = 0; i < g.size(); i++)\n        {\n            for (auto &e :\
    \ g[i])\n            {\n                rg.add_directed_edge(e.to, e.from, e.cost);\n\
    \            }\n        }\n        comp.assign(g.size(), -1);\n        used.assign(g.size(),\
    \ 0);\n        // dfs for (not reversed) graph\n        for (int i = 0; i < g.size();\
    \ i++)\n            dfs(i);\n        reverse(begin(order), end(order));\n    \
    \    int ptr = 0;\n        for (int i : order)\n            if (comp[i] == -1)\n\
    \                rdfs(i, ptr), ptr++;\n        dag = Graph<T>(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++)\n        {\n            for (auto &e : g[i])\n\
    \            {\n                int x = comp[e.from], y = comp[e.to];\n      \
    \          if (x == y)\n                    continue;\n                dag.add_directed_edge(x,\
    \ y, e.cost);\n            }\n        }\n        group.resize(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++)\n        {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n    }\n\n    int operator[](int k) const { return comp[k]; }\n\nprivate:\n\
    \    vector<int> order, used; // order:post order\n    Graph<T> rg;          \
    \   // reversed graph\n\n    void dfs(int idx)\n    {\n        if (exchange(used[idx],\
    \ true))\n            return;\n        for (auto &to : g[idx])\n            dfs(to);\n\
    \        order.push_back(idx);\n    }\n\n    void rdfs(int idx, int cnt)\n   \
    \ {\n        if (comp[idx] != -1)\n            return;\n        comp[idx] = cnt;\n\
    \        for (auto &to : rg.g[idx])\n            rdfs(to, cnt);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/connected-components/StronglyConnectedComponents.cpp
  requiredBy:
  - library/graph/connected-components/TwoSat.cpp
  timestamp: '2021-08-25 11:38:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-two_sat.test.cpp
documentation_of: library/graph/connected-components/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/library/graph/connected-components/StronglyConnectedComponents.cpp
- /library/library/graph/connected-components/StronglyConnectedComponents.cpp.html
title: library/graph/connected-components/StronglyConnectedComponents.cpp
---
