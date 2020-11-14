---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-dsl-1-a.test.cpp
    title: verify/aoj-dsl-1-a.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 1 \"library/structure/UnionFind/UnionFind.cpp\"\n\n/**\n * @brief\
    \ UnionFind\n * @docs docs/union-find.md\n */\nstruct UnionFind {\n    vector<int>\
    \ data;  // sizes of sets\n\n    UnionFind(int sz) : data(sz, -1) {}\n\n    bool\
    \ unite(int x, int y) {\n        x = find(x), y = find(y);\n        if (x == y)\
    \ return false;\n        if (data[x] > data[y]) swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ k) {\n        if (data[k] < 0) return k;\n        return data[k] = find(data[k]);\n\
    \    }\n\n    int size(int k) { return (-data[find(k)]); }\n\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n};\n"
  code: "\n/**\n * @brief UnionFind\n * @docs docs/union-find.md\n */\nstruct UnionFind\
    \ {\n    vector<int> data;  // sizes of sets\n\n    UnionFind(int sz) : data(sz,\
    \ -1) {}\n\n    bool unite(int x, int y) {\n        x = find(x), y = find(y);\n\
    \        if (x == y) return false;\n        if (data[x] > data[y]) swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n        return true;\n   \
    \ }\n\n    int find(int k) {\n        if (data[k] < 0) return k;\n        return\
    \ data[k] = find(data[k]);\n    }\n\n    int size(int k) { return (-data[find(k)]);\
    \ }\n\n    bool same(int x, int y) { return find(x) == find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/UnionFind/UnionFind.cpp
  requiredBy: []
  timestamp: '2020-11-14 11:43:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-dsl-1-a.test.cpp
documentation_of: library/structure/UnionFind/UnionFind.cpp
layout: document
redirect_from:
- /library/library/structure/UnionFind/UnionFind.cpp
- /library/library/structure/UnionFind/UnionFind.cpp.html
title: UnionFind
---
