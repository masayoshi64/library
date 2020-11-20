---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/StronglyConnectedComponents.cpp
    title: library/graph/connected-components/StronglyConnectedComponents.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/TwoSat.cpp
    title: library/graph/connected-components/TwoSat.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/graph-template.cpp
    title: library/graph/graph-template.cpp
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/yosupo-two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
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
    \ntemplate <typename T>\nvector<int> IOTA(vector<T> a) {\n    int n = a.size();\n\
    \    vector<int> id(n);\n    iota(all(id), 0);\n    sort(all(id), [&](int i, int\
    \ j) { return a[i] < a[j]; });\n    return id;\n}\n#line 3 \"verify/yosupo-two_sat.test.cpp\"\
    \n// library\n#line 1 \"library/graph/graph-template.cpp\"\ntemplate <typename\
    \ T = int>\nstruct Edge {\n    int from, to;\n    T cost;\n    int idx;\n\n  \
    \  Edge() = default;\n\n    Edge(int from, int to, T cost = 1, int idx = -1)\n\
    \        : from(from), to(to), cost(cost), idx(idx) {}\n\n    operator int() const\
    \ { return to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T>\
    \ > > g;\n    int es;\n\n    Graph() = default;\n\n    explicit Graph(int n) :\
    \ g(n), es(0) {}\n\n    size_t size() const { return g.size(); }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int a, b;\n            cin >> a >> b;\n            a += padding;\n        \
    \    b += padding;\n            T c = T(1);\n            if (weighted) cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(a, b, c);\n\
    \            else\n                add_edge(a, b, c);\n        }\n    }\n};\n\
    #line 2 \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n\ntemplate <typename T = int>\nstruct StronglyConnectedComponents : Graph<T>\
    \ {\n   public:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int>\
    \ comp;\n    Graph<T> dag;\n    vector<vector<int> > group;\n\n    void build()\
    \ {\n        rg = Graph<T>(g.size());\n        for (int i = 0; i < g.size(); i++)\
    \ {\n            for (auto &e : g[i]) {\n                rg.add_directed_edge(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        comp.assign(g.size(), -1);\n\
    \        used.assign(g.size(), 0);\n        for (int i = 0; i < g.size(); i++)\
    \ dfs(i);\n        reverse(begin(order), end(order));\n        int ptr = 0;\n\
    \        for (int i : order)\n            if (comp[i] == -1) rdfs(i, ptr), ptr++;\n\
    \        dag = Graph<T>(ptr);\n        for (int i = 0; i < g.size(); i++) {\n\
    \            for (auto &e : g[i]) {\n                int x = comp[e.from], y =\
    \ comp[e.to];\n                if (x == y) continue;\n                dag.add_directed_edge(x,\
    \ y, e.cost);\n            }\n        }\n        group.resize(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++) {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n    }\n\n    int operator[](int k) const { return comp[k]; }\n\n \
    \  private:\n    vector<int> order, used;\n    Graph<T> rg;\n\n    void dfs(int\
    \ idx) {\n        if (exchange(used[idx], true)) return;\n        for (auto &to\
    \ : g[idx]) dfs(to);\n        order.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (auto &to : rg.g[idx]) rdfs(to, cnt);\n    }\n};\n#line 2 \"library/graph/connected-components/TwoSat.cpp\"\
    \n\nstruct TwoSat : StronglyConnectedComponents<bool> {\n   public:\n    using\
    \ StronglyConnectedComponents<bool>::g;\n    using StronglyConnectedComponents<bool>::comp;\n\
    \    using StronglyConnectedComponents<bool>::add_edge;\n    size_t sz;\n\n  \
    \  explicit TwoSat(size_t v)\n        : sz(v), StronglyConnectedComponents<bool>(v\
    \ + v) {}\n\n    void add_if(int u, int v) {\n        // u -> v <=> !v -> !u\n\
    \        add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n\
    \    }\n\n    void add_or(int u, int v) {\n        // u or v <=> !u -> v\n   \
    \     add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v) {\n       \
    \ // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void set_true(int\
    \ u) {\n        // u <=> !u -> u\n        add_directed_edge(rev(u), u);\n    }\n\
    \n    void set_false(int u) {\n        // !u <=> u -> !u\n        add_directed_edge(u,\
    \ rev(u));\n    }\n\n    inline int rev(int x) {\n        if (x >= sz) return\
    \ x - sz;\n        return x + sz;\n    }\n\n    vector<int> solve() {\n      \
    \  StronglyConnectedComponents<bool>::build();\n        vector<int> ret(sz);\n\
    \        for (int i = 0; i < sz; i++) {\n            if (comp[i] == comp[rev(i)])\
    \ return {};\n            ret[i] = comp[i] > comp[rev(i)];\n        }\n      \
    \  return ret;\n    }\n};\n#line 5 \"verify/yosupo-two_sat.test.cpp\"\nint main()\
    \ {\n    string p, cnf;\n    int n, m;\n    cin >> p >> cnf >> n >> m;\n    TwoSat\
    \ ts(n);\n    rep(i, m) {\n        int u, v, z;\n        cin >> u >> v >> z;\n\
    \        if (u < 0)\n            u = ts.rev(-u - 1);\n        else\n         \
    \   u--;\n        if (v < 0)\n            v = ts.rev(-v - 1);\n        else\n\
    \            v--;\n        ts.add_or(u, v);\n    }\n    auto ret = ts.solve();\n\
    \    if (ret.size()) {\n        cout << \"s SATISFIABLE\" << endl;\n        cout\
    \ << \"v \";\n        rep(i, n) cout << (ret[i] ? i + 1 : -i - 1) << ' ';\n  \
    \      cout << 0 << ' ' << endl;\n    } else {\n        cout << \"s UNSATISFIABLE\"\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    library/template/template.cpp\"\n// library\n#include \"library/graph/connected-components/TwoSat.cpp\"\
    \nint main() {\n    string p, cnf;\n    int n, m;\n    cin >> p >> cnf >> n >>\
    \ m;\n    TwoSat ts(n);\n    rep(i, m) {\n        int u, v, z;\n        cin >>\
    \ u >> v >> z;\n        if (u < 0)\n            u = ts.rev(-u - 1);\n        else\n\
    \            u--;\n        if (v < 0)\n            v = ts.rev(-v - 1);\n     \
    \   else\n            v--;\n        ts.add_or(u, v);\n    }\n    auto ret = ts.solve();\n\
    \    if (ret.size()) {\n        cout << \"s SATISFIABLE\" << endl;\n        cout\
    \ << \"v \";\n        rep(i, n) cout << (ret[i] ? i + 1 : -i - 1) << ' ';\n  \
    \      cout << 0 << ' ' << endl;\n    } else {\n        cout << \"s UNSATISFIABLE\"\
    \ << endl;\n    }\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/connected-components/TwoSat.cpp
  - library/graph/connected-components/StronglyConnectedComponents.cpp
  - library/graph/graph-template.cpp
  isVerificationFile: true
  path: verify/yosupo-two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 19:34:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-two_sat.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-two_sat.test.cpp
- /verify/verify/yosupo-two_sat.test.cpp.html
title: verify/yosupo-two_sat.test.cpp
---
