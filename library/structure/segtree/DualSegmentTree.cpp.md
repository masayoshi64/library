---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/range_arithmetic_progression_add.test.cpp
    title: verify/range_arithmetic_progression_add.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/structure/segtree/DualSegmentTree.cpp\"\ntemplate\
    \ <typename OperatorMonoid>\nstruct DualSegmentTree {\n    int sz, height;\n \
    \   vector<OperatorMonoid> lazy;\n    using H = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n    const H h;\n    const OperatorMonoid OM0;\n\n    DualSegmentTree(int\
    \ n, const H h, const OperatorMonoid& OM0)\n        : h(h), OM0(OM0) {\n     \
    \   sz = 1;\n        height = 0;\n        while (sz < n) sz <<= 1, height++;\n\
    \        lazy.assign(2 * sz, OM0);\n    }\n\n    inline void propagate(int k)\
    \ {\n        if (lazy[k] != OM0) {\n            lazy[2 * k + 0] = h(lazy[2 * k\
    \ + 0], lazy[k]);\n            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\
    \            lazy[k] = OM0;\n        }\n    }\n\n    inline void thrust(int k)\
    \ {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n  \
    \  void update(int a, int b, const OperatorMonoid& x) {\n        thrust(a += sz);\n\
    \        thrust(b += sz - 1);\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n      \
    \      if (r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n    }\n\n    OperatorMonoid\
    \ operator[](int k) {\n        thrust(k += sz);\n        return lazy[k];\n   \
    \ }\n};\n\ntemplate <class T, class F = T>\nT myreplace(T x, F y) {\n    if (y\
    \ != numeric_limits<F>::max()) x = y;\n    return x;\n}\n\ntemplate <class T>\n\
    struct RRQ : DualSegmentTree<T> {\n    using Seg = DualSegmentTree<T>;\n    RRQ(int\
    \ n) : Seg(n, myreplace<T>, numeric_limits<T>::max()) {}\n};\n"
  code: "template <typename OperatorMonoid>\nstruct DualSegmentTree {\n    int sz,\
    \ height;\n    vector<OperatorMonoid> lazy;\n    using H = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n    const H h;\n    const OperatorMonoid OM0;\n\n    DualSegmentTree(int\
    \ n, const H h, const OperatorMonoid& OM0)\n        : h(h), OM0(OM0) {\n     \
    \   sz = 1;\n        height = 0;\n        while (sz < n) sz <<= 1, height++;\n\
    \        lazy.assign(2 * sz, OM0);\n    }\n\n    inline void propagate(int k)\
    \ {\n        if (lazy[k] != OM0) {\n            lazy[2 * k + 0] = h(lazy[2 * k\
    \ + 0], lazy[k]);\n            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\
    \            lazy[k] = OM0;\n        }\n    }\n\n    inline void thrust(int k)\
    \ {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n  \
    \  void update(int a, int b, const OperatorMonoid& x) {\n        thrust(a += sz);\n\
    \        thrust(b += sz - 1);\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n      \
    \      if (r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n    }\n\n    OperatorMonoid\
    \ operator[](int k) {\n        thrust(k += sz);\n        return lazy[k];\n   \
    \ }\n};\n\ntemplate <class T, class F = T>\nT myreplace(T x, F y) {\n    if (y\
    \ != numeric_limits<F>::max()) x = y;\n    return x;\n}\n\ntemplate <class T>\n\
    struct RRQ : DualSegmentTree<T> {\n    using Seg = DualSegmentTree<T>;\n    RRQ(int\
    \ n) : Seg(n, myreplace<T>, numeric_limits<T>::max()) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/segtree/DualSegmentTree.cpp
  requiredBy: []
  timestamp: '2021-01-02 17:35:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/range_arithmetic_progression_add.test.cpp
documentation_of: library/structure/segtree/DualSegmentTree.cpp
layout: document
redirect_from:
- /library/library/structure/segtree/DualSegmentTree.cpp
- /library/library/structure/segtree/DualSegmentTree.cpp.html
title: library/structure/segtree/DualSegmentTree.cpp
---
