---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B.test.cpp
    title: verify/aoj-DSL_2_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/structure/BIT/BIT.cpp\"\ntemplate <typename T>\n\
    struct BIT {\n    vector<T> data;\n\n    BIT(int sz) { data.assign(++sz, 0); }\n\
    \    //[0, k)\n    T sum(int k) {\n        T ret = 0;\n        for (; k > 0; k\
    \ -= k & -k) ret += data[k];\n        return (ret);\n    }\n\n    T sum(int l,\
    \ int r) { return sum(r) - sum(l); }\n\n    void add(int k, T x) {\n        for\
    \ (++k; k < data.size(); k += k & -k) data[k] += x;\n    }\n\n    // 0-indexed\u3067\
    k\u756A\u76EE\u306E\u5024\u3092\u8FD4\u3059\u3002\n    int search(long long k)\
    \ {\n        ++k;\n        int res = 0;\n        int N = 1;\n        while (N\
    \ < (int)data.size()) N *= 2;\n        for (int i = N / 2; i > 0; i /= 2) {\n\
    \            if (res + i < (int)data.size() && data[res + i] < k) {\n        \
    \        k = k - data[res + i];\n                res = res + i;\n            }\n\
    \        }\n        return res;\n    }\n\n    // for debug\n    void show() {\n\
    \        rep(i, SZ(data) - 1) cout << sum(i + 1) - sum(i) << ' ';\n        cout\
    \ << endl;\n    }\n};\n"
  code: "template <typename T>\nstruct BIT {\n    vector<T> data;\n\n    BIT(int sz)\
    \ { data.assign(++sz, 0); }\n    //[0, k)\n    T sum(int k) {\n        T ret =\
    \ 0;\n        for (; k > 0; k -= k & -k) ret += data[k];\n        return (ret);\n\
    \    }\n\n    T sum(int l, int r) { return sum(r) - sum(l); }\n\n    void add(int\
    \ k, T x) {\n        for (++k; k < data.size(); k += k & -k) data[k] += x;\n \
    \   }\n\n    // 0-indexed\u3067k\u756A\u76EE\u306E\u5024\u3092\u8FD4\u3059\u3002\
    \n    int search(long long k) {\n        ++k;\n        int res = 0;\n        int\
    \ N = 1;\n        while (N < (int)data.size()) N *= 2;\n        for (int i = N\
    \ / 2; i > 0; i /= 2) {\n            if (res + i < (int)data.size() && data[res\
    \ + i] < k) {\n                k = k - data[res + i];\n                res = res\
    \ + i;\n            }\n        }\n        return res;\n    }\n\n    // for debug\n\
    \    void show() {\n        rep(i, SZ(data) - 1) cout << sum(i + 1) - sum(i) <<\
    \ ' ';\n        cout << endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/BIT/BIT.cpp
  requiredBy: []
  timestamp: '2020-11-21 10:59:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_2_B.test.cpp
documentation_of: library/structure/BIT/BIT.cpp
layout: document
redirect_from:
- /library/library/structure/BIT/BIT.cpp
- /library/library/structure/BIT/BIT.cpp.html
title: library/structure/BIT/BIT.cpp
---
