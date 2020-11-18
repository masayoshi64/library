#line 1 "verify/yosupo-convolution_mod_1000000007.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
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
#line 3 "verify/yosupo-convolution_mod_1000000007.test.cpp"
// library
#line 1 "library/convolution/NTT.cpp"
template <typename Mint>
struct NTT {
    vector<Mint> dw, idw;
    int max_base;
    Mint root;

    NTT() {
        const unsigned mod = Mint::get_mod();
        assert(mod >= 3 && mod % 2 == 1);
        auto tmp = mod - 1;
        max_base = 0;
        while (tmp % 2 == 0) tmp >>= 1, max_base++;
        root = 2;
        while (root.pow((mod - 1) >> 1) == 1) root += 1;
        assert(root.pow(mod - 1) == 1);
        dw.resize(max_base);
        idw.resize(max_base);
        for (int i = 0; i < max_base; i++) {
            dw[i] = -root.pow((mod - 1) >> (i + 2));
            idw[i] = Mint(1) / dw[i];
        }
    }

    void ntt(vector<Mint>& a) {
        const int n = (int)a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        for (int m = n; m >>= 1;) {
            Mint w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = a[i], y = a[j] * w;
                    a[i] = x + y, a[j] = x - y;
                }
                w *= dw[__builtin_ctz(++k)];
            }
        }
    }

    void intt(vector<Mint>& a, bool f = true) {
        const int n = (int)a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        for (int m = 1; m < n; m *= 2) {
            Mint w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = a[i], y = a[j];
                    a[i] = x + y, a[j] = (x - y) * w;
                }
                w *= idw[__builtin_ctz(++k)];
            }
        }
        if (f) {
            Mint inv_sz = Mint(1) / n;
            for (int i = 0; i < n; i++) a[i] *= inv_sz;
        }
    }

    vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
        int need = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need) nbase++;
        int sz = 1 << nbase;
        a.resize(sz, 0);
        b.resize(sz, 0);
        ntt(a);
        ntt(b);
        Mint inv_sz = Mint(1) / sz;
        for (int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;
        intt(a, false);
        a.resize(need);
        return a;
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

    inline int get() { return x; }
};
#line 6 "verify/yosupo-convolution_mod_1000000007.test.cpp"
//
#line 1 "library/convolution/FFT.cpp"
// namespace FastFourierTransform {
// using real = long double;

// struct C {
//     real x, y;

//     C() : x(0), y(0) {}

//     C(real x, real y) : x(x), y(y) {}

//     inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

//     inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

//     inline C operator*(const C &c) const {
//         return C(x * c.x - y * c.y, x * c.y + y * c.x);
//     }

//     inline C conj() const { return C(x, -y); }
// };

// const real PI = acosl(-1);
// int base = 1;
// vector<C> rts = {{0, 0}, {1, 0}};
// vector<int> rev = {0, 1};

// void ensure_base(int nbase) {
//     if (nbase <= base) return;
//     rev.resize(1 << nbase);
//     rts.resize(1 << nbase);
//     for (int i = 0; i < (1 << nbase); i++) {
//         rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
//     }
//     while (base < nbase) {
//         real angle = PI * 2.0 / (1 << (base + 1));
//         for (int i = 1 << (base - 1); i < (1 << base); i++) {
//             rts[i << 1] = rts[i];
//             real angle_i = angle * (2 * i + 1 - (1 << base));
//             rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
//         }
//         ++base;
//     }
// }

// void fft(vector<C> &a, int n) {
//     assert((n & (n - 1)) == 0);
//     int zeros = __builtin_ctz(n);
//     ensure_base(zeros);
//     int shift = base - zeros;
//     for (int i = 0; i < n; i++) {
//         if (i < (rev[i] >> shift)) {
//             swap(a[i], a[rev[i] >> shift]);
//         }
//     }
//     for (int k = 1; k < n; k <<= 1) {
//         for (int i = 0; i < n; i += 2 * k) {
//             for (int j = 0; j < k; j++) {
//                 C z = a[i + j + k] * rts[j + k];
//                 a[i + j + k] = a[i + j] - z;
//                 a[i + j] = a[i + j] + z;
//             }
//         }
//     }
// }

// vector<int64_t> multiply(const vector<int> &a, const vector<int> &b) {
//     int need = (int)a.size() + (int)b.size() - 1;
//     int nbase = 1;
//     while ((1 << nbase) < need) nbase++;
//     ensure_base(nbase);
//     int sz = 1 << nbase;
//     vector<C> fa(sz);
//     for (int i = 0; i < sz; i++) {
//         int x = (i < (int)a.size() ? a[i] : 0);
//         int y = (i < (int)b.size() ? b[i] : 0);
//         fa[i] = C(x, y);
//     }
//     fft(fa, sz);
//     C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
//     for (int i = 0; i <= (sz >> 1); i++) {
//         int j = (sz - i) & (sz - 1);
//         C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
//         fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
//         fa[i] = z;
//     }
//     for (int i = 0; i < (sz >> 1); i++) {
//         C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
//         C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
//         fa[i] = A0 + A1 * s;
//     }
//     fft(fa, sz >> 1);
//     vector<int64_t> ret(need);
//     for (int i = 0; i < need; i++) {
//         ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
//     }
//     return ret;
// }
// };  // namespace FastFourierTransform
// #include "library/convolution/NTT.cpp"
// #include "library/mod/modint.cpp"
// template <typename Mint>
// struct FFT {
//     constexpr int mod0 = 1045430273;
//     constexpr int mod1 = 1051721729;
//     constexpr int mod2 = 1053818881;
//     using mint0 = modint<mod0>;
//     using mint1 = modint<mod1>;
//     using mint2 = modint<mod2>;
//     NTT<mint0> ntt0;
//     NTT<mint1> ntt1;
//     NTT<mint2> ntt2;
//     vector<Mint> multiply(const vector<int> &x, const vector<int> &y) {
//         auto d0 = ntt0.multiply(x, y);
//         auto d1 = ntt1.multiply(x, y);
//         auto d2 = ntt2.multiply(x, y);
//         int n = d0.size();
//         vector<Mint> res(n);
//         static const mint1 r01 = mint1(mint0.get_mod()).inv();
//         static const mint2 r02 = mint2(mint0.get_mod()).inv();
//         static const mint2 r12 = mint2(mint1.get_mod()).inv();
//         static const mint2 r02r12 = r02 * r12;
//         static const Mint w1 = Mint(mint0.get_mod());
//         static const Mint w2 = w1 * Mint(mint1.get_mod());
//         rep(i, n) {
//             ull a = d0[i].v;
//             ull b = (d1[i].v + mint1.get_mod() - a) * r01.v %
//             mint1.get_mod(); ull c = ((d2[i].v + mint2.get_mod() - a) *
//             r02r12.v +
//                      (mint2.get_mod() - b) * r12.v) %
//                     mint2.get_mod();
//             res[i].v = (a + b * w1.v + c * w2.v) % Mint.get_mod();
//         }
//         return res;
//     }
// };

// template <class mint>
// void inplace_fmt(vector<mint> &f, bool inv) {
//     const int n = f.size();
//     static vector<mint> g, ig, p2;
//     if (g.size() == 0) {
//         rep(i, 30) {
//             mint w = -mint::root().pow(((mint::mod - 1) >> (i + 2)) * 3);
//             g.pb(w);
//             ig.pb(w.inv());
//             p2.pb(mint(1 << i).inv());
//         }
//     }
//     static constexpr uint mod2 = mint::mod * 2;
//     if (!inv) {
//         int b = n;
//         if (b >>= 1) {  // input:[0,mod)
//             rep(i, b) {
//                 uint x = f[i + b].x;
//                 f[i + b].x = f[i].x + mint::mod - x;
//                 f[i].x += x;
//             }
//         }
//         if (b >>= 1) {  // input:[0,mod*2)
//             mint p = 1;
//             for (int i = 0, k = 0; i < n; i += b * 2) {
//                 rep(j, i, i + b) {
//                     uint x = (f[j + b] * p).x;
//                     f[j + b].x = f[j].x + mint::mod - x;
//                     f[j].x += x;
//                 }
//                 p *= g[__builtin_ctz(++k)];
//             }
//         }
//         while (b) {
//             if (b >>= 1) {  // input:[0,mod*3)
//                 mint p = 1;
//                 for (int i = 0, k = 0; i < n; i += b * 2) {
//                     rep(j, i, i + b) {
//                         uint x = (f[j + b] * p).x;
//                         f[j + b].x = f[j].x + mint::mod - x;
//                         f[j].x += x;
//                     }
//                     p *= g[__builtin_ctz(++k)];
//                 }
//             }
//             if (b >>= 1) {  // input:[0,mod*4)
//                 mint p = 1;
//                 for (int i = 0, k = 0; i < n; i += b * 2) {
//                     rep(j, i, i + b) {
//                         uint x = (f[j + b] * p).x;
//                         f[j].x = (f[j].x < mod2 ? f[j].x : f[j].x - mod2);
//                         f[j + b].x = f[j].x + mint::mod - x;
//                         f[j].x += x;
//                     }
//                     p *= g[__builtin_ctz(++k)];
//                 }
//             }
//         }
//     } else {
//         int b = 1;
//         if (b < n / 2) {  // input:[0,mod)
//             mint p = 1;
//             for (int i = 0, k = 0; i < n; i += b * 2) {
//                 rep(j, i, i + b) {
//                     ull x = f[j].v + mint::mod - f[j + b].v;
//                     f[j].v += f[j + b].v;
//                     f[j + b].v = x * p.v % mint::mod;
//                 }
//                 p *= ig[__builtin_ctz(++k)];
//             }
//             b <<= 1;
//         }
//         for (; b < n / 2; b <<= 1) {  // input:[0,mod*2)
//             mint p = 1;
//             for (int i = 0, k = 0; i < n; i += b * 2) {
//                 rep(j, i, i + b / 2) {
//                     ull x = f[j].v + mod2 - f[j + b].v;
//                     f[j].v += f[j + b].v;
//                     f[j].v = (f[j].v) < mod2 ? f[j].v : f[j].v - mod2;
//                     f[j + b].v = x * p.v % mint::mod;
//                 }
//                 rep(j, i + b / 2, i + b) {
//                     ull x = f[j].v + mod2 - f[j + b].v;
//                     f[j].v += f[j + b].v;
//                     // f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
//                     f[j + b].v = x * p.v % mint::mod;
//                 }
//                 p *= ig[__builtin_ctz(++k)];
//             }
//         }
//         if (b < n) {  // input:[0,mod*2)
//             rep(i, b) {
//                 uint x = f[i + b].v;
//                 f[i + b].v = f[i].v + mod2 - x;
//                 f[i].v += x;
//             }
//         }
//         int lg = 1;
//         int tmp = n;
//         while (tmp > 1) lg *= 2, tmp /= 2;
//         mint z = p2[lg];
//         rep(i, n) f[i] *= z;
//     }
// }
// template <class mint>
// vector<mint> multiply(vector<mint> x, const vector<mint> &y,
//                       bool same = false) {
//     int n = x.size() + y.size() - 1;
//     int s = 1;
//     while (s < n) s *= 2;
//     x.resize(s);
//     inplace_fmt(x, false);
//     if (!same) {
//         vector<mint> z(s);
//         rep(i, y.size()) z[i] = y[i];
//         inplace_fmt(z, false);
//         rep(i, s) x[i] *= z[i];
//     } else {
//         rep(i, s) x[i] *= x[i];
//     }
//     inplace_fmt(x, true);
//     x.resize(n);
//     return x;
// }

template <int mod>
vector<int> multiply(vector<int>& a, vector<int>& b) {
    using mint = modint<mod>;
    using mint1 = modint<167772161>;
    using mint2 = modint<469762049>;
    using mint3 = modint<595591169>;
    NTT<mint1> ntt1;
    NTT<mint2> ntt2;
    NTT<mint3> ntt3;
    vector<mint1> a1(begin(a), end(a)), b1(begin(b), end(b));
    vector<mint2> a2(begin(a), end(a)), b2(begin(b), end(b));
    vector<mint3> a3(begin(a), end(a)), b3(begin(b), end(b));
    auto x = ntt1.multiply(a1, b1);
    auto y = ntt2.multiply(a2, b2);
    auto z = ntt3.multiply(a3, b3);
    const int m1 = 167772161, m2 = 469762049, m3 = 595591169;
    const auto m1_inv_m2 = mint2(m1).inverse().get();
    const auto m12_inv_m3 = (mint3(m1) * m2).inverse().get();
    const auto m12_mod = (mint(m1) * m2).get();
    vector<int> ret(x.size());
    for (int i = 0; i < x.size(); i++) {
        auto v1 = ((mint2(y[i]) + m2 - x[i].get()) * m1_inv_m2).get();
        auto v2 =
            ((z[i] + m3 - x[i].get() - mint3(m1) * v1) * m12_inv_m3).get();
        ret[i] = (mint(x[i].get()) + mint(m1) * v1 + mint(m12_mod) * v2).get();
    }
    return ret;
}
#line 1 "library/math/FormalPowerSeries.cpp"
template <typename T>
struct FormalPowerSeries : vector<T> {
    using vector<T>::vector;
    using P = FormalPowerSeries;

    using MULT = function<P(P, P)>;

    static MULT& get_mult() {
        static MULT mult = nullptr;
        return mult;
    }

    static void set_fft(MULT f) { get_mult() = f; }

    // 末尾の0を消す
    void shrink() {
        while (this->size() && this->back() == T(0)) this->pop_back();
    }

    P operator+(const P& r) const { return P(*this) += r; }

    P operator+(const T& v) const { return P(*this) += v; }

    P operator-(const P& r) const { return P(*this) -= r; }

    P operator-(const T& v) const { return P(*this) -= v; }

    P operator*(const P& r) const { return P(*this) *= r; }

    P operator*(const T& v) const { return P(*this) *= v; }

    P operator/(const P& r) const { return P(*this) /= r; }

    P operator%(const P& r) const { return P(*this) %= r; }

    P& operator+=(const P& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < r.size(); i++) (*this)[i] += r[i];
        return *this;
    }

    P& operator+=(const T& r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }

    P& operator-=(const P& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
        shrink();
        return *this;
    }

    P& operator-=(const T& r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        shrink();
        return *this;
    }

    P& operator*=(const T& v) {
        const int n = (int)this->size();
        for (int k = 0; k < n; k++) (*this)[k] *= v;
        return *this;
    }

    P& operator*=(const P& r) {
        if (this->empty() || r.empty()) {
            this->clear();
            return *this;
        }
        assert(get_mult() != nullptr);
        return *this = get_mult()(*this, r);
    }

    P& operator%=(const P& r) { return *this -= *this / r * r; }

    P operator-() const {
        P ret(this->size());
        for (int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
        return ret;
    }

    P& operator/=(const P& r) {
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
    }

    P pre(int sz) const {
        return P(begin(*this), begin(*this) + min((int)this->size(), sz));
    }

    // f/x^sz
    P operator>>(int sz) const {
        if (this->size() <= sz) return {};
        P ret(*this);
        ret.erase(ret.begin(), ret.begin() + sz);
        return ret;
    }

    // f*x^sz
    P operator<<(int sz) const {
        P ret(*this);
        ret.insert(ret.begin(), sz, T(0));
        return ret;
    }

    // 反転
    P rev(int deg = -1) const {
        P ret(*this);
        if (deg != -1) ret.resize(deg, T(0));
        reverse(begin(ret), end(ret));
        return ret;
    }

    //微分
    P diff() const {
        const int n = (int)this->size();
        P ret(max(0, n - 1));
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
        return ret;
    }

    // 積分
    P integral() const {
        const int n = (int)this->size();
        P ret(n + 1);
        ret[0] = T(0);
        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
        return ret;
    }

    // 1/fのdeg項
    // F(0) must not be 0
    P inv(int deg = -1) const {
        assert(((*this)[0]) != T(0));
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        P ret({T(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
        }
        return ret.pre(deg);
    }

    // F(0) must be 1
    P log(int deg = -1) const {
        assert((*this)[0] == 1);
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    P sqrt(int deg = -1) const {
        const int n = (int)this->size();
        if (deg == -1) deg = n;

        if ((*this)[0] == T(0)) {
            for (int i = 1; i < n; i++) {
                if ((*this)[i] != T(0)) {
                    if (i & 1) return {};
                    if (deg - i / 2 <= 0) break;
                    auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
                    if (ret.size() < deg) ret.resize(deg, T(0));
                    return ret;
                }
            }
            return P(deg, 0);
        }

        P ret({T(1)});
        T inv2 = T(1) / T(2);
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
        }
        return ret.pre(deg);
    }

    // F(0) must be 0
    P exp(int deg = -1) const {
        assert((*this)[0] == T(0));
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        P ret({T(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
    }

    P pow(int64_t k, int deg = -1) const {
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != T(0)) {
                T rev = T(1) / (*this)[i];
                P C(*this * rev);
                P D(n - i);
                for (int j = i; j < n; j++) D[j - i] = C[j];
                D = (D.log() * k).exp() * (*this)[i].pow(k);
                P E(deg);
                if (i * k > deg) return E;
                auto S = i * k;
                for (int j = 0; j + S < deg && j < D.size(); j++)
                    E[j + S] = D[j];
                return E;
            }
        }
        return *this;
    }

    //代入
    T eval(T x) const {
        T r = 0, w = 1;
        for (auto& v : *this) {
            r += w * v;
            w *= x;
        }
        return r;
    }
};

// NTT<mint> ntt;
// FPS mult_ntt(const FPS::P& a, const FPS::P& b) {
//     auto ret = ntt.multiply(a, b);
//     return FPS::P(ret.begin(), ret.end());
// }
// FPS mult(const FPS::P& a, const FPS::P& b) {
//     FPS c(a.size() + b.size() - 1);
//     rep(i, a.size()) rep(j, b.size()) { c[i + j] += a[i] * b[j]; }
//     return c;
// }
#line 9 "verify/yosupo-convolution_mod_1000000007.test.cpp"
using mint = modint<1000000007>;
using FPS = FormalPowerSeries<mint>;
FPS mult_fft(const FPS::P& a, const FPS::P& b) {
    vi aa(a.size()), bb(b.size());
    rep(i, a.size()) aa[i] = a[i].x;
    rep(i, b.size()) bb[i] = b[i].x;
    auto ret = multiply<1000000007>(aa, bb);
    return FPS::P(ret.begin(), ret.end());
}
// FPS::set_fft(mult_ntt); in main
int main() {
    int n, m;
    cin >> n >> m;
    FPS a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    FPS::set_fft(mult_fft);
    auto c = a * b;
    rep(i, n + m - 1) { cout << c[i] << ' '; }
    cout << endl;
}
