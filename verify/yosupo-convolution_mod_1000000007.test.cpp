#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "library/template/template.cpp"
// library
#include "library/mod/modint.cpp"
//
#include "library/convolution/FFT.cpp"
using mint = modint<1000000007>;
FFT fft;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    auto c = fft.multiply(a, b);
    rep(i, n + m - 1) { cout << c[i] << ' '; }
    cout << endl;
}