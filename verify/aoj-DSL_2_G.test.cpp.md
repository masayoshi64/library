---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/structure/segtree/LazySegmentTree.cpp
    title: "Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"verify/aoj-DSL_2_G.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\n\n#line 1\
    \ \"library/template/template.cpp\"\n/* #region header */\n\n#pragma GCC optimize(\"\
    Ofast\")\n#include <bits/stdc++.h>\nusing namespace std;\n// types\nusing ll =\
    \ long long;\nusing ull = unsigned long long;\nusing ld = long double;\ntypedef\
    \ pair<ll, ll> Pl;\ntypedef pair<int, int> Pi;\ntypedef vector<ll> vl;\ntypedef\
    \ vector<int> vi;\ntypedef vector<char> vc;\ntemplate <typename T>\nusing mat\
    \ = vector<vector<T>>;\ntypedef vector<vector<int>> vvi;\ntypedef vector<vector<long\
    \ long>> vvl;\ntypedef vector<vector<char>> vvc;\n// abreviations\n#define all(x)\
    \ (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define rep_(i,\
    \ a_, b_, a, b, ...) for (ll i = (a), max_i = (b); i < max_i; i++)\n#define rep(i,\
    \ ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n#define rrep_(i, a_,\
    \ b_, a, b, ...) \\\n    for (ll i = (b - 1), min_i = (a); i >= min_i; i--)\n\
    #define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n#define\
    \ srep(i, a, b, c) for (ll i = (a), max_i = (b); i < max_i; i += c)\n#define SZ(x)\
    \ ((int)(x).size())\n#define pb(x) push_back(x)\n#define eb(x) emplace_back(x)\n\
    #define mp make_pair\n//\u5165\u51FA\u529B\n#define print(x) cout << x << endl\n\
    template <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n \
    \   for (auto& e : v) cout << e << \" \";\n    cout << endl;\n    return os;\n\
    }\nvoid scan(int& a) { cin >> a; }\nvoid scan(long long& a) { cin >> a; }\nvoid\
    \ scan(char& a) { cin >> a; }\nvoid scan(double& a) { cin >> a; }\nvoid scan(string&\
    \ a) { cin >> a; }\ntemplate <class T>\nvoid scan(vector<T>& a) {\n    for (auto&\
    \ i : a) scan(i);\n}\n#define vsum(x) accumulate(all(x), 0LL)\n#define vmax(a)\
    \ *max_element(all(a))\n#define vmin(a) *min_element(all(a))\n#define lb(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define ub(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n// functions\n// gcd(0, x) fails.\nll gcd(ll a, ll\
    \ b) { return b ? gcd(b, a % b) : a; }\nll lcm(ll a, ll b) { return a / gcd(a,\
    \ b) * b; }\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n    if (a < b)\
    \ {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <class\
    \ T>\nbool chmin(T& a, const T& b) {\n    if (b < a) {\n        a = b;\n     \
    \   return 1;\n    }\n    return 0;\n}\ntemplate <typename T>\nT mypow(T x, ll\
    \ n) {\n    T ret = 1;\n    while (n > 0) {\n        if (n & 1) (ret *= x);\n\
    \        (x *= x);\n        n >>= 1;\n    }\n    return ret;\n}\nll modpow(ll\
    \ x, ll n, const ll mod) {\n    ll ret = 1;\n    while (n > 0) {\n        if (n\
    \ & 1) (ret *= x);\n        (x *= x);\n        n >>= 1;\n        x %= mod;\n \
    \       ret %= mod;\n    }\n    return ret;\n}\n\nuint64_t my_rand(void) {\n \
    \   static uint64_t x = 88172645463325252ULL;\n    x = x ^ (x << 13);\n    x =\
    \ x ^ (x >> 7);\n    return x = x ^ (x << 17);\n}\nint popcnt(ull x) { return\
    \ __builtin_popcountll(x); }\n// graph template\ntemplate <typename T>\nstruct\
    \ edge {\n    int src, to;\n    T cost;\n\n    edge(int to, T cost) : src(-1),\
    \ to(to), cost(cost) {}\n\n    edge(int src, int to, T cost) : src(src), to(to),\
    \ cost(cost) {}\n\n    edge& operator=(const int& x) {\n        to = x;\n    \
    \    return *this;\n    }\n\n    bool operator<(const edge<T>& r) const { return\
    \ cost < r.cost; }\n\n    operator int() const { return to; }\n};\ntemplate <typename\
    \ T>\nusing Edges = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph\
    \ = vector<Edges<T>>;\nusing UnWeightedGraph = vector<vector<int>>;\nstruct Timer\
    \ {\n    clock_t start_time;\n    void start() { start_time = clock(); }\n   \
    \ int lap() {\n        // return x ms.\n        return (clock() - start_time)\
    \ * 1000 / CLOCKS_PER_SEC;\n    }\n};\n/* #endregion*/\n// constant\n#define inf\
    \ 1000000000ll\n#define INF 4000000004000000000LL\n#define endl '\\n'\nconst long\
    \ double eps = 0.000000000000001;\nconst long double PI = 3.141592653589793;\n\
    \ntemplate <typename T>\nvector<int> IOTA(vector<T> a) {\n    int n = a.size();\n\
    \    vector<int> id(n);\n    iota(all(id), 0);\n    sort(all(id), [&](int i, int\
    \ j) { return a[i] < a[j]; });\n    return id;\n}\n#line 5 \"verify/aoj-DSL_2_G.test.cpp\"\
    \n// library\n#line 1 \"library/structure/segtree/LazySegmentTree.cpp\"\n/**\n\
    \ * @brief Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\
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
    \  T sum(int l, int r) { return this->query(l, r).val; }\n};\ntemplate <class\
    \ T>\nstruct RSRRQ : LazySegmentTree<segobj<T>, T> {\n    using Seg = LazySegmentTree<segobj<T>,\
    \ T>;\n    using obj = segobj<T>;\n    RSRRQ(int n)\n        : Seg(n, plus<obj>(),\
    \ myreplace<obj, T>, myreplace<T>, segobj<T>(),\n              numeric_limits<T>::max())\
    \ {\n        rep(i, n) this->set(i, segobj<T>(0, 1));\n        this->build();\n\
    \    }\n    T sum(int l, int r) { return this->query(l, r).val; }\n};\n#line 7\
    \ \"verify/aoj-DSL_2_G.test.cpp\"\nint main() {\n    int n, q;\n    cin >> n >>\
    \ q;\n    RSRAQ<ll> seg(n);\n    rep(i, q) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int s, t, x;\n            cin >> s >> t >>\
    \ x;\n            s--;\n            seg.update(s, t, x);\n        } else {\n \
    \           int s, t;\n            cin >> s >> t;\n            s--;\n        \
    \    print(seg.query(s, t));\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/structure/segtree/LazySegmentTree.cpp\"\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    RSRAQ<ll> seg(n);\n   \
    \ rep(i, q) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n    \
    \        int s, t, x;\n            cin >> s >> t >> x;\n            s--;\n   \
    \         seg.update(s, t, x);\n        } else {\n            int s, t;\n    \
    \        cin >> s >> t;\n            s--;\n            print(seg.query(s, t));\n\
    \        }\n    }\n}"
  dependsOn:
  - library/template/template.cpp
  - library/structure/segtree/LazySegmentTree.cpp
  isVerificationFile: true
  path: verify/aoj-DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 20:04:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-DSL_2_G.test.cpp
- /verify/verify/aoj-DSL_2_G.test.cpp.html
title: verify/aoj-DSL_2_G.test.cpp
---
