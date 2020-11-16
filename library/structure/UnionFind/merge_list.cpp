struct mergetree {
    using pii = pair<int, int>;

   public:
    mergetree() {}
    mergetree(int n) : n(n) {}

    vector<pii> build(const vector<int>& type, const vector<pii>& vs) {
        q = int(type.size());

        parent_or_size.assign(n, -1);
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        vid.resize(n);
        child.resize(q);
        range.resize(n + q);
        vector<int> idx(q, -1);
        for (int i = 0; i < q; i++) {
            switch (type[i]) {
                case 1: {
                    auto [a, b] = vs[i];
                    if (same(a, b)) continue;
                    child[i] = pii(root[leader(a)], root[leader(b)]);
                    root[merge(a, b)] = n + i;
                } break;
                case 2: {
                    int x = vs[i].first;
                    idx[i] = root[leader(x)];
                } break;
                default: {
                    assert(false);
                } break;
            }
        }

        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (leader(i) == i) {
                dfs(root[i], pos);
            }
        }

        vector<pii> ret(q);
        for (int i = 0; i < q; i++) {
            if (~idx[i]) {
                ret[i] = range[idx[i]];
            }
        }

        return ret;
    }

    int operator[](int i) { return vid[i]; }

   private:
    int n, q;
    // root node: -1 * component size
    // otherwise: parent
    vector<int> parent_or_size, root, vid;
    vector<pii> child, range;

    void dfs(int v, int& pos) {
        int l = pos;
        if (v < n) {
            vid[v] = pos++;
        } else {
            dfs(child[v - n].first, pos);
            dfs(child[v - n].second, pos);
        }
        int r = pos;
        range[v] = pii(l, r);
    };

    int merge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
};