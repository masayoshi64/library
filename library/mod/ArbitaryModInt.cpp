struct ArbitraryModInt {
    int x;

    ArbitraryModInt() : x(0) {}

    ArbitraryModInt(int64_t y)
        : x(y >= 0 ? y % Mod() : (Mod() - (-y) % Mod()) % Mod()) {}

    static int& Mod() {
        static int Mod = 0;
        return Mod;
    }

    static void set_mod(int md) { Mod() = md; }

    ArbitraryModInt& operator+=(const ArbitraryModInt& p) {
        if ((x += p.x) >= Mod()) x -= Mod();
        return *this;
    }

    ArbitraryModInt& operator-=(const ArbitraryModInt& p) {
        if ((x += Mod() - p.x) >= Mod()) x -= Mod();
        return *this;
    }

    ArbitraryModInt& operator*=(const ArbitraryModInt& p) {
        unsigned long long a = (unsigned long long)x * p.x;
        unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
        asm("divl %4; \n	"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(Mod()));
        x = m;
        return *this;
    }

    ArbitraryModInt& operator/=(const ArbitraryModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

    ArbitraryModInt operator+(const ArbitraryModInt& p) const {
        return ArbitraryModInt(*this) += p;
    }

    ArbitraryModInt operator-(const ArbitraryModInt& p) const {
        return ArbitraryModInt(*this) -= p;
    }

    ArbitraryModInt operator*(const ArbitraryModInt& p) const {
        return ArbitraryModInt(*this) *= p;
    }

    ArbitraryModInt operator/(const ArbitraryModInt& p) const {
        return ArbitraryModInt(*this) /= p;
    }

    bool operator==(const ArbitraryModInt& p) const { return x == p.x; }

    bool operator!=(const ArbitraryModInt& p) const { return x != p.x; }

    ArbitraryModInt inverse() const {
        int a = x, b = Mod(), u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ArbitraryModInt(u);
    }

    ArbitraryModInt pow(int64_t n) const {
        ArbitraryModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ArbitraryModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ArbitraryModInt& a) {
        int64_t t;
        is >> t;
        a = ArbitraryModInt(t);
        return (is);
    }

    static int get_mod() { return Mod(); }

    constexpr int get() const { return x; }
};
#define amint ArbitraryModInt
// amint::set_mod(mod);