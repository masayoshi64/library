struct HLD {
    vector<vector<int>> G;
    vector<int> parent, depth, sub_size, v_id, id_to_v, head;
    HLD(int n)
        : G(n),
          v_id(n, -1),
          head(n),
          sub_size(n, 1),
          parent(n, -1),
          depth(n, 0),
          id_to_v(n) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(int root = 0) {
        int pos = 0;
        dfs_size(root);
        head[root] = root;
        dfs_hld(root, pos);
    }

    void dfs_size(int v) {
        for (int& nv : G[v]) {
            if (nv == parent[v]) {
                nv = G[v].back();
                G[v].pop_back();
            }
        }
        for (int& nv : G[v]) {
            parent[nv] = v;
            depth[nv] = depth[v] + 1;
            dfs_size(nv);
            sub_size[v] += sub_size[nv];
            if (sub_size[nv] > sub_size[G[v][0]]) swap(nv, G[v][0]);
        }
    }

    void dfs_hld(int v, int& pos) {
        v_id[v] = pos;
        id_to_v[pos++] = v;
        for (int nv : G[v]) {
            head[nv] = (nv == G[v][0] ? head[v] : nv);
            dfs_hld(nv, pos);
        }
    }

    int lca(int u, int v) {
        while (1) {
            if (v_id[u] > v_id[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = parent[head[v]];
        }
    }

    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // update vertexes in [u, v] with f
    template <typename F>
    void update(int u, int v, const F& f) {
        while (1) {
            if (v_id[u] > v_id[v]) swap(u, v);
            f(max(v_id[head[v]], v_id[u]), v_id[v]);
            if (head[u] != head[v])
                v = parent[head[v]];
            else
                break;
        }
    }

    // get res for [u, v] with query q and merge each value with f
    // root->leaf
    template <typename T, typename Q, typename F>
    T query(int u, int v, T id, const Q& q, const F& f) {
        T l = id, r = id;
        while (1) {
            if (v_id[u] > v_id[v]) {
                swap(u, v);
                swap(l, r);
            }
            l = f(q(max(v_id[head[v]], v_id[u]), v_id[v]), l);
            if (head[u] != head[v])
                v = parent[head[v]];
            else
                break;
        }
        return f(l, r);
    }

    // update edges between u, v inclusive with func f
    template <typename F>
    void update_edge(int u, int v, const F& f) {
        while (1) {
            if (v_id[u] > v_id[v]) swap(u, v);
            if (head[u] != head[v]) {
                f(v_id[head[v]], v_id[v]);
                v = parent[head[v]];
            } else {
                if (u != v) f(v_id[u] + 1, v_id[v]);
                break;
            }
        }
    }

    // query for edges between u, v inclusive with query q and merge func f
    // root->leaf
    template <typename T, typename Q, typename F>
    T query_edge(int u, int v, T id, const Q& q, const F& f) {
        T l = id, r = id;
        while (1) {
            if (v_id[u] > v_id[v]) {
                swap(u, v);
                swap(l, r);
            }
            if (head[u] != head[v]) {
                l = f(q(v_id[head[v]], v_id[v]), l);
                v = parent[head[v]];
            } else {
                if (u != v) l = f(q(v_id[u] + 1, v_id[v]), l);
                break;
            }
        }
        return f(l, r);
    }
};