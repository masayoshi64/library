#pragma once
/**
 * @brief Number Theoretic Transform
 * @docs docs/NTT.md
 * @param modint
 */
template <typename Mint>
struct NTT
{
    vector<Mint> root_pow, root_pow_inv;
    int max_base;
    Mint root; //原始根

    NTT()
    {
        const unsigned Mod = Mint::get_mod();
        auto tmp = Mod - 1;
        max_base = 0;
        while (tmp % 2 == 0)
            tmp >>= 1, max_base++;
        root = 2;
        while (root.pow((Mod - 1) >> 1) == 1)
            root += 1;
        root_pow.resize(max_base);
        root_pow_inv.resize(max_base);
        for (int i = 0; i < max_base; i++)
        {
            root_pow[i] = -root.pow((Mod - 1) >> (i + 2));
            root_pow_inv[i] = Mint(1) / root_pow[i];
        }
    }

    void ntt(vector<Mint> &a)
    {
        const int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        for (int m = n / 2; m >= 1; m >>= 1)
        {
            Mint w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m)
            {
                for (int i = s, j = s + m; i < s + m; ++i, ++j)
                {
                    auto x = a[i], y = a[j] * w;
                    a[i] = x + y, a[j] = x - y;
                }
                w *= root_pow[__builtin_ctz(++k)];
            }
        }
    }

    void intt(vector<Mint> &a)
    {
        const int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        for (int m = 1; m < n; m *= 2)
        {
            Mint w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m)
            {
                for (int i = s, j = s + m; i < s + m; ++i, ++j)
                {
                    auto x = a[i], y = a[j];
                    a[i] = x + y, a[j] = (x - y) * w;
                }
                w *= root_pow_inv[__builtin_ctz(++k)];
            }
        }
    }

    vector<Mint> multiply(vector<Mint> a, vector<Mint> b)
    {
        const int need = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need)
            nbase++;
        int sz = 1 << nbase;
        a.resize(sz, 0);
        b.resize(sz, 0);
        ntt(a);
        ntt(b);
        Mint inv_sz = Mint(1) / sz;
        for (int i = 0; i < sz; i++)
            a[i] *= b[i] * inv_sz;
        intt(a);
        a.resize(need);
        return a;
    }
};
