---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/structure/segtree/DualSegmentTree.cpp
    title: library/structure/segtree/DualSegmentTree.cpp
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165
  bundledCode: "#line 1 \"verify/range_arithmetic_progression_add.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165\"\n\n\
    #line 1 \"library/template/template.cpp\"\n/* #region header */\n\n#pragma GCC\
    \ optimize(\"Ofast\")\n#include <bits/stdc++.h>\nusing namespace std;\n// types\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    typedef pair<ll, ll> Pl;\ntypedef pair<int, int> Pi;\ntypedef vector<ll> vl;\n\
    typedef vector<int> vi;\ntypedef vector<char> vc;\ntemplate <typename T>\nusing\
    \ mat = vector<vector<T>>;\ntypedef vector<vector<int>> vvi;\ntypedef vector<vector<long\
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
    \       ret %= mod;\n    }\n    return ret;\n}\nll safemod(ll x, ll mod) { return\
    \ (x % mod + mod) % mod; }\nuint64_t my_rand(void) {\n    static uint64_t x =\
    \ 88172645463325252ULL;\n    x = x ^ (x << 13);\n    x = x ^ (x >> 7);\n    return\
    \ x = x ^ (x << 17);\n}\nint popcnt(ull x) { return __builtin_popcountll(x); }\n\
    template <typename T>\nvector<int> IOTA(vector<T> a) {\n    int n = a.size();\n\
    \    vector<int> id(n);\n    iota(all(id), 0);\n    sort(all(id), [&](int i, int\
    \ j) { return a[i] < a[j]; });\n    return id;\n}\nstruct Timer {\n    clock_t\
    \ start_time;\n    void start() { start_time = clock(); }\n    int lap() {\n \
    \       // return x ms.\n        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;\n\
    \    }\n};\ntemplate <typename T = int>\nstruct Edge {\n    int from, to;\n  \
    \  T cost;\n    int idx;\n\n    Edge() = default;\n\n    Edge(int from, int to,\
    \ T cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n\n    operator int() const { return to; }\n};\n\ntemplate <typename T =\
    \ int>\nstruct Graph {\n    vector<vector<Edge<T>>> g;\n    int es;\n\n    Graph()\
    \ = default;\n\n    explicit Graph(int n) : g(n), es(0) {}\n\n    size_t size()\
    \ const { return g.size(); }\n\n    void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\n\
    \    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int a, b;\n            cin >> a >> b;\n            a += padding;\n        \
    \    b += padding;\n            T c = T(1);\n            if (weighted) cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(a, b, c);\n\
    \            else\n                add_edge(a, b, c);\n        }\n    }\n};\n\n\
    /* #endregion*/\n// constant\n#define inf 1000000000ll\n#define INF 4000000004000000000LL\n\
    #define endl '\\n'\nconst long double eps = 0.000000000000001;\nconst long double\
    \ PI = 3.141592653589793;\n#line 4 \"verify/range_arithmetic_progression_add.test.cpp\"\
    \n// library\n#line 1 \"library/structure/segtree/DualSegmentTree.cpp\"\ntemplate\
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
    \ n) : Seg(n, myreplace<T>, numeric_limits<T>::max()) {}\n};\n#line 6 \"verify/range_arithmetic_progression_add.test.cpp\"\
    \n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n\n    auto h = [&](Pl p, Pl\
    \ q) {\n        return mp(p.first + q.first, p.second + q.second);\n    };\n \
    \   auto dp = DualSegmentTree<Pl>(n, h, mp(0, 0));\n\n    rep(i, q) {\n      \
    \  ll l, k;\n        cin >> l >> k;\n        l--;\n        dp.update(l, l + k,\
    \ mp(1 - l, 1));\n    }\n    rep(i, n - 1) cout << dp[i].first + dp[i].second\
    \ * i << ' ';\n    cout << dp[n - 1].first + dp[n - 1].second * (n - 1) << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/structure/segtree/DualSegmentTree.cpp\"\
    \n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n\n    auto h = [&](Pl p, Pl\
    \ q) {\n        return mp(p.first + q.first, p.second + q.second);\n    };\n \
    \   auto dp = DualSegmentTree<Pl>(n, h, mp(0, 0));\n\n    rep(i, q) {\n      \
    \  ll l, k;\n        cin >> l >> k;\n        l--;\n        dp.update(l, l + k,\
    \ mp(1 - l, 1));\n    }\n    rep(i, n - 1) cout << dp[i].first + dp[i].second\
    \ * i << ' ';\n    cout << dp[n - 1].first + dp[n - 1].second * (n - 1) << endl;\n\
    }"
  dependsOn:
  - library/template/template.cpp
  - library/structure/segtree/DualSegmentTree.cpp
  isVerificationFile: true
  path: verify/range_arithmetic_progression_add.test.cpp
  requiredBy: []
  timestamp: '2021-02-18 11:48:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/range_arithmetic_progression_add.test.cpp
layout: document
redirect_from:
- /verify/verify/range_arithmetic_progression_add.test.cpp
- /verify/verify/range_arithmetic_progression_add.test.cpp.html
title: verify/range_arithmetic_progression_add.test.cpp
---
