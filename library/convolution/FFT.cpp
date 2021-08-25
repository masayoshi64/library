#pragma once
#include "library/mod/modint.cpp"
#include "library/convolution/NTT.cpp"
/**
 * @brief Fast Fourier Transform
 * @see https://nyaannyaan.github.io/library/ntt/arbitrary-ntt.hpp
 * @docs docs/FFT.md
 */
struct FFT
{
private:
    using i64 = int64_t;
    static const int32_t m0 = 167772161;
    static const int32_t m1 = 469762049;
    static const int32_t m2 = 754974721;
    using mint0 = modint<m0>;
    using mint1 = modint<m1>;
    using mint2 = modint<m2>;
    const int32_t r01 = 104391568;
    const int32_t r02 = 323560596;
    const int32_t r12 = 399692502;
    const int32_t r02r12 = i64(r02) * r12 % m2;
    const i64 w1 = m0;
    const i64 w2 = i64(m0) * m1;
    template <typename T, typename submint>

    vector<submint> mul(const vector<T> &a, const vector<T> &b)
    {
        static NTT<submint> ntt;
        vector<submint> s(a.size()), t(b.size());
        for (int i = 0; i < (int)a.size(); ++i)
            s[i] = i64(a[i] % submint::get_mod());
        for (int i = 0; i < (int)b.size(); ++i)
            t[i] = i64(b[i] % submint::get_mod());
        return ntt.multiply(s, t);
    }

public:
    FFT()
    {
    }

    /**
     * @brief 任意modによるmodintの畳み込み
     * @arg vector<modint<mod>>
     */
    template <typename Mint>
    vector<Mint> multiply(const vector<Mint> &x, const vector<Mint> &y)
    {
        if (x.size() == 0 && y.size() == 0)
            return {};
        if (min<int>(x.size(), y.size()) < 128)
        {
            vector<Mint> ret(x.size() + y.size() - 1);
            for (int i = 0; i < (int)x.size(); ++i)
                for (int j = 0; j < (int)y.size(); ++j)
                    ret[i + j] += x[i] * y[j];
            return ret;
        }
        vector<int> s(x.size()), t(y.size());
        for (int i = 0; i < (int)x.size(); ++i)
            s[i] = x[i].get();
        for (int i = 0; i < (int)y.size(); ++i)
            t[i] = y[i].get();
        auto d0 = mul<int, mint0>(s, t);
        auto d1 = mul<int, mint1>(s, t);
        auto d2 = mul<int, mint2>(s, t);
        int n = d0.size();
        vector<Mint> ret(n);
        const Mint W1 = w1;
        const Mint W2 = w2;
        for (int i = 0; i < n; i++)
        {
            int n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();
            int b = i64(n1 + m1 - a) * r01 % m1;
            int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;
            ret[i] = W1 * b + W2 * c + a;
        }
        return ret;
    }

    /**
     * @brief int, long long用の畳み込み
     * @arg vector<long long>を想定
     */
    template <typename T>
    vector<T> multiply_ll(const vector<T> &s, const vector<T> &t)
    {
        if (s.size() == 0 && t.size() == 0)
            return {};
        if (min<int>(s.size(), t.size()) < 128)
        {
            vector<T> ret(s.size() + t.size() - 1);
            for (int i = 0; i < (int)s.size(); ++i)
                for (int j = 0; j < (int)t.size(); ++j)
                    ret[i + j] += i64(s[i]) * t[j];
            return ret;
        }
        auto d0 = mul<T, mint0>(s, t);
        auto d1 = mul<T, mint1>(s, t);
        auto d2 = mul<T, mint2>(s, t);
        int n = d0.size();
        vector<T> ret(n);
        for (int i = 0; i < n; i++)
        {
            i64 n1 = d1[i].get(), n2 = d2[i].get();
            i64 a = d0[i].get();
            T b = (n1 + m1 - a) * r01 % m1;
            T c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
            ret[i] = a + b * w1 + c * w2;
        }
        return ret;
    }
};
