---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_G.test.cpp
    title: verify/aoj-DSL_2_G.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lazy-segment-tree.md
    document_title: "Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728)"
    links: []
  bundledCode: "#line 1 \"library/structure/segtree/LazySegmentTree.cpp\"\n/**\n *\
    \ @brief Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n * @docs docs/lazy-segment-tree.md\n */\ntemplate <typename Monoid, typename\
    \ OperatorMonoid>\nstruct LazySegmentTree {\n    int n, sz, height;\n    vector<Monoid>\
    \ data;\n    vector<OperatorMonoid> lazy;\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n    using G = function<Monoid(Monoid, OperatorMonoid)>;\n    using\
    \ H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n    const F f;\n\
    \    const G g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid\
    \ OM0;\n\n    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid&\
    \ M1,\n                    const OperatorMonoid OM0)\n        : n(n), f(f), g(g),\
    \ h(h), M1(M1), OM0(OM0) {\n        sz = 1;\n        height = 0;\n        while\
    \ (sz < n) sz <<= 1, height++;\n        data.assign(2 * sz, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n    }\n\n    void set(int k, const Monoid& x) { data[k + sz] =\
    \ x; }\n\n    void build() {\n        for (int k = sz - 1; k > 0; k--) {\n   \
    \         data[k] = f(data[2 * k + 0], data[2 * k + 1]);\n        }\n    }\n\n\
    \    inline void propagate(int k) {\n        if (lazy[k] != OM0) {\n         \
    \   lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n            lazy[2 * k + 1]\
    \ = h(lazy[2 * k + 1], lazy[k]);\n            data[k] = apply(k);\n          \
    \  lazy[k] = OM0;\n        }\n    }\n\n    inline Monoid apply(int k) {\n    \
    \    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);\n    }\n\n    inline\
    \ void recalc(int k) {\n        while (k >>= 1) data[k] = f(apply(2 * k + 0),\
    \ apply(2 * k + 1));\n    }\n\n    inline void thrust(int k) {\n        for (int\
    \ i = height; i > 0; i--) propagate(k >> i);\n    }\n\n    void update(int a,\
    \ int b, const OperatorMonoid& x) {\n        if (a >= b) return;\n        thrust(a\
    \ += sz);\n        thrust(b += sz - 1);\n        for (int l = a, r = b + 1; l\
    \ < r; l >>= 1, r >>= 1) {\n            if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n\
    \            if (r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n\n    Monoid query(int a, int b) {\n        if (a\
    \ >= b) return M1;\n        thrust(a += sz);\n        thrust(b += sz - 1);\n \
    \       Monoid L = M1, R = M1;\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) L = f(L, apply(l++));\n            if\
    \ (r & 1) R = f(apply(--r), R);\n        }\n        return f(L, R);\n    }\n\n\
    \    Monoid operator[](const int& k) { return query(k, k + 1); }\n\n    template\
    \ <typename C>\n    int find_subtree(int a, const C& check, Monoid& M, bool type)\
    \ {\n        while (a < sz) {\n            propagate(a);\n            Monoid nxt\
    \ =\n                type ? f(apply(2 * a + type), M) : f(M, apply(2 * a + type));\n\
    \            if (check(nxt))\n                a = 2 * a + type;\n            else\n\
    \                M = nxt, a = 2 * a + 1 - type;\n        }\n        return a -\
    \ sz;\n    }\n\n    template <typename C>\n    int find_first(int a, const C&\
    \ check) {\n        Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L,\
    \ apply(1)))) return find_subtree(1, check, L, false);\n            return -1;\n\
    \        }\n        thrust(a + sz);\n        int b = sz;\n        for (a += sz,\
    \ b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a & 1) {\n            \
    \    Monoid nxt = f(L, apply(a));\n                if (check(nxt)) return find_subtree(a,\
    \ check, L, false);\n                L = nxt;\n                ++a;\n        \
    \    }\n        }\n        return -1;\n    }\n\n    template <typename C>\n  \
    \  int find_last(int b, const C& check) {\n        Monoid R = M1;\n        if\
    \ (b >= sz) {\n            if (check(f(apply(1), R))) return find_subtree(1, check,\
    \ R, true);\n            return -1;\n        }\n        thrust(b + sz - 1);\n\
    \        int a = sz;\n        for (b += sz; a < b; a >>= 1, b >>= 1) {\n     \
    \       if (b & 1) {\n                Monoid nxt = f(apply(--b), R);\n       \
    \         if (check(nxt)) return find_subtree(b, check, R, true);\n          \
    \      R = nxt;\n            }\n        }\n        return -1;\n    }\n\n    void\
    \ show() {\n        rep(i, n) cout << query(i, i + 1) << ' ';\n        cout <<\
    \ endl;\n    }\n};\n\ntemplate <class T, class F = T>\nT myreplace(T x, F y) {\n\
    \    if (y != numeric_limits<F>::max()) x = y;\n    return x;\n}\ntemplate <class\
    \ T>\nT mymax(T x, T y) {\n    return max(x, y);\n}\ntemplate <class T>\nT mymin(T\
    \ x, T y) {\n    return min(x, y);\n}\ntemplate <class T, class F = T>\nT myadd(T\
    \ x, F y) {\n    return x + y;\n}\ntemplate <class T>\nstruct segobj {\n    T\
    \ val;\n    int size;\n    segobj(T x, int y) : val(x), size(y) {}\n    segobj()\
    \ : val(0), size(0) {}\n    segobj& operator+=(const segobj& p) {\n        val\
    \ += p.val;\n        size += p.size;\n        return *this;\n    }\n    segobj&\
    \ operator+=(const T& p) {\n        val += p * size;\n        return *this;\n\
    \    }\n    segobj& operator=(const T& p) {\n        val = p * size;\n       \
    \ return *this;\n    }\n    friend ostream& operator<<(ostream& os, const segobj&\
    \ p) {\n        return os << p.val;\n    }\n    segobj operator+(const segobj&\
    \ p) const { return segobj(*this) += p; }\n    segobj operator+(const T& p) const\
    \ { return segobj(*this) += p; }\n};\ntemplate <class T>\nstruct RMRRQ : LazySegmentTree<T,\
    \ T> {\n    using Seg = LazySegmentTree<T, T>;\n    RMRRQ(int n)\n        : Seg(n,\
    \ mymax<T>, myreplace<T>, myreplace<T>, numeric_limits<T>::min(),\n          \
    \    numeric_limits<T>::max()) {}\n};\ntemplate <class T>\nstruct RmRRQ : LazySegmentTree<T,\
    \ T> {\n    using Seg = LazySegmentTree<T, T>;\n    RmRRQ(int n)\n        : Seg(n,\
    \ mymin<T>, myreplace<T>, myreplace<T>, numeric_limits<T>::max(),\n          \
    \    numeric_limits<T>::max()) {}\n};\ntemplate <class T>\nstruct RMRAQ : LazySegmentTree<T,\
    \ T> {\n    using Seg = LazySegmentTree<T, T>;\n    RMRAQ(int n)\n        : Seg(n,\
    \ mymax<T>, plus<T>(), plus<T>(), numeric_limits<T>::min() / 2,\n            \
    \  T()) {}\n};\ntemplate <class T>\nstruct RmRAQ : LazySegmentTree<T, T> {\n \
    \   using Seg = LazySegmentTree<T, T>;\n    RmRAQ(int n)\n        : Seg(n, mymin<T>,\
    \ plus<T>(), plus<T>(), numeric_limits<T>::max() / 2,\n              T()) {}\n\
    };\ntemplate <class T>\nstruct RSRAQ : LazySegmentTree<segobj<T>, T> {\n    using\
    \ Seg = LazySegmentTree<segobj<T>, T>;\n    RSRAQ(int n)\n        : Seg(n, plus<segobj<T>>(),\
    \ myadd<segobj<T>, T>, plus<T>(), segobj<T>(),\n              T()) {\n       \
    \ rep(i, n) this->set(i, segobj<T>(0, 1));\n        this->build();\n    }\n  \
    \  T sum(int l, int r) { return this->query(l, r).val; }\n};\n\n// T = mint\u306E\
    \u6642\u306Fnumerical_limits<mint>::max()\u3092\u5358\u4F4D\u5143\u306E\u4EE3\u308F\
    \u308A\u306B\u3067\u304D\u306A\u3044\u306E\u3067\n// M = int\u3092\u3057\u3066\
    \u4F7F\u3046\u3002\ntemplate <class T, class M = T>\nstruct RSRRQ : LazySegmentTree<segobj<T>,\
    \ M> {\n    using Seg = LazySegmentTree<segobj<T>, M>;\n    using obj = segobj<T>;\n\
    \    RSRRQ(int n)\n        : Seg(n, plus<obj>(), myreplace<obj, M>, myreplace<M>,\
    \ segobj<T>(),\n              numeric_limits<M>::max()) {\n        rep(i, n) this->set(i,\
    \ segobj<T>(0, 1));\n        this->build();\n    }\n    T sum(int l, int r) {\
    \ return this->query(l, r).val; }\n};\n"
  code: "/**\n * @brief Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n * @docs docs/lazy-segment-tree.md\n */\ntemplate <typename\
    \ Monoid, typename OperatorMonoid>\nstruct LazySegmentTree {\n    int n, sz, height;\n\
    \    vector<Monoid> data;\n    vector<OperatorMonoid> lazy;\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n    using G = function<Monoid(Monoid, OperatorMonoid)>;\n    using\
    \ H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n    const F f;\n\
    \    const G g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid\
    \ OM0;\n\n    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid&\
    \ M1,\n                    const OperatorMonoid OM0)\n        : n(n), f(f), g(g),\
    \ h(h), M1(M1), OM0(OM0) {\n        sz = 1;\n        height = 0;\n        while\
    \ (sz < n) sz <<= 1, height++;\n        data.assign(2 * sz, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n    }\n\n    void set(int k, const Monoid& x) { data[k + sz] =\
    \ x; }\n\n    void build() {\n        for (int k = sz - 1; k > 0; k--) {\n   \
    \         data[k] = f(data[2 * k + 0], data[2 * k + 1]);\n        }\n    }\n\n\
    \    inline void propagate(int k) {\n        if (lazy[k] != OM0) {\n         \
    \   lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n            lazy[2 * k + 1]\
    \ = h(lazy[2 * k + 1], lazy[k]);\n            data[k] = apply(k);\n          \
    \  lazy[k] = OM0;\n        }\n    }\n\n    inline Monoid apply(int k) {\n    \
    \    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);\n    }\n\n    inline\
    \ void recalc(int k) {\n        while (k >>= 1) data[k] = f(apply(2 * k + 0),\
    \ apply(2 * k + 1));\n    }\n\n    inline void thrust(int k) {\n        for (int\
    \ i = height; i > 0; i--) propagate(k >> i);\n    }\n\n    void update(int a,\
    \ int b, const OperatorMonoid& x) {\n        if (a >= b) return;\n        thrust(a\
    \ += sz);\n        thrust(b += sz - 1);\n        for (int l = a, r = b + 1; l\
    \ < r; l >>= 1, r >>= 1) {\n            if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n\
    \            if (r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n\n    Monoid query(int a, int b) {\n        if (a\
    \ >= b) return M1;\n        thrust(a += sz);\n        thrust(b += sz - 1);\n \
    \       Monoid L = M1, R = M1;\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) L = f(L, apply(l++));\n            if\
    \ (r & 1) R = f(apply(--r), R);\n        }\n        return f(L, R);\n    }\n\n\
    \    Monoid operator[](const int& k) { return query(k, k + 1); }\n\n    template\
    \ <typename C>\n    int find_subtree(int a, const C& check, Monoid& M, bool type)\
    \ {\n        while (a < sz) {\n            propagate(a);\n            Monoid nxt\
    \ =\n                type ? f(apply(2 * a + type), M) : f(M, apply(2 * a + type));\n\
    \            if (check(nxt))\n                a = 2 * a + type;\n            else\n\
    \                M = nxt, a = 2 * a + 1 - type;\n        }\n        return a -\
    \ sz;\n    }\n\n    template <typename C>\n    int find_first(int a, const C&\
    \ check) {\n        Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L,\
    \ apply(1)))) return find_subtree(1, check, L, false);\n            return -1;\n\
    \        }\n        thrust(a + sz);\n        int b = sz;\n        for (a += sz,\
    \ b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a & 1) {\n            \
    \    Monoid nxt = f(L, apply(a));\n                if (check(nxt)) return find_subtree(a,\
    \ check, L, false);\n                L = nxt;\n                ++a;\n        \
    \    }\n        }\n        return -1;\n    }\n\n    template <typename C>\n  \
    \  int find_last(int b, const C& check) {\n        Monoid R = M1;\n        if\
    \ (b >= sz) {\n            if (check(f(apply(1), R))) return find_subtree(1, check,\
    \ R, true);\n            return -1;\n        }\n        thrust(b + sz - 1);\n\
    \        int a = sz;\n        for (b += sz; a < b; a >>= 1, b >>= 1) {\n     \
    \       if (b & 1) {\n                Monoid nxt = f(apply(--b), R);\n       \
    \         if (check(nxt)) return find_subtree(b, check, R, true);\n          \
    \      R = nxt;\n            }\n        }\n        return -1;\n    }\n\n    void\
    \ show() {\n        rep(i, n) cout << query(i, i + 1) << ' ';\n        cout <<\
    \ endl;\n    }\n};\n\ntemplate <class T, class F = T>\nT myreplace(T x, F y) {\n\
    \    if (y != numeric_limits<F>::max()) x = y;\n    return x;\n}\ntemplate <class\
    \ T>\nT mymax(T x, T y) {\n    return max(x, y);\n}\ntemplate <class T>\nT mymin(T\
    \ x, T y) {\n    return min(x, y);\n}\ntemplate <class T, class F = T>\nT myadd(T\
    \ x, F y) {\n    return x + y;\n}\ntemplate <class T>\nstruct segobj {\n    T\
    \ val;\n    int size;\n    segobj(T x, int y) : val(x), size(y) {}\n    segobj()\
    \ : val(0), size(0) {}\n    segobj& operator+=(const segobj& p) {\n        val\
    \ += p.val;\n        size += p.size;\n        return *this;\n    }\n    segobj&\
    \ operator+=(const T& p) {\n        val += p * size;\n        return *this;\n\
    \    }\n    segobj& operator=(const T& p) {\n        val = p * size;\n       \
    \ return *this;\n    }\n    friend ostream& operator<<(ostream& os, const segobj&\
    \ p) {\n        return os << p.val;\n    }\n    segobj operator+(const segobj&\
    \ p) const { return segobj(*this) += p; }\n    segobj operator+(const T& p) const\
    \ { return segobj(*this) += p; }\n};\ntemplate <class T>\nstruct RMRRQ : LazySegmentTree<T,\
    \ T> {\n    using Seg = LazySegmentTree<T, T>;\n    RMRRQ(int n)\n        : Seg(n,\
    \ mymax<T>, myreplace<T>, myreplace<T>, numeric_limits<T>::min(),\n          \
    \    numeric_limits<T>::max()) {}\n};\ntemplate <class T>\nstruct RmRRQ : LazySegmentTree<T,\
    \ T> {\n    using Seg = LazySegmentTree<T, T>;\n    RmRRQ(int n)\n        : Seg(n,\
    \ mymin<T>, myreplace<T>, myreplace<T>, numeric_limits<T>::max(),\n          \
    \    numeric_limits<T>::max()) {}\n};\ntemplate <class T>\nstruct RMRAQ : LazySegmentTree<T,\
    \ T> {\n    using Seg = LazySegmentTree<T, T>;\n    RMRAQ(int n)\n        : Seg(n,\
    \ mymax<T>, plus<T>(), plus<T>(), numeric_limits<T>::min() / 2,\n            \
    \  T()) {}\n};\ntemplate <class T>\nstruct RmRAQ : LazySegmentTree<T, T> {\n \
    \   using Seg = LazySegmentTree<T, T>;\n    RmRAQ(int n)\n        : Seg(n, mymin<T>,\
    \ plus<T>(), plus<T>(), numeric_limits<T>::max() / 2,\n              T()) {}\n\
    };\ntemplate <class T>\nstruct RSRAQ : LazySegmentTree<segobj<T>, T> {\n    using\
    \ Seg = LazySegmentTree<segobj<T>, T>;\n    RSRAQ(int n)\n        : Seg(n, plus<segobj<T>>(),\
    \ myadd<segobj<T>, T>, plus<T>(), segobj<T>(),\n              T()) {\n       \
    \ rep(i, n) this->set(i, segobj<T>(0, 1));\n        this->build();\n    }\n  \
    \  T sum(int l, int r) { return this->query(l, r).val; }\n};\n\n// T = mint\u306E\
    \u6642\u306Fnumerical_limits<mint>::max()\u3092\u5358\u4F4D\u5143\u306E\u4EE3\u308F\
    \u308A\u306B\u3067\u304D\u306A\u3044\u306E\u3067\n// M = int\u3092\u3057\u3066\
    \u4F7F\u3046\u3002\ntemplate <class T, class M = T>\nstruct RSRRQ : LazySegmentTree<segobj<T>,\
    \ M> {\n    using Seg = LazySegmentTree<segobj<T>, M>;\n    using obj = segobj<T>;\n\
    \    RSRRQ(int n)\n        : Seg(n, plus<obj>(), myreplace<obj, M>, myreplace<M>,\
    \ segobj<T>(),\n              numeric_limits<M>::max()) {\n        rep(i, n) this->set(i,\
    \ segobj<T>(0, 1));\n        this->build();\n    }\n    T sum(int l, int r) {\
    \ return this->query(l, r).val; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/segtree/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2020-12-15 21:38:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_2_G.test.cpp
documentation_of: library/structure/segtree/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/library/structure/segtree/LazySegmentTree.cpp
- /library/library/structure/segtree/LazySegmentTree.cpp.html
title: "Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
  )"
---
