#include "library/template/template.cpp"
/**
 * @brief bfs dial
 * @arg graph, start
 * @docs docs/bfs_dial.md
 * @details O(|V|max_cost)
 */
template <typename T>
vector<T> bfs_dial(const Graph<T> &g, int s)
{
    T max_cost = 0, max_dist = 0;
    for (auto &es : g.g)
    {
        for (auto &e : es)
            max_cost = max(max_cost, e.cost);
    }
    ++max_cost;
    const auto TINF = numeric_limits<T>::max();
    vector<T> dist(g.size(), TINF);
    vector<queue<int>> ques(max_cost + 1);
    dist[s] = 0;
    ques[0].emplace(s);
    for (T cost = 0; cost <= max_dist; cost++)
    {
        auto &que = ques[cost % max_cost];
        while (!que.empty())
        {
            int idx = que.front();
            que.pop();
            if (dist[idx] < cost)
                continue;
            for (auto &e : g.g[idx])
            {
                auto next_cost = cost + e.cost;
                if (dist[e.to] <= next_cost)
                    continue;
                dist[e.to] = next_cost;
                max_dist = max(max_dist, dist[e.to]);
                ques[dist[e.to] % max_cost].emplace(e.to);
            }
        }
    }
    return dist;
}