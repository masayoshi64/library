#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446"
#define ERROR "1e-6"
#include "library/template/template.cpp"
// library
#include "library/convolution/FZT.cpp"
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(30) << fixed;
    ll n, m;
    cin >> n >> m;
    vl a(n);
    vector<ld> p(n);
    scan(a);
    rep(i, n) cin >> p[i], p[i] /= 100;
    vector<ll> f(1 << n);
    rep(s, 1 << n) {
        ll prod = 1;
        rep(i, n) {
            if ((s & (1 << i)) == 0) continue;
            ll g = gcd(prod, a[i]);
            if ((__int128_t)prod * a[i] / g <= m)
                prod = prod * (a[i] / g);
            else
                prod = m + 1;
        }
        if (s == 0) continue;
        f[s] = (popcnt(s) % 2 ? 1 : -1) * (m / prod);
    }
    // FZTで包除原理
    auto g = FZT(f);
    ld ans = 0;
    // 期待値計算
    rep(s, 1 << n) {
        ld ps = 1;
        rep(i, n) {
            if ((s & (1 << i)) == 0)
                ps *= 1 - p[i];
            else
                ps *= p[i];
        }
        ll tmp = g[s];
        ans += ps * g[s];
    }
    print(ans);
}