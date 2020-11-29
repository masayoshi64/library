#define PROBLEM "https://yukicoder.me/problems/no/1302"
#include "library/template/template.cpp"
// library
#include "library/convolution/NTT.cpp"
#include "library/math/FormalPowerSeries.cpp"
#include "library/math/combination.cpp"
#include "library/mod/modint.cpp"
using mint = modint<998244353>;
using FPS = FormalPowerSeries<mint>;
NTT<mint> ntt;
FPS mult_ntt(const FPS::P& a, const FPS::P& b) {
    auto ret = ntt.multiply(a, b);
    return FPS::P(ret.begin(), ret.end());
}
// FPS::set_fft(mult_ntt); in main
int main() {
    FPS::set_fft(mult_ntt);
    int n;
    cin >> n;
    Combination<mint> comb(n);
    FPS f(n + 1);
    rep(i, n + 1) { f[i] = (mint)(i + 1) / comb.fact(i); }
    f = f.pow(n, n);
    print(f[n - 2] * comb.fact(n - 2) / mypow<mint>(n, n - 2));
}