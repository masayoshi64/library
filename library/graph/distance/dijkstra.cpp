#pragma once
#include "library/template/template.cpp"
/**
 * @brief dijkstra
 * @docs docs/dijkstra.md
 */
template <typename T>
vector<T> dijkstra(Graph<T> &g, int s) {
    const auto TINF = numeric_limits<T>::max();
    vector<T> dist(g.size(), TINF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while (!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if (dist[idx] < cost) continue;
        for (auto &e : g.g[idx]) {
            auto next_cost = cost + e.cost;
            if (dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}