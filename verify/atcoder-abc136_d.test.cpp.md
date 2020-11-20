---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/others/Doubling.cpp
    title: library/others/Doubling.cpp
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc136/tasks/abc136_d
    links:
    - https://atcoder.jp/contests/abc136/tasks/abc136_d
  bundledCode: "#line 1 \"verify/atcoder-abc136_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc136/tasks/abc136_d\"\
    \n\n#line 1 \"library/template/template.cpp\"\n/* #region header */\n\n#pragma\
    \ GCC optimize(\"Ofast\")\n#include <bits/stdc++.h>\nusing namespace std;\n//\
    \ types\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long\
    \ double;\ntypedef pair<ll, ll> Pl;\ntypedef pair<int, int> Pi;\ntypedef vector<ll>\
    \ vl;\ntypedef vector<int> vi;\ntypedef vector<char> vc;\ntemplate <typename T>\n\
    using mat = vector<vector<T>>;\ntypedef vector<vector<int>> vvi;\ntypedef vector<vector<long\
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
    \ j) { return a[i] < a[j]; });\n    return id;\n}\n#line 4 \"verify/atcoder-abc136_d.test.cpp\"\
    \n// library\n#line 1 \"library/others/Doubling.cpp\"\nstruct Doubling {\n   \
    \ const int LOG;\n    vector<vector<int> > table;\n\n    Doubling(int sz, int64_t\
    \ lim_t) : LOG(64 - __builtin_clzll(lim_t)) {\n        table.assign(LOG, vector<int>(sz,\
    \ -1));\n    }\n\n    void set_next(int k, int x) { table[0][k] = x; }\n\n   \
    \ void build() {\n        for (int k = 0; k + 1 < LOG; k++) {\n            for\
    \ (int i = 0; i < table[k].size(); i++) {\n                if (table[k][i] ==\
    \ -1)\n                    table[k + 1][i] = -1;\n                else\n     \
    \               table[k + 1][i] = table[k][table[k][i]];\n            }\n    \
    \    }\n    }\n\n    int query(int k, int64_t t) {\n        for (int i = LOG -\
    \ 1; i >= 0; i--) {\n            if ((t >> i) & 1) k = table[i][k];\n        }\n\
    \        return k;\n    }\n};\n#line 6 \"verify/atcoder-abc136_d.test.cpp\"\n\
    int main() {\n    string s;\n    cin >> s;\n    int n = s.size();\n    Doubling\
    \ dl(n, 1000000000);\n    rep(i, n) { dl.set_next(i, (s[i] == 'L' ? i - 1 : i\
    \ + 1)); }\n    dl.build();\n    vi ans(n);\n    rep(i, n) { ans[dl.query(i, 1000000000)]++;\
    \ }\n    cout << ans;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc136/tasks/abc136_d\"\n\n\
    #include \"library/template/template.cpp\"\n// library\n#include \"library/others/Doubling.cpp\"\
    \nint main() {\n    string s;\n    cin >> s;\n    int n = s.size();\n    Doubling\
    \ dl(n, 1000000000);\n    rep(i, n) { dl.set_next(i, (s[i] == 'L' ? i - 1 : i\
    \ + 1)); }\n    dl.build();\n    vi ans(n);\n    rep(i, n) { ans[dl.query(i, 1000000000)]++;\
    \ }\n    cout << ans;\n}"
  dependsOn:
  - library/template/template.cpp
  - library/others/Doubling.cpp
  isVerificationFile: true
  path: verify/atcoder-abc136_d.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 20:54:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/atcoder-abc136_d.test.cpp
layout: document
redirect_from:
- /verify/verify/atcoder-abc136_d.test.cpp
- /verify/verify/atcoder-abc136_d.test.cpp.html
title: verify/atcoder-abc136_d.test.cpp
---
