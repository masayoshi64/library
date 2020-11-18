#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "library/template/template.cpp"
// library
#include "library/convolution/NTT.cpp"
#include "library/mod/modint.cpp"
//
#include "library/convolution/FFT.cpp"
#include "library/math/FormalPowerSeries.cpp"
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