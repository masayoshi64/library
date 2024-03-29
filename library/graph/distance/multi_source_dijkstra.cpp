#pragma once
/**
 * @brief multi-source dijkstra
 * @docs docs/multi_source_dijkstra.md
 */
template <typename T>
vector<T> multi_source_dijkstra(Graph<T> &g, vector<int> &s) {
    const auto Inf = numeric_limits<T>::max();
    vector<T> dist(g.size(), Inf);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    for (int ss : s)
        dist[ss] = 0, que.emplace(dist[ss], ss);
    while (!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if (dist[idx] < cost) continue;
        for (auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if (dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}