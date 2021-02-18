---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/structure/UnionFind/UnionFind.cpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/structure/UnionFind/UnionFind.cpp\"\n\n/**\n * @brief\
    \ UnionFind\n * @docs docs/UnionFind.md\n */\nstruct UnionFind {\n    vector<int>\
    \ data;  // sizes of sets\n\n    UnionFind(int sz) : data(sz, -1) {}\n\n    bool\
    \ unite(int x, int y) {\n        x = find(x), y = find(y);\n        if (x == y)\
    \ return false;\n        if (data[x] > data[y]) swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ k) {\n        if (data[k] < 0) return k;\n        return data[k] = find(data[k]);\n\
    \    }\n\n    int size(int k) { return (-data[find(k)]); }\n\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n};\n#line 2 \"library/structure/UnionFind/merge_tree.cpp\"\
    \n//\u8449:\u8981\u7D20, \u7BC0\u70B9:\u30AF\u30A8\u30EA,\nstruct MergeTree {\n\
    \    UnionFind uf;\n    mat<int> g;\n    vector<int> root;\n    Mergetree(int\
    \ n, int q) : uf(n), g(n + q), root(n) { iota(all(root), 0); }\n\n    void merge(int\
    \ u, int v, int id) {\n        if (uf.same(u, v)) return;\n        g[root[u]].pb(id\
    \ + n);\n        g[root[v]].pb(id + n);\n        g[id + n].pb(root[u]);\n    \
    \    g[id+n].pb(root[v];\n        uf.unite(u, v);\n        int r = uf.find(u);\n\
    \        root[r] = id+n;\n    }\n\n    // todo: \u5404\u6642\u70B9\u3067\u9023\
    \u7D50\u6210\u5206\u304C\u533A\u9593\u306B\u306A\u308B\u3088\u3046\u306B\u30BD\
    \u30FC\u30C8\u3057\u305F\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u95A2\u6570\n   \
    \ // \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u3067\u8449\u3092\u4E26\u3079\u308C\
    \u3070\u3044\u3044\n    // vector<int> align()\n}\n"
  code: "#include \"library/structure/UnionFind/UnionFind.cpp\"\n//\u8449:\u8981\u7D20\
    , \u7BC0\u70B9:\u30AF\u30A8\u30EA,\nstruct MergeTree {\n    UnionFind uf;\n  \
    \  mat<int> g;\n    vector<int> root;\n    Mergetree(int n, int q) : uf(n), g(n\
    \ + q), root(n) { iota(all(root), 0); }\n\n    void merge(int u, int v, int id)\
    \ {\n        if (uf.same(u, v)) return;\n        g[root[u]].pb(id + n);\n    \
    \    g[root[v]].pb(id + n);\n        g[id + n].pb(root[u]);\n        g[id+n].pb(root[v];\n\
    \        uf.unite(u, v);\n        int r = uf.find(u);\n        root[r] = id+n;\n\
    \    }\n\n    // todo: \u5404\u6642\u70B9\u3067\u9023\u7D50\u6210\u5206\u304C\u533A\
    \u9593\u306B\u306A\u308B\u3088\u3046\u306B\u30BD\u30FC\u30C8\u3057\u305F\u30EA\
    \u30B9\u30C8\u3092\u8FD4\u3059\u95A2\u6570\n    // \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\u3067\u8449\u3092\u4E26\u3079\u308C\u3070\u3044\u3044\n    // vector<int>\
    \ align()\n}"
  dependsOn:
  - library/structure/UnionFind/UnionFind.cpp
  isVerificationFile: false
  path: library/structure/UnionFind/merge_tree.cpp
  requiredBy: []
  timestamp: '2020-11-18 22:08:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/structure/UnionFind/merge_tree.cpp
layout: document
redirect_from:
- /library/library/structure/UnionFind/merge_tree.cpp
- /library/library/structure/UnionFind/merge_tree.cpp.html
title: library/structure/UnionFind/merge_tree.cpp
---
