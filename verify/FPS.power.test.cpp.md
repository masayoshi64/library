---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.cpp
    title: library/convolution/NTT.cpp
  - icon: ':heavy_check_mark:'
    path: library/math/FormalPowerSeries.cpp
    title: library/math/FormalPowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: library/math/combination.cpp
    title: Combination(P, C, H, Stirling number, Bell number)
  - icon: ':heavy_check_mark:'
    path: library/mod/modint.cpp
    title: library/mod/modint.cpp
  - icon: ':question:'
    path: library/template/template.cpp
    title: library/template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1302
    links:
    - https://yukicoder.me/problems/no/1302
  bundledCode: "#line 1 \"verify/FPS.power.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1302\"\
    \n#line 1 \"library/template/template.cpp\"\n/* #region header */\n\n#pragma GCC\
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
    \ PI = 3.141592653589793;\n#line 3 \"verify/FPS.power.test.cpp\"\n// library\n\
    #line 1 \"library/convolution/NTT.cpp\"\ntemplate <typename Mint>\nstruct NTT\
    \ {\n    vector<Mint> dw, idw;\n    int max_base;\n    Mint root;\n\n    NTT()\
    \ {\n        const unsigned Mod = Mint::get_mod();\n        assert(Mod >= 3 &&\
    \ Mod % 2 == 1);\n        auto tmp = Mod - 1;\n        max_base = 0;\n       \
    \ while (tmp % 2 == 0) tmp >>= 1, max_base++;\n        root = 2;\n        while\
    \ (root.pow((Mod - 1) >> 1) == 1) root += 1;\n        assert(root.pow(Mod - 1)\
    \ == 1);\n        dw.resize(max_base);\n        idw.resize(max_base);\n      \
    \  for (int i = 0; i < max_base; i++) {\n            dw[i] = -root.pow((Mod -\
    \ 1) >> (i + 2));\n            idw[i] = Mint(1) / dw[i];\n        }\n    }\n\n\
    \    void ntt(vector<Mint> &a) {\n        const int n = (int)a.size();\n     \
    \   assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = n; m >>= 1;) {\n            Mint w = 1;\n            for\
    \ (int s = 0, k = 0; s < n; s += 2 * m) {\n                for (int i = s, j =\
    \ s + m; i < s + m; ++i, ++j) {\n                    auto x = a[i], y = a[j] *\
    \ w;\n                    a[i] = x + y, a[j] = x - y;\n                }\n   \
    \             w *= dw[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n\
    \    void intt(vector<Mint> &a, bool f = true) {\n        const int n = (int)a.size();\n\
    \        assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = 1; m < n; m *= 2) {\n            Mint w = 1;\n         \
    \   for (int s = 0, k = 0; s < n; s += 2 * m) {\n                for (int i =\
    \ s, j = s + m; i < s + m; ++i, ++j) {\n                    auto x = a[i], y =\
    \ a[j];\n                    a[i] = x + y, a[j] = (x - y) * w;\n             \
    \   }\n                w *= idw[__builtin_ctz(++k)];\n            }\n        }\n\
    \        if (f) {\n            Mint inv_sz = Mint(1) / n;\n            for (int\
    \ i = 0; i < n; i++) a[i] *= inv_sz;\n        }\n    }\n\n    vector<Mint> multiply(vector<Mint>\
    \ a, vector<Mint> b) {\n        int need = a.size() + b.size() - 1;\n        int\
    \ nbase = 1;\n        while ((1 << nbase) < need) nbase++;\n        int sz = 1\
    \ << nbase;\n        a.resize(sz, 0);\n        b.resize(sz, 0);\n        ntt(a);\n\
    \        ntt(b);\n        Mint inv_sz = Mint(1) / sz;\n        for (int i = 0;\
    \ i < sz; i++) a[i] *= b[i] * inv_sz;\n        intt(a, false);\n        a.resize(need);\n\
    \        return a;\n    }\n};\n#line 1 \"library/math/FormalPowerSeries.cpp\"\n\
    template <typename T>\nstruct FormalPowerSeries : vector<T> {\n    using vector<T>::vector;\n\
    \    using P = FormalPowerSeries;\n\n    using MULT = function<P(P, P)>;\n\n \
    \   static MULT& get_mult() {\n        static MULT mult = nullptr;\n        return\
    \ mult;\n    }\n\n    static void set_fft(MULT f) { get_mult() = f; }\n\n    //\
    \ \u672B\u5C3E\u306E0\u3092\u6D88\u3059\n    void shrink() {\n        while (this->size()\
    \ && this->back() == T(0)) this->pop_back();\n    }\n\n    P operator+(const P&\
    \ r) const { return P(*this) += r; }\n\n    P operator+(const T& v) const { return\
    \ P(*this) += v; }\n\n    P operator-(const P& r) const { return P(*this) -= r;\
    \ }\n\n    P operator-(const T& v) const { return P(*this) -= v; }\n\n    P operator*(const\
    \ P& r) const { return P(*this) *= r; }\n\n    P operator*(const T& v) const {\
    \ return P(*this) *= v; }\n\n    P operator/(const P& r) const { return P(*this)\
    \ /= r; }\n\n    P operator%(const P& r) const { return P(*this) %= r; }\n\n \
    \   P& operator+=(const P& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n\n    P& operator+=(const T& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    P& operator-=(const P& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    P& operator-=(const T& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        shrink();\n        return\
    \ *this;\n    }\n\n    P& operator*=(const T& v) {\n        const int n = (int)this->size();\n\
    \        for (int k = 0; k < n; k++) (*this)[k] *= v;\n        return *this;\n\
    \    }\n\n    P& operator*=(const P& r) {\n        if (this->empty() || r.empty())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  assert(get_mult() != nullptr);\n        return *this = get_mult()(*this, r);\n\
    \    }\n\n    P& operator%=(const P& r) { return *this -= *this / r * r; }\n\n\
    \    P operator-() const {\n        P ret(this->size());\n        for (int i =\
    \ 0; i < this->size(); i++) ret[i] = -(*this)[i];\n        return ret;\n    }\n\
    \n    P& operator/=(const P& r) {\n        if (this->size() < r.size()) {\n  \
    \          this->clear();\n            return *this;\n        }\n        int n\
    \ = this->size() - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P pre(int sz) const {\n        return P(begin(*this), begin(*this)\
    \ + min((int)this->size(), sz));\n    }\n\n    // f/x^sz\n    P operator>>(int\
    \ sz) const {\n        if (this->size() <= sz) return {};\n        P ret(*this);\n\
    \        ret.erase(ret.begin(), ret.begin() + sz);\n        return ret;\n    }\n\
    \n    // f*x^sz\n    P operator<<(int sz) const {\n        P ret(*this);\n   \
    \     ret.insert(ret.begin(), sz, T(0));\n        return ret;\n    }\n\n    //\
    \ \u53CD\u8EE2\n    P rev(int deg = -1) const {\n        P ret(*this);\n     \
    \   if (deg != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n\
    \        return ret;\n    }\n\n    //\u5FAE\u5206\n    P diff() const {\n    \
    \    const int n = (int)this->size();\n        P ret(max(0, n - 1));\n       \
    \ for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    // \u7A4D\u5206\n    P integral() const {\n        const\
    \ int n = (int)this->size();\n        P ret(n + 1);\n        ret[0] = T(0);\n\
    \        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);\n   \
    \     return ret;\n    }\n\n    // 1/f\u306Edeg\u9805\n    // F(0) must not be\
    \ 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // F(0) must be 1\n    P\
    \ log(int deg = -1) const {\n        assert((*this)[0] == 1);\n        const int\
    \ n = (int)this->size();\n        if (deg == -1) deg = n;\n        return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n    }\n\n    P sqrt(int deg = -1)\
    \ const {\n        const int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n\n        if ((*this)[0] == T(0)) {\n            for (int i = 1; i < n;\
    \ i++) {\n                if ((*this)[i] != T(0)) {\n                    if (i\
    \ & 1) return {};\n                    if (deg - i / 2 <= 0) break;\n        \
    \            auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);\n         \
    \           if (ret.size() < deg) ret.resize(deg, T(0));\n                   \
    \ return ret;\n                }\n            }\n            return P(deg, 0);\n\
    \        }\n\n        P ret({T(1)});\n        T inv2 = T(1) / T(2);\n        for\
    \ (int i = 1; i < deg; i <<= 1) {\n            ret = (ret + pre(i << 1) * ret.inv(i\
    \ << 1)) * inv2;\n        }\n        return ret.pre(deg);\n    }\n\n    // F(0)\
    \ must be 0\n    P exp(int deg = -1) const {\n        assert((*this)[0] == T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1)});\n        for (int i = 1; i < deg; i <<= 1) {\n        \
    \    ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n     \
    \   }\n        return ret.pre(deg);\n    }\n\n    P pow(int64_t k, int deg = -1)\
    \ const {\n        const int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i] != T(0))\
    \ {\n                T rev = T(1) / (*this)[i];\n                P C(*this * rev);\n\
    \                P D(n - i);\n                for (int j = i; j < n; j++) D[j\
    \ - i] = C[j];\n                D = (D.log() * k).exp() * (*this)[i].pow(k);\n\
    \                P E(deg);\n                if (i * k > deg) return E;\n     \
    \           auto S = i * k;\n                for (int j = 0; j + S < deg && j\
    \ < D.size(); j++)\n                    E[j + S] = D[j];\n                return\
    \ E;\n            }\n        }\n        return *this;\n    }\n\n    //\u4EE3\u5165\
    \n    T eval(T x) const {\n        T r = 0, w = 1;\n        for (auto& v : *this)\
    \ {\n            r += w * v;\n            w *= x;\n        }\n        return r;\n\
    \    }\n};\n\n// NTT<mint> ntt;\n// FPS mult_ntt(const FPS::P& a, const FPS::P&\
    \ b) {\n//     auto ret = ntt.multiply(a, b);\n//     return FPS::P(ret.begin(),\
    \ ret.end());\n// }\n// FPS mult(const FPS::P& a, const FPS::P& b) {\n//     FPS\
    \ c(a.size() + b.size() - 1);\n//     rep(i, a.size()) rep(j, b.size()) { c[i\
    \ + j] += a[i] * b[j]; }\n//     return c;\n// }\n#line 1 \"library/math/combination.cpp\"\
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
    \ntemplate <int Mod>\nstruct modint {\n    int x;\n\n    modint() : x(0) {}\n\n\
    \    modint(long long y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {}\n\
    \n    modint& operator+=(const modint& p) {\n        if ((x += p.x) >= Mod) x\
    \ -= Mod;\n        return *this;\n    }\n\n    modint& operator-=(const modint&\
    \ p) {\n        if ((x += Mod - p.x) >= Mod) x -= Mod;\n        return *this;\n\
    \    }\n\n    modint& operator*=(const modint& p) {\n        x = (int)(1LL * x\
    \ * p.x % Mod);\n        return *this;\n    }\n\n    modint& operator/=(const\
    \ modint& p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    modint operator-() const { return modint(-x); }\n\n    modint operator+(const\
    \ modint& p) const { return modint(*this) += p; }\n\n    modint operator-(const\
    \ modint& p) const { return modint(*this) -= p; }\n\n    modint operator*(const\
    \ modint& p) const { return modint(*this) *= p; }\n\n    modint operator/(const\
    \ modint& p) const { return modint(*this) /= p; }\n\n    bool operator==(const\
    \ modint& p) const { return x == p.x; }\n\n    bool operator!=(const modint& p)\
    \ const { return x != p.x; }\n\n    modint inverse() const {\n        int a =\
    \ x, b = Mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return modint(u);\n    }\n\n    modint pow(int64_t n) const {\n     \
    \   modint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1) ret\
    \ *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    friend ostream& operator<<(ostream& os, const modint& p)\
    \ {\n        return os << p.x;\n    }\n\n    friend istream& operator>>(istream&\
    \ is, modint& a) {\n        long long t;\n        is >> t;\n        a = modint<Mod>(t);\n\
    \        return (is);\n    }\n\n    static int get_mod() { return Mod; }\n\n \
    \   constexpr int get() const { return x; }\n};\n#line 8 \"verify/FPS.power.test.cpp\"\
    \nusing mint = modint<998244353>;\nusing FPS = FormalPowerSeries<mint>;\nNTT<mint>\
    \ ntt;\nFPS mult_ntt(const FPS::P& a, const FPS::P& b) {\n    auto ret = ntt.multiply(a,\
    \ b);\n    return FPS::P(ret.begin(), ret.end());\n}\n// FPS::set_fft(mult_ntt);\
    \ in main\nint main() {\n    FPS::set_fft(mult_ntt);\n    int n;\n    cin >> n;\n\
    \    Combination<mint> comb(n);\n    FPS f(n + 1);\n    rep(i, n + 1) { f[i] =\
    \ (mint)(i + 1) / comb.fact(i); }\n    f = f.pow(n, n);\n    print(f[n - 2] *\
    \ comb.fact(n - 2) / mypow<mint>(n, n - 2));\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1302\"\n#include \"library/template/template.cpp\"\
    \n// library\n#include \"library/convolution/NTT.cpp\"\n#include \"library/math/FormalPowerSeries.cpp\"\
    \n#include \"library/math/combination.cpp\"\n#include \"library/mod/modint.cpp\"\
    \nusing mint = modint<998244353>;\nusing FPS = FormalPowerSeries<mint>;\nNTT<mint>\
    \ ntt;\nFPS mult_ntt(const FPS::P& a, const FPS::P& b) {\n    auto ret = ntt.multiply(a,\
    \ b);\n    return FPS::P(ret.begin(), ret.end());\n}\n// FPS::set_fft(mult_ntt);\
    \ in main\nint main() {\n    FPS::set_fft(mult_ntt);\n    int n;\n    cin >> n;\n\
    \    Combination<mint> comb(n);\n    FPS f(n + 1);\n    rep(i, n + 1) { f[i] =\
    \ (mint)(i + 1) / comb.fact(i); }\n    f = f.pow(n, n);\n    print(f[n - 2] *\
    \ comb.fact(n - 2) / mypow<mint>(n, n - 2));\n}"
  dependsOn:
  - library/template/template.cpp
  - library/convolution/NTT.cpp
  - library/math/FormalPowerSeries.cpp
  - library/math/combination.cpp
  - library/mod/modint.cpp
  isVerificationFile: true
  path: verify/FPS.power.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 17:35:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/FPS.power.test.cpp
layout: document
redirect_from:
- /verify/verify/FPS.power.test.cpp
- /verify/verify/FPS.power.test.cpp.html
title: verify/FPS.power.test.cpp
---
