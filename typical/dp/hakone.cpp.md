---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/mod/modint.cpp
    title: library/mod/modint.cpp
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595
  bundledCode: "#line 1 \"typical/dp/hakone.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595\"\
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
    \ __builtin_popcountll(x); }\ntemplate <typename T>\nvector<int> IOTA(vector<T>\
    \ a) {\n    int n = a.size();\n    vector<int> id(n);\n    iota(all(id), 0);\n\
    \    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });\n    return id;\n\
    }\nstruct Timer {\n    clock_t start_time;\n    void start() { start_time = clock();\
    \ }\n    int lap() {\n        // return x ms.\n        return (clock() - start_time)\
    \ * 1000 / CLOCKS_PER_SEC;\n    }\n};\n/* #endregion*/\n// constant\n#define inf\
    \ 1000000000ll\n#define INF 4000000004000000000LL\n#define endl '\\n'\nconst long\
    \ double eps = 0.000000000000001;\nconst long double PI = 3.141592653589793;\n\
    #line 4 \"typical/dp/hakone.cpp\"\n//\n#line 1 \"library/mod/modint.cpp\"\ntemplate\
    \ <int mod>\nstruct modint {\n    int x;\n\n    modint() : x(0) {}\n\n    modint(long\
    \ long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    modint& operator+=(const\
    \ modint& p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    modint& operator-=(const modint& p) {\n        if ((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    modint& operator*=(const\
    \ modint& p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    modint& operator/=(const modint& p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n\n    modint operator-() const { return modint(-x);\
    \ }\n\n    modint operator+(const modint& p) const { return modint(*this) += p;\
    \ }\n\n    modint operator-(const modint& p) const { return modint(*this) -= p;\
    \ }\n\n    modint operator*(const modint& p) const { return modint(*this) *= p;\
    \ }\n\n    modint operator/(const modint& p) const { return modint(*this) /= p;\
    \ }\n\n    bool operator==(const modint& p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const modint& p) const { return x != p.x; }\n\n    modint inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return modint(u);\n    }\n\n    modint pow(int64_t\
    \ n) const {\n        modint ret(1), mul(x);\n        while (n > 0) {\n      \
    \      if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const modint& p) {\n        return os << p.x;\n    }\n\n    friend istream&\
    \ operator>>(istream& is, modint& a) {\n        long long t;\n        is >> t;\n\
    \        a = modint<mod>(t);\n        return (is);\n    }\n\n    static int get_mod()\
    \ { return mod; }\n\n    constexpr int get() const { return x; }\n};\n#line 6\
    \ \"typical/dp/hakone.cpp\"\nconst ll mod = 1000000007;\nusing mint = modint<mod>;\n\
    // library\nint main() {\n    int n;\n    cin >> n;\n    vc c(n);\n    scan(c);\n\
    \    vector<mint> dp(n + 1);  // dp[i]:=\u4FDD\u7559\u3057\u305F\u9806\u4F4D\u306E\
    \u6570\n    dp[0] = 1;\n    // \u524D\u304B\u3089\u898B\u3066\u3044\u304F\n  \
    \  rep(i, n) {\n        vector<mint> tmp(n + 1);\n        if (c[i] == '-') {\n\
    \            continue;\n        }\n        rep(nokori, n + 1) {\n            if\
    \ (c[i] == 'D') {\n                tmp[nokori] += dp[nokori] * nokori;\n     \
    \           if (nokori - 1 >= 0)\n                    tmp[nokori - 1] += dp[nokori]\
    \ * nokori * nokori;\n            } else {\n                if (nokori + 1 <=\
    \ n) tmp[nokori + 1] += dp[nokori];\n                tmp[nokori] += dp[nokori]\
    \ * nokori;\n            }\n        }\n        dp = tmp;\n    }\n    print(dp[0]);\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595\"\
    \n\n#include \"library/template/template.cpp\"\n//\n#include \"library/mod/modint.cpp\"\
    \nconst ll mod = 1000000007;\nusing mint = modint<mod>;\n// library\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vc c(n);\n    scan(c);\n    vector<mint> dp(n\
    \ + 1);  // dp[i]:=\u4FDD\u7559\u3057\u305F\u9806\u4F4D\u306E\u6570\n    dp[0]\
    \ = 1;\n    // \u524D\u304B\u3089\u898B\u3066\u3044\u304F\n    rep(i, n) {\n \
    \       vector<mint> tmp(n + 1);\n        if (c[i] == '-') {\n            continue;\n\
    \        }\n        rep(nokori, n + 1) {\n            if (c[i] == 'D') {\n   \
    \             tmp[nokori] += dp[nokori] * nokori;\n                if (nokori\
    \ - 1 >= 0)\n                    tmp[nokori - 1] += dp[nokori] * nokori * nokori;\n\
    \            } else {\n                if (nokori + 1 <= n) tmp[nokori + 1] +=\
    \ dp[nokori];\n                tmp[nokori] += dp[nokori] * nokori;\n         \
    \   }\n        }\n        dp = tmp;\n    }\n    print(dp[0]);\n}"
  dependsOn:
  - library/template/template.cpp
  - library/mod/modint.cpp
  isVerificationFile: false
  path: typical/dp/hakone.cpp
  requiredBy: []
  timestamp: '2020-12-18 23:34:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: typical/dp/hakone.cpp
layout: document
redirect_from:
- /library/typical/dp/hakone.cpp
- /library/typical/dp/hakone.cpp.html
title: typical/dp/hakone.cpp
---
