#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "library/template/template.cpp"
// library
#include "library/convolution/FFT.cpp"
#include "library/math/FormalPowerSeries.cpp"
#include "library/mod/modint.cpp"
using mint = modint<1000000007>;
using FPS = FormalPowerSeries<mint>;
FFT<mint> fft;
FPS mult_fft(const FPS::P& a, const FPS::P& b) {
    auto ret = fft.multiply(a, b);
    return FPS::P(ret.begin(), ret.end());
}
FPS mult(const FPS::P& a, const FPS::P& b) {
    FPS c(a.size() + b.size() - 1);
    rep(i, a.size()) rep(j, b.size()) { c[i + j] += a[i] * b[j]; }
    return c;
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