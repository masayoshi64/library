template <typename T>
struct BIT {
    vector<T> data;

    BIT(int sz) { data.assign(++sz, 0); }
    //[0, k)
    T sum(int k) {
        T ret = 0;
        for (; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    T sum(int l, int r) { return sum(r) - sum(l); }

    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }

    // 0-indexedでk番目の値を返す。
    int search(long long k) {
        ++k;
        int res = 0;
        int N = 1;
        while (N < (int)data.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)data.size() && data[res + i] < k) {
                k = k - data[res + i];
                res = res + i;
            }
        }
        return res;
    }

    // for debug
    void show() {
        rep(i, SZ(data) - 1) cout << sum(i + 1) - sum(i) << ' ';
        cout << endl;
    }
};