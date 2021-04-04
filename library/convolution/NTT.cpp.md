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
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/convolution/NTT.cpp\"\ntemplate <typename Mint>\n\
    struct NTT {\n    vector<Mint> dw, idw;\n    int max_base;\n    Mint root;\n\n\
    \    NTT() {\n        const unsigned Mod = Mint::get_mod();\n        assert(Mod\
    \ >= 3 && Mod % 2 == 1);\n        auto tmp = Mod - 1;\n        max_base = 0;\n\
    \        while (tmp % 2 == 0) tmp >>= 1, max_base++;\n        root = 2;\n    \
    \    while (root.pow((Mod - 1) >> 1) == 1) root += 1;\n        assert(root.pow(Mod\
    \ - 1) == 1);\n        dw.resize(max_base);\n        idw.resize(max_base);\n \
    \       for (int i = 0; i < max_base; i++) {\n            dw[i] = -root.pow((Mod\
    \ - 1) >> (i + 2));\n            idw[i] = Mint(1) / dw[i];\n        }\n    }\n\
    \n    void ntt(vector<Mint> &a) {\n        const int n = (int)a.size();\n    \
    \    assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = n; m >>= 1;) {\n            Mint w = 1;\n            for\
    \ (int s = 0, k = 0; s < n; s += 2 * m) {\n                for (int i = s, j =\
    \ s + m; i < s + m; ++i, ++j) {\n                    auto x = a[i], y = a[j] *\
    \ w;\n                    a[i] = x + y, a[j] = x - y;\n                }\n   \
    \             w *= dw[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n\
    \    void intt(vector<Mint> &a, bool f = true) {\n        const int n = (int)a.size();\n\
    \        assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = 1; m < n; m *= 2) {\n            Mint w = 1;\n         \
    \   for (int s = 0, k = 0; s < n; s += 2 * m) {\n                for (int i =\
    \ s, j = s + m; i < s + m; ++i, ++j) {\n                    auto x = a[i], y =\
    \ a[j];\n                    a[i] = x + y, a[j] = (x - y) * w;\n             \
    \   }\n                w *= idw[__builtin_ctz(++k)];\n            }\n        }\n\
    \        if (f) {\n            Mint inv_sz = Mint(1) / n;\n            for (int\
    \ i = 0; i < n; i++) a[i] *= inv_sz;\n        }\n    }\n\n    vector<Mint> multiply(vector<Mint>\
    \ a, vector<Mint> b) {\n        int need = a.size() + b.size() - 1;\n        int\
    \ nbase = 1;\n        while ((1 << nbase) < need) nbase++;\n        int sz = 1\
    \ << nbase;\n        a.resize(sz, 0);\n        b.resize(sz, 0);\n        ntt(a);\n\
    \        ntt(b);\n        Mint inv_sz = Mint(1) / sz;\n        for (int i = 0;\
    \ i < sz; i++) a[i] *= b[i] * inv_sz;\n        intt(a, false);\n        a.resize(need);\n\
    \        return a;\n    }\n};\n"
  code: "template <typename Mint>\nstruct NTT {\n    vector<Mint> dw, idw;\n    int\
    \ max_base;\n    Mint root;\n\n    NTT() {\n        const unsigned Mod = Mint::get_mod();\n\
    \        assert(Mod >= 3 && Mod % 2 == 1);\n        auto tmp = Mod - 1;\n    \
    \    max_base = 0;\n        while (tmp % 2 == 0) tmp >>= 1, max_base++;\n    \
    \    root = 2;\n        while (root.pow((Mod - 1) >> 1) == 1) root += 1;\n   \
    \     assert(root.pow(Mod - 1) == 1);\n        dw.resize(max_base);\n        idw.resize(max_base);\n\
    \        for (int i = 0; i < max_base; i++) {\n            dw[i] = -root.pow((Mod\
    \ - 1) >> (i + 2));\n            idw[i] = Mint(1) / dw[i];\n        }\n    }\n\
    \n    void ntt(vector<Mint> &a) {\n        const int n = (int)a.size();\n    \
    \    assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = n; m >>= 1;) {\n            Mint w = 1;\n            for\
    \ (int s = 0, k = 0; s < n; s += 2 * m) {\n                for (int i = s, j =\
    \ s + m; i < s + m; ++i, ++j) {\n                    auto x = a[i], y = a[j] *\
    \ w;\n                    a[i] = x + y, a[j] = x - y;\n                }\n   \
    \             w *= dw[__builtin_ctz(++k)];\n            }\n        }\n    }\n\n\
    \    void intt(vector<Mint> &a, bool f = true) {\n        const int n = (int)a.size();\n\
    \        assert((n & (n - 1)) == 0);\n        assert(__builtin_ctz(n) <= max_base);\n\
    \        for (int m = 1; m < n; m *= 2) {\n            Mint w = 1;\n         \
    \   for (int s = 0, k = 0; s < n; s += 2 * m) {\n                for (int i =\
    \ s, j = s + m; i < s + m; ++i, ++j) {\n                    auto x = a[i], y =\
    \ a[j];\n                    a[i] = x + y, a[j] = (x - y) * w;\n             \
    \   }\n                w *= idw[__builtin_ctz(++k)];\n            }\n        }\n\
    \        if (f) {\n            Mint inv_sz = Mint(1) / n;\n            for (int\
    \ i = 0; i < n; i++) a[i] *= inv_sz;\n        }\n    }\n\n    vector<Mint> multiply(vector<Mint>\
    \ a, vector<Mint> b) {\n        int need = a.size() + b.size() - 1;\n        int\
    \ nbase = 1;\n        while ((1 << nbase) < need) nbase++;\n        int sz = 1\
    \ << nbase;\n        a.resize(sz, 0);\n        b.resize(sz, 0);\n        ntt(a);\n\
    \        ntt(b);\n        Mint inv_sz = Mint(1) / sz;\n        for (int i = 0;\
    \ i < sz; i++) a[i] *= b[i] * inv_sz;\n        intt(a, false);\n        a.resize(need);\n\
    \        return a;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/NTT.cpp
  requiredBy: []
  timestamp: '2020-11-21 10:59:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/FPS.power.test.cpp
  - verify/yosupo-convolution_mod_1000000007.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
documentation_of: library/convolution/NTT.cpp
layout: document
redirect_from:
- /library/library/convolution/NTT.cpp
- /library/library/convolution/NTT.cpp.html
title: library/convolution/NTT.cpp
---
