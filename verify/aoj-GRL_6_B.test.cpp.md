---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/flow/MinCostFlow.cpp
    title: library/graph/flow/MinCostFlow.cpp
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"verify/aoj-GRL_6_B.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\n\n#line 1\
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
    \ PI = 3.141592653589793;\n#line 5 \"verify/aoj-GRL_6_B.test.cpp\"\n// library\n\
    #line 1 \"library/graph/flow/MinCostFlow.cpp\"\ntemplate <typename flow_t, typename\
    \ cost_t>\nstruct MinCostFlow {\n    const cost_t TINF;\n\n    struct edge {\n\
    \        int to;\n        flow_t cap;\n        cost_t cost;\n        int rev;\n\
    \        bool isrev;\n    };\n    vector<vector<edge> > graph;\n    vector<cost_t>\
    \ potential, min_cost;\n    vector<int> prevv, preve;\n\n    MinCostFlow(int V)\
    \ : graph(V), TINF(numeric_limits<cost_t>::max()) {}\n\n    void add_edge(int\
    \ from, int to, flow_t cap, cost_t cost) {\n        graph[from].emplace_back(\n\
    \            (edge){to, cap, cost, (int)graph[to].size(), false});\n        graph[to].emplace_back(\n\
    \            (edge){from, 0, -cost, (int)graph[from].size() - 1, true});\n   \
    \ }\n\n    cost_t min_cost_flow(int s, int t, flow_t f) {\n        int V = (int)graph.size();\n\
    \        cost_t ret = 0;\n        using Pi = pair<cost_t, int>;\n        priority_queue<Pi,\
    \ vector<Pi>, greater<Pi> > que;\n        potential.assign(V, 0);\n        preve.assign(V,\
    \ -1);\n        prevv.assign(V, -1);\n\n        while (f > 0) {\n            min_cost.assign(V,\
    \ TINF);\n            que.emplace(0, s);\n            min_cost[s] = 0;\n     \
    \       while (!que.empty()) {\n                Pi p = que.top();\n          \
    \      que.pop();\n                if (min_cost[p.second] < p.first) continue;\n\
    \                for (int i = 0; i < graph[p.second].size(); i++) {\n        \
    \            edge &e = graph[p.second][i];\n                    cost_t nextCost\
    \ = min_cost[p.second] + e.cost +\n                                      potential[p.second]\
    \ - potential[e.to];\n                    if (e.cap > 0 && min_cost[e.to] > nextCost)\
    \ {\n                        min_cost[e.to] = nextCost;\n                    \
    \    prevv[e.to] = p.second, preve[e.to] = i;\n                        que.emplace(min_cost[e.to],\
    \ e.to);\n                    }\n                }\n            }\n          \
    \  if (min_cost[t] == TINF) return -1;\n            for (int v = 0; v < V; v++)\
    \ potential[v] += min_cost[v];\n            flow_t addflow = f;\n            for\
    \ (int v = t; v != s; v = prevv[v]) {\n                addflow = min(addflow,\
    \ graph[prevv[v]][preve[v]].cap);\n            }\n            f -= addflow;\n\
    \            ret += addflow * potential[t];\n            for (int v = t; v !=\
    \ s; v = prevv[v]) {\n                edge &e = graph[prevv[v]][preve[v]];\n \
    \               e.cap -= addflow;\n                graph[v][e.rev].cap += addflow;\n\
    \            }\n        }\n        return ret;\n    }\n\n    void output() {\n\
    \        for (int i = 0; i < graph.size(); i++) {\n            for (auto &e :\
    \ graph[i]) {\n                if (e.isrev) continue;\n                auto &rev_e\
    \ = graph[e.to][e.rev];\n                cout << i << \"->\" << e.to << \" (flow:\
    \ \" << rev_e.cap << \"/\"\n                     << rev_e.cap + e.cap << \")\"\
    \ << endl;\n            }\n        }\n    }\n};\n#line 7 \"verify/aoj-GRL_6_B.test.cpp\"\
    \nint main() {\n    ll v, e, f;\n    cin >> v >> e >> f;\n    MinCostFlow<ll,\
    \ ll> mf(v);\n    rep(i, e) {\n        ll u, v, c, d;\n        cin >> u >> v >>\
    \ c >> d;\n        mf.add_edge(u, v, c, d);\n    }\n    print(mf.min_cost_flow(0,\
    \ v - 1, f));\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/graph/flow/MinCostFlow.cpp\"\
    \nint main() {\n    ll v, e, f;\n    cin >> v >> e >> f;\n    MinCostFlow<ll,\
    \ ll> mf(v);\n    rep(i, e) {\n        ll u, v, c, d;\n        cin >> u >> v >>\
    \ c >> d;\n        mf.add_edge(u, v, c, d);\n    }\n    print(mf.min_cost_flow(0,\
    \ v - 1, f));\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/flow/MinCostFlow.cpp
  isVerificationFile: true
  path: verify/aoj-GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2020-12-23 20:37:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_6_B.test.cpp
- /verify/verify/aoj-GRL_6_B.test.cpp.html
title: verify/aoj-GRL_6_B.test.cpp
---