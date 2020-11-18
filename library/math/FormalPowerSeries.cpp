template <typename T>
struct FormalPowerSeries : vector<T> {
    using vector<T>::vector;
    using P = FormalPowerSeries;

    using MULT = function<P(P, P)>;

    static MULT& get_mult() {
        static MULT mult = nullptr;
        return mult;
    }

    static void set_fft(MULT f) { get_mult() = f; }

    // 末尾の0を消す
    void shrink() {
        while (this->size() && this->back() == T(0)) this->pop_back();
    }

    P operator+(const P& r) const { return P(*this) += r; }

    P operator+(const T& v) const { return P(*this) += v; }

    P operator-(const P& r) const { return P(*this) -= r; }

    P operator-(const T& v) const { return P(*this) -= v; }

    P operator*(const P& r) const { return P(*this) *= r; }

    P operator*(const T& v) const { return P(*this) *= v; }

    P operator/(const P& r) const { return P(*this) /= r; }

    P operator%(const P& r) const { return P(*this) %= r; }

    P& operator+=(const P& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < r.size(); i++) (*this)[i] += r[i];
        return *this;
    }

    P& operator+=(const T& r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }

    P& operator-=(const P& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
        shrink();
        return *this;
    }

    P& operator-=(const T& r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        shrink();
        return *this;
    }

    P& operator*=(const T& v) {
        const int n = (int)this->size();
        for (int k = 0; k < n; k++) (*this)[k] *= v;
        return *this;
    }

    P& operator*=(const P& r) {
        if (this->empty() || r.empty()) {
            this->clear();
            return *this;
        }
        assert(get_mult() != nullptr);
        return *this = get_mult()(*this, r);
    }

    P& operator%=(const P& r) { return *this -= *this / r * r; }

    P operator-() const {
        P ret(this->size());
        for (int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
        return ret;
    }

    P& operator/=(const P& r) {
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
    }

    P pre(int sz) const {
        return P(begin(*this), begin(*this) + min((int)this->size(), sz));
    }

    // f/x^sz
    P operator>>(int sz) const {
        if (this->size() <= sz) return {};
        P ret(*this);
        ret.erase(ret.begin(), ret.begin() + sz);
        return ret;
    }

    // f*x^sz
    P operator<<(int sz) const {
        P ret(*this);
        ret.insert(ret.begin(), sz, T(0));
        return ret;
    }

    // 反転
    P rev(int deg = -1) const {
        P ret(*this);
        if (deg != -1) ret.resize(deg, T(0));
        reverse(begin(ret), end(ret));
        return ret;
    }

    //微分
    P diff() const {
        const int n = (int)this->size();
        P ret(max(0, n - 1));
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
        return ret;
    }

    // 積分
    P integral() const {
        const int n = (int)this->size();
        P ret(n + 1);
        ret[0] = T(0);
        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
        return ret;
    }

    // 1/fのdeg項
    // F(0) must not be 0
    P inv(int deg = -1) const {
        assert(((*this)[0]) != T(0));
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        P ret({T(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
        }
        return ret.pre(deg);
    }

    // F(0) must be 1
    P log(int deg = -1) const {
        assert((*this)[0] == 1);
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    P sqrt(int deg = -1) const {
        const int n = (int)this->size();
        if (deg == -1) deg = n;

        if ((*this)[0] == T(0)) {
            for (int i = 1; i < n; i++) {
                if ((*this)[i] != T(0)) {
                    if (i & 1) return {};
                    if (deg - i / 2 <= 0) break;
                    auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
                    if (ret.size() < deg) ret.resize(deg, T(0));
                    return ret;
                }
            }
            return P(deg, 0);
        }

        P ret({T(1)});
        T inv2 = T(1) / T(2);
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
        }
        return ret.pre(deg);
    }

    // F(0) must be 0
    P exp(int deg = -1) const {
        assert((*this)[0] == T(0));
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        P ret({T(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
    }

    P pow(int64_t k, int deg = -1) const {
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != T(0)) {
                T rev = T(1) / (*this)[i];
                P C(*this * rev);
                P D(n - i);
                for (int j = i; j < n; j++) D[j - i] = C[j];
                D = (D.log() * k).exp() * (*this)[i].pow(k);
                P E(deg);
                if (i * k > deg) return E;
                auto S = i * k;
                for (int j = 0; j + S < deg && j < D.size(); j++)
                    E[j + S] = D[j];
                return E;
            }
        }
        return *this;
    }

    //代入
    T eval(T x) const {
        T r = 0, w = 1;
        for (auto& v : *this) {
            r += w * v;
            w *= x;
        }
        return r;
    }
};

// NTT<mint> ntt;
// FPS mult_ntt(const FPS::P& a, const FPS::P& b) {
//     auto ret = ntt.multiply(a, b);
//     return FPS::P(ret.begin(), ret.end());
// }
// FPS mult(const FPS::P& a, const FPS::P& b) {
//     FPS c(a.size() + b.size() - 1);
//     rep(i, a.size()) rep(j, b.size()) { c[i + j] += a[i] * b[j]; }
//     return c;
// }