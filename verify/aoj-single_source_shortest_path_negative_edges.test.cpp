#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"

#include "library/template/template.cpp"
// library
#include "library/graph/distance/bellman_ford.cpp"
int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph<int> g(V);
    g.read(E, 0, true, true);
    auto dist = bellman_ford(g, r);
    if (dist.size() == 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, V) {
        if (dist[i] < inf)
            cout << dist[i] << endl;
        else
            cout << "INF" << endl;
    }
}