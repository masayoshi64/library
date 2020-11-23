#define PROBLEM "https://yukicoder.me/problems/no/545"

#include "library/template/template.cpp"
// library
#include "library/dp/rekkyo.cpp"
int main() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) a[i] += b[i];
    ll sm = vsum(b);
    auto x = rekkyo<ll>({a.begin(), a.begin() + n / 2});
    auto y = rekkyo<ll>({a.begin() + n / 2, a.end()});
    ll smx = accumulate(b.begin(), b.begin() + n / 2, 0ll);
    ll smy = accumulate(b.begin() + n / 2, b.end(), 0ll);
    for (ll& xi : x) xi -= smx;
    for (ll& yi : y) yi -= smy;
    reverse(all(x));
    ll ans = INF;
    auto iter = y.begin();
    for (ll xi : x) {
        while (iter != y.end() && *iter + xi < 0) iter++;
        chmin(ans, abs(*iter + xi));
        if (iter != y.begin()) {
            chmin(ans, abs(*(iter - 1) + xi));
        }
    }
    print(ans);
}