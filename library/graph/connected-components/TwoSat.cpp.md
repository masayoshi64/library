---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/StronglyConnectedComponents.cpp
    title: library/graph/connected-components/StronglyConnectedComponents.cpp
  _extendedRequiredBy: []
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
    \        for (auto &to : rg.g[idx])\n            rdfs(to, cnt);\n    }\n};\n#line\
    \ 2 \"library/graph/connected-components/TwoSat.cpp\"\n\nstruct TwoSat : StronglyConnectedComponents<bool>\n\
    {\npublic:\n    using StronglyConnectedComponents<bool>::g;\n    using StronglyConnectedComponents<bool>::comp;\n\
    \    using StronglyConnectedComponents<bool>::add_edge;\n    int sz;\n\n    explicit\
    \ TwoSat(int v)\n        : sz(v), StronglyConnectedComponents<bool>(v + v) {}\n\
    \n    void add_if(int u, int v)\n    {\n        // u -> v <=> !v -> !u\n     \
    \   add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n   \
    \ }\n\n    void add_or(int u, int v)\n    {\n        // u or v <=> !u -> v\n \
    \       add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v)\n    {\n\
    \        // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void\
    \ set_true(int u)\n    {\n        // u <=> !u -> u\n        add_directed_edge(rev(u),\
    \ u);\n    }\n\n    void set_false(int u)\n    {\n        // !u <=> u -> !u\n\
    \        add_directed_edge(u, rev(u));\n    }\n\n    inline int rev(int x)\n \
    \   {\n        if (x >= sz)\n            return x - sz;\n        return x + sz;\n\
    \    }\n\n    vector<int> solve()\n    {\n        StronglyConnectedComponents<bool>::build();\n\
    \        vector<int> ret(sz);\n        for (int i = 0; i < sz; i++)\n        {\n\
    \            if (comp[i] == comp[rev(i)])\n                return {};\n      \
    \      ret[i] = comp[i] > comp[rev(i)];\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#include \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n\nstruct TwoSat : StronglyConnectedComponents<bool>\n{\npublic:\n    using StronglyConnectedComponents<bool>::g;\n\
    \    using StronglyConnectedComponents<bool>::comp;\n    using StronglyConnectedComponents<bool>::add_edge;\n\
    \    int sz;\n\n    explicit TwoSat(int v)\n        : sz(v), StronglyConnectedComponents<bool>(v\
    \ + v) {}\n\n    void add_if(int u, int v)\n    {\n        // u -> v <=> !v ->\
    \ !u\n        add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n\
    \    }\n\n    void add_or(int u, int v)\n    {\n        // u or v <=> !u -> v\n\
    \        add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v)\n    {\n\
    \        // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void\
    \ set_true(int u)\n    {\n        // u <=> !u -> u\n        add_directed_edge(rev(u),\
    \ u);\n    }\n\n    void set_false(int u)\n    {\n        // !u <=> u -> !u\n\
    \        add_directed_edge(u, rev(u));\n    }\n\n    inline int rev(int x)\n \
    \   {\n        if (x >= sz)\n            return x - sz;\n        return x + sz;\n\
    \    }\n\n    vector<int> solve()\n    {\n        StronglyConnectedComponents<bool>::build();\n\
    \        vector<int> ret(sz);\n        for (int i = 0; i < sz; i++)\n        {\n\
    \            if (comp[i] == comp[rev(i)])\n                return {};\n      \
    \      ret[i] = comp[i] > comp[rev(i)];\n        }\n        return ret;\n    }\n\
    };"
  dependsOn:
  - library/graph/connected-components/StronglyConnectedComponents.cpp
  isVerificationFile: false
  path: library/graph/connected-components/TwoSat.cpp
  requiredBy: []
  timestamp: '2021-08-25 11:38:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-two_sat.test.cpp
documentation_of: library/graph/connected-components/TwoSat.cpp
layout: document
redirect_from:
- /library/library/graph/connected-components/TwoSat.cpp
- /library/library/graph/connected-components/TwoSat.cpp.html
title: library/graph/connected-components/TwoSat.cpp
---
