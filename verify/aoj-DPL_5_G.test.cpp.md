---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/combination.cpp
    title: Combination(P, C, H, Stirling number, Bell number)
  - icon: ':heavy_check_mark:'
    path: library/mod/modint.cpp
    title: library/mod/modint.cpp
  - icon: ':heavy_check_mark:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
  bundledCode: "#line 1 \"verify/aoj-DPL_5_G.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\n#line 1 \"\
    library/template/template.cpp\"\n/* #region header */\n\n#pragma GCC optimize(\"\
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
    #line 4 \"verify/aoj-DPL_5_G.test.cpp\"\n// library\n#line 1 \"library/math/combination.cpp\"\
    \n/**\n * @brief Combination(P, C, H, Stirling number, Bell number)\n * @docs\
    \ docs/Combination.md\n */\ntemplate <typename T>\nstruct Combination {\n    vector<T>\
    \ _fact, _rfact, _inv;\n\n    Combination(int sz) : _fact(sz + 1), _rfact(sz +\
    \ 1), _inv(sz + 1) {\n        _fact[0] = _rfact[sz] = _inv[0] = 1;\n        for\
    \ (int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n        _rfact[sz] /=\
    \ _fact[sz];\n        for (int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i +\
    \ 1] * (i + 1);\n        for (int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i\
    \ - 1];\n    }\n\n    inline T fact(int k) const { return _fact[k]; }\n\n    inline\
    \ T rfact(int k) const { return _rfact[k]; }\n\n    inline T inv(int k) const\
    \ { return _inv[k]; }\n\n    T P(int n, int r) const {\n        if (r < 0 || n\
    \ < r) return 0;\n        return fact(n) * rfact(n - r);\n    }\n\n    T C(int\
    \ p, int q) const {\n        if (q < 0 || p < q) return 0;\n        return fact(p)\
    \ * rfact(q) * rfact(p - q);\n    }\n\n    T H(int n, int r) const {\n       \
    \ if (n < 0 || r < 0) return (0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n\
    \    }\n\n    // O(klog(n))\n    // n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\
    \u7389\u3092k\u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u5272\u3059\u308B\
    \u5834\u5408\u306E\u6570\uFF08\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\
    \u306F1\u4EE5\u4E0A\uFF09\n    T Stirling(int n, int k) {\n        T res = 0;\n\
    \        rep(i, k + 1) {\n            res += (T)((k - i) % 2 ? -1 : 1) * C(k,\
    \ i) * mypow<T>(i, n);\n        }\n        return res / _fact[k];\n    }\n\n \
    \   // O(klog(n))\n    // n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u7389\u3092\
    k\u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u5272\u3059\u308B\u5834\u5408\
    \u306E\u6570\uFF08\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u306F0\u4EE5\
    \u4E0A\uFF09\n    // \u3082\u3057\u304F\u306F\u3001k\u500B\u4EE5\u4E0B\u306E\u7389\
    \u306E\u4E00\u500B\u4EE5\u4E0A\u5165\u3063\u305F\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5206\u3051\u308B\u3068\u8003\u3048\u3066\u3082\u3044\u3044\n    T Bell(int n,\
    \ int k) {\n        if (n < k) k = n;\n        vector<T> sm(k + 1);\n        sm[0]\
    \ = 1;\n        rep(j, 1, k + 1) { sm[j] = sm[j - 1] + (T)(j % 2 ? -1 : 1) / _fact[j];\
    \ }\n        T res = 0;\n        rep(i, k + 1) { res += mypow<T>(i, n) / _fact[i]\
    \ * sm[k - i]; }\n        return res;\n    }\n};\n#line 1 \"library/mod/modint.cpp\"\
    \ntemplate <int mod>\nstruct modint {\n    int x;\n\n    modint() : x(0) {}\n\n\
    \    modint(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\
    \n    modint& operator+=(const modint& p) {\n        if ((x += p.x) >= mod) x\
    \ -= mod;\n        return *this;\n    }\n\n    modint& operator-=(const modint&\
    \ p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    modint& operator*=(const modint& p) {\n        x = (int)(1LL * x\
    \ * p.x % mod);\n        return *this;\n    }\n\n    modint& operator/=(const\
    \ modint& p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    modint operator-() const { return modint(-x); }\n\n    modint operator+(const\
    \ modint& p) const { return modint(*this) += p; }\n\n    modint operator-(const\
    \ modint& p) const { return modint(*this) -= p; }\n\n    modint operator*(const\
    \ modint& p) const { return modint(*this) *= p; }\n\n    modint operator/(const\
    \ modint& p) const { return modint(*this) /= p; }\n\n    bool operator==(const\
    \ modint& p) const { return x == p.x; }\n\n    bool operator!=(const modint& p)\
    \ const { return x != p.x; }\n\n    modint inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return modint(u);\n    }\n\n    modint pow(int64_t n) const {\n     \
    \   modint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1) ret\
    \ *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    friend ostream& operator<<(ostream& os, const modint& p)\
    \ {\n        return os << p.x;\n    }\n\n    friend istream& operator>>(istream&\
    \ is, modint& a) {\n        long long t;\n        is >> t;\n        a = modint<mod>(t);\n\
    \        return (is);\n    }\n\n    static int get_mod() { return mod; }\n\n \
    \   inline int get() { return x; }\n};\n#line 7 \"verify/aoj-DPL_5_G.test.cpp\"\
    \n#define mod 1000000007ll\nusing mint = modint<mod>;\nint main() {\n    int n,\
    \ k;\n    cin >> n >> k;\n    Combination<mint> comb(n);\n    print(comb.Bell(n,\
    \ k));\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\
    \n#include \"library/template/template.cpp\"\n// library\n#include \"library/math/combination.cpp\"\
    \n#include \"library/mod/modint.cpp\"\n#define mod 1000000007ll\nusing mint =\
    \ modint<mod>;\nint main() {\n    int n, k;\n    cin >> n >> k;\n    Combination<mint>\
    \ comb(n);\n    print(comb.Bell(n, k));\n    return 0;\n}"
  dependsOn:
  - library/template/template.cpp
  - library/math/combination.cpp
  - library/mod/modint.cpp
  isVerificationFile: true
  path: verify/aoj-DPL_5_G.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 22:28:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-DPL_5_G.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-DPL_5_G.test.cpp
- /verify/verify/aoj-DPL_5_G.test.cpp.html
title: verify/aoj-DPL_5_G.test.cpp
---
