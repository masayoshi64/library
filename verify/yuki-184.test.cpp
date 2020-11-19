#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "library/template/template.cpp"
// library
#include "library/math/BitMatrix.cpp"
int main() {
    int n;
    cin >> n;
    BitMatrix bm(n, 60);
    vl a(n);
    scan(a);
    rep(i, n) { bm[i] = a[i]; }
    bm.build();
    print(((ll)1 << bm.rank));
}