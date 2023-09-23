---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/structure/wavelet/WaveletMatrix.cpp
    title: library/structure/wavelet/WaveletMatrix.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/yosupo-range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 2 \"library/template/template.cpp\"\
    \n/* #region header */\n#pragma GCC optimize(\"Ofast\")\n#include <bits/stdc++.h>\n\
    using namespace std;\n// types\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\ntypedef pair<ll, ll> Pl;\ntypedef pair<int,\
    \ int> Pi;\ntypedef vector<ll> vl;\ntypedef vector<int> vi;\ntypedef vector<char>\
    \ vc;\ntemplate <typename T>\nusing mat = vector<vector<T>>;\ntypedef vector<vector<int>>\
    \ vvi;\ntypedef vector<vector<long long>> vvl;\ntypedef vector<vector<char>> vvc;\n\
    // abreviations\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define rep_(i, a_, b_, a, b, ...) for (ll i = (a), max_i = (b);\
    \ i < max_i; i++)\n#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n\
    #define rrep_(i, a_, b_, a, b, ...) \\\n    for (ll i = (b - 1), min_i = (a);\
    \ i >= min_i; i--)\n#define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0,\
    \ __VA_ARGS__)\n#define srep(i, a, b, c) for (ll i = (a), max_i = (b); i < max_i;\
    \ i += c)\n#define SZ(x) ((int)(x).size())\n#define pb(x) push_back(x)\n#define\
    \ eb(x) emplace_back(x)\n#define mp make_pair\n//\u5165\u51FA\u529B\n#define print(x)\
    \ cout << x << endl\ntemplate <class T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v)\n{\n    for (auto &e : v)\n        cout << e << \" \";\n    cout\
    \ << endl;\n    return os;\n}\nvoid scan(int &a) { cin >> a; }\nvoid scan(long\
    \ long &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double &a)\
    \ { cin >> a; }\nvoid scan(string &a) { cin >> a; }\ntemplate <class T>\nvoid\
    \ scan(vector<T> &a)\n{\n    for (auto &i : a)\n        scan(i);\n}\n#define vsum(x)\
    \ accumulate(all(x), 0LL)\n#define vmax(a) *max_element(all(a))\n#define vmin(a)\
    \ *min_element(all(a))\n#define lb(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n//\
    \ functions\n// gcd(0, x) fails.\nll gcd(ll a, ll b) { return b ? gcd(b, a % b)\
    \ : a; }\nll lcm(ll a, ll b) { return a / gcd(a, b) * b; }\ntemplate <class T>\n\
    bool chmax(T &a, const T &b)\n{\n    if (a < b)\n    {\n        a = b;\n     \
    \   return 1;\n    }\n    return 0;\n}\ntemplate <class T>\nbool chmin(T &a, const\
    \ T &b)\n{\n    if (b < a)\n    {\n        a = b;\n        return 1;\n    }\n\
    \    return 0;\n}\ntemplate <typename T>\nT mypow(T x, ll n)\n{\n    T ret = 1;\n\
    \    while (n > 0)\n    {\n        if (n & 1)\n            (ret *= x);\n     \
    \   (x *= x);\n        n >>= 1;\n    }\n    return ret;\n}\nll modpow(ll x, ll\
    \ n, const ll mod)\n{\n    ll ret = 1;\n    while (n > 0)\n    {\n        if (n\
    \ & 1)\n            (ret *= x);\n        (x *= x);\n        n >>= 1;\n       \
    \ x %= mod;\n        ret %= mod;\n    }\n    return ret;\n}\nll safemod(ll x,\
    \ ll mod) { return (x % mod + mod) % mod; }\nint popcnt(ull x) { return __builtin_popcountll(x);\
    \ }\ntemplate <typename T>\nvector<int> IOTA(vector<T> a)\n{\n    int n = a.size();\n\
    \    vector<int> id(n);\n    iota(all(id), 0);\n    sort(all(id), [&](int i, int\
    \ j)\n         { return a[i] < a[j]; });\n    return id;\n}\nlong long xor64(long\
    \ long range) {\n    static uint64_t x = 88172645463325252ULL;\n    x ^= x <<\
    \ 13;\n    x ^= x >> 7;\n    return (x ^= x << 17) % range;\n}\nstruct Timer\n\
    {\n    clock_t start_time;\n    void start() { start_time = clock(); }\n    int\
    \ lap()\n    {\n        // return x ms.\n        return (clock() - start_time)\
    \ * 1000 / CLOCKS_PER_SEC;\n    }\n};\ntemplate <typename T = int>\nstruct Edge\n\
    {\n    int from, to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n \
    \   Edge(int from, int to, T cost = 1, int idx = -1)\n        : from(from), to(to),\
    \ cost(cost), idx(idx) {}\n\n    operator int() const { return to; }\n};\n\ntemplate\
    \ <typename T = int>\nstruct Graph\n{\n    vector<vector<Edge<T>>> g;\n    int\
    \ es;\n\n    Graph() = default;\n\n    explicit Graph(int n) : g(n), es(0) {}\n\
    \n    size_t size() const { return g.size(); }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1)\n    {\n        g[from].emplace_back(from, to, cost,\
    \ es++);\n    }\n\n    void add_edge(int from, int to, T cost = 1)\n    {\n  \
    \      g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n\n    void read(int M, int padding = -1, bool weighted\
    \ = false,\n              bool directed = false)\n    {\n        for (int i =\
    \ 0; i < M; i++)\n        {\n            int a, b;\n            cin >> a >> b;\n\
    \            a += padding;\n            b += padding;\n            T c = T(1);\n\
    \            if (weighted)\n                cin >> c;\n            if (directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n};\n\n/* #endregion*/\n// constant\n\
    #define inf 1000000000ll\n#define INF 4000000004000000000LL\n#define endl '\\\
    n'\nconst long double eps = 0.000000000000001;\nconst long double PI = 3.141592653589793;\n\
    #line 3 \"verify/yosupo-range_kth_smallest.test.cpp\"\n// library\n#line 1 \"\
    library/structure/wavelet/WaveletMatrix.cpp\"\nstruct SuccinctIndexableDictionary\
    \ {\n    size_t length;\n    size_t blocks;\n    vector<unsigned> bit, sum;\n\n\
    \    SuccinctIndexableDictionary() = default;\n\n    SuccinctIndexableDictionary(size_t\
    \ length)\n        : length(length), blocks((length + 31) >> 5) {\n        bit.assign(blocks,\
    \ 0U);\n        sum.assign(blocks, 0U);\n    }\n\n    void set(int k) { bit[k\
    \ >> 5] |= 1U << (k & 31); }\n\n    void build() {\n        sum[0] = 0U;\n   \
    \     for (int i = 1; i < blocks; i++) {\n            sum[i] = sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\n        }\n    }\n\n    bool operator[](int k) { return (bool((bit[k\
    \ >> 5] >> (k & 31)) & 1)); }\n\n    int rank(int k) {\n        return (sum[k\
    \ >> 5] +\n                __builtin_popcount(bit[k >> 5] & ((1U << (k & 31))\
    \ - 1)));\n    }\n\n    int rank(bool val, int k) { return (val ? rank(k) : k\
    \ - rank(k)); }\n};\ntemplate <typename T, int MAXLOG>\nstruct WaveletMatrix {\n\
    \    size_t length;\n    SuccinctIndexableDictionary matrix[MAXLOG];\n    int\
    \ mid[MAXLOG];\n\n    WaveletMatrix() = default;\n\n    WaveletMatrix(vector<T>\
    \ v) : length(v.size()) {\n        vector<T> l(length), r(length);\n        for\
    \ (int level = MAXLOG - 1; level >= 0; level--) {\n            matrix[level] =\
    \ SuccinctIndexableDictionary(length + 1);\n            int left = 0, right =\
    \ 0;\n            for (int i = 0; i < length; i++) {\n                if (((v[i]\
    \ >> level) & 1)) {\n                    matrix[level].set(i);\n             \
    \       r[right++] = v[i];\n                } else {\n                    l[left++]\
    \ = v[i];\n                }\n            }\n            mid[level] = left;\n\
    \            matrix[level].build();\n            v.swap(l);\n            for (int\
    \ i = 0; i < right; i++) {\n                v[left + i] = r[i];\n            }\n\
    \        }\n    }\n\n    pair<int, int> succ(bool f, int l, int r, int level)\
    \ {\n        return {matrix[level].rank(f, l) + mid[level] * f,\n            \
    \    matrix[level].rank(f, r) + mid[level] * f};\n    }\n\n    // v[k]\n    T\
    \ access(int k) {\n        T ret = 0;\n        for (int level = MAXLOG - 1; level\
    \ >= 0; level--) {\n            bool f = matrix[level][k];\n            if (f)\
    \ ret |= T(1) << level;\n            k = matrix[level].rank(f, k) + mid[level]\
    \ * f;\n        }\n        return ret;\n    }\n\n    T operator[](const int &k)\
    \ { return access(k); }\n\n    // count i s.t. (0 <= i < r) && v[i] == x\n   \
    \ int rank(const T &x, int r) {\n        int l = 0;\n        for (int level =\
    \ MAXLOG - 1; level >= 0; level--) {\n            tie(l, r) = succ((x >> level)\
    \ & 1, l, r, level);\n        }\n        return r - l;\n    }\n\n    // k-th(0-indexed)\
    \ smallest number in v[l,r)\n    T kth_smallest(int l, int r, int k) {\n     \
    \   assert(0 <= k && k < r - l);\n        T ret = 0;\n        for (int level =\
    \ MAXLOG - 1; level >= 0; level--) {\n            int cnt =\n                matrix[level].rank(false,\
    \ r) - matrix[level].rank(false, l);\n            bool f = cnt <= k;\n       \
    \     if (f) {\n                ret |= T(1) << level;\n                k -= cnt;\n\
    \            }\n            tie(l, r) = succ(f, l, r, level);\n        }\n   \
    \     return ret;\n    }\n\n    // k-th(0-indexed) largest number in v[l,r)\n\
    \    T kth_largest(int l, int r, int k) {\n        return kth_smallest(l, r, r\
    \ - l - k - 1);\n    }\n\n    // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \    int range_freq(int l, int r, T upper) {\n        int ret = 0;\n        for\
    \ (int level = MAXLOG - 1; level >= 0; level--) {\n            bool f = ((upper\
    \ >> level) & 1);\n            if (f)\n                ret +=\n              \
    \      matrix[level].rank(false, r) - matrix[level].rank(false, l);\n        \
    \    tie(l, r) = succ(f, l, r, level);\n        }\n        return ret;\n    }\n\
    \n    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)\n    int range_freq(int\
    \ l, int r, T lower, T upper) {\n        return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\n    }\n\n    // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n \
    \   T prev_value(int l, int r, T upper) {\n        int cnt = range_freq(l, r,\
    \ upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n  \
    \  }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n    T next_value(int\
    \ l, int r, T lower) {\n        int cnt = range_freq(l, r, lower);\n        return\
    \ cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n    }\n};\n#line 5 \"verify/yosupo-range_kth_smallest.test.cpp\"\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    vl a(n);\n    scan(a);\n\
    \    WaveletMatrix<ll, 32> wm(a);\n    rep(_, q) {\n        int l, r, k;\n   \
    \     cin >> l >> r >> k;\n        print(wm.kth_smallest(l, r, k));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"library/template/template.cpp\"\n// library\n#include \"library/structure/wavelet/WaveletMatrix.cpp\"\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    vl a(n);\n    scan(a);\n\
    \    WaveletMatrix<ll, 32> wm(a);\n    rep(_, q) {\n        int l, r, k;\n   \
    \     cin >> l >> r >> k;\n        print(wm.kth_smallest(l, r, k));\n    }\n}"
  dependsOn:
  - library/template/template.cpp
  - library/structure/wavelet/WaveletMatrix.cpp
  isVerificationFile: true
  path: verify/yosupo-range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2023-09-23 21:29:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-range_kth_smallest.test.cpp
- /verify/verify/yosupo-range_kth_smallest.test.cpp.html
title: verify/yosupo-range_kth_smallest.test.cpp
---
