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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/template/template.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../../library/template/template.cpp\"\ntemplate\
    \ <typename T = int>\nstruct StronglyConnectedComponents : Graph<T>\n{\npublic:\n\
    \    using Graph<T>::Graph;\n    using Graph<T>::g;\n    vector<int> comp;   \
    \       // id of scc\n    Graph<T> dag;              // DAG\n    vector<vector<int>>\
    \ group; // lists of each scc\n\n    void build()\n    {\n        rg = Graph<T>(g.size());\n\
    \        // add reversed edges\n        for (int i = 0; i < g.size(); i++)\n \
    \       {\n            for (auto &e : g[i])\n            {\n                rg.add_directed_edge(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        comp.assign(g.size(), -1);\n\
    \        used.assign(g.size(), 0);\n        // dfs for (not reversed) graph\n\
    \        for (int i = 0; i < g.size(); i++)\n            dfs(i);\n        reverse(begin(order),\
    \ end(order));\n        int ptr = 0;\n        for (int i : order)\n          \
    \  if (comp[i] == -1)\n                rdfs(i, ptr), ptr++;\n        dag = Graph<T>(ptr);\n\
    \        for (int i = 0; i < g.size(); i++)\n        {\n            for (auto\
    \ &e : g[i])\n            {\n                int x = comp[e.from], y = comp[e.to];\n\
    \                if (x == y)\n                    continue;\n                dag.add_directed_edge(x,\
    \ y, e.cost);\n            }\n        }\n        group.resize(ptr);\n        for\
    \ (int i = 0; i < g.size(); i++)\n        {\n            group[comp[i]].emplace_back(i);\n\
    \        }\n    }\n\n    int operator[](int k) const { return comp[k]; }\n\nprivate:\n\
    \    vector<int> order, used; // order:post order\n    Graph<T> rg;          \
    \   // reversed graph\n\n    void dfs(int idx)\n    {\n        if (exchange(used[idx],\
    \ true))\n            return;\n        for (auto &to : g[idx])\n            dfs(to);\n\
    \        order.push_back(idx);\n    }\n\n    void rdfs(int idx, int cnt)\n   \
    \ {\n        if (comp[idx] != -1)\n            return;\n        comp[idx] = cnt;\n\
    \        for (auto &to : rg.g[idx])\n            rdfs(to, cnt);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/connected-components/StronglyConnectedComponents.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/connected-components/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/library/graph/connected-components/StronglyConnectedComponents.cpp
- /library/library/graph/connected-components/StronglyConnectedComponents.cpp.html
title: library/graph/connected-components/StronglyConnectedComponents.cpp
---
