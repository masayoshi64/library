---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/structure/UnionFind/merge_list.cpp\"\nstruct mergetree\
    \ {\n    using pii = pair<int, int>;\n\n   public:\n    mergetree() {}\n    mergetree(int\
    \ n) : n(n) {}\n\n    vector<pii> build(const vector<int>& type, const vector<pii>&\
    \ vs) {\n        q = int(type.size());\n\n        parent_or_size.assign(n, -1);\n\
    \        root.resize(n);\n        iota(root.begin(), root.end(), 0);\n       \
    \ vid.resize(n);\n        child.resize(q);\n        range.resize(n + q);\n   \
    \     vector<int> idx(q, -1);\n        for (int i = 0; i < q; i++) {\n       \
    \     switch (type[i]) {\n                case 1: {\n                    auto\
    \ [a, b] = vs[i];\n                    if (same(a, b)) continue;\n           \
    \         child[i] = pii(root[leader(a)], root[leader(b)]);\n                \
    \    root[merge(a, b)] = n + i;\n                } break;\n                case\
    \ 2: {\n                    int x = vs[i].first;\n                    idx[i] =\
    \ root[leader(x)];\n                } break;\n                default: {\n   \
    \                 assert(false);\n                } break;\n            }\n  \
    \      }\n\n        int pos = 0;\n        for (int i = 0; i < n; i++) {\n    \
    \        if (leader(i) == i) {\n                dfs(root[i], pos);\n         \
    \   }\n        }\n\n        vector<pii> ret(q);\n        for (int i = 0; i < q;\
    \ i++) {\n            if (~idx[i]) {\n                ret[i] = range[idx[i]];\n\
    \            }\n        }\n\n        return ret;\n    }\n\n    int operator[](int\
    \ i) { return vid[i]; }\n\n   private:\n    int n, q;\n    // root node: -1 *\
    \ component size\n    // otherwise: parent\n    vector<int> parent_or_size, root,\
    \ vid;\n    vector<pii> child, range;\n\n    void dfs(int v, int& pos) {\n   \
    \     int l = pos;\n        if (v < n) {\n            vid[v] = pos++;\n      \
    \  } else {\n            dfs(child[v - n].first, pos);\n            dfs(child[v\
    \ - n].second, pos);\n        }\n        int r = pos;\n        range[v] = pii(l,\
    \ r);\n    };\n\n    int merge(int a, int b) {\n        assert(0 <= a && a < n);\n\
    \        assert(0 <= b && b < n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < n);\n        assert(0 <= b && b < n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n};\n"
  code: "struct mergetree {\n    using pii = pair<int, int>;\n\n   public:\n    mergetree()\
    \ {}\n    mergetree(int n) : n(n) {}\n\n    vector<pii> build(const vector<int>&\
    \ type, const vector<pii>& vs) {\n        q = int(type.size());\n\n        parent_or_size.assign(n,\
    \ -1);\n        root.resize(n);\n        iota(root.begin(), root.end(), 0);\n\
    \        vid.resize(n);\n        child.resize(q);\n        range.resize(n + q);\n\
    \        vector<int> idx(q, -1);\n        for (int i = 0; i < q; i++) {\n    \
    \        switch (type[i]) {\n                case 1: {\n                    auto\
    \ [a, b] = vs[i];\n                    if (same(a, b)) continue;\n           \
    \         child[i] = pii(root[leader(a)], root[leader(b)]);\n                \
    \    root[merge(a, b)] = n + i;\n                } break;\n                case\
    \ 2: {\n                    int x = vs[i].first;\n                    idx[i] =\
    \ root[leader(x)];\n                } break;\n                default: {\n   \
    \                 assert(false);\n                } break;\n            }\n  \
    \      }\n\n        int pos = 0;\n        for (int i = 0; i < n; i++) {\n    \
    \        if (leader(i) == i) {\n                dfs(root[i], pos);\n         \
    \   }\n        }\n\n        vector<pii> ret(q);\n        for (int i = 0; i < q;\
    \ i++) {\n            if (~idx[i]) {\n                ret[i] = range[idx[i]];\n\
    \            }\n        }\n\n        return ret;\n    }\n\n    int operator[](int\
    \ i) { return vid[i]; }\n\n   private:\n    int n, q;\n    // root node: -1 *\
    \ component size\n    // otherwise: parent\n    vector<int> parent_or_size, root,\
    \ vid;\n    vector<pii> child, range;\n\n    void dfs(int v, int& pos) {\n   \
    \     int l = pos;\n        if (v < n) {\n            vid[v] = pos++;\n      \
    \  } else {\n            dfs(child[v - n].first, pos);\n            dfs(child[v\
    \ - n].second, pos);\n        }\n        int r = pos;\n        range[v] = pii(l,\
    \ r);\n    };\n\n    int merge(int a, int b) {\n        assert(0 <= a && a < n);\n\
    \        assert(0 <= b && b < n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < n);\n        assert(0 <= b && b < n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/UnionFind/merge_list.cpp
  requiredBy: []
  timestamp: '2020-11-17 08:44:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/structure/UnionFind/merge_list.cpp
layout: document
redirect_from:
- /library/library/structure/UnionFind/merge_list.cpp
- /library/library/structure/UnionFind/merge_list.cpp.html
title: library/structure/UnionFind/merge_list.cpp
---
