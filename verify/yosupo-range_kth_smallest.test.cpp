#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "library/template/template.cpp"
// library
#include "library/structure/wavelet/WaveletMatrix.cpp"
int main() {
    int n, q;
    cin >> n >> q;
    vl a(n);
    scan(a);
    WaveletMatrix<ll, 32> wm(a);
    rep(_, q) {
        int l, r, k;
        cin >> l >> r >> k;
        print(wm.kth_smallest(l, r, k));
    }
}