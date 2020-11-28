#define PROBLEM "https://yukicoder.me/problems/no/1301"
#include "library/template/template.cpp"
// library
#include "library/graph/flow/MinCostFlow.cpp"
#include "library/graph/graph-template.cpp"
int main() {
    int n, m;
    cin >> n >> m;
    MinCostFlow<ll, ll> g(n);
    rep(i, m) {
        ll u, v, c, d;
        cin >> u >> v >> c >> d;
        u--, v--;
        g.add_edge(u, v, 1, c);
        g.add_edge(v, u, 1, c);
        g.add_edge(u, v, 1, d);
        g.add_edge(v, u, 1, d);
    }
    print(g.min_cost_flow(0, n - 1, 2));
}