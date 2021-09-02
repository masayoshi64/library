---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/connected-components/StronglyConnectedComponents.cpp
    title: Strongly Connected Components
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-two_sat.test.cpp
    title: verify/yosupo-two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/TwoSat.md
    document_title: 2-SAT
    links: []
  bundledCode: "#line 2 \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n\n/**\n * @brief Strongly Connected Components\n * @arg int: type of weight\n\
    \ * @docs docs/StronglyConnectedComponents\n */\n#line 2 \"library/template/template.cpp\"\
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
    \ ll mod) { return (x % mod + mod) % mod; }\nuint64_t my_rand(void)\n{\n    static\
    \ uint64_t x = 88172645463325252ULL;\n    x = x ^ (x << 13);\n    x = x ^ (x >>\
    \ 7);\n    return x = x ^ (x << 17);\n}\nint popcnt(ull x) { return __builtin_popcountll(x);\
    \ }\ntemplate <typename T>\nvector<int> IOTA(vector<T> a)\n{\n    int n = a.size();\n\
    \    vector<int> id(n);\n    iota(all(id), 0);\n    sort(all(id), [&](int i, int\
    \ j)\n         { return a[i] < a[j]; });\n    return id;\n}\nstruct Timer\n{\n\
    \    clock_t start_time;\n    void start() { start_time = clock(); }\n    int\
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
    #line 9 \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \ntemplate <typename T = int>\nstruct StronglyConnectedComponents : Graph<T>\n\
    {\npublic:\n    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int>\
    \ comp;          // id of scc\n    Graph<T> dag;              // DAG\n    vector<vector<int>>\
    \ group; // lists of each scc\n\n    void build()\n    {\n        rg = Graph<T>(g.size());\n\
    \        // add reversed edges\n        for (int i = 0; i < g.size(); i++)\n \
    \       {\n            for (auto &e : g[i])\n            {\n                rg.add_directed_edge(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        comp.assign(g.size(), -1);\n\
    \        used.assign(g.size(), 0);\n        // dfs for (not reversed) graph\n\
    \        for (int i = 0; i < g.size(); i++)\n            dfs(i);\n        reverse(begin(order),\
    \ end(order));\n        int ptr = 0;\n        for (int i : order)\n          \
    \  if (comp[i] == -1)\n                rdfs(i, ptr), ptr++;\n        dag = Graph<T>(ptr);\n\
    \        for (int i = 0; i < g.size(); i++)\n        {\n            for (auto\
    \ &e : g[i])\n            {\n                int x = comp[e.from], y = comp[e.to];\n\
    \                if (x == y)\n                    continue;\n                dag.add_directed_edge(x,\
    \ y, e.cost);\n            }\n        }\n        group.resize(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++)\n        {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n    }\n\n    int operator[](int k) const { return comp[k]; }\n\nprivate:\n\
    \    vector<int> order, used; // order:post order\n    Graph<T> rg;          \
    \   // reversed graph\n\n    void dfs(int idx)\n    {\n        if (exchange(used[idx],\
    \ true))\n            return;\n        for (auto &to : g[idx])\n            dfs(to);\n\
    \        order.push_back(idx);\n    }\n\n    void rdfs(int idx, int cnt)\n   \
    \ {\n        if (comp[idx] != -1)\n            return;\n        comp[idx] = cnt;\n\
    \        for (auto &to : rg.g[idx])\n            rdfs(to, cnt);\n    }\n};\n#line\
    \ 2 \"library/graph/connected-components/TwoSat.cpp\"\n/**\n * @brief 2-SAT\n\
    \ * @docs docs/TwoSat.md\n */\nstruct TwoSat : StronglyConnectedComponents<bool>\n\
    {\npublic:\n    using StronglyConnectedComponents<bool>::g;\n    using StronglyConnectedComponents<bool>::comp;\n\
    \    using StronglyConnectedComponents<bool>::add_edge;\n    int sz;\n\n    explicit\
    \ TwoSat(int v)\n        : sz(v), StronglyConnectedComponents<bool>(v + v) {}\n\
    \n    void add_if(int u, int v)\n    {\n        // u -> v <=> !v -> !u\n     \
    \   add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n   \
    \ }\n\n    void add_or(int u, int v)\n    {\n        // u or v <=> !u -> v\n \
    \       add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v)\n    {\n\
    \        // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void\
    \ set_true(int u)\n    {\n        // u <=> !u -> u\n        add_directed_edge(rev(u),\
    \ u);\n    }\n\n    void set_false(int u)\n    {\n        // !u <=> u -> !u\n\
    \        add_directed_edge(u, rev(u));\n    }\n\n    inline int rev(int x)\n \
    \   {\n        if (x >= sz)\n            return x - sz;\n        return x + sz;\n\
    \    }\n\n    vector<int> solve()\n    {\n        StronglyConnectedComponents<bool>::build();\n\
    \        vector<int> ret(sz);\n        for (int i = 0; i < sz; i++)\n        {\n\
    \            if (comp[i] == comp[rev(i)])\n                return {};\n      \
    \      ret[i] = comp[i] > comp[rev(i)];\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#include \"library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n/**\n * @brief 2-SAT\n * @docs docs/TwoSat.md\n */\nstruct TwoSat : StronglyConnectedComponents<bool>\n\
    {\npublic:\n    using StronglyConnectedComponents<bool>::g;\n    using StronglyConnectedComponents<bool>::comp;\n\
    \    using StronglyConnectedComponents<bool>::add_edge;\n    int sz;\n\n    explicit\
    \ TwoSat(int v)\n        : sz(v), StronglyConnectedComponents<bool>(v + v) {}\n\
    \n    void add_if(int u, int v)\n    {\n        // u -> v <=> !v -> !u\n     \
    \   add_directed_edge(u, v);\n        add_directed_edge(rev(v), rev(u));\n   \
    \ }\n\n    void add_or(int u, int v)\n    {\n        // u or v <=> !u -> v\n \
    \       add_if(rev(u), v);\n    }\n\n    void add_nand(int u, int v)\n    {\n\
    \        // u nand v <=> u -> !v\n        add_if(u, rev(v));\n    }\n\n    void\
    \ set_true(int u)\n    {\n        // u <=> !u -> u\n        add_directed_edge(rev(u),\
    \ u);\n    }\n\n    void set_false(int u)\n    {\n        // !u <=> u -> !u\n\
    \        add_directed_edge(u, rev(u));\n    }\n\n    inline int rev(int x)\n \
    \   {\n        if (x >= sz)\n            return x - sz;\n        return x + sz;\n\
    \    }\n\n    vector<int> solve()\n    {\n        StronglyConnectedComponents<bool>::build();\n\
    \        vector<int> ret(sz);\n        for (int i = 0; i < sz; i++)\n        {\n\
    \            if (comp[i] == comp[rev(i)])\n                return {};\n      \
    \      ret[i] = comp[i] > comp[rev(i)];\n        }\n        return ret;\n    }\n\
    };"
  dependsOn:
  - library/graph/connected-components/StronglyConnectedComponents.cpp
  - library/template/template.cpp
  isVerificationFile: false
  path: library/graph/connected-components/TwoSat.cpp
  requiredBy: []
  timestamp: '2021-08-26 18:19:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-two_sat.test.cpp
documentation_of: library/graph/connected-components/TwoSat.cpp
layout: document
redirect_from:
- /library/library/graph/connected-components/TwoSat.cpp
- /library/library/graph/connected-components/TwoSat.cpp.html
title: 2-SAT
---
## メモ

## closureを追加
- todo

## 問題を解く
```c++
auto ans = twosat.solve();//ans[x] == 1 -> x is true
```
ansが空なら充足できない。