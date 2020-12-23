---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ArticulationPoint.test.cpp
    title: verify/ArticulationPoint.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/others/LowLink.cpp\"\n\ntemplate <typename\
    \ T = int>\nstruct LowLink : Graph<T> {\n   public:\n    using Graph<T>::Graph;\n\
    \    vector<int> ord, low, articulation;\n    vector<Edge<T> > bridge;\n    using\
    \ Graph<T>::g;\n\n    virtual void build() {\n        used.assign(g.size(), 0);\n\
    \        ord.assign(g.size(), 0);\n        low.assign(g.size(), 0);\n        int\
    \ k = 0;\n        for (int i = 0; i < (int)g.size(); i++) {\n            if (!used[i])\
    \ k = dfs(i, k, -1);\n        }\n    }\n\n    explicit LowLink(const Graph<T>\
    \ &g) : Graph<T>(g) {}\n\n   private:\n    vector<int> used;\n\n    int dfs(int\
    \ idx, int k, int par) {\n        used[idx] = true;\n        ord[idx] = k++;\n\
    \        low[idx] = ord[idx];\n        bool is_articulation = false;\n       \
    \ int cnt = 0;\n        for (auto &to : g[idx]) {\n            if (!used[to])\
    \ {  //\u5F8C\u9000\u8FBA\u3067\u306A\u3044\u5834\u5408\n                ++cnt;\n\
    \                k = dfs(to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                //\u6839\u3067\u306F\u306A\u304F\u81EA\u5206\u306E\
    ord<=\u5B50\u306Elow\u306A\u3089\u95A2\u7BC0\u70B9\n                is_articulation\
    \ |= par >= 0 && low[to] >= ord[idx];\n                //\u81EA\u5206\u306Eord<\u5B50\
    \u306Elow\u306A\u3089\u6A4B\n                if (ord[idx] < low[to]) bridge.emplace_back(to);\n\
    \            } else {  //\u5F8C\u9000\u8FBA\u306E\u5834\u5408\n              \
    \  low[idx] = min(low[idx], ord[to]);\n            }\n        }\n        is_articulation\
    \ |= par == -1 && cnt > 1;  // dfs\u6728\u306E\u9802\u70B9\u306E\u5834\u5408\n\
    \        if (is_articulation) articulation.push_back(idx);\n        return k;\n\
    \    }\n};\n"
  code: "\ntemplate <typename T = int>\nstruct LowLink : Graph<T> {\n   public:\n\
    \    using Graph<T>::Graph;\n    vector<int> ord, low, articulation;\n    vector<Edge<T>\
    \ > bridge;\n    using Graph<T>::g;\n\n    virtual void build() {\n        used.assign(g.size(),\
    \ 0);\n        ord.assign(g.size(), 0);\n        low.assign(g.size(), 0);\n  \
    \      int k = 0;\n        for (int i = 0; i < (int)g.size(); i++) {\n       \
    \     if (!used[i]) k = dfs(i, k, -1);\n        }\n    }\n\n    explicit LowLink(const\
    \ Graph<T> &g) : Graph<T>(g) {}\n\n   private:\n    vector<int> used;\n\n    int\
    \ dfs(int idx, int k, int par) {\n        used[idx] = true;\n        ord[idx]\
    \ = k++;\n        low[idx] = ord[idx];\n        bool is_articulation = false;\n\
    \        int cnt = 0;\n        for (auto &to : g[idx]) {\n            if (!used[to])\
    \ {  //\u5F8C\u9000\u8FBA\u3067\u306A\u3044\u5834\u5408\n                ++cnt;\n\
    \                k = dfs(to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                //\u6839\u3067\u306F\u306A\u304F\u81EA\u5206\u306E\
    ord<=\u5B50\u306Elow\u306A\u3089\u95A2\u7BC0\u70B9\n                is_articulation\
    \ |= par >= 0 && low[to] >= ord[idx];\n                //\u81EA\u5206\u306Eord<\u5B50\
    \u306Elow\u306A\u3089\u6A4B\n                if (ord[idx] < low[to]) bridge.emplace_back(to);\n\
    \            } else {  //\u5F8C\u9000\u8FBA\u306E\u5834\u5408\n              \
    \  low[idx] = min(low[idx], ord[to]);\n            }\n        }\n        is_articulation\
    \ |= par == -1 && cnt > 1;  // dfs\u6728\u306E\u9802\u70B9\u306E\u5834\u5408\n\
    \        if (is_articulation) articulation.push_back(idx);\n        return k;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/others/LowLink.cpp
  requiredBy: []
  timestamp: '2020-12-23 20:37:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ArticulationPoint.test.cpp
documentation_of: library/graph/others/LowLink.cpp
layout: document
redirect_from:
- /library/library/graph/others/LowLink.cpp
- /library/library/graph/others/LowLink.cpp.html
title: library/graph/others/LowLink.cpp
---
