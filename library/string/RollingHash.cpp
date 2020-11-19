struct RollingHash {
    vector<unsigned long long> hashed, power;
    const unsigned long long MASK30 = (1ULL << 30) - 1;
    const unsigned long long MASK31 = (1ULL << 31) - 1;
    const unsigned long long MOD = (1ULL << 61) - 1;
    const unsigned long long MASK61 = MOD;

    RollingHash(const string &s, unsigned long long base = 10007) {
        int sz = (int)s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++) {
            power[i + 1] = CalcMod(Mul(power[i], base));
            hashed[i + 1] = CalcMod(Mul(hashed[i], base) + s[i]);
        }
    }

    // a*b mod 2^61-1を返す関数(最後にModを取る)
    long long Mul(unsigned long long a, unsigned long long b) {
        unsigned long long au = a >> 31;
        unsigned long long ad = a & MASK31;
        unsigned long long bu = b >> 31;
        unsigned long long bd = b & MASK31;
        unsigned long long mid = ad * bu + au * bd;
        unsigned long long midu = mid >> 30;
        unsigned long long midd = mid & MASK30;
        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    // mod 2^61-1を計算する関数
    unsigned long long CalcMod(unsigned long long x) {
        unsigned long long xu = x >> 61;
        unsigned long long xd = x & MASK61;
        unsigned long long res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }

    unsigned long long get(int l, int r) {
        unsigned long long ret =
            CalcMod(hashed[r] + MOD * 3 - Mul(hashed[l], power[r - l]));
        return ret;
    }

    // CalcModを多めにとってる
    unsigned long long connect(unsigned long long h1, unsigned long long h2,
                               int h2len) {
        unsigned long long ret = CalcMod(CalcMod(Mul(h1, power[h2len])) + h2);
        return ret;
    }

    int LCP(RollingHash &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
};