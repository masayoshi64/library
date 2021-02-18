---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder-abc136_d.cpp
    title: test/atcoder-abc136_d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/others/Doubling.cpp\"\nstruct Doubling {\n    const\
    \ int LOG;\n    vector<vector<int> > table;\n\n    Doubling(int sz, int64_t lim_t)\
    \ : LOG(64 - __builtin_clzll(lim_t)) {\n        table.assign(LOG, vector<int>(sz,\
    \ -1));\n    }\n\n    void set_next(int k, int x) { table[0][k] = x; }\n\n   \
    \ void build() {\n        for (int k = 0; k + 1 < LOG; k++) {\n            for\
    \ (int i = 0; i < table[k].size(); i++) {\n                if (table[k][i] ==\
    \ -1)\n                    table[k + 1][i] = -1;\n                else\n     \
    \               table[k + 1][i] = table[k][table[k][i]];\n            }\n    \
    \    }\n    }\n\n    int query(int k, int64_t t) {\n        for (int i = LOG -\
    \ 1; i >= 0; i--) {\n            if ((t >> i) & 1) k = table[i][k];\n        }\n\
    \        return k;\n    }\n};\n"
  code: "struct Doubling {\n    const int LOG;\n    vector<vector<int> > table;\n\n\
    \    Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t)) {\n  \
    \      table.assign(LOG, vector<int>(sz, -1));\n    }\n\n    void set_next(int\
    \ k, int x) { table[0][k] = x; }\n\n    void build() {\n        for (int k = 0;\
    \ k + 1 < LOG; k++) {\n            for (int i = 0; i < table[k].size(); i++) {\n\
    \                if (table[k][i] == -1)\n                    table[k + 1][i] =\
    \ -1;\n                else\n                    table[k + 1][i] = table[k][table[k][i]];\n\
    \            }\n        }\n    }\n\n    int query(int k, int64_t t) {\n      \
    \  for (int i = LOG - 1; i >= 0; i--) {\n            if ((t >> i) & 1) k = table[i][k];\n\
    \        }\n        return k;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/others/Doubling.cpp
  requiredBy:
  - test/atcoder-abc136_d.cpp
  timestamp: '2020-11-20 20:38:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/others/Doubling.cpp
layout: document
redirect_from:
- /library/library/others/Doubling.cpp
- /library/library/others/Doubling.cpp.html
title: library/others/Doubling.cpp
---
