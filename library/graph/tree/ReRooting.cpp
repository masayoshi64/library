template <typename T>
struct ReRooting {
    using F = function<T(T, int)>;  // apply to a child dp value:function dp,
                                    // child index to value
    using F2 = function<T(T, T)>;   // apply to get parent dp values
    int V;
    vector<vector<int>> E;  // graph
    vector<vector<T>> dp;
    // dp_v = g(merge(f(dp_c1,c1), f(dp_c2,c2), ..., f(dp_ck,ck)) , v)
    F f, g;
    F2 merge;  // merge children values
    T mi;      // identity of merge

    ReRooting(
        int V_, F f_, F2 merge_, T mi_, F g_ = [](T a, int b) { return a; })
        : V(V_), f(f_), merge(merge_), mi(mi_), g(g_) {
        E.resize(V);
        dp.resize(V);
    }

    void add_edge(int a, int b) {
        E[a].push_back(b);
        E[b].push_back(a);
    }

    T dfs1(int p, int v) {
        T res = mi;
        for (int i = 0; i < E[v].size(); ++i) {
            if (E[v][i] == p) continue;
            dp[v][i] = dfs1(v, E[v][i]);
            res = merge(res, f(dp[v][i], E[v][i]));
        }
        return g(res, v);
    }

    void dfs2(int p, int v, T add) {
        for (int i = 0; i < E[v].size(); ++i) {
            if (E[v][i] == p) {
                dp[v][i] = add;
                break;
            }
        }

        vector<T> pL(E[v].size() + 1), pR(E[v].size() + 1);
        pL[0] = mi;
        for (int i = 0; i < E[v].size(); ++i)
            pL[i + 1] = merge(pL[i], f(dp[v][i], E[v][i]));
        pR[E[v].size()] = mi;
        for (int i = E[v].size(); i > 0; --i)
            pR[i - 1] = merge(pR[i], f(dp[v][i - 1], E[v][i - 1]));

        for (int i = 0; i < E[v].size(); ++i) {
            if (E[v][i] == p) continue;
            T val = merge(pL[i], pR[i + 1]);
            dfs2(v, E[v][i], g(val, v));
        }
    }
    // build rerooting
    void build(int root = 0) {
        for (int i = 0; i < V; ++i) dp[i].resize(E[i].size());
        dfs1(-1, root);
        dfs2(-1, root, mi);
    }
    // answer for root v
    T query(int v) {
        T ans = mi;
        for (int i = 0; i < E[v].size(); ++i) {
            ans = merge(ans, f(dp[v][i], E[v][i]));
        }
        return g(ans, v);
    }
};