---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yuki-650.cpp
    title: verify/yuki-650.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/tree/HLD.cpp\"\nstruct HLD {\n    vector<vector<int>>\
    \ G;\n    vector<int> parent, depth, sub_size, v_id, id_to_v, head;\n    HLD(int\
    \ n)\n        : G(n),\n          v_id(n, -1),\n          head(n),\n          sub_size(n,\
    \ 1),\n          parent(n, -1),\n          depth(n, 0),\n          id_to_v(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n   \
    \     G[v].emplace_back(u);\n    }\n\n    void build(int root = 0) {\n       \
    \ int pos = 0;\n        dfs_size(root);\n        head[root] = root;\n        dfs_hld(root,\
    \ pos);\n    }\n\n    void dfs_size(int v) {\n        for (int& nv : G[v]) {\n\
    \            if (nv == parent[v]) {\n                nv = G[v].back();\n     \
    \           G[v].pop_back();\n            }\n        }\n        for (int& nv :\
    \ G[v]) {\n            parent[nv] = v;\n            depth[nv] = depth[v] + 1;\n\
    \            dfs_size(nv);\n            sub_size[v] += sub_size[nv];\n       \
    \     if (sub_size[nv] > sub_size[G[v][0]]) swap(nv, G[v][0]);\n        }\n  \
    \  }\n\n    void dfs_hld(int v, int& pos) {\n        v_id[v] = pos;\n        id_to_v[pos++]\
    \ = v;\n        for (int nv : G[v]) {\n            head[nv] = (nv == G[v][0] ?\
    \ head[v] : nv);\n            dfs_hld(nv, pos);\n        }\n    }\n\n    int lca(int\
    \ u, int v) {\n        while (1) {\n            if (v_id[u] > v_id[v]) swap(u,\
    \ v);\n            if (head[u] == head[v]) return u;\n            v = parent[head[v]];\n\
    \        }\n    }\n\n    int distance(int u, int v) {\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    // update vertexes in [u, v]\
    \ with f\n    template <typename F>\n    void update(int u, int v, const F& f)\
    \ {\n        while (1) {\n            if (v_id[u] > v_id[v]) swap(u, v);\n   \
    \         f(max(v_id[head[v]], v_id[u]), v_id[v]);\n            if (head[u] !=\
    \ head[v])\n                v = parent[head[v]];\n            else\n         \
    \       break;\n        }\n    }\n\n    // get res for [u, v] with query q and\
    \ merge each value with f\n    // root->leaf\n    template <typename T, typename\
    \ Q, typename F>\n    T query(int u, int v, T id, const Q& q, const F& f) {\n\
    \        T l = id, r = id;\n        while (1) {\n            if (v_id[u] > v_id[v])\
    \ {\n                swap(u, v);\n                swap(l, r);\n            }\n\
    \            l = f(q(max(v_id[head[v]], v_id[u]), v_id[v]), l);\n            if\
    \ (head[u] != head[v])\n                v = parent[head[v]];\n            else\n\
    \                break;\n        }\n        return f(r, l);\n    }\n\n    // update\
    \ edges between u, v inclusive with func f\n    template <typename F>\n    void\
    \ update_edge(int u, int v, const F& f) {\n        while (1) {\n            if\
    \ (v_id[u] > v_id[v]) swap(u, v);\n            if (head[u] != head[v]) {\n   \
    \             f(v_id[head[v]], v_id[v]);\n                v = parent[head[v]];\n\
    \            } else {\n                if (u != v) f(v_id[u] + 1, v_id[v]);\n\
    \                break;\n            }\n        }\n    }\n\n    // query for edges\
    \ between u, v inclusive with query q and merge func f\n    // root->leaf\n  \
    \  template <typename T, typename Q, typename F>\n    T query_edge(int u, int\
    \ v, T id, const Q& q, const F& f) {\n        T l = id, r = id;\n        while\
    \ (1) {\n            if (v_id[u] > v_id[v]) {\n                swap(u, v);\n \
    \               swap(l, r);\n            }\n            if (head[u] != head[v])\
    \ {\n                l = f(q(v_id[head[v]], v_id[v]), l);\n                v =\
    \ parent[head[v]];\n            } else {\n                if (u != v) l = f(q(v_id[u]\
    \ + 1, v_id[v]), l);\n                break;\n            }\n        }\n     \
    \   return f(r, l);\n    }\n};\n"
  code: "struct HLD {\n    vector<vector<int>> G;\n    vector<int> parent, depth,\
    \ sub_size, v_id, id_to_v, head;\n    HLD(int n)\n        : G(n),\n          v_id(n,\
    \ -1),\n          head(n),\n          sub_size(n, 1),\n          parent(n, -1),\n\
    \          depth(n, 0),\n          id_to_v(n) {}\n\n    void add_edge(int u, int\
    \ v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n\
    \    void build(int root = 0) {\n        int pos = 0;\n        dfs_size(root);\n\
    \        head[root] = root;\n        dfs_hld(root, pos);\n    }\n\n    void dfs_size(int\
    \ v) {\n        for (int& nv : G[v]) {\n            if (nv == parent[v]) {\n \
    \               nv = G[v].back();\n                G[v].pop_back();\n        \
    \    }\n        }\n        for (int& nv : G[v]) {\n            parent[nv] = v;\n\
    \            depth[nv] = depth[v] + 1;\n            dfs_size(nv);\n          \
    \  sub_size[v] += sub_size[nv];\n            if (sub_size[nv] > sub_size[G[v][0]])\
    \ swap(nv, G[v][0]);\n        }\n    }\n\n    void dfs_hld(int v, int& pos) {\n\
    \        v_id[v] = pos;\n        id_to_v[pos++] = v;\n        for (int nv : G[v])\
    \ {\n            head[nv] = (nv == G[v][0] ? head[v] : nv);\n            dfs_hld(nv,\
    \ pos);\n        }\n    }\n\n    int lca(int u, int v) {\n        while (1) {\n\
    \            if (v_id[u] > v_id[v]) swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n            v = parent[head[v]];\n        }\n    }\n\n    int distance(int\
    \ u, int v) {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n  \
    \  }\n\n    // update vertexes in [u, v] with f\n    template <typename F>\n \
    \   void update(int u, int v, const F& f) {\n        while (1) {\n           \
    \ if (v_id[u] > v_id[v]) swap(u, v);\n            f(max(v_id[head[v]], v_id[u]),\
    \ v_id[v]);\n            if (head[u] != head[v])\n                v = parent[head[v]];\n\
    \            else\n                break;\n        }\n    }\n\n    // get res\
    \ for [u, v] with query q and merge each value with f\n    // root->leaf\n   \
    \ template <typename T, typename Q, typename F>\n    T query(int u, int v, T id,\
    \ const Q& q, const F& f) {\n        T l = id, r = id;\n        while (1) {\n\
    \            if (v_id[u] > v_id[v]) {\n                swap(u, v);\n         \
    \       swap(l, r);\n            }\n            l = f(q(max(v_id[head[v]], v_id[u]),\
    \ v_id[v]), l);\n            if (head[u] != head[v])\n                v = parent[head[v]];\n\
    \            else\n                break;\n        }\n        return f(r, l);\n\
    \    }\n\n    // update edges between u, v inclusive with func f\n    template\
    \ <typename F>\n    void update_edge(int u, int v, const F& f) {\n        while\
    \ (1) {\n            if (v_id[u] > v_id[v]) swap(u, v);\n            if (head[u]\
    \ != head[v]) {\n                f(v_id[head[v]], v_id[v]);\n                v\
    \ = parent[head[v]];\n            } else {\n                if (u != v) f(v_id[u]\
    \ + 1, v_id[v]);\n                break;\n            }\n        }\n    }\n\n\
    \    // query for edges between u, v inclusive with query q and merge func f\n\
    \    // root->leaf\n    template <typename T, typename Q, typename F>\n    T query_edge(int\
    \ u, int v, T id, const Q& q, const F& f) {\n        T l = id, r = id;\n     \
    \   while (1) {\n            if (v_id[u] > v_id[v]) {\n                swap(u,\
    \ v);\n                swap(l, r);\n            }\n            if (head[u] !=\
    \ head[v]) {\n                l = f(q(v_id[head[v]], v_id[v]), l);\n         \
    \       v = parent[head[v]];\n            } else {\n                if (u != v)\
    \ l = f(q(v_id[u] + 1, v_id[v]), l);\n                break;\n            }\n\
    \        }\n        return f(r, l);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/tree/HLD.cpp
  requiredBy:
  - verify/yuki-650.cpp
  timestamp: '2020-11-18 22:56:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/tree/HLD.cpp
layout: document
redirect_from:
- /library/library/graph/tree/HLD.cpp
- /library/library/graph/tree/HLD.cpp.html
title: library/graph/tree/HLD.cpp
---
