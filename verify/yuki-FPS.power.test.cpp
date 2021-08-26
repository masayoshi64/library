#define PROBLEM "https://yukicoder.me/problems/no/1302"
#include "library/template/template.cpp"
// library
#include "library/math/FormalPowerSeries.cpp"
#include "library/math/combination.cpp"
#include "library/mod/modint.cpp"
using mint = modint<998244353>;
FFT<mint> fft;
using FPS = FormalPowerSeries<mint, fft>;
int main()
{
    int n;
    cin >> n;
    Combination<mint> comb(n);
    FPS f(n + 1);
    rep(i, n + 1) { f[i] = (mint)(i + 1) / comb.fact(i); }
    f = f.pow(n, n);
    print(f[n - 2] * comb.fact(n - 2) / mypow<mint>(n, n - 2));
}