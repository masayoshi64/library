/**
 * @brief Combination(P, C, H, Stirling number, Bell number)
 * @docs docs/Combination.md
 */
template <typename T>
struct Combination {
    vector<T> _fact, _rfact, _inv;

    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for (int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for (int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
        for (int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const {
        if (q < 0 || p < q) return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const {
        if (n < 0 || r < 0) return (0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }

    // O(klog(n))
    // n個の区別できる玉をk個のグループに分割する場合の数（グループのサイズは1以上）
    T Stirling(int n, int k) {
        T res = 0;
        rep(i, k + 1) {
            res += (T)((k - i) % 2 ? -1 : 1) * C(k, i) * mypow<T>(i, n);
        }
        return res / _fact[k];
    }

    // O(klog(n))
    // n個の区別できる玉をk個のグループに分割する場合の数（グループのサイズは0以上）
    // もしくは、k個以下の玉の一個以上入ったグループに分けると考えてもいい
    T Bell(int n, int k) {
        vector<T> sm(k + 1);
        sm[0] = 1;
        rep(j, 1, k + 1) { sm[j] = sm[j - 1] + (T)(j % 2 ? -1 : 1) / _fact[j]; }
        T res = 0;
        rep(i, k + 1) { res += mypow<T>(i, n) / _fact[i] * sm[k - i]; }
        return res;
    }
};