#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165"

#include "library/template/template.cpp"
// library
#include "library/structure/segtree/DualSegmentTree.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    auto h = [&](Pi p, Pi q) {
        return mp(p.first + q.first, p.second + q.second);
    };
    auto dp = get_dual_segment_tree<Pi>(n, h, mp(0, 0));

    rep(i, q) {
        int l, k;
        cin >> l >> k;
        l--;
        dp.update(l, l + k, mp(1 - l, 1));
    }
    rep(i, n - 1) cout << dp[i].first + dp[i].second * i << ' ';
    cout << dp[n - 1].first + dp[n - 1].second * (n - 1) << endl;
}