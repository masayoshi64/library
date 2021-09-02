---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/distance/TSP.cpp
    title: travelling salesman problem
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja
  bundledCode: "#line 1 \"verify/aoj-TSP.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja\"\
    \n\n#line 2 \"library/template/template.cpp\"\n/* #region header */\n#pragma GCC\
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
    template <class T>\nostream &operator<<(ostream &os, const vector<T> &v)\n{\n\
    \    for (auto &e : v)\n        cout << e << \" \";\n    cout << endl;\n    return\
    \ os;\n}\nvoid scan(int &a) { cin >> a; }\nvoid scan(long long &a) { cin >> a;\
    \ }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double &a) { cin >> a; }\nvoid\
    \ scan(string &a) { cin >> a; }\ntemplate <class T>\nvoid scan(vector<T> &a)\n\
    {\n    for (auto &i : a)\n        scan(i);\n}\n#define vsum(x) accumulate(all(x),\
    \ 0LL)\n#define vmax(a) *max_element(all(a))\n#define vmin(a) *min_element(all(a))\n\
    #define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define ub(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n// functions\n// gcd(0,\
    \ x) fails.\nll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }\nll lcm(ll a,\
    \ ll b) { return a / gcd(a, b) * b; }\ntemplate <class T>\nbool chmax(T &a, const\
    \ T &b)\n{\n    if (a < b)\n    {\n        a = b;\n        return 1;\n    }\n\
    \    return 0;\n}\ntemplate <class T>\nbool chmin(T &a, const T &b)\n{\n    if\
    \ (b < a)\n    {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    template <typename T>\nT mypow(T x, ll n)\n{\n    T ret = 1;\n    while (n > 0)\n\
    \    {\n        if (n & 1)\n            (ret *= x);\n        (x *= x);\n     \
    \   n >>= 1;\n    }\n    return ret;\n}\nll modpow(ll x, ll n, const ll mod)\n\
    {\n    ll ret = 1;\n    while (n > 0)\n    {\n        if (n & 1)\n           \
    \ (ret *= x);\n        (x *= x);\n        n >>= 1;\n        x %= mod;\n      \
    \  ret %= mod;\n    }\n    return ret;\n}\nll safemod(ll x, ll mod) { return (x\
    \ % mod + mod) % mod; }\nuint64_t my_rand(void)\n{\n    static uint64_t x = 88172645463325252ULL;\n\
    \    x = x ^ (x << 13);\n    x = x ^ (x >> 7);\n    return x = x ^ (x << 17);\n\
    }\nint popcnt(ull x) { return __builtin_popcountll(x); }\ntemplate <typename T>\n\
    vector<int> IOTA(vector<T> a)\n{\n    int n = a.size();\n    vector<int> id(n);\n\
    \    iota(all(id), 0);\n    sort(all(id), [&](int i, int j)\n         { return\
    \ a[i] < a[j]; });\n    return id;\n}\nstruct Timer\n{\n    clock_t start_time;\n\
    \    void start() { start_time = clock(); }\n    int lap()\n    {\n        //\
    \ return x ms.\n        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;\n\
    \    }\n};\ntemplate <typename T = int>\nstruct Edge\n{\n    int from, to;\n \
    \   T cost;\n    int idx;\n\n    Edge() = default;\n\n    Edge(int from, int to,\
    \ T cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n\n    operator int() const { return to; }\n};\n\ntemplate <typename T =\
    \ int>\nstruct Graph\n{\n    vector<vector<Edge<T>>> g;\n    int es;\n\n    Graph()\
    \ = default;\n\n    explicit Graph(int n) : g(n), es(0) {}\n\n    size_t size()\
    \ const { return g.size(); }\n\n    void add_directed_edge(int from, int to, T\
    \ cost = 1)\n    {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\
    \n    void add_edge(int from, int to, T cost = 1)\n    {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false)\n    {\n        for (int i = 0; i < M; i++)\n       \
    \ {\n            int a, b;\n            cin >> a >> b;\n            a += padding;\n\
    \            b += padding;\n            T c = T(1);\n            if (weighted)\n\
    \                cin >> c;\n            if (directed)\n                add_directed_edge(a,\
    \ b, c);\n            else\n                add_edge(a, b, c);\n        }\n  \
    \  }\n};\n\n/* #endregion*/\n// constant\n#define inf 1000000000ll\n#define INF\
    \ 4000000004000000000LL\n#define endl '\\n'\nconst long double eps = 0.000000000000001;\n\
    const long double PI = 3.141592653589793;\n#line 4 \"verify/aoj-TSP.test.cpp\"\
    \n// library\n#line 2 \"library/graph/distance/TSP.cpp\"\n/**\n * @brief travelling\
    \ salesman problem\n * @arg graph, start\n * @docs docs/TSP.md\n * @details cycle:\
    \ dp[all][s], path from s to t: dp[all^(1<<s)][t]\n */\ntemplate <typename T>\n\
    vector<vector<T>> TSP(Graph<T> g, int s = 0) {\n    int n = g.g.size();\n    T\
    \ TINF = numeric_limits<T>::max();\n    vector<vector<T>> dp(1 << n, vector<T>(n,\
    \ TINF / 2));\n    dp[0][s] = 0;\n    int all = (1 << n) - 1;\n    rep(visited,\
    \ all + 1) {\n        rep(pv, n) {\n            for (auto &e : g.g[pv]) {\n  \
    \              if ((visited & (1 << e.to)) == 0 || dp[visited ^ (1 << e.to)][e.from]\
    \ == TINF) continue;\n                chmin(dp[visited][e.to], dp[visited ^ (1\
    \ << e.to)][e.from] + e.cost);\n            }\n        }\n    }\n    return dp;\n\
    }\n#line 6 \"verify/aoj-TSP.test.cpp\"\nint main() {\n    int V, E;\n    cin >>\
    \ V >> E;\n    Graph<int> g(V);\n    g.read(E, 0, true, true);\n    auto dp =\
    \ TSP(g);\n    cout << (dp[(1 << V) - 1][0] < inf ? dp[(1 << V) - 1][0] : -1)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/graph/distance/TSP.cpp\"\
    \nint main() {\n    int V, E;\n    cin >> V >> E;\n    Graph<int> g(V);\n    g.read(E,\
    \ 0, true, true);\n    auto dp = TSP(g);\n    cout << (dp[(1 << V) - 1][0] < inf\
    \ ? dp[(1 << V) - 1][0] : -1) << endl;\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/distance/TSP.cpp
  isVerificationFile: true
  path: verify/aoj-TSP.test.cpp
  requiredBy: []
  timestamp: '2021-09-02 11:31:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-TSP.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-TSP.test.cpp
- /verify/verify/aoj-TSP.test.cpp.html
title: verify/aoj-TSP.test.cpp
---
