#define PROBLEM "https://yukicoder.me/problems/no/650"
#include "library/template/template.cpp"
// library
#include "library/graph/tree/HLD.cpp"
#include "library/math/Matrix.cpp"
#include "library/mod/modint.cpp"
#include "library/structure/segtree/SegmentTree.cpp"
using mint = modint<1000000007>;
using mmat = Matrix<mint>;
int main() {
    int n, q;
    cin >> n;
    HLD hld(n);
    vector<Pi> etov(n - 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        hld.add_edge(a, b);
        etov[i] = mp(a, b);
    }
    cin >> q;
    SegmentTree<mmat> seg(
        n, [&](mmat a, mmat b) { return a * b; }, mmat::I(2));
    hld.build();
    rep(_, q) {
        char t;
        cin >> t;
        if (t == 'g') {
            int u, v;
            cin >> u >> v;
            mmat res = hld.query_edge(
                u, v, mmat::I(2),
                [&](int a, int b) { return seg.query(a, b + 1); },
                [&](mmat a, mmat b) { return a * b; });
            cout << res[0][0] << " " << res[0][1] << " " << res[1][0] << " "
                 << res[1][1] << "\n";
        } else {
            int i, a, b, c, d;
            cin >> i >> a >> b >> c >> d;
            int u = etov[i].first, v = etov[i].second;
            hld.update_edge(u, v, [&](int l, int r) {
                return seg.update(l, mmat({{a, b}, {c, d}}));
            });
        }
    }
}