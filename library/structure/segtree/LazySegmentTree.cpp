/**
 * @brief Lazy-Segment-Tree(遅延伝搬セグメント木)
 * @docs docs/lazy-segment-tree.md
 */
template <typename Monoid, typename OperatorMonoid>
struct LazySegmentTree {
    int n, sz, height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid& M1,
                    const OperatorMonoid OM0)
        : n(n), f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        height = 0;
        while (sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid& x) { data[k + sz] = x; }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if (lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = apply(k);
            lazy[k] = OM0;
        }
    }

    inline Monoid apply(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    inline void recalc(int k) {
        while (k >>= 1) data[k] = f(apply(2 * k + 0), apply(2 * k + 1));
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid& x) {
        if (a >= b) return;
        thrust(a += sz);
        thrust(b += sz - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        if (a >= b) return M1;
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, apply(l++));
            if (r & 1) R = f(apply(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int& k) { return query(k, k + 1); }

    template <typename C>
    int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < sz) {
            propagate(a);
            Monoid nxt =
                type ? f(apply(2 * a + type), M) : f(M, apply(2 * a + type));
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C& check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, apply(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + sz);
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, apply(a));
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C& check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + sz - 1);
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(apply(--b), R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

    void show() {
        rep(i, n) cout << query(i, i + 1) << ' ';
        cout << endl;
    }
};

template <class T, class F = T>
T myreplace(T x, F y) {
    if (y != numeric_limits<F>::max()) x = y;
    return x;
}
template <class T>
T mymax(T x, T y) {
    return max(x, y);
}
template <class T>
T mymin(T x, T y) {
    return min(x, y);
}
template <class T, class F = T>
T myadd(T x, F y) {
    return x + y;
}
template <class T>
struct segobj {
    T val;
    int size;
    segobj(T x, int y) : val(x), size(y) {}
    segobj() : val(0), size(0) {}
    segobj& operator+=(const segobj& p) {
        val += p.val;
        size += p.size;
        return *this;
    }
    segobj& operator+=(const T& p) {
        val += p * size;
        return *this;
    }
    segobj& operator=(const T& p) {
        val = p * size;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const segobj& p) {
        return os << p.val;
    }
    segobj operator+(const segobj& p) const { return segobj(*this) += p; }
    segobj operator+(const T& p) const { return segobj(*this) += p; }
};
template <class T>
struct RMRRQ : LazySegmentTree<T, T> {
    using Seg = LazySegmentTree<T, T>;
    RMRRQ(int n)
        : Seg(n, mymax<T>, myreplace<T>, myreplace<T>, numeric_limits<T>::min(),
              numeric_limits<T>::max()) {}
};
template <class T>
struct RmRRQ : LazySegmentTree<T, T> {
    using Seg = LazySegmentTree<T, T>;
    RmRRQ(int n)
        : Seg(n, mymin<T>, myreplace<T>, myreplace<T>, numeric_limits<T>::max(),
              numeric_limits<T>::max()) {}
};
template <class T>
struct RMRAQ : LazySegmentTree<T, T> {
    using Seg = LazySegmentTree<T, T>;
    RMRAQ(int n)
        : Seg(n, mymax<T>, plus<T>(), plus<T>(), numeric_limits<T>::min() / 2,
              T()) {}
};
template <class T>
struct RmRAQ : LazySegmentTree<T, T> {
    using Seg = LazySegmentTree<T, T>;
    RmRAQ(int n)
        : Seg(n, mymin<T>, plus<T>(), plus<T>(), numeric_limits<T>::max() / 2,
              T()) {}
};
template <class T>
struct RSRAQ : LazySegmentTree<segobj<T>, T> {
    using Seg = LazySegmentTree<segobj<T>, T>;
    RSRAQ(int n)
        : Seg(n, plus<segobj<T>>(), myadd<segobj<T>, T>, plus<T>(), segobj<T>(),
              T()) {
        rep(i, n) this->set(i, segobj<T>(0, 1));
        this->build();
    }
    T sum(int l, int r) { return this->query(l, r).val; }
};
template <class T>
struct RSRRQ : LazySegmentTree<segobj<T>, T> {
    using Seg = LazySegmentTree<segobj<T>, T>;
    using obj = segobj<T>;
    RSRRQ(int n)
        : Seg(n, plus<obj>(), myreplace<obj, T>, myreplace<T>, segobj<T>(),
              numeric_limits<T>::max()) {
        rep(i, n) this->set(i, segobj<T>(0, 1));
        this->build();
    }
    T sum(int l, int r) { return this->query(l, r).val; }
};