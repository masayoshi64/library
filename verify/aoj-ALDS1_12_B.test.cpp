#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"

#include "library/template/template.cpp"
//
//#include "library/graph/graph-template.cpp"
// library
#include "library/graph/distance/bfs_dial.cpp"
int main() {
    int n;
    cin >> n;
    Graph g(n);
    rep(i, n) {
        int u, k;
        cin >> u >> k;
        rep(j, k) {
            int v, c;
            cin >> v >> c;
            g.add_directed_edge(u, v, c);
        }
    }
    auto dist = bfs_dial(g, 0);
    rep(i, n) { cout << i << ' ' << dist[i] << endl; }
}