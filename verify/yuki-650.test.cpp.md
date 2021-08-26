---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/HLD.cpp
    title: library/graph/tree/HLD.cpp
  - icon: ':heavy_check_mark:'
    path: library/math/Matrix.cpp
    title: library/math/Matrix.cpp
  - icon: ':question:'
    path: library/mod/modint.cpp
    title: library/mod/modint.cpp
  - icon: ':heavy_check_mark:'
    path: library/structure/segtree/SegmentTree.cpp
    title: Segment Tree
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
    PROBLEM: https://yukicoder.me/problems/no/650
    links:
    - https://yukicoder.me/problems/no/650
  bundledCode: "#line 1 \"verify/yuki-650.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/650\"\
    \n#line 2 \"library/template/template.cpp\"\n/* #region header */\n#pragma GCC\
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
    const long double PI = 3.141592653589793;\n#line 3 \"verify/yuki-650.test.cpp\"\
    \n// library\n#line 1 \"library/graph/tree/HLD.cpp\"\nstruct HLD {\n    vector<vector<int>>\
    \ G;\n    vector<int> parent, depth, sub_size, v_id, id_to_v, head;\n    HLD(int\
    \ n)\n        : G(n),\n          v_id(n, -1),\n          head(n),\n          sub_size(n,\
    \ 1),\n          parent(n, -1),\n          depth(n, 0),\n          id_to_v(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n   \
    \     G[v].emplace_back(u);\n    }\n\n    void build(int root = 0) {\n       \
    \ int pos = 0;\n        dfs_size(root);\n        head[root] = root;\n        dfs_hld(root,\
    \ pos);\n    }\n\n    void dfs_size(int v) {\n        for (int& nv : G[v]) {\n\
    \            if (nv == parent[v]) {\n                nv = G[v].back();\n     \
    \           G[v].pop_back();\n            }\n        }\n        for (int& nv :\
    \ G[v]) {\n            parent[nv] = v;\n            depth[nv] = depth[v] + 1;\n\
    \            dfs_size(nv);\n            sub_size[v] += sub_size[nv];\n       \
    \     if (sub_size[nv] > sub_size[G[v][0]]) swap(nv, G[v][0]);\n        }\n  \
    \  }\n\n    void dfs_hld(int v, int& pos) {\n        v_id[v] = pos;\n        id_to_v[pos++]\
    \ = v;\n        for (int nv : G[v]) {\n            head[nv] = (nv == G[v][0] ?\
    \ head[v] : nv);\n            dfs_hld(nv, pos);\n        }\n    }\n\n    int lca(int\
    \ u, int v) {\n        while (1) {\n            if (v_id[u] > v_id[v]) swap(u,\
    \ v);\n            if (head[u] == head[v]) return u;\n            v = parent[head[v]];\n\
    \        }\n    }\n\n    int distance(int u, int v) {\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    // update vertexes in [u, v]\
    \ with f\n    template <typename F>\n    void update(int u, int v, const F& f)\
    \ {\n        while (1) {\n            if (v_id[u] > v_id[v]) swap(u, v);\n   \
    \         f(max(v_id[head[v]], v_id[u]), v_id[v]);\n            if (head[u] !=\
    \ head[v])\n                v = parent[head[v]];\n            else\n         \
    \       break;\n        }\n    }\n\n    // get res for [u, v] with query q and\
    \ merge each value with f\n    // root->leaf\n    template <typename T, typename\
    \ Q, typename F>\n    T query(int u, int v, T id, const Q& q, const F& f) {\n\
    \        T l = id, r = id;\n        while (1) {\n            if (v_id[u] > v_id[v])\
    \ {\n                swap(u, v);\n                swap(l, r);\n            }\n\
    \            l = f(q(max(v_id[head[v]], v_id[u]), v_id[v]), l);\n            if\
    \ (head[u] != head[v])\n                v = parent[head[v]];\n            else\n\
    \                break;\n        }\n        return f(r, l);\n    }\n\n    // update\
    \ edges between u, v inclusive with func f\n    template <typename F>\n    void\
    \ update_edge(int u, int v, const F& f) {\n        while (1) {\n            if\
    \ (v_id[u] > v_id[v]) swap(u, v);\n            if (head[u] != head[v]) {\n   \
    \             f(v_id[head[v]], v_id[v]);\n                v = parent[head[v]];\n\
    \            } else {\n                if (u != v) f(v_id[u] + 1, v_id[v]);\n\
    \                break;\n            }\n        }\n    }\n\n    // query for edges\
    \ between u, v inclusive with query q and merge func f\n    // root->leaf\n  \
    \  template <typename T, typename Q, typename F>\n    T query_edge(int u, int\
    \ v, T id, const Q& q, const F& f) {\n        T l = id, r = id;\n        while\
    \ (1) {\n            if (v_id[u] > v_id[v]) {\n                swap(u, v);\n \
    \               swap(l, r);\n            }\n            if (head[u] != head[v])\
    \ {\n                l = f(q(v_id[head[v]], v_id[v]), l);\n                v =\
    \ parent[head[v]];\n            } else {\n                if (u != v) l = f(q(v_id[u]\
    \ + 1, v_id[v]), l);\n                break;\n            }\n        }\n     \
    \   return f(r, l);\n    }\n};\n#line 1 \"library/math/Matrix.cpp\"\ntemplate\
    \ <class T>\nstruct Matrix {\n    vector<vector<T>> A;\n\n    Matrix() {}\n\n\
    \    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n\n    Matrix(size_t\
    \ n) : A(n, vector<T>(n, 0)){};\n\n    Matrix(vector<vector<T>> a) { A = a; }\n\
    \n    size_t height() const { return (A.size()); }\n\n    size_t width() const\
    \ { return (A[0].size()); }\n\n    inline const vector<T>& operator[](int k) const\
    \ { return (A.at(k)); }\n\n    inline vector<T>& operator[](int k) { return (A.at(k));\
    \ }\n\n    static Matrix I(size_t n) {\n        Matrix mat(n);\n        for (int\
    \ i = 0; i < n; i++) mat[i][i] = 1;\n        return (mat);\n    }\n\n    Matrix&\
    \ operator+=(const Matrix& B) {\n        size_t n = height(), m = width();\n \
    \       assert(n == B.height() && m == B.width());\n        for (int i = 0; i\
    \ < n; i++)\n            for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n\
    \        return (*this);\n    }\n\n    Matrix& operator-=(const Matrix& B) {\n\
    \        size_t n = height(), m = width();\n        assert(n == B.height() &&\
    \ m == B.width());\n        for (int i = 0; i < n; i++)\n            for (int\
    \ j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n        return (*this);\n    }\n\
    \n    Matrix& operator*=(const Matrix& B) {\n        size_t n = height(), m =\
    \ B.width(), p = width();\n        assert(p == B.height());\n        vector<vector<T>>\
    \ C(n, vector<T>(m, 0));\n        for (int i = 0; i < n; i++)\n            for\
    \ (int j = 0; j < m; j++)\n                for (int k = 0; k < p; k++)\n     \
    \               C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n        A.swap(C);\n\
    \        return (*this);\n    }\n\n    Matrix& operator^=(long long k) {\n   \
    \     Matrix B = Matrix::I(height());\n        while (k > 0) {\n            if\
    \ (k & 1) B *= *this;\n            *this *= *this;\n            k >>= 1LL;\n \
    \       }\n        A.swap(B.A);\n        return (*this);\n    }\n\n    Matrix\
    \ operator+(const Matrix& B) const { return (Matrix(*this) += B); }\n\n    Matrix\
    \ operator-(const Matrix& B) const { return (Matrix(*this) -= B); }\n\n    Matrix\
    \ operator*(const Matrix& B) const { return (Matrix(*this) *= B); }\n\n    Matrix\
    \ operator^(const long long k) const { return (Matrix(*this) ^= k); }\n\n    Matrix\
    \ pow(long long n) {\n        Matrix ret = I(height());\n        Matrix x = Matrix(*this);\n\
    \        while (n > 0) {\n            if (n & 1) (ret *= x);\n            (x *=\
    \ x);\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ ostream& operator<<(ostream& os, Matrix& p) {\n        size_t n = p.height(),\
    \ m = p.width();\n        for (int i = 0; i < n; i++) {\n            os << \"\
    [\";\n            for (int j = 0; j < m; j++) {\n                os << p[i][j]\
    \ << (j + 1 == m ? \"]\\n\" : \",\");\n            }\n        }\n        return\
    \ (os);\n    }\n\n    T determinant() {\n        Matrix B(*this);\n        assert(width()\
    \ == height());\n        T ret = 1;\n        for (int i = 0; i < width(); i++)\
    \ {\n            int idx = -1;\n            for (int j = i; j < width(); j++)\
    \ {\n                if (B[j][i] != 0) idx = j;\n            }\n            if\
    \ (idx == -1) return (0);\n            if (i != idx) {\n                ret *=\
    \ -1;\n                swap(B[i], B[idx]);\n            }\n            ret *=\
    \ B[i][i];\n            T vv = B[i][i];\n            for (int j = 0; j < width();\
    \ j++) {\n                B[i][j] /= vv;\n            }\n            for (int\
    \ j = i + 1; j < width(); j++) {\n                T a = B[j][i];\n           \
    \     for (int k = 0; k < width(); k++) {\n                    B[j][k] -= B[i][k]\
    \ * a;\n                }\n            }\n        }\n        return (ret);\n \
    \   }\n\n    Matrix transpose() {\n        Matrix ret(width(), height());\n  \
    \      rep(i, height()) { rep(j, width()) ret[j][i] = A[i][j]; }\n        return\
    \ ret;\n    }\n};\n#line 2 \"library/mod/modint.cpp\"\ntemplate <int Mod>\nstruct\
    \ modint\n{\n    int x;\n\n    modint() : x(0) {}\n\n    modint(long long y) :\
    \ x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {}\n\n    modint &operator+=(const\
    \ modint &p)\n    {\n        if ((x += p.x) >= Mod)\n            x -= Mod;\n \
    \       return *this;\n    }\n\n    modint &operator-=(const modint &p)\n    {\n\
    \        if ((x += Mod - p.x) >= Mod)\n            x -= Mod;\n        return *this;\n\
    \    }\n\n    modint &operator*=(const modint &p)\n    {\n        x = (int)(1LL\
    \ * x * p.x % Mod);\n        return *this;\n    }\n\n    modint &operator/=(const\
    \ modint &p)\n    {\n        *this *= p.inverse();\n        return *this;\n  \
    \  }\n\n    modint operator-() const { return modint(-x); }\n\n    modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n\n    modint operator-(const\
    \ modint &p) const { return modint(*this) -= p; }\n\n    modint operator*(const\
    \ modint &p) const { return modint(*this) *= p; }\n\n    modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n\n    bool operator==(const\
    \ modint &p) const { return x == p.x; }\n\n    bool operator!=(const modint &p)\
    \ const { return x != p.x; }\n\n    modint inverse() const\n    {\n        int\
    \ a = x, b = Mod, u = 1, v = 0, t;\n        while (b > 0)\n        {\n       \
    \     t = a / b;\n            swap(a -= t * b, b);\n            swap(u -= t *\
    \ v, v);\n        }\n        return modint(u);\n    }\n\n    modint pow(int64_t\
    \ n) const\n    {\n        modint ret(1), mul(x);\n        while (n > 0)\n   \
    \     {\n            if (n & 1)\n                ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend ostream &operator<<(ostream &os, const modint &p)\n    {\n        return\
    \ os << p.x;\n    }\n\n    friend istream &operator>>(istream &is, modint &a)\n\
    \    {\n        long long t;\n        is >> t;\n        a = modint<Mod>(t);\n\
    \        return (is);\n    }\n\n    static int get_mod() { return Mod; }\n\n \
    \   constexpr int get() const { return x; }\n};\n#line 1 \"library/structure/segtree/SegmentTree.cpp\"\
    \n/**\n * @brief Segment Tree\n * @docs docs/segmenttree.md\n */\ntemplate <typename\
    \ Monoid>\nstruct SegmentTree {\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \n    int sz;\n    vector<Monoid> seg;\n\n    const F f;\n    const Monoid M1;\n\
    \n    SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {\n     \
    \   sz = 1;\n        while (sz < n) sz <<= 1;\n        seg.assign(2 * sz, M1);\n\
    \    }\n\n    void set(int k, const Monoid& x) { seg[k + sz] = x; }\n\n    void\
    \ build() {\n        for (int k = sz - 1; k > 0; k--) {\n            seg[k] =\
    \ f(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n    void update(int\
    \ k, const Monoid& x) {\n        k += sz;\n        seg[k] = x;\n        while\
    \ (k >>= 1) {\n            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);\n     \
    \   }\n    }\n\n    Monoid query(int a, int b) {\n        Monoid L = M1, R = M1;\n\
    \        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a\
    \ & 1) L = f(L, seg[a++]);\n            if (b & 1) R = f(seg[--b], R);\n     \
    \   }\n        return f(L, R);\n    }\n\n    Monoid operator[](const int& k) const\
    \ { return seg[k + sz]; }\n\n    template <typename C>\n    int find_subtree(int\
    \ a, const C& check, Monoid& M, bool type) {\n        while (a < sz) {\n     \
    \       Monoid nxt =\n                type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n            if (check(nxt))\n                a = 2 * a + type;\n\
    \            else\n                M = nxt, a = 2 * a + 1 - type;\n        }\n\
    \        return a - sz;\n    }\n\n    // check(seg.query(b, i))\u3092\u6E80\u305F\
    \u3059\u6700\u5C0F\u306Eb<=i\u3092\u8FD4\u3059.\u306A\u3051\u308C\u3070-1\n  \
    \  template <typename C>\n    int find_first(int a, const C& check) {\n      \
    \  Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L, seg[1])))\
    \ return find_subtree(1, check, L, false);\n            return -1;\n        }\n\
    \        int b = sz;\n        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)\
    \ {\n            if (a & 1) {\n                Monoid nxt = f(L, seg[a]);\n  \
    \              if (check(nxt)) return find_subtree(a, check, L, false);\n    \
    \            L = nxt;\n                ++a;\n            }\n        }\n      \
    \  return -1;\n    }\n\n    // check(seg.query(i, b))\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ei<b\u3092\u8FD4\u3059.\u306A\u3051\u308C\u3070-1\n    template <typename\
    \ C>\n    int find_last(int b, const C& check) {\n        Monoid R = M1;\n   \
    \     if (b >= sz) {\n            if (check(f(seg[1], R))) return find_subtree(1,\
    \ check, R, true);\n            return -1;\n        }\n        int a = sz;\n \
    \       for (b += sz; a < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n \
    \               Monoid nxt = f(seg[--b], R);\n                if (check(nxt))\
    \ return find_subtree(b, check, R, true);\n                R = nxt;\n        \
    \    }\n        }\n        return -1;\n    }\n};\n#line 8 \"verify/yuki-650.test.cpp\"\
    \nusing mint = modint<1000000007>;\nusing mmat = Matrix<mint>;\nint main() {\n\
    \    int n, q;\n    cin >> n;\n    HLD hld(n);\n    vector<Pi> etov(n - 1);\n\
    \    rep(i, n - 1) {\n        int a, b;\n        cin >> a >> b;\n        hld.add_edge(a,\
    \ b);\n        etov[i] = mp(a, b);\n    }\n    cin >> q;\n    SegmentTree<mmat>\
    \ seg(\n        n, [&](mmat a, mmat b) { return a * b; }, mmat::I(2));\n    hld.build();\n\
    \    rep(_, q) {\n        char t;\n        cin >> t;\n        if (t == 'g') {\n\
    \            int u, v;\n            cin >> u >> v;\n            mmat res = hld.query_edge(\n\
    \                u, v, mmat::I(2),\n                [&](int a, int b) { return\
    \ seg.query(a, b + 1); },\n                [&](mmat a, mmat b) { return a * b;\
    \ });\n            cout << res[0][0] << \" \" << res[0][1] << \" \" << res[1][0]\
    \ << \" \"\n                 << res[1][1] << \"\\n\";\n        } else {\n    \
    \        int i, a, b, c, d;\n            cin >> i >> a >> b >> c >> d;\n     \
    \       int u = etov[i].first, v = etov[i].second;\n            hld.update_edge(u,\
    \ v, [&](int l, int r) {\n                return seg.update(l, mmat({{a, b}, {c,\
    \ d}}));\n            });\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/650\"\n#include \"library/template/template.cpp\"\
    \n// library\n#include \"library/graph/tree/HLD.cpp\"\n#include \"library/math/Matrix.cpp\"\
    \n#include \"library/mod/modint.cpp\"\n#include \"library/structure/segtree/SegmentTree.cpp\"\
    \nusing mint = modint<1000000007>;\nusing mmat = Matrix<mint>;\nint main() {\n\
    \    int n, q;\n    cin >> n;\n    HLD hld(n);\n    vector<Pi> etov(n - 1);\n\
    \    rep(i, n - 1) {\n        int a, b;\n        cin >> a >> b;\n        hld.add_edge(a,\
    \ b);\n        etov[i] = mp(a, b);\n    }\n    cin >> q;\n    SegmentTree<mmat>\
    \ seg(\n        n, [&](mmat a, mmat b) { return a * b; }, mmat::I(2));\n    hld.build();\n\
    \    rep(_, q) {\n        char t;\n        cin >> t;\n        if (t == 'g') {\n\
    \            int u, v;\n            cin >> u >> v;\n            mmat res = hld.query_edge(\n\
    \                u, v, mmat::I(2),\n                [&](int a, int b) { return\
    \ seg.query(a, b + 1); },\n                [&](mmat a, mmat b) { return a * b;\
    \ });\n            cout << res[0][0] << \" \" << res[0][1] << \" \" << res[1][0]\
    \ << \" \"\n                 << res[1][1] << \"\\n\";\n        } else {\n    \
    \        int i, a, b, c, d;\n            cin >> i >> a >> b >> c >> d;\n     \
    \       int u = etov[i].first, v = etov[i].second;\n            hld.update_edge(u,\
    \ v, [&](int l, int r) {\n                return seg.update(l, mmat({{a, b}, {c,\
    \ d}}));\n            });\n        }\n    }\n}"
  dependsOn:
  - library/template/template.cpp
  - library/graph/tree/HLD.cpp
  - library/math/Matrix.cpp
  - library/mod/modint.cpp
  - library/structure/segtree/SegmentTree.cpp
  isVerificationFile: true
  path: verify/yuki-650.test.cpp
  requiredBy: []
  timestamp: '2021-08-26 10:32:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yuki-650.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki-650.test.cpp
- /verify/verify/yuki-650.test.cpp.html
title: verify/yuki-650.test.cpp
---
