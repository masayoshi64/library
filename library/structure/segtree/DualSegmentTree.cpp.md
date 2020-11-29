---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/dual-segment-tree.md
    document_title: "Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "#line 1 \"library/structure/segtree/DualSegmentTree.cpp\"\n/**\n *\
    \ @brief Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\
    \ * @docs docs/dual-segment-tree.md\n */\n\ntemplate <typename OperatorMonoid,\
    \ typename H>\nstruct DualSegmentTree {\n    int sz, height;\n    vector<OperatorMonoid>\
    \ lazy;\n    const H h;\n    const OperatorMonoid OM0;\n\n    DualSegmentTree(int\
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
    \ }\n};\n\ntemplate <typename OperatorMonoid, typename H>\nDualSegmentTree<OperatorMonoid,\
    \ H> get_dual_segment_tree(\n    int N, const H& h, const OperatorMonoid& OM0)\
    \ {\n    return {N, h, OM0};\n}\n"
  code: "/**\n * @brief Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n * @docs docs/dual-segment-tree.md\n */\n\ntemplate <typename OperatorMonoid,\
    \ typename H>\nstruct DualSegmentTree {\n    int sz, height;\n    vector<OperatorMonoid>\
    \ lazy;\n    const H h;\n    const OperatorMonoid OM0;\n\n    DualSegmentTree(int\
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
    \ }\n};\n\ntemplate <typename OperatorMonoid, typename H>\nDualSegmentTree<OperatorMonoid,\
    \ H> get_dual_segment_tree(\n    int N, const H& h, const OperatorMonoid& OM0)\
    \ {\n    return {N, h, OM0};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/segtree/DualSegmentTree.cpp
  requiredBy: []
  timestamp: '2020-11-29 19:14:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/structure/segtree/DualSegmentTree.cpp
layout: document
redirect_from:
- /library/library/structure/segtree/DualSegmentTree.cpp
- /library/library/structure/segtree/DualSegmentTree.cpp.html
title: "Dual-Segment-Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
