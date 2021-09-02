#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "library/template/template.cpp"
// library
#include "library/graph/flow/max_flow.cpp"
int main() {
    int V, E;
    cin >> V >> E;
    mf_graph<ll> mf(V);
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        mf.add_edge(u, v, c);
    }
    print(mf.flow(0, V - 1));
}