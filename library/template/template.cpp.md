---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder-abc136_d.cpp
    title: test/atcoder-abc136_d.cpp
  - icon: ':warning:'
    path: verify/aoj.cpp
    title: verify/aoj.cpp
  - icon: ':warning:'
    path: verify/yuki-1408.cpp
    title: verify/yuki-1408.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-1595.test.cpp
    title: verify/aoj-1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-2446.test.cpp
    title: verify/aoj-2446.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_14_B.test.cpp
    title: verify/aoj-ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_14_D.test.cpp
    title: verify/aoj-ALDS1_14_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DPL_5_G.test.cpp
    title: verify/aoj-DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B.test.cpp
    title: verify/aoj-DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_G.test.cpp
    title: verify/aoj-DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_6_A.test.cpp
    title: verify/aoj-GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_6_B.test.cpp
    title: verify/aoj-GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_7_A.test.cpp
    title: verify/aoj-GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_A.test.cpp
    title: verify/aoj-NTL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_E.test.cpp
    title: verify/aoj-NTL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-dsl-1-a.test.cpp
    title: verify/aoj-dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod.test.cpp
    title: verify/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_kth_smallest.test.cpp
    title: verify/yosupo-range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-two_sat.test.cpp
    title: verify/yosupo-two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki-184.test.cpp
    title: verify/yuki-184.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki-650.test.cpp
    title: verify/yuki-650.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/template/template.cpp\"\n/* #region header */\n\n\
    #pragma GCC optimize(\"Ofast\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    // types\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long\
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
    \ __builtin_popcountll(x); }\ntemplate <typename T>\nvector<int> IOTA(vector<T>\
    \ a) {\n    int n = a.size();\n    vector<int> id(n);\n    iota(all(id), 0);\n\
    \    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });\n    return id;\n\
    }\nstruct Timer {\n    clock_t start_time;\n    void start() { start_time = clock();\
    \ }\n    int lap() {\n        // return x ms.\n        return (clock() - start_time)\
    \ * 1000 / CLOCKS_PER_SEC;\n    }\n};\n/* #endregion*/\n// constant\n#define inf\
    \ 1000000000ll\n#define INF 4000000004000000000LL\n#define endl '\\n'\nconst long\
    \ double eps = 0.000000000000001;\nconst long double PI = 3.141592653589793;\n"
  code: "/* #region header */\n\n#pragma GCC optimize(\"Ofast\")\n#include <bits/stdc++.h>\n\
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
    \ cout << x << endl\ntemplate <class T>\nostream& operator<<(ostream& os, const\
    \ vector<T>& v) {\n    for (auto& e : v) cout << e << \" \";\n    cout << endl;\n\
    \    return os;\n}\nvoid scan(int& a) { cin >> a; }\nvoid scan(long long& a) {\
    \ cin >> a; }\nvoid scan(char& a) { cin >> a; }\nvoid scan(double& a) { cin >>\
    \ a; }\nvoid scan(string& a) { cin >> a; }\ntemplate <class T>\nvoid scan(vector<T>&\
    \ a) {\n    for (auto& i : a) scan(i);\n}\n#define vsum(x) accumulate(all(x),\
    \ 0LL)\n#define vmax(a) *max_element(all(a))\n#define vmin(a) *min_element(all(a))\n\
    #define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define ub(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n// functions\n// gcd(0,\
    \ x) fails.\nll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }\nll lcm(ll a,\
    \ ll b) { return a / gcd(a, b) * b; }\ntemplate <class T>\nbool chmax(T& a, const\
    \ T& b) {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\ntemplate <class T>\nbool chmin(T& a, const T& b) {\n    if (b < a) {\n\
    \        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <typename\
    \ T>\nT mypow(T x, ll n) {\n    T ret = 1;\n    while (n > 0) {\n        if (n\
    \ & 1) (ret *= x);\n        (x *= x);\n        n >>= 1;\n    }\n    return ret;\n\
    }\nll modpow(ll x, ll n, const ll mod) {\n    ll ret = 1;\n    while (n > 0) {\n\
    \        if (n & 1) (ret *= x);\n        (x *= x);\n        n >>= 1;\n       \
    \ x %= mod;\n        ret %= mod;\n    }\n    return ret;\n}\n\nuint64_t my_rand(void)\
    \ {\n    static uint64_t x = 88172645463325252ULL;\n    x = x ^ (x << 13);\n \
    \   x = x ^ (x >> 7);\n    return x = x ^ (x << 17);\n}\nint popcnt(ull x) { return\
    \ __builtin_popcountll(x); }\ntemplate <typename T>\nvector<int> IOTA(vector<T>\
    \ a) {\n    int n = a.size();\n    vector<int> id(n);\n    iota(all(id), 0);\n\
    \    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });\n    return id;\n\
    }\nstruct Timer {\n    clock_t start_time;\n    void start() { start_time = clock();\
    \ }\n    int lap() {\n        // return x ms.\n        return (clock() - start_time)\
    \ * 1000 / CLOCKS_PER_SEC;\n    }\n};\n/* #endregion*/\n// constant\n#define inf\
    \ 1000000000ll\n#define INF 4000000004000000000LL\n#define endl '\\n'\nconst long\
    \ double eps = 0.000000000000001;\nconst long double PI = 3.141592653589793;\n"
  dependsOn: []
  isVerificationFile: false
  path: library/template/template.cpp
  requiredBy:
  - test/atcoder-abc136_d.cpp
  - verify/aoj.cpp
  - verify/yuki-1408.cpp
  timestamp: '2020-11-22 22:28:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_7_A.test.cpp
  - verify/aoj-GRL_6_A.test.cpp
  - verify/yosupo-convolution_mod_1000000007.test.cpp
  - verify/aoj-1595.test.cpp
  - verify/aoj-ALDS1_14_D.test.cpp
  - verify/yosupo-two_sat.test.cpp
  - verify/aoj-NTL_1_E.test.cpp
  - verify/yosupo-range_kth_smallest.test.cpp
  - verify/aoj-ALDS1_14_B.test.cpp
  - verify/aoj-DPL_5_G.test.cpp
  - verify/yuki-184.test.cpp
  - verify/aoj-dsl-1-a.test.cpp
  - verify/aoj-2446.test.cpp
  - verify/yuki-650.test.cpp
  - verify/aoj-GRL_6_B.test.cpp
  - verify/aoj-DSL_2_G.test.cpp
  - verify/aoj-NTL_1_A.test.cpp
  - verify/aoj-DSL_2_B.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
documentation_of: library/template/template.cpp
layout: document
redirect_from:
- /library/library/template/template.cpp
- /library/library/template/template.cpp.html
title: library/template/template.cpp
---