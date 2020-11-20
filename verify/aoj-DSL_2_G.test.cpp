#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "library/template/template.cpp"
// library
#include "library/structure/segtree/LazySegmentTree.cpp"
int main() {
    int n, q;
    cin >> n >> q;
    RSRAQ<ll> seg(n);
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            s--;
            seg.update(s, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            s--;
            print(seg.query(s, t));
        }
    }
}