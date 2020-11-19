#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include "library/template/template.cpp"
// library
#include "library/graph/tree/ReRooting.cpp"
int main() {
    int n;
    cin >> n;
    auto f = [&](ll x, int u) { return x + 1; };
    auto merge = [&](ll x, ll y) { return max(x, y); };
    ReRooting<ll> rr(n, f, merge, 0);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        rr.add_edge(u, v);
    }
    rr.build();
    rep(i, n) { print((n - 1) * 2 - rr.query(i)); }
}