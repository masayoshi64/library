---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/distance/TSP.cpp\"\n\n//\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n\n// \u30CF\u30DF\u30EB\u30C8\u30F3\
    \u9589\u8DEF\ntemplate <typename T>\nT TSP1(vector<vector<T>> dist) {\n    int\
    \ n = dist.size();\n    T TINF = numeric_limits<T>::max();\n    vector<vector<T>>\
    \ dp(1 << n, vector<T>(n, TINF / 2));\n    dp[0][0] = 0;\n    rep(s, (1 << n))\
    \ {\n        rep(pv, n) {\n            rep(nv, n) {\n                chmin(dp[s\
    \ | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);\n                chmin(dp[s | (1\
    \ << nv)][nv], TINF / 2);\n            }\n        }\n    }\n    return vmin(dp[(1\
    \ << n) - 1]);\n}\n\n// \u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9 from st\ntemplate\
    \ <typename T>\nT TSP2(vector<vector<T>> dist, int st) {\n    int n = dist.size();\n\
    \    T TINF = numeric_limits<T>::max();\n    vector<vector<T>> dp(1 << n, vector<T>(n,\
    \ TINF / 2));\n    dp[(1 << st)][st] = 0;\n    rep(s, (1 << n)) {\n        rep(pv,\
    \ n) {\n            rep(nv, n) {\n                chmin(dp[s | (1 << nv)][nv],\
    \ dp[s][pv] + dist[pv][nv]);\n                chmin(dp[s | (1 << nv)][nv], TINF\
    \ / 2);\n            }\n        }\n    }\n    return vmin(dp[(1 << n) - 1]);\n\
    }\n\n// \u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9 from anywhere\ntemplate <typename\
    \ T>\nT TSP3(vector<vector<T>> dist) {\n    int n = dist.size();\n    T TINF =\
    \ numeric_limits<T>::max();\n    vector<vector<T>> dp(1 << n, vector<T>(n, TINF\
    \ / 2));\n    rep(s, n) dp[(1 << s)][s] = 0;\n    rep(s, (1 << n)) {\n       \
    \ rep(pv, n) {\n            rep(nv, n) {\n                chmin(dp[s | (1 << nv)][nv],\
    \ dp[s][pv] + dist[pv][nv]);\n                chmin(dp[s | (1 << nv)][nv], TINF\
    \ / 2);\n            }\n        }\n    }\n    return vmin(dp[(1 << n) - 1]);\n\
    }\n"
  code: "\n//\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n\n// \u30CF\
    \u30DF\u30EB\u30C8\u30F3\u9589\u8DEF\ntemplate <typename T>\nT TSP1(vector<vector<T>>\
    \ dist) {\n    int n = dist.size();\n    T TINF = numeric_limits<T>::max();\n\
    \    vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));\n    dp[0][0] = 0;\n\
    \    rep(s, (1 << n)) {\n        rep(pv, n) {\n            rep(nv, n) {\n    \
    \            chmin(dp[s | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);\n       \
    \         chmin(dp[s | (1 << nv)][nv], TINF / 2);\n            }\n        }\n\
    \    }\n    return vmin(dp[(1 << n) - 1]);\n}\n\n// \u30CF\u30DF\u30EB\u30C8\u30F3\
    \u30D1\u30B9 from st\ntemplate <typename T>\nT TSP2(vector<vector<T>> dist, int\
    \ st) {\n    int n = dist.size();\n    T TINF = numeric_limits<T>::max();\n  \
    \  vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));\n    dp[(1 << st)][st]\
    \ = 0;\n    rep(s, (1 << n)) {\n        rep(pv, n) {\n            rep(nv, n) {\n\
    \                chmin(dp[s | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);\n   \
    \             chmin(dp[s | (1 << nv)][nv], TINF / 2);\n            }\n       \
    \ }\n    }\n    return vmin(dp[(1 << n) - 1]);\n}\n\n// \u30CF\u30DF\u30EB\u30C8\
    \u30F3\u30D1\u30B9 from anywhere\ntemplate <typename T>\nT TSP3(vector<vector<T>>\
    \ dist) {\n    int n = dist.size();\n    T TINF = numeric_limits<T>::max();\n\
    \    vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));\n    rep(s, n) dp[(1\
    \ << s)][s] = 0;\n    rep(s, (1 << n)) {\n        rep(pv, n) {\n            rep(nv,\
    \ n) {\n                chmin(dp[s | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);\n\
    \                chmin(dp[s | (1 << nv)][nv], TINF / 2);\n            }\n    \
    \    }\n    }\n    return vmin(dp[(1 << n) - 1]);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/distance/TSP.cpp
  requiredBy: []
  timestamp: '2021-02-18 11:40:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/distance/TSP.cpp
layout: document
redirect_from:
- /library/library/graph/distance/TSP.cpp
- /library/library/graph/distance/TSP.cpp.html
title: library/graph/distance/TSP.cpp
---
