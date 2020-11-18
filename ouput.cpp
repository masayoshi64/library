#line 1 "verify/yuki-650.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/650"
#line 1 "library/template/template.cpp"
/* #region header */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// types
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<ll, ll> Pl;
typedef pair<int, int> Pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
template <typename T>
using mat = vector<vector<T>>;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<char>> vvc;
// abreviations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep_(i, a_, b_, a, b, ...) for (ll i = (a), max_i = (b); i < max_i; i++)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define rrep_(i, a_, b_, a, b, ...) \
    for (ll i = (b - 1), min_i = (a); i >= min_i; i--)
#define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define srep(i, a, b, c) for (ll i = (a), max_i = (b); i < max_i; i += c)
#define SZ(x) ((int)(x).size())
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp make_pair
//入出力
#define print(x) cout << x << endl
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto& e : v) cout << e << " ";
    cout << endl;
    return os;
}
void scan(int& a) { cin >> a; }
void scan(long long& a) { cin >> a; }
void scan(char& a) { cin >> a; }
void scan(double& a) { cin >> a; }
void scan(string& a) { cin >> a; }
template <class T>
void scan(vector<T>& a) {
    for (auto& i : a) scan(i);
}
#define vsum(x) accumulate(all(x), 0LL)
#define vmax(a) *max_element(all(a))
#define vmin(a) *min_element(all(a))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
// functions
// gcd(0, x) fails.
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
T mypow(T x, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}
ll modpow(ll x, ll n, const ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x);
        (x *= x);
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}

uint64_t my_rand(void) {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}
int popcnt(ull x) { return __builtin_popcountll(x); }
// graph template
template <typename T>
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge& operator=(const int& x) {
        to = x;
        return *this;
    }

    bool operator<(const edge<T>& r) const { return cost < r.cost; }

    operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
struct Timer {
    clock_t start_time;
    void start() { start_time = clock(); }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};
/* #endregion*/
// constant
#define inf 1000000000ll
#define INF 4000000004000000000LL
#define endl '\n'
const long double eps = 0.000000000000001;
const long double PI = 3.141592653589793;
#line 3 "verify/yuki-650.test.cpp"
// library
#line 1 "library/graph/tree/HLD.cpp"
struct HLD {
    vector<vector<int>> G;
    vector<int> parent, depth, sub_size, v_id, id_to_v, head;
    HLD(int n)
        : G(n),
          v_id(n, -1),
          head(n),
          sub_size(n, 1),
          parent(n, -1),
          depth(n, 0),
          id_to_v(n) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(int root = 0) {
        int pos = 0;
        dfs_size(root);
        head[root] = root;
        dfs_hld(root, pos);
    }

    void dfs_size(int v) {
        for (int& nv : G[v]) {
            if (nv == parent[v]) {
                nv = G[v].back();
                G[v].pop_back();
            }
        }
        for (int& nv : G[v]) {
            parent[nv] = v;
            depth[nv] = depth[v] + 1;
            dfs_size(nv);
            sub_size[v] += sub_size[nv];
            if (sub_size[nv] > sub_size[G[v][0]]) swap(nv, G[v][0]);
        }
    }

    void dfs_hld(int v, int& pos) {
        v_id[v] = pos;
        id_to_v[pos++] = v;
        for (int nv : G[v]) {
            head[nv] = (nv == G[v][0] ? head[v] : nv);
            dfs_hld(nv, pos);
        }
    }

    int lca(int u, int v) {
        while (1) {
            if (v_id[u] > v_id[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = parent[head[v]];
        }
    }

    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // update vertexes in [u, v] with f
    template <typename F>
    void update(int u, int v, const F& f) {
        while (1) {
            if (v_id[u] > v_id[v]) swap(u, v);
            f(max(v_id[head[v]], v_id[u]), v_id[v]);
            if (head[u] != head[v])
                v = parent[head[v]];
            else
                break;
        }
    }

    // get res for [u, v] with query q and merge each value with f
    template <typename T, typename Q, typename F>
    T query(int u, int v, T id, const Q& q, const F& f) {
        T l = id, r = id;
        while (1) {
            if (v_id[u] > v_id[v]) {
                swap(u, v);
                swap(l, r);
            }
            l = f(l, q(max(v_id[head[v]], v_id[u]), v_id[v]));
            if (head[u] != head[v])
                v = parent[head[v]];
            else
                break;
        }
        return f(l, r);
    }

    // update edges between u, v inclusive with func f
    template <typename F>
    void update_edge(int u, int v, const F& f) {
        while (1) {
            if (v_id[u] > v_id[v]) swap(u, v);
            if (head[u] != head[v]) {
                f(v_id[head[v]], v_id[v]);
                v = parent[head[v]];
            } else {
                if (u != v) f(v_id[u] + 1, v_id[v]);
                break;
            }
        }
    }

    // query for edges between u, v inclusive with query q and merge func f
    template <typename T, typename Q, typename F>
    T query_edge(int u, int v, T id, const Q& q, const F& f) {
        T l = id, r = id;
        while (1) {
            if (v_id[u] > v_id[v]) {
                swap(u, v);
                swap(l, r);
            }
            if (head[u] != head[v]) {
                l = f(l, q(v_id[head[v]], v_id[v]));
                v = parent[head[v]];
            } else {
                if (u != v) l = f(l, q(v_id[u] + 1, v_id[v]));
                break;
            }
        }
        return f(l, r);
    }
};
#line 1 "library/math/Matrix.cpp"
template <class T>
struct Matrix {
    vector<vector<T>> A;

    Matrix() {}

    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}

    Matrix(size_t n) : A(n, vector<T>(n, 0)){};

    Matrix(vector<vector<T>> a) { A = a; }

    size_t height() const { return (A.size()); }

    size_t width() const { return (A[0].size()); }

    inline const vector<T> &operator[](int k) const { return (A.at(k)); }

    inline vector<T> &operator[](int k) { return (A.at(k)); }

    static Matrix I(size_t n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
    }

    Matrix &operator+=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
        return (*this);
    }

    Matrix &operator-=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];
        return (*this);
    }

    Matrix &operator*=(const Matrix &B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector<vector<T>> C(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++)
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }

    Matrix &operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return (*this);
    }

    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

    Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

    Matrix pow(long long n) {
        Matrix ret = I(height());
        Matrix x = Matrix(*this);
        while (n > 0) {
            if (n & 1) (ret *= x);
            (x *= x);
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, Matrix &p) {
        size_t n = p.height(), m = p.width();
        for (int i = 0; i < n; i++) {
            os << "[";
            for (int j = 0; j < m; j++) {
                os << p[i][j] << (j + 1 == m ? "]\n" : ",");
            }
        }
        return (os);
    }

    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++) {
            int idx = -1;
            for (int j = i; j < width(); j++) {
                if (B[j][i] != 0) idx = j;
            }
            if (idx == -1) return (0);
            if (i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++) {
                B[i][j] /= vv;
            }
            for (int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return (ret);
    }
};
#line 1 "library/mod/modint.cpp"
template <int mod>
struct modint {
    int x;

    modint() : x(0) {}

    modint(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    modint& operator+=(const modint& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    modint& operator-=(const modint& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    modint& operator*=(const modint& p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    modint& operator/=(const modint& p) {
        *this *= p.inverse();
        return *this;
    }

    modint operator-() const { return modint(-x); }

    modint operator+(const modint& p) const { return modint(*this) += p; }

    modint operator-(const modint& p) const { return modint(*this) -= p; }

    modint operator*(const modint& p) const { return modint(*this) *= p; }

    modint operator/(const modint& p) const { return modint(*this) /= p; }

    bool operator==(const modint& p) const { return x == p.x; }

    bool operator!=(const modint& p) const { return x != p.x; }

    modint inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }

    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const modint& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, modint& a) {
        long long t;
        is >> t;
        a = modint<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};
#line 1 "library/structure/segtree/SegmentTree.cpp"
/**
 * @brief Segment Tree
 * @docs docs/segmenttree.md
 */
template <typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) { seg[k + sz] = x; }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const { return seg[k + sz]; }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            Monoid nxt =
                type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    // check(seg[i])を満たす最小のb<=iを返す.なければ-1
    template <typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    // check(seg[i])を満たす最小のi<bを返す.なければ-1
    template <typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};
#line 8 "verify/yuki-650.test.cpp"
using mint = modint<1000000007>;
using mmat = Matrix<mint>;

int main() {
    int n, q;
    cin >> n;
    HLD hld(n);
    vector<Pi> etov(n - 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        hld.add_edge(a, b);
        etov[i] = mp(a, b);
    }
    cin >> q;
    SegmentTree<mmat> seg(
        n, [&](mmat a, mmat b) { return a * b; }, mmat::I(2));
    hld.build();
    rep(_, q) {
        char t;
        cin >> t;
        if (t == 'g') {
            int u, v;
            cin >> u >> v;
            mmat res = hld.query_edge(
                u, v, mmat::I(2),
                [&](int a, int b) { return seg.query(a, b + 1); },
                [&](mmat a, mmat b) { return a * b; });
            rep(r, 2) {
                rep(c, 2) { cout << res[r][c] << ' '; }
            }
            cout << endl;
        } else {
            int i, a, b, c, d;
            cin >> i >> a >> b >> c >> d;
            auto [u, v] = etov[i];
            hld.update_edge(u, v, [&](int l, int r) {
                return seg.update(l, mmat({{a, b}, {c, d}}));
            });
        }
    }
}
