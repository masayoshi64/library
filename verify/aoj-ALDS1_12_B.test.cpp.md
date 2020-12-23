---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/distance/bfs_dial.cpp
    title: library/graph/distance/bfs_dial.cpp
  - icon: ':x:'
    path: library/graph/graph-template.cpp
    title: library/graph/graph-template.cpp
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B
  bundledCode: "#line 1 \"verify/aoj-ALDS1_12_B.test.cpp\"\n#define PROBLEM \\\n \
    \   \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\"\n\n\
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
    \ PI = 3.141592653589793;\n#line 5 \"verify/aoj-ALDS1_12_B.test.cpp\"\n//\n#line\
    \ 1 \"library/graph/graph-template.cpp\"\ntemplate <typename T = int>\nstruct\
    \ Edge {\n    int from, to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\
    \n    Edge(int from, int to, T cost = 1, int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n\n    operator int() const { return to; }\n\
    };\n\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T> >\
    \ > g;\n    int es;\n\n    Graph() = default;\n\n    explicit Graph(int n) : g(n),\
    \ es(0) {}\n\n    size_t size() const { return g.size(); }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int a, b;\n            cin >> a >> b;\n            a += padding;\n        \
    \    b += padding;\n            T c = T(1);\n            if (weighted) cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(a, b, c);\n\
    \            else\n                add_edge(a, b, c);\n        }\n    }\n};\n\
    #line 7 \"verify/aoj-ALDS1_12_B.test.cpp\"\n// library\n#line 1 \"library/graph/distance/bfs_dial.cpp\"\
    \n// Dial's algorithm\ntemplate <typename T>\nvector<T> bfs_dial(const Graph<T>\
    \ &g, int s) {\n    T max_cost = 0, max_dist = 0;\n    for (auto &es : g.g) {\n\
    \        for (auto &e : es) max_cost = max(max_cost, e.cost);\n    }\n    ++max_cost;\n\
    \    const auto TINF = numeric_limits<T>::max();\n    vector<T> dist(g.size(),\
    \ TINF);\n    vector<queue<int> > ques(max_cost + 1);\n    dist[s] = 0;\n    ques[0].emplace(s);\n\
    \    for (T cost = 0; cost <= max_dist; cost++) {\n        auto &que = ques[cost\
    \ % max_cost];\n        while (!que.empty()) {\n            int idx = que.front();\n\
    \            que.pop();\n            if (dist[idx] < cost) continue;\n       \
    \     for (auto &e : g.g[idx]) {\n                auto next_cost = cost + e.cost;\n\
    \                if (dist[e.to] <= next_cost) continue;\n                dist[e.to]\
    \ = next_cost;\n                max_dist = max(max_dist, dist[e.to]);\n      \
    \          ques[dist[e.to] % max_cost].emplace(e.to);\n            }\n       \
    \ }\n    }\n    return dist;\n}\n#line 9 \"verify/aoj-ALDS1_12_B.test.cpp\"\n\
    int main() {\n    int n;\n    cin >> n;\n    Graph g(n);\n    rep(i, n) {\n  \
    \      int u, k;\n        cin >> u >> k;\n        rep(j, k) {\n            int\
    \ v, c;\n            cin >> v >> c;\n            g.add_directed_edge(u, v, c);\n\
    \        }\n    }\n    auto dist = bfs_dial(g, 0);\n    rep(i, n) { cout << i\
    \ << ' ' << dist[i] << endl; }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\"\
    \n\n#include \"library/template/template.cpp\"\n//\n#include \"library/graph/graph-template.cpp\"\
    \n// library\n#include \"library/graph/distance/bfs_dial.cpp\"\nint main() {\n\
    \    int n;\n    cin >> n;\n    Graph g(n);\n    rep(i, n) {\n        int u, k;\n\
    \        cin >> u >> k;\n        rep(j, k) {\n            int v, c;\n        \
    \    cin >> v >> c;\n            g.add_directed_edge(u, v, c);\n        }\n  \
    \  }\n    auto dist = bfs_dial(g, 0);\n    rep(i, n) { cout << i << ' ' << dist[i]\
    \ << endl; }\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/graph-template.cpp
  - library/graph/distance/bfs_dial.cpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_12_B.test.cpp
  requiredBy: []
  timestamp: '2020-12-23 20:37:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_12_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_12_B.test.cpp
- /verify/verify/aoj-ALDS1_12_B.test.cpp.html
title: verify/aoj-ALDS1_12_B.test.cpp
---
