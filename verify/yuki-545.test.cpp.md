---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/rekkyo.cpp
    title: library/dp/rekkyo.cpp
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
    PROBLEM: https://yukicoder.me/problems/no/545
    links:
    - https://yukicoder.me/problems/no/545
  bundledCode: "#line 1 \"verify/yuki-545.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/545\"\
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
    \ % mod + mod) % mod; }\nint popcnt(ull x) { return __builtin_popcountll(x); }\n\
    template <typename T>\nvector<int> IOTA(vector<T> a)\n{\n    int n = a.size();\n\
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
    #line 4 \"verify/yuki-545.test.cpp\"\n// library\n#line 1 \"library/dp/rekkyo.cpp\"\
    \ntemplate <typename T>\nvector<T> rekkyo(const vector<T>& items) {\n    vector<T>\
    \ res = {0}, tmp, tmp1;\n    for (T item : items) {\n        for (auto val : res)\
    \ {\n            tmp.pb(item + val);\n        }\n        //\u30BD\u30FC\u30C8\u3055\
    \u308C\u305F\u307E\u307Emerge\n        merge(all(res), all(tmp), back_inserter(tmp1));\n\
    \        swap(res, tmp1);\n        tmp.clear();\n        tmp1.clear();\n    }\n\
    \    return res;\n}\n\n// vector<T> a = rekkyo({items.begin(), items.begin() +\
    \ n / 2});\n// vector<T> b = rekkyo({items.begin() + n / 2, items.end()});\n#line\
    \ 6 \"verify/yuki-545.test.cpp\"\nint main() {\n    ll n;\n    cin >> n;\n   \
    \ vl a(n), b(n);\n    rep(i, n) cin >> a[i] >> b[i];\n    rep(i, n) a[i] += b[i];\n\
    \    ll sm = vsum(b);\n    auto x = rekkyo<ll>({a.begin(), a.begin() + n / 2});\n\
    \    auto y = rekkyo<ll>({a.begin() + n / 2, a.end()});\n    ll smx = accumulate(b.begin(),\
    \ b.begin() + n / 2, 0ll);\n    ll smy = accumulate(b.begin() + n / 2, b.end(),\
    \ 0ll);\n    for (ll& xi : x) xi -= smx;\n    for (ll& yi : y) yi -= smy;\n  \
    \  reverse(all(x));\n    ll ans = INF;\n    auto iter = y.begin();\n    for (ll\
    \ xi : x) {\n        while (iter != y.end() && *iter + xi < 0) iter++;\n     \
    \   chmin(ans, abs(*iter + xi));\n        if (iter != y.begin()) {\n         \
    \   chmin(ans, abs(*(iter - 1) + xi));\n        }\n    }\n    print(ans);\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/545\"\n\n#include \"library/template/template.cpp\"\
    \n// library\n#include \"library/dp/rekkyo.cpp\"\nint main() {\n    ll n;\n  \
    \  cin >> n;\n    vl a(n), b(n);\n    rep(i, n) cin >> a[i] >> b[i];\n    rep(i,\
    \ n) a[i] += b[i];\n    ll sm = vsum(b);\n    auto x = rekkyo<ll>({a.begin(),\
    \ a.begin() + n / 2});\n    auto y = rekkyo<ll>({a.begin() + n / 2, a.end()});\n\
    \    ll smx = accumulate(b.begin(), b.begin() + n / 2, 0ll);\n    ll smy = accumulate(b.begin()\
    \ + n / 2, b.end(), 0ll);\n    for (ll& xi : x) xi -= smx;\n    for (ll& yi :\
    \ y) yi -= smy;\n    reverse(all(x));\n    ll ans = INF;\n    auto iter = y.begin();\n\
    \    for (ll xi : x) {\n        while (iter != y.end() && *iter + xi < 0) iter++;\n\
    \        chmin(ans, abs(*iter + xi));\n        if (iter != y.begin()) {\n    \
    \        chmin(ans, abs(*(iter - 1) + xi));\n        }\n    }\n    print(ans);\n\
    }"
  dependsOn:
  - library/template/template.cpp
  - library/dp/rekkyo.cpp
  isVerificationFile: true
  path: verify/yuki-545.test.cpp
  requiredBy: []
  timestamp: '2023-09-23 21:29:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yuki-545.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki-545.test.cpp
- /verify/verify/yuki-545.test.cpp.html
title: verify/yuki-545.test.cpp
---
