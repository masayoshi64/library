---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/flow/Dinic.cpp
    title: "Dinic(\u6700\u5927\u6D41)"
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"verify/aoj-GRL_6_A.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n#line 1\
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
    #line 5 \"verify/aoj-GRL_6_A.test.cpp\"\n// library\n#line 1 \"library/graph/flow/Dinic.cpp\"\
    \n/**\n * @brief Dinic(\u6700\u5927\u6D41)\n * @docs docs/dinic.md\n */\ntemplate\
    \ <typename flow_t>\nstruct Dinic {\n    const flow_t TINF;\n\n    struct edge\
    \ {\n        int to;\n        flow_t cap;\n        int rev;\n        bool isrev;\n\
    \        int idx;\n    };\n\n    vector<vector<edge> > graph;\n    vector<int>\
    \ min_cost, iter;\n\n    explicit Dinic(int V) : TINF(numeric_limits<flow_t>::max()),\
    \ graph(V) {}\n\n    void add_edge(int from, int to, flow_t cap, int idx = -1)\
    \ {\n        graph[from].emplace_back(\n            (edge){to, cap, (int)graph[to].size(),\
    \ false, idx});\n        graph[to].emplace_back(\n            (edge){from, 0,\
    \ (int)graph[from].size() - 1, true, idx});\n    }\n\n    bool build_augment_path(int\
    \ s, int t) {\n        min_cost.assign(graph.size(), -1);\n        queue<int>\
    \ que;\n        min_cost[s] = 0;\n        que.push(s);\n        while (!que.empty()\
    \ && min_cost[t] == -1) {\n            int p = que.front();\n            que.pop();\n\
    \            for (auto &e : graph[p]) {\n                if (e.cap > 0 && min_cost[e.to]\
    \ == -1) {\n                    min_cost[e.to] = min_cost[p] + 1;\n          \
    \          que.push(e.to);\n                }\n            }\n        }\n    \
    \    return min_cost[t] != -1;\n    }\n\n    flow_t find_min_dist_augment_path(int\
    \ idx, const int t, flow_t flow) {\n        if (idx == t) return flow;\n     \
    \   for (int &i = iter[idx]; i < graph[idx].size(); i++) {\n            edge &e\
    \ = graph[idx][i];\n            if (e.cap > 0 && min_cost[idx] < min_cost[e.to])\
    \ {\n                flow_t d =\n                    find_min_dist_augment_path(e.to,\
    \ t, min(flow, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    graph[e.to][e.rev].cap += d;\n                  \
    \  return d;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n\n    flow_t max_flow(int s, int t) {\n        flow_t flow = 0;\n    \
    \    while (build_augment_path(s, t)) {\n            iter.assign(graph.size(),\
    \ 0);\n            flow_t f;\n            while ((f = find_min_dist_augment_path(s,\
    \ t, TINF)) > 0) flow += f;\n        }\n        return flow;\n    }\n\n    void\
    \ output() {\n        for (int i = 0; i < graph.size(); i++) {\n            for\
    \ (auto &e : graph[i]) {\n                if (e.isrev) continue;\n           \
    \     auto &rev_e = graph[e.to][e.rev];\n                cout << i << \"->\" <<\
    \ e.to << \" (flow: \" << rev_e.cap << \"/\"\n                     << e.cap +\
    \ rev_e.cap << \")\" << endl;\n            }\n        }\n    }\n};\n#line 7 \"\
    verify/aoj-GRL_6_A.test.cpp\"\nint main() {\n    int v, e;\n    cin >> v >> e;\n\
    \    Dinic<ll> mf(v);\n    rep(i, e) {\n        int u, v, c;\n        cin >> u\
    \ >> v >> c;\n        mf.add_edge(u, v, c);\n    }\n    print(mf.max_flow(0, v\
    \ - 1));\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/graph/flow/Dinic.cpp\"\
    \nint main() {\n    int v, e;\n    cin >> v >> e;\n    Dinic<ll> mf(v);\n    rep(i,\
    \ e) {\n        int u, v, c;\n        cin >> u >> v >> c;\n        mf.add_edge(u,\
    \ v, c);\n    }\n    print(mf.max_flow(0, v - 1));\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/flow/Dinic.cpp
  isVerificationFile: true
  path: verify/aoj-GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2020-11-19 22:26:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_6_A.test.cpp
- /verify/verify/aoj-GRL_6_A.test.cpp.html
title: verify/aoj-GRL_6_A.test.cpp
---
