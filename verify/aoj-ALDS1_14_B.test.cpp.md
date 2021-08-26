---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/RollingHash.cpp
    title: library/string/RollingHash.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verify/aoj-ALDS1_14_B.test.cpp\"\n#define PROBLEM \\\n \
    \   \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #line 2 \"library/template/template.cpp\"\n/* #region header */\n#pragma GCC optimize(\"\
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
    const long double PI = 3.141592653589793;\n#line 5 \"verify/aoj-ALDS1_14_B.test.cpp\"\
    \n// library\n#line 1 \"library/string/RollingHash.cpp\"\nstruct RollingHash {\n\
    \    vector<unsigned long long> hashed, power;\n    const unsigned long long MASK30\
    \ = (1ULL << 30) - 1;\n    const unsigned long long MASK31 = (1ULL << 31) - 1;\n\
    \    const unsigned long long MOD = (1ULL << 61) - 1;\n    const unsigned long\
    \ long MASK61 = MOD;\n\n    RollingHash(const string &s, unsigned long long base\
    \ = 10007) {\n        int sz = (int)s.size();\n        hashed.assign(sz + 1, 0);\n\
    \        power.assign(sz + 1, 0);\n        power[0] = 1;\n        for (int i =\
    \ 0; i < sz; i++) {\n            power[i + 1] = CalcMod(Mul(power[i], base));\n\
    \            hashed[i + 1] = CalcMod(Mul(hashed[i], base) + s[i]);\n        }\n\
    \    }\n\n    // a*b mod 2^61-1\u3092\u8FD4\u3059\u95A2\u6570(\u6700\u5F8C\u306B\
    Mod\u3092\u53D6\u308B)\n    long long Mul(unsigned long long a, unsigned long\
    \ long b) {\n        unsigned long long au = a >> 31;\n        unsigned long long\
    \ ad = a & MASK31;\n        unsigned long long bu = b >> 31;\n        unsigned\
    \ long long bd = b & MASK31;\n        unsigned long long mid = ad * bu + au *\
    \ bd;\n        unsigned long long midu = mid >> 30;\n        unsigned long long\
    \ midd = mid & MASK30;\n        return au * bu * 2 + midu + (midd << 31) + ad\
    \ * bd;\n    }\n\n    // mod 2^61-1\u3092\u8A08\u7B97\u3059\u308B\u95A2\u6570\n\
    \    unsigned long long CalcMod(unsigned long long x) {\n        unsigned long\
    \ long xu = x >> 61;\n        unsigned long long xd = x & MASK61;\n        unsigned\
    \ long long res = xu + xd;\n        if (res >= MOD) res -= MOD;\n        return\
    \ res;\n    }\n\n    unsigned long long get(int l, int r) {\n        unsigned\
    \ long long ret =\n            CalcMod(hashed[r] + MOD * 3 - Mul(hashed[l], power[r\
    \ - l]));\n        return ret;\n    }\n\n    // CalcMod\u3092\u591A\u3081\u306B\
    \u3068\u3063\u3066\u308B\n    unsigned long long connect(unsigned long long h1,\
    \ unsigned long long h2,\n                               int h2len) {\n      \
    \  unsigned long long ret = CalcMod(CalcMod(Mul(h1, power[h2len])) + h2);\n  \
    \      return ret;\n    }\n\n    int LCP(RollingHash &b, int l1, int r1, int l2,\
    \ int r2) {\n        int len = min(r1 - l1, r2 - l2);\n        int low = -1, high\
    \ = len + 1;\n        while (high - low > 1) {\n            int mid = (low + high)\
    \ / 2;\n            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))\n          \
    \      low = mid;\n            else\n                high = mid;\n        }\n\
    \        return (low);\n    }\n};\n#line 7 \"verify/aoj-ALDS1_14_B.test.cpp\"\n\
    int main() {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(), m =\
    \ p.size();\n    RollingHash rht(t), rhp(p);\n    rep(i, n - m + 1) {\n      \
    \  if (rht.get(i, i + m) == rhp.get(0, m)) print(i);\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"library/template/template.cpp\"\n// library\n#include \"library/string/RollingHash.cpp\"\
    \nint main() {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(), m\
    \ = p.size();\n    RollingHash rht(t), rhp(p);\n    rep(i, n - m + 1) {\n    \
    \    if (rht.get(i, i + m) == rhp.get(0, m)) print(i);\n    }\n}"
  dependsOn:
  - library/template/template.cpp
  - library/string/RollingHash.cpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2021-08-24 21:28:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_14_B.test.cpp
- /verify/verify/aoj-ALDS1_14_B.test.cpp.html
title: verify/aoj-ALDS1_14_B.test.cpp
---
