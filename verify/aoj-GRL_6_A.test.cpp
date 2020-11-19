#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "library/template/template.cpp"
// library
#include "library/graph/flow/Dinic.cpp"
int main() {
    int v, e;
    cin >> v >> e;
    Dinic<ll> mf(v);
    rep(i, e) {
        int u, v, c;
        cin >> u >> v >> c;
        mf.add_edge(u, v, c);
    }
    print(mf.max_flow(0, v - 1));
}