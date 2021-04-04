---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yuki-650.test.cpp
    title: verify/yuki-650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segmenttree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 1 \"library/structure/segtree/SegmentTree.cpp\"\n/**\n * @brief\
    \ Segment Tree\n * @docs docs/segmenttree.md\n */\ntemplate <typename Monoid>\n\
    struct SegmentTree {\n    using F = function<Monoid(Monoid, Monoid)>;\n\n    int\
    \ sz;\n    vector<Monoid> seg;\n\n    const F f;\n    const Monoid M1;\n\n   \
    \ SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {\n        sz\
    \ = 1;\n        while (sz < n) sz <<= 1;\n        seg.assign(2 * sz, M1);\n  \
    \  }\n\n    void set(int k, const Monoid& x) { seg[k + sz] = x; }\n\n    void\
    \ build() {\n        for (int k = sz - 1; k > 0; k--) {\n            seg[k] =\
    \ f(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n    void update(int\
    \ k, const Monoid& x) {\n        k += sz;\n        seg[k] = x;\n        while\
    \ (k >>= 1) {\n            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);\n     \
    \   }\n    }\n\n    Monoid query(int a, int b) {\n        Monoid L = M1, R = M1;\n\
    \        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a\
    \ & 1) L = f(L, seg[a++]);\n            if (b & 1) R = f(seg[--b], R);\n     \
    \   }\n        return f(L, R);\n    }\n\n    Monoid operator[](const int& k) const\
    \ { return seg[k + sz]; }\n\n    template <typename C>\n    int find_subtree(int\
    \ a, const C& check, Monoid& M, bool type) {\n        while (a < sz) {\n     \
    \       Monoid nxt =\n                type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n            if (check(nxt))\n                a = 2 * a + type;\n\
    \            else\n                M = nxt, a = 2 * a + 1 - type;\n        }\n\
    \        return a - sz;\n    }\n\n    // check(seg.query(b, i))\u3092\u6E80\u305F\
    \u3059\u6700\u5C0F\u306Eb<=i\u3092\u8FD4\u3059.\u306A\u3051\u308C\u3070-1\n  \
    \  template <typename C>\n    int find_first(int a, const C& check) {\n      \
    \  Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L, seg[1])))\
    \ return find_subtree(1, check, L, false);\n            return -1;\n        }\n\
    \        int b = sz;\n        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)\
    \ {\n            if (a & 1) {\n                Monoid nxt = f(L, seg[a]);\n  \
    \              if (check(nxt)) return find_subtree(a, check, L, false);\n    \
    \            L = nxt;\n                ++a;\n            }\n        }\n      \
    \  return -1;\n    }\n\n    // check(seg.query(i, b))\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ei<b\u3092\u8FD4\u3059.\u306A\u3051\u308C\u3070-1\n    template <typename\
    \ C>\n    int find_last(int b, const C& check) {\n        Monoid R = M1;\n   \
    \     if (b >= sz) {\n            if (check(f(seg[1], R))) return find_subtree(1,\
    \ check, R, true);\n            return -1;\n        }\n        int a = sz;\n \
    \       for (b += sz; a < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n \
    \               Monoid nxt = f(seg[--b], R);\n                if (check(nxt))\
    \ return find_subtree(b, check, R, true);\n                R = nxt;\n        \
    \    }\n        }\n        return -1;\n    }\n};\n"
  code: "/**\n * @brief Segment Tree\n * @docs docs/segmenttree.md\n */\ntemplate\
    \ <typename Monoid>\nstruct SegmentTree {\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    int sz;\n    vector<Monoid> seg;\n\n    const F f;\n    const\
    \ Monoid M1;\n\n    SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1)\
    \ {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        seg.assign(2 *\
    \ sz, M1);\n    }\n\n    void set(int k, const Monoid& x) { seg[k + sz] = x; }\n\
    \n    void build() {\n        for (int k = sz - 1; k > 0; k--) {\n           \
    \ seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n    void update(int\
    \ k, const Monoid& x) {\n        k += sz;\n        seg[k] = x;\n        while\
    \ (k >>= 1) {\n            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);\n     \
    \   }\n    }\n\n    Monoid query(int a, int b) {\n        Monoid L = M1, R = M1;\n\
    \        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a\
    \ & 1) L = f(L, seg[a++]);\n            if (b & 1) R = f(seg[--b], R);\n     \
    \   }\n        return f(L, R);\n    }\n\n    Monoid operator[](const int& k) const\
    \ { return seg[k + sz]; }\n\n    template <typename C>\n    int find_subtree(int\
    \ a, const C& check, Monoid& M, bool type) {\n        while (a < sz) {\n     \
    \       Monoid nxt =\n                type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n            if (check(nxt))\n                a = 2 * a + type;\n\
    \            else\n                M = nxt, a = 2 * a + 1 - type;\n        }\n\
    \        return a - sz;\n    }\n\n    // check(seg.query(b, i))\u3092\u6E80\u305F\
    \u3059\u6700\u5C0F\u306Eb<=i\u3092\u8FD4\u3059.\u306A\u3051\u308C\u3070-1\n  \
    \  template <typename C>\n    int find_first(int a, const C& check) {\n      \
    \  Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L, seg[1])))\
    \ return find_subtree(1, check, L, false);\n            return -1;\n        }\n\
    \        int b = sz;\n        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)\
    \ {\n            if (a & 1) {\n                Monoid nxt = f(L, seg[a]);\n  \
    \              if (check(nxt)) return find_subtree(a, check, L, false);\n    \
    \            L = nxt;\n                ++a;\n            }\n        }\n      \
    \  return -1;\n    }\n\n    // check(seg.query(i, b))\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ei<b\u3092\u8FD4\u3059.\u306A\u3051\u308C\u3070-1\n    template <typename\
    \ C>\n    int find_last(int b, const C& check) {\n        Monoid R = M1;\n   \
    \     if (b >= sz) {\n            if (check(f(seg[1], R))) return find_subtree(1,\
    \ check, R, true);\n            return -1;\n        }\n        int a = sz;\n \
    \       for (b += sz; a < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n \
    \               Monoid nxt = f(seg[--b], R);\n                if (check(nxt))\
    \ return find_subtree(b, check, R, true);\n                R = nxt;\n        \
    \    }\n        }\n        return -1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/segtree/SegmentTree.cpp
  requiredBy: []
  timestamp: '2021-04-04 20:39:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki-650.test.cpp
documentation_of: library/structure/segtree/SegmentTree.cpp
layout: document
redirect_from:
- /library/library/structure/segtree/SegmentTree.cpp
- /library/library/structure/segtree/SegmentTree.cpp.html
title: Segment Tree
---
