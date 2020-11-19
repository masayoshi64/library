---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_14_B.test.cpp
    title: verify/aoj-ALDS1_14_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/string/RollingHash.cpp\"\nstruct RollingHash {\n\
    \    vector<unsigned long long> hashed, power;\n    const unsigned long long MASK30\
    \ = (1ULL << 30) - 1;\n    const unsigned long long MASK31 = (1ULL << 31) - 1;\n\
    \    const unsigned long long MOD = (1ULL << 61) - 1;\n    const unsigned long\
    \ long MASK61 = MOD;\n\n    RollingHash(const string &s, unsigned long long base\
    \ = 10007) {\n        int sz = (int)s.size();\n        hashed.assign(sz + 1, 0);\n\
    \        power.assign(sz + 1, 0);\n        power[0] = 1;\n        for (int i =\
    \ 0; i < sz; i++) {\n            power[i + 1] = CalcMod(Mul(power[i], base));\n\
    \            hashed[i + 1] = CalcMod(Mul(hashed[i], base) + s[i]);\n        }\n\
    \    }\n\n    // a*b mod 2^61-1\u3092\u8FD4\u3059\u95A2\u6570(\u6700\u5F8C\u306B\
    Mod\u3092\u53D6\u308B)\n    long long Mul(unsigned long long a, unsigned long\
    \ long b) {\n        unsigned long long au = a >> 31;\n        unsigned long long\
    \ ad = a & MASK31;\n        unsigned long long bu = b >> 31;\n        unsigned\
    \ long long bd = b & MASK31;\n        unsigned long long mid = ad * bu + au *\
    \ bd;\n        unsigned long long midu = mid >> 30;\n        unsigned long long\
    \ midd = mid & MASK30;\n        return au * bu * 2 + midu + (midd << 31) + ad\
    \ * bd;\n    }\n\n    // mod 2^61-1\u3092\u8A08\u7B97\u3059\u308B\u95A2\u6570\n\
    \    unsigned long long CalcMod(unsigned long long x) {\n        unsigned long\
    \ long xu = x >> 61;\n        unsigned long long xd = x & MASK61;\n        unsigned\
    \ long long res = xu + xd;\n        if (res >= MOD) res -= MOD;\n        return\
    \ res;\n    }\n\n    unsigned long long get(int l, int r) {\n        unsigned\
    \ long long ret =\n            CalcMod(hashed[r] + MOD * 3 - Mul(hashed[l], power[r\
    \ - l]));\n        return ret;\n    }\n\n    // CalcMod\u3092\u591A\u3081\u306B\
    \u3068\u3063\u3066\u308B\n    unsigned long long connect(unsigned long long h1,\
    \ unsigned long long h2,\n                               int h2len) {\n      \
    \  unsigned long long ret = CalcMod(CalcMod(Mul(h1, power[h2len])) + h2);\n  \
    \      return ret;\n    }\n\n    int LCP(RollingHash &b, int l1, int r1, int l2,\
    \ int r2) {\n        int len = min(r1 - l1, r2 - l2);\n        int low = -1, high\
    \ = len + 1;\n        while (high - low > 1) {\n            int mid = (low + high)\
    \ / 2;\n            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))\n          \
    \      low = mid;\n            else\n                high = mid;\n        }\n\
    \        return (low);\n    }\n};\n"
  code: "struct RollingHash {\n    vector<unsigned long long> hashed, power;\n   \
    \ const unsigned long long MASK30 = (1ULL << 30) - 1;\n    const unsigned long\
    \ long MASK31 = (1ULL << 31) - 1;\n    const unsigned long long MOD = (1ULL <<\
    \ 61) - 1;\n    const unsigned long long MASK61 = MOD;\n\n    RollingHash(const\
    \ string &s, unsigned long long base = 10007) {\n        int sz = (int)s.size();\n\
    \        hashed.assign(sz + 1, 0);\n        power.assign(sz + 1, 0);\n       \
    \ power[0] = 1;\n        for (int i = 0; i < sz; i++) {\n            power[i +\
    \ 1] = CalcMod(Mul(power[i], base));\n            hashed[i + 1] = CalcMod(Mul(hashed[i],\
    \ base) + s[i]);\n        }\n    }\n\n    // a*b mod 2^61-1\u3092\u8FD4\u3059\u95A2\
    \u6570(\u6700\u5F8C\u306BMod\u3092\u53D6\u308B)\n    long long Mul(unsigned long\
    \ long a, unsigned long long b) {\n        unsigned long long au = a >> 31;\n\
    \        unsigned long long ad = a & MASK31;\n        unsigned long long bu =\
    \ b >> 31;\n        unsigned long long bd = b & MASK31;\n        unsigned long\
    \ long mid = ad * bu + au * bd;\n        unsigned long long midu = mid >> 30;\n\
    \        unsigned long long midd = mid & MASK30;\n        return au * bu * 2 +\
    \ midu + (midd << 31) + ad * bd;\n    }\n\n    // mod 2^61-1\u3092\u8A08\u7B97\
    \u3059\u308B\u95A2\u6570\n    unsigned long long CalcMod(unsigned long long x)\
    \ {\n        unsigned long long xu = x >> 61;\n        unsigned long long xd =\
    \ x & MASK61;\n        unsigned long long res = xu + xd;\n        if (res >= MOD)\
    \ res -= MOD;\n        return res;\n    }\n\n    unsigned long long get(int l,\
    \ int r) {\n        unsigned long long ret =\n            CalcMod(hashed[r] +\
    \ MOD * 3 - Mul(hashed[l], power[r - l]));\n        return ret;\n    }\n\n   \
    \ // CalcMod\u3092\u591A\u3081\u306B\u3068\u3063\u3066\u308B\n    unsigned long\
    \ long connect(unsigned long long h1, unsigned long long h2,\n               \
    \                int h2len) {\n        unsigned long long ret = CalcMod(CalcMod(Mul(h1,\
    \ power[h2len])) + h2);\n        return ret;\n    }\n\n    int LCP(RollingHash\
    \ &b, int l1, int r1, int l2, int r2) {\n        int len = min(r1 - l1, r2 - l2);\n\
    \        int low = -1, high = len + 1;\n        while (high - low > 1) {\n   \
    \         int mid = (low + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return (low);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/string/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-11-19 12:41:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_14_B.test.cpp
documentation_of: library/string/RollingHash.cpp
layout: document
redirect_from:
- /library/library/string/RollingHash.cpp
- /library/library/string/RollingHash.cpp.html
title: library/string/RollingHash.cpp
---
