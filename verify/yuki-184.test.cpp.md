---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/BitMatrix.cpp
    title: library/math/BitMatrix.cpp
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/184
    links:
    - https://yukicoder.me/problems/no/184
  bundledCode: "#line 1 \"verify/yuki-184.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/184\"\
    \n#line 1 \"library/template/template.cpp\"\n/* #region header */\n\n#pragma GCC\
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
    #line 3 \"verify/yuki-184.test.cpp\"\n// library\n#line 1 \"library/math/BitMatrix.cpp\"\
    \n\ntemplate <int MAX_ROW, int MAX_COL>\nstruct BitMatrix {\n    int H, W, rank;\n\
    \    vector<int> top;  // top bit\n    bitset<MAX_COL> A[MAX_ROW];\n    BitMatrix(int\
    \ h = 1, int w = 1) : H(h), W(w), rank(0) { top.resize(h); }\n    void build(bool\
    \ is_extended = false) {\n        rep(col, W) {\n            if (is_extended &&\
    \ col == W - 1) break;\n            int row = rank;\n            for (; row <\
    \ H; ++row) {\n                if (A[row][col]) {\n                    swap(A[rank],\
    \ A[row]);\n                    break;\n                }\n            }\n   \
    \         if (row == H) continue;\n            top[rank] = col;\n            rep(k,\
    \ H) {\n                if (k == rank) continue;\n                if (A[k][col])\
    \ A[k] ^= A[rank];\n            }\n            ++rank;\n        }\n    }\n   \
    \ int solve(vector<int>& res) {\n        // if it has no solution then return\
    \ -1\n        for (int row = rank; row < H; ++row)\n            if (A[row][W -\
    \ 1]) return -1;\n        res.assign(W - 1, 0);\n        for (int i = 0; i < rank;\
    \ ++i) res[i] = A[i][W - 1];\n        return rank;\n    }\n    inline bitset<MAX_COL>&\
    \ operator[](int i) { return A[i]; }\n};\n#line 5 \"verify/yuki-184.test.cpp\"\
    \nint main() {\n    int n;\n    cin >> n;\n    BitMatrix<100000, 61> bm(n, 61);\n\
    \    vl a(n);\n    scan(a);\n    rep(i, n) { bm[i] = a[i]; }\n    bm.build();\n\
    \    print(((ll)1 << bm.rank));\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/184\"\n#include \"library/template/template.cpp\"\
    \n// library\n#include \"library/math/BitMatrix.cpp\"\nint main() {\n    int n;\n\
    \    cin >> n;\n    BitMatrix<100000, 61> bm(n, 61);\n    vl a(n);\n    scan(a);\n\
    \    rep(i, n) { bm[i] = a[i]; }\n    bm.build();\n    print(((ll)1 << bm.rank));\n\
    }"
  dependsOn:
  - library/template/template.cpp
  - library/math/BitMatrix.cpp
  isVerificationFile: true
  path: verify/yuki-184.test.cpp
  requiredBy: []
  timestamp: '2020-11-19 21:50:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yuki-184.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki-184.test.cpp
- /verify/verify/yuki-184.test.cpp.html
title: verify/yuki-184.test.cpp
---
