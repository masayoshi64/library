#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530"

#include "library/template/template.cpp"
// library
#include "library/math/BitMatrix.cpp"
int main() {
    int r, c;
    cin >> r >> c;
    BitMatrix<2505, 2505> bm(r * c, r * c + 1);
    rep(i, r) {
        rep(j, c) {
            int b;
            cin >> b;
            int k = i * c + j;
            bm[k][r * c] = b;
        }
    }
    rep(i, r) {
        rep(j, c) {
            int b;
            cin >> b;
            int k = i * c + j;
            bm[k][r * c] = b;
        }
    }
}