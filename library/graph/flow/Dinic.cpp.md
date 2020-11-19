---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_6_A.test.cpp
    title: verify/aoj-GRL_6_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dinic.md
    document_title: "Dinic(\u6700\u5927\u6D41)"
    links: []
  bundledCode: "#line 1 \"library/graph/flow/Dinic.cpp\"\n/**\n * @brief Dinic(\u6700\
    \u5927\u6D41)\n * @docs docs/dinic.md\n */\ntemplate <typename flow_t>\nstruct\
    \ Dinic {\n    const flow_t TINF;\n\n    struct edge {\n        int to;\n    \
    \    flow_t cap;\n        int rev;\n        bool isrev;\n        int idx;\n  \
    \  };\n\n    vector<vector<edge> > graph;\n    vector<int> min_cost, iter;\n\n\
    \    explicit Dinic(int V) : TINF(numeric_limits<flow_t>::max()), graph(V) {}\n\
    \n    void add_edge(int from, int to, flow_t cap, int idx = -1) {\n        graph[from].emplace_back(\n\
    \            (edge){to, cap, (int)graph[to].size(), false, idx});\n        graph[to].emplace_back(\n\
    \            (edge){from, 0, (int)graph[from].size() - 1, true, idx});\n    }\n\
    \n    bool build_augment_path(int s, int t) {\n        min_cost.assign(graph.size(),\
    \ -1);\n        queue<int> que;\n        min_cost[s] = 0;\n        que.push(s);\n\
    \        while (!que.empty() && min_cost[t] == -1) {\n            int p = que.front();\n\
    \            que.pop();\n            for (auto &e : graph[p]) {\n            \
    \    if (e.cap > 0 && min_cost[e.to] == -1) {\n                    min_cost[e.to]\
    \ = min_cost[p] + 1;\n                    que.push(e.to);\n                }\n\
    \            }\n        }\n        return min_cost[t] != -1;\n    }\n\n    flow_t\
    \ find_min_dist_augment_path(int idx, const int t, flow_t flow) {\n        if\
    \ (idx == t) return flow;\n        for (int &i = iter[idx]; i < graph[idx].size();\
    \ i++) {\n            edge &e = graph[idx][i];\n            if (e.cap > 0 && min_cost[idx]\
    \ < min_cost[e.to]) {\n                flow_t d =\n                    find_min_dist_augment_path(e.to,\
    \ t, min(flow, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    graph[e.to][e.rev].cap += d;\n                  \
    \  return d;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n\n    flow_t max_flow(int s, int t) {\n        flow_t flow = 0;\n    \
    \    while (build_augment_path(s, t)) {\n            iter.assign(graph.size(),\
    \ 0);\n            flow_t f;\n            while ((f = find_min_dist_augment_path(s,\
    \ t, TINF)) > 0) flow += f;\n        }\n        return flow;\n    }\n\n    void\
    \ output() {\n        for (int i = 0; i < graph.size(); i++) {\n            for\
    \ (auto &e : graph[i]) {\n                if (e.isrev) continue;\n           \
    \     auto &rev_e = graph[e.to][e.rev];\n                cout << i << \"->\" <<\
    \ e.to << \" (flow: \" << rev_e.cap << \"/\"\n                     << e.cap +\
    \ rev_e.cap << \")\" << endl;\n            }\n        }\n    }\n};\n"
  code: "/**\n * @brief Dinic(\u6700\u5927\u6D41)\n * @docs docs/dinic.md\n */\ntemplate\
    \ <typename flow_t>\nstruct Dinic {\n    const flow_t TINF;\n\n    struct edge\
    \ {\n        int to;\n        flow_t cap;\n        int rev;\n        bool isrev;\n\
    \        int idx;\n    };\n\n    vector<vector<edge> > graph;\n    vector<int>\
    \ min_cost, iter;\n\n    explicit Dinic(int V) : TINF(numeric_limits<flow_t>::max()),\
    \ graph(V) {}\n\n    void add_edge(int from, int to, flow_t cap, int idx = -1)\
    \ {\n        graph[from].emplace_back(\n            (edge){to, cap, (int)graph[to].size(),\
    \ false, idx});\n        graph[to].emplace_back(\n            (edge){from, 0,\
    \ (int)graph[from].size() - 1, true, idx});\n    }\n\n    bool build_augment_path(int\
    \ s, int t) {\n        min_cost.assign(graph.size(), -1);\n        queue<int>\
    \ que;\n        min_cost[s] = 0;\n        que.push(s);\n        while (!que.empty()\
    \ && min_cost[t] == -1) {\n            int p = que.front();\n            que.pop();\n\
    \            for (auto &e : graph[p]) {\n                if (e.cap > 0 && min_cost[e.to]\
    \ == -1) {\n                    min_cost[e.to] = min_cost[p] + 1;\n          \
    \          que.push(e.to);\n                }\n            }\n        }\n    \
    \    return min_cost[t] != -1;\n    }\n\n    flow_t find_min_dist_augment_path(int\
    \ idx, const int t, flow_t flow) {\n        if (idx == t) return flow;\n     \
    \   for (int &i = iter[idx]; i < graph[idx].size(); i++) {\n            edge &e\
    \ = graph[idx][i];\n            if (e.cap > 0 && min_cost[idx] < min_cost[e.to])\
    \ {\n                flow_t d =\n                    find_min_dist_augment_path(e.to,\
    \ t, min(flow, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    graph[e.to][e.rev].cap += d;\n                  \
    \  return d;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n\n    flow_t max_flow(int s, int t) {\n        flow_t flow = 0;\n    \
    \    while (build_augment_path(s, t)) {\n            iter.assign(graph.size(),\
    \ 0);\n            flow_t f;\n            while ((f = find_min_dist_augment_path(s,\
    \ t, TINF)) > 0) flow += f;\n        }\n        return flow;\n    }\n\n    void\
    \ output() {\n        for (int i = 0; i < graph.size(); i++) {\n            for\
    \ (auto &e : graph[i]) {\n                if (e.isrev) continue;\n           \
    \     auto &rev_e = graph[e.to][e.rev];\n                cout << i << \"->\" <<\
    \ e.to << \" (flow: \" << rev_e.cap << \"/\"\n                     << e.cap +\
    \ rev_e.cap << \")\" << endl;\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/flow/Dinic.cpp
  requiredBy: []
  timestamp: '2020-11-19 22:26:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_6_A.test.cpp
documentation_of: library/graph/flow/Dinic.cpp
layout: document
redirect_from:
- /library/library/graph/flow/Dinic.cpp
- /library/library/graph/flow/Dinic.cpp.html
title: "Dinic(\u6700\u5927\u6D41)"
---
