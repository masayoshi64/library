#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "library/template/template.cpp"
// library
#include "library/graph/flow/MinCostFlow.cpp"
int main() {
    ll v, e, f;
    cin >> v >> e >> f;
    MinCostFlow<ll, ll> mf(v);
    rep(i, e) {
        ll u, v, c, d;
        cin >> u >> v >> c >> d;
        mf.add_edge(u, v, c, d);
    }
    print(mf.min_cost_flow(0, v - 1, f));
}