#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "library/template/template.cpp"
// library
#include "library/structure/BIT/BIT.cpp"
int main() {
    int n, q;
    cin >> n >> q;
    BIT<ll> bit(n);
    rep(i, q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            x--;
            bit.add(x, y);
        } else {
            x--;
            print(bit.sum(x, y));
        }
    }
}