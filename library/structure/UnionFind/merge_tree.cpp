#include "library/structure/UnionFind/UnionFind.cpp"
//葉:要素, 節点:クエリ,
struct MergeTree {
    UnionFind uf;
    mat<int> g;
    vector<int> root;
    Mergetree(int n, int q) : uf(n), g(n + q), root(n) { iota(all(root), 0); }

    void merge(int u, int v, int id) {
        if (uf.same(u, v)) return;
        g[root[u]].pb(id + n);
        g[root[v]].pb(id + n);
        g[id + n].pb(root[u]);
        g[id+n].pb(root[v];
        uf.unite(u, v);
        int r = uf.find(u);
        root[r] = id+n;
    }

    // todo: 各時点で連結成分が区間になるようにソートしたリストを返す関数
    // オイラーツアーで葉を並べればいい
    // vector<int> align()
}