#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include "library/template/template.cpp"
// library
#include "library/graph/distance/dijkstra.cpp"
int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph<int> g(V);
    g.read(E, 0, true, true);
    auto dist = dijkstra(g, r);
    rep(i, V) {
        if (dist[i] < inf)
            cout << dist[i] << endl;
        else
            cout << "INF" << endl;
    }
}