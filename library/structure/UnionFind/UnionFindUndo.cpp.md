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
  bundledCode: "#line 1 \"library/structure/UnionFind/UnionFindUndo.cpp\"\nstruct\
    \ UnionFindUndo {\n    vector<int> data;\n    stack<pair<int, int> > history;\n\
    \n    UnionFindUndo(int sz) { data.assign(sz, -1); }\n\n    bool unite(int x,\
    \ int y) {\n        x = find(x), y = find(y);\n        history.emplace(x, data[x]);\n\
    \        history.emplace(y, data[y]);\n        if (x == y) return (false);\n \
    \       if (data[x] > data[y]) swap(x, y);\n        data[x] += data[y];\n    \
    \    data[y] = x;\n        return (true);\n    }\n\n    int find(int k) {\n  \
    \      if (data[k] < 0) return (k);\n        return (find(data[k]));\n    }\n\n\
    \    int size(int k) { return (-data[find(k)]); }\n\n    void undo() {\n     \
    \   data[history.top().first] = history.top().second;\n        history.pop();\n\
    \        data[history.top().first] = history.top().second;\n        history.pop();\n\
    \    }\n\n    void snapshot() {\n        while (history.size()) history.pop();\n\
    \    }\n\n    void rollback() {\n        while (history.size()) undo();\n    }\n\
    };\n"
  code: "struct UnionFindUndo {\n    vector<int> data;\n    stack<pair<int, int> >\
    \ history;\n\n    UnionFindUndo(int sz) { data.assign(sz, -1); }\n\n    bool unite(int\
    \ x, int y) {\n        x = find(x), y = find(y);\n        history.emplace(x, data[x]);\n\
    \        history.emplace(y, data[y]);\n        if (x == y) return (false);\n \
    \       if (data[x] > data[y]) swap(x, y);\n        data[x] += data[y];\n    \
    \    data[y] = x;\n        return (true);\n    }\n\n    int find(int k) {\n  \
    \      if (data[k] < 0) return (k);\n        return (find(data[k]));\n    }\n\n\
    \    int size(int k) { return (-data[find(k)]); }\n\n    void undo() {\n     \
    \   data[history.top().first] = history.top().second;\n        history.pop();\n\
    \        data[history.top().first] = history.top().second;\n        history.pop();\n\
    \    }\n\n    void snapshot() {\n        while (history.size()) history.pop();\n\
    \    }\n\n    void rollback() {\n        while (history.size()) undo();\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/UnionFind/UnionFindUndo.cpp
  requiredBy: []
  timestamp: '2021-01-02 17:35:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/structure/UnionFind/UnionFindUndo.cpp
layout: document
redirect_from:
- /library/library/structure/UnionFind/UnionFindUndo.cpp
- /library/library/structure/UnionFind/UnionFindUndo.cpp.html
title: library/structure/UnionFind/UnionFindUndo.cpp
---
