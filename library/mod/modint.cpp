#pragma once
template <int Mod>
struct modint
{
    int x;

    modint() : x(0) {}

    modint(long long y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {}

    modint &operator+=(const modint &p)
    {
        if ((x += p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator-=(const modint &p)
    {
        if ((x += Mod - p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator*=(const modint &p)
    {
        x = (int)(1LL * x * p.x % Mod);
        return *this;
    }

    modint &operator/=(const modint &p)
    {
        *this *= p.inverse();
        return *this;
    }

    modint operator-() const { return modint(-x); }

    modint operator+(const modint &p) const { return modint(*this) += p; }

    modint operator-(const modint &p) const { return modint(*this) -= p; }

    modint operator*(const modint &p) const { return modint(*this) *= p; }

    modint operator/(const modint &p) const { return modint(*this) /= p; }

    bool operator==(const modint &p) const { return x == p.x; }

    bool operator!=(const modint &p) const { return x != p.x; }

    modint inverse() const
    {
        int a = x, b = Mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }

    modint pow(int64_t n) const
    {
        modint ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const modint &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a)
    {
        long long t;
        is >> t;
        a = modint<Mod>(t);
        return (is);
    }

    static int get_mod() { return Mod; }

    constexpr int get() const { return x; }
};
