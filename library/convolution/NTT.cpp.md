---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/FPS.power.test.cpp
    title: verify/FPS.power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod.test.cpp
    title: verify/yosupo-convolution_mod.test.cpp
  - icon: ':x:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/convolution/NTT.cpp\"\ntemplate <typename Mint>\n\
    struct NTT\n{\n    vector<Mint> root_pow, root_pow_inv;\n    int max_base;\n \
    \   Mint root; //\u539F\u59CB\u6839\n\n    NTT()\n    {\n        const unsigned\
    \ Mod = Mint::get_mod();\n        auto tmp = Mod - 1;\n        max_base = 0;\n\
    \        while (tmp % 2 == 0)\n            tmp >>= 1, max_base++;\n        root\
    \ = 2;\n        while (root.pow((Mod - 1) >> 1) == 1)\n            root += 1;\n\
    \        root_pow.resize(max_base);\n        root_pow_inv.resize(max_base);\n\
    \        for (int i = 0; i < max_base; i++)\n        {\n            root_pow[i]\
    \ = -root.pow((Mod - 1) >> (i + 2));\n            root_pow_inv[i] = Mint(1) /\
    \ root_pow[i];\n        }\n    }\n\n    void ntt(vector<Mint> &a)\n    {\n   \
    \     const int n = a.size();\n        assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n)\
    \ <= max_base);\n        for (int m = n / 2; m >= 1; m >>= 1)\n        {\n   \
    \         Mint w = 1;\n            for (int s = 0, k = 0; s < n; s += 2 * m)\n\
    \            {\n                for (int i = s, j = s + m; i < s + m; ++i, ++j)\n\
    \                {\n                    auto x = a[i], y = a[j] * w;\n       \
    \             a[i] = x + y, a[j] = x - y;\n                }\n               \
    \ w *= root_pow[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n    void\
    \ intt(vector<Mint> &a)\n    {\n        const int n = a.size();\n        assert((n\
    \ & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n        for\
    \ (int m = 1; m < n; m *= 2)\n        {\n            Mint w = 1;\n           \
    \ for (int s = 0, k = 0; s < n; s += 2 * m)\n            {\n                for\
    \ (int i = s, j = s + m; i < s + m; ++i, ++j)\n                {\n           \
    \         auto x = a[i], y = a[j];\n                    a[i] = x + y, a[j] = (x\
    \ - y) * w;\n                }\n                w *= root_pow_inv[__builtin_ctz(++k)];\n\
    \            }\n        }\n    }\n\n    vector<Mint> multiply(vector<Mint> a,\
    \ vector<Mint> b)\n    {\n        const int need = a.size() + b.size() - 1;\n\
    \        int nbase = 1;\n        while ((1 << nbase) < need)\n            nbase++;\n\
    \        int sz = 1 << nbase;\n        a.resize(sz, 0);\n        b.resize(sz,\
    \ 0);\n        ntt(a);\n        ntt(b);\n        Mint inv_sz = Mint(1) / sz;\n\
    \        for (int i = 0; i < sz; i++)\n            a[i] *= b[i] * inv_sz;\n  \
    \      intt(a);\n        a.resize(need);\n        return a;\n    }\n};\n"
  code: "template <typename Mint>\nstruct NTT\n{\n    vector<Mint> root_pow, root_pow_inv;\n\
    \    int max_base;\n    Mint root; //\u539F\u59CB\u6839\n\n    NTT()\n    {\n\
    \        const unsigned Mod = Mint::get_mod();\n        auto tmp = Mod - 1;\n\
    \        max_base = 0;\n        while (tmp % 2 == 0)\n            tmp >>= 1, max_base++;\n\
    \        root = 2;\n        while (root.pow((Mod - 1) >> 1) == 1)\n          \
    \  root += 1;\n        root_pow.resize(max_base);\n        root_pow_inv.resize(max_base);\n\
    \        for (int i = 0; i < max_base; i++)\n        {\n            root_pow[i]\
    \ = -root.pow((Mod - 1) >> (i + 2));\n            root_pow_inv[i] = Mint(1) /\
    \ root_pow[i];\n        }\n    }\n\n    void ntt(vector<Mint> &a)\n    {\n   \
    \     const int n = a.size();\n        assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n)\
    \ <= max_base);\n        for (int m = n / 2; m >= 1; m >>= 1)\n        {\n   \
    \         Mint w = 1;\n            for (int s = 0, k = 0; s < n; s += 2 * m)\n\
    \            {\n                for (int i = s, j = s + m; i < s + m; ++i, ++j)\n\
    \                {\n                    auto x = a[i], y = a[j] * w;\n       \
    \             a[i] = x + y, a[j] = x - y;\n                }\n               \
    \ w *= root_pow[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n    void\
    \ intt(vector<Mint> &a)\n    {\n        const int n = a.size();\n        assert((n\
    \ & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n        for\
    \ (int m = 1; m < n; m *= 2)\n        {\n            Mint w = 1;\n           \
    \ for (int s = 0, k = 0; s < n; s += 2 * m)\n            {\n                for\
    \ (int i = s, j = s + m; i < s + m; ++i, ++j)\n                {\n           \
    \         auto x = a[i], y = a[j];\n                    a[i] = x + y, a[j] = (x\
    \ - y) * w;\n                }\n                w *= root_pow_inv[__builtin_ctz(++k)];\n\
    \            }\n        }\n    }\n\n    vector<Mint> multiply(vector<Mint> a,\
    \ vector<Mint> b)\n    {\n        const int need = a.size() + b.size() - 1;\n\
    \        int nbase = 1;\n        while ((1 << nbase) < need)\n            nbase++;\n\
    \        int sz = 1 << nbase;\n        a.resize(sz, 0);\n        b.resize(sz,\
    \ 0);\n        ntt(a);\n        ntt(b);\n        Mint inv_sz = Mint(1) / sz;\n\
    \        for (int i = 0; i < sz; i++)\n            a[i] *= b[i] * inv_sz;\n  \
    \      intt(a);\n        a.resize(need);\n        return a;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/NTT.cpp
  requiredBy: []
  timestamp: '2021-08-24 20:56:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo-convolution_mod_1000000007.test.cpp
  - verify/FPS.power.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
documentation_of: library/convolution/NTT.cpp
layout: document
redirect_from:
- /library/library/convolution/NTT.cpp
- /library/library/convolution/NTT.cpp.html
title: library/convolution/NTT.cpp
---
