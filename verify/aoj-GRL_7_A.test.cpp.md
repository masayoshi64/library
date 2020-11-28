---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/flow/BipartiteMatching.cpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"verify/aoj-GRL_7_A.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\n\n#line 1\
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
    \ __builtin_popcountll(x); }\ntemplate <typename T>\nvector<int> IOTA(vector<T>\
    \ a) {\n    int n = a.size();\n    vector<int> id(n);\n    iota(all(id), 0);\n\
    \    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });\n    return id;\n\
    }\nstruct Timer {\n    clock_t start_time;\n    void start() { start_time = clock();\
    \ }\n    int lap() {\n        // return x ms.\n        return (clock() - start_time)\
    \ * 1000 / CLOCKS_PER_SEC;\n    }\n};\n/* #endregion*/\n// constant\n#define inf\
    \ 1000000000ll\n#define INF 4000000004000000000LL\n#define endl '\\n'\nconst long\
    \ double eps = 0.000000000000001;\nconst long double PI = 3.141592653589793;\n\
    #line 5 \"verify/aoj-GRL_7_A.test.cpp\"\n// library\n#line 1 \"library/graph/flow/BipartiteMatching.cpp\"\
    \n/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\n * @docs docs/bipartite-matching.md\n */\nstruct BipartiteMatching\
    \ {\n    vector<vector<int> > graph;\n    vector<int> match, alive, used;\n  \
    \  int timestamp;\n    int a_size;\n\n    explicit BipartiteMatching(int n)\n\
    \        : a_size(-1),\n          graph(n),\n          alive(n, 1),\n        \
    \  used(n, 0),\n          match(n, -1),\n          timestamp(0) {}\n\n    explicit\
    \ BipartiteMatching(int n, int m)\n        : a_size(n),\n          graph(n + m),\n\
    \          alive(n + m, 1),\n          used(n + m, 0),\n          match(n + m,\
    \ -1),\n          timestamp(0) {}\n\n    void add_edge(int u, int v) {\n     \
    \   if (a_size < 0) {\n            graph[u].push_back(v);\n            graph[v].push_back(u);\n\
    \        } else {\n            graph[u].push_back(v + a_size);\n            graph[v\
    \ + a_size].push_back(u);\n        }\n    }\n\n    bool augment(int idx) {\n \
    \       used[idx] = timestamp;\n        for (auto &to : graph[idx]) {\n      \
    \      int to_match = match[to];\n            if (alive[to] == 0) continue;\n\
    \            if (to_match == -1 ||\n                (used[to_match] != timestamp\
    \ && augment(to_match))) {\n                match[idx] = to;\n               \
    \ match[to] = idx;\n                return true;\n            }\n        }\n \
    \       return false;\n    }\n\n    int matching() {\n        int ret = 0;\n \
    \       for (int i = 0; i < (int)graph.size(); i++) {\n            if (alive[i]\
    \ == 0) continue;\n            if (match[i] == -1) {\n                ++timestamp;\n\
    \                ret += augment(i);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int add_vertex(int idx) {\n        alive[idx] = 1;\n    \
    \    ++timestamp;\n        return augment(idx);\n    }\n\n    int erase_vertex(int\
    \ idx) {\n        alive[idx] = 0;\n        if (match[idx] == -1) {\n         \
    \   return 0;\n        }\n        match[match[idx]] = -1;\n        ++timestamp;\n\
    \        int ret = augment(match[idx]);\n        match[idx] = -1;\n        return\
    \ ret - 1;\n    }\n\n    void output() const {\n        for (int i = 0; i < (int)graph.size();\
    \ i++) {\n            if (i < match[i]) {\n                cout << i << \"-\"\
    \ << match[i] << endl;\n            }\n        }\n    }\n};\n#line 7 \"verify/aoj-GRL_7_A.test.cpp\"\
    \nint main() {\n    int X, Y, E;\n    cin >> X >> Y >> E;\n    BipartiteMatching\
    \ bm(X, Y);\n    rep(i, E) {\n        int x, y;\n        cin >> x >> y;\n    \
    \    bm.add_edge(x, y);\n    }\n    print(bm.matching());\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/graph/flow/BipartiteMatching.cpp\"\
    \nint main() {\n    int X, Y, E;\n    cin >> X >> Y >> E;\n    BipartiteMatching\
    \ bm(X, Y);\n    rep(i, E) {\n        int x, y;\n        cin >> x >> y;\n    \
    \    bm.add_edge(x, y);\n    }\n    print(bm.matching());\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/flow/BipartiteMatching.cpp
  isVerificationFile: true
  path: verify/aoj-GRL_7_A.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 22:28:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_7_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_7_A.test.cpp
- /verify/verify/aoj-GRL_7_A.test.cpp.html
title: verify/aoj-GRL_7_A.test.cpp
---
