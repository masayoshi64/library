---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki-184.test.cpp
    title: verify/yuki-184.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/BitMatrix.cpp\"\nconst int MAX_ROW = 100005;\n\
    const int MAX_COL = 65;\n\nstruct BitMatrix {\n    int H, W, rank;\n    vector<int>\
    \ top;  // top bit\n    bitset<MAX_COL> A[MAX_ROW];\n    BitMatrix(int h = 1,\
    \ int w = 1) : H(h), W(w), rank(0) { top.resize(h); }\n    void build(bool is_extended\
    \ = false) {\n        rep(col, W) {\n            if (is_extended && col == W -\
    \ 1) break;\n            int row = rank;\n            for (; row < H; ++row) {\n\
    \                if (A[row][col]) {\n                    swap(A[rank], A[row]);\n\
    \                    break;\n                }\n            }\n            if\
    \ (row == H) continue;\n            top[rank] = col;\n            rep(k, H) {\n\
    \                if (k == rank) continue;\n                if (A[k][col]) A[k]\
    \ ^= A[rank];\n            }\n            ++rank;\n        }\n    }\n    int solve(vector<int>&\
    \ res) {\n        // if it has no solution then return -1\n        for (int row\
    \ = rank; row < H; ++row)\n            if (A[row][W - 1]) return -1;\n       \
    \ res.assign(W - 1, 0);\n        for (int i = 0; i < rank; ++i) res[i] = A[i][W\
    \ - 1];\n        return rank;\n    }\n    inline bitset<MAX_COL>& operator[](int\
    \ i) { return A[i]; }\n};\n"
  code: "const int MAX_ROW = 100005;\nconst int MAX_COL = 65;\n\nstruct BitMatrix\
    \ {\n    int H, W, rank;\n    vector<int> top;  // top bit\n    bitset<MAX_COL>\
    \ A[MAX_ROW];\n    BitMatrix(int h = 1, int w = 1) : H(h), W(w), rank(0) { top.resize(h);\
    \ }\n    void build(bool is_extended = false) {\n        rep(col, W) {\n     \
    \       if (is_extended && col == W - 1) break;\n            int row = rank;\n\
    \            for (; row < H; ++row) {\n                if (A[row][col]) {\n  \
    \                  swap(A[rank], A[row]);\n                    break;\n      \
    \          }\n            }\n            if (row == H) continue;\n           \
    \ top[rank] = col;\n            rep(k, H) {\n                if (k == rank) continue;\n\
    \                if (A[k][col]) A[k] ^= A[rank];\n            }\n            ++rank;\n\
    \        }\n    }\n    int solve(vector<int>& res) {\n        // if it has no\
    \ solution then return -1\n        for (int row = rank; row < H; ++row)\n    \
    \        if (A[row][W - 1]) return -1;\n        res.assign(W - 1, 0);\n      \
    \  for (int i = 0; i < rank; ++i) res[i] = A[i][W - 1];\n        return rank;\n\
    \    }\n    inline bitset<MAX_COL>& operator[](int i) { return A[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/BitMatrix.cpp
  requiredBy: []
  timestamp: '2020-11-19 21:23:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki-184.test.cpp
documentation_of: library/math/BitMatrix.cpp
layout: document
redirect_from:
- /library/library/math/BitMatrix.cpp
- /library/library/math/BitMatrix.cpp.html
title: library/math/BitMatrix.cpp
---
