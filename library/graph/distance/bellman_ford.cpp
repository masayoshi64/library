#include "library/template/template.cpp"
/**
 * @brief bellman ford
 * @docs docs/bellman_ford.md
 */
template <typename T>
vector<T> bellman_ford(const Graph<T> &g, int s) {
    int n = g.g.size();
    const auto TINF = numeric_limits<T>::max();
    vector<T> dist(n, TINF);
    dist[s] = 0;
    vector<Edge<T>> edges;
    for (int v = 0; v < n; v++) {
        for (auto e : g.g[v])
            edges.push_back(e);
    }
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.from] == TINF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    for (auto &e : edges) {
        if (dist[e.from] == TINF) continue;
        if (dist[e.from] + e.cost < dist[e.to]) return vector<T>();
    }
    return dist;
}