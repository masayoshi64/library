#define PROBLEM "https://atcoder.jp/contests/abc216/tasks/abc216_g"
#include "library/graph/distance/dijkstra.cpp"
#include "library/template/template.cpp"
/**
 * @brief 牛ゲー
 * @docs docs/cow_game.md
 */
int main() {
    int n, m;
    cin >> n >> m;
    Graph<ll> g(n + 1);
    rep(i, n) {
        g.add_directed_edge(i, i + 1, 1);
        g.add_directed_edge(i + 1, i, 0);
    }
    rep(i, m) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        g.add_directed_edge(l, r, r - l - x);
    }
    auto dist = dijkstra(g, 0);
    rep(i, n) {
        if (dist[i + 1] - dist[i])
            cout << "0 ";
        else
            cout << "1 ";
    }
    cout << endl;
}
