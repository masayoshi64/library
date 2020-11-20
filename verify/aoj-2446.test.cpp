#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446"

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
    vector<ld> f(1 << n);
    rep(s, 1 << n) {
        ll prod = 1;
        rep(i, n) {
            if ((s & (1 << i)) == 0) continue;
            if ((__int128_t)prod * a[i] <= m)
                prod *= a[i];
            else
                prod = m + 1;
        }
        f[s] = (popcnt(s) % 2 ? -1 : 1) * (m / prod);
    }
    // FZTで包除原理
    auto g = FZT(f);
    ld ans = 0;
    // 期待値計算
    rep(s, 1 << n) {
        double ps = 1;
        rep(i, n) {
            if ((s & (1 << i)) == 0)
                ps *= 1 - p[i];
            else
                ps *= p[i];
        }
        ans += ps * g[s];
    }
    print((ld)m - ans);
}