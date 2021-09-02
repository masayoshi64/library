#include "library/template/template.cpp"
/**
 * @brief travelling salesman problem
 * @arg graph, start
 * @docs docs/TSP.md
 * @details cycle: dp[all][s], path from s to t: dp[all^(1<<s)][t]
 */
template <typename T>
vector<vector<T>> TSP(Graph<T> g, int s = 0) {
    int n = g.g.size();
    T TINF = numeric_limits<T>::max();
    vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));
    dp[0][s] = 0;
    int all = (1 << n) - 1;
    rep(visited, all + 1) {
        rep(pv, n) {
            for (auto &e : g.g[pv]) {
                if ((visited & (1 << e.to)) == 0 || dp[visited ^ (1 << e.to)][e.from] == TINF) continue;
                chmin(dp[visited][e.to], dp[visited ^ (1 << e.to)][e.from] + e.cost);
            }
        }
    }
    return dp;
}
