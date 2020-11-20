template <typename T>
void warshall_floyd(vector<vector<T>> &g) {
    const auto TINF = numeric_limits<T>::max();
    for (int k = 0; k < g.size(); k++) {
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g.size(); j++) {
                if (g[i][k] == TINF || g[k][j] == TINF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}