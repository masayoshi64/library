#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "library/template/template.cpp"
// library
#include "library/convolution/NTT.cpp"
#include "library/mod/modint.cpp"
using mint = modint<998244353>;
int main() {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    NTT<mint> ntt;
    auto c = ntt.multiply(a, b);
    rep(i, n + m - 1) { cout << c[i] << ' '; }
    cout << endl;
}