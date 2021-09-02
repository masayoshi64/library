---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-max_flow.test.cpp
    title: verify/aoj-max_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/max_flow.md
    document_title: "\u6700\u5927\u6D41"
    links: []
  bundledCode: "#line 1 \"library/graph/flow/max_flow.cpp\"\n/**\n * @brief \u6700\
    \u5927\u6D41\n * @docs docs/max_flow.md\n */\ntemplate <class Cap>\nstruct mf_graph\
    \ {\n  public:\n    mf_graph() : _n(0) {\n    }\n    explicit mf_graph(int n)\
    \ : _n(n), g(n) {\n    }\n\n    int add_edge(int from, int to, Cap cap) {\n  \
    \      assert(0 <= from && from < _n);\n        assert(0 <= to && to < _n);\n\
    \        assert(0 <= cap);\n        int m = int(pos.size());\n        pos.push_back({from,\
    \ int(g[from].size())});\n        int from_id = int(g[from].size());\n       \
    \ int to_id = int(g[to].size());\n        if (from == to) to_id++;\n        g[from].push_back(_edge{to,\
    \ to_id, cap});\n        g[to].push_back(_edge{from, from_id, 0});\n        return\
    \ m;\n    }\n\n    struct edge {\n        int from, to;\n        Cap cap, flow;\n\
    \    };\n\n    edge get_edge(int i) {\n        int m = int(pos.size());\n    \
    \    assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto &_e = g[pos[i].first][pos[i].second];\n\
    \        auto &_re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        deque<int> que;\n\n        auto bfs = [&]() {\n         \
    \   std::fill(level.begin(), level.end(), -1);\n            level[s] = 0;\n  \
    \          que.clear();\n            que.push_front(s);\n            while (!que.empty())\
    \ {\n                int v = que.front();\n                que.pop_front();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push_front(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int &i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge &e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));\n\
    \                if (d <= 0) continue;\n                g[v][i].cap += d;\n  \
    \              g[e.to][e.rev].cap -= d;\n                res += d;\n         \
    \       if (res == up) return res;\n            }\n            level[v] = _n;\n\
    \            return res;\n        };\n\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs();\n            if (level[t] == -1) break;\n\
    \            std::fill(iter.begin(), iter.end(), 0);\n            Cap f = dfs(dfs,\
    \ t, flow_limit - flow);\n            if (!f) break;\n            flow += f;\n\
    \        }\n        return flow;\n    }\n\n    std::vector<bool> min_cut(int s)\
    \ {\n        std::vector<bool> visited(_n);\n        deque<int> que;\n       \
    \ que.push_front(s);\n        while (!que.empty()) {\n            int p = que.front();\n\
    \            que.pop_front();\n            visited[p] = true;\n            for\
    \ (auto e : g[p]) {\n                if (e.cap && !visited[e.to]) {\n        \
    \            visited[e.to] = true;\n                    que.push_front(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \n  private:\n    int _n;\n    struct _edge {\n        int to, rev;\n        Cap\
    \ cap;\n    };\n    std::vector<std::pair<int, int>> pos;\n    std::vector<std::vector<_edge>>\
    \ g;\n};\n"
  code: "/**\n * @brief \u6700\u5927\u6D41\n * @docs docs/max_flow.md\n */\ntemplate\
    \ <class Cap>\nstruct mf_graph {\n  public:\n    mf_graph() : _n(0) {\n    }\n\
    \    explicit mf_graph(int n) : _n(n), g(n) {\n    }\n\n    int add_edge(int from,\
    \ int to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        int from_id = int(g[from].size());\n\
    \        int to_id = int(g[to].size());\n        if (from == to) to_id++;\n  \
    \      g[from].push_back(_edge{to, to_id, cap});\n        g[to].push_back(_edge{from,\
    \ from_id, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto &_e = g[pos[i].first][pos[i].second];\n\
    \        auto &_re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        deque<int> que;\n\n        auto bfs = [&]() {\n         \
    \   std::fill(level.begin(), level.end(), -1);\n            level[s] = 0;\n  \
    \          que.clear();\n            que.push_front(s);\n            while (!que.empty())\
    \ {\n                int v = que.front();\n                que.pop_front();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push_front(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int &i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge &e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));\n\
    \                if (d <= 0) continue;\n                g[v][i].cap += d;\n  \
    \              g[e.to][e.rev].cap -= d;\n                res += d;\n         \
    \       if (res == up) return res;\n            }\n            level[v] = _n;\n\
    \            return res;\n        };\n\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs();\n            if (level[t] == -1) break;\n\
    \            std::fill(iter.begin(), iter.end(), 0);\n            Cap f = dfs(dfs,\
    \ t, flow_limit - flow);\n            if (!f) break;\n            flow += f;\n\
    \        }\n        return flow;\n    }\n\n    std::vector<bool> min_cut(int s)\
    \ {\n        std::vector<bool> visited(_n);\n        deque<int> que;\n       \
    \ que.push_front(s);\n        while (!que.empty()) {\n            int p = que.front();\n\
    \            que.pop_front();\n            visited[p] = true;\n            for\
    \ (auto e : g[p]) {\n                if (e.cap && !visited[e.to]) {\n        \
    \            visited[e.to] = true;\n                    que.push_front(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \n  private:\n    int _n;\n    struct _edge {\n        int to, rev;\n        Cap\
    \ cap;\n    };\n    std::vector<std::pair<int, int>> pos;\n    std::vector<std::vector<_edge>>\
    \ g;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/flow/max_flow.cpp
  requiredBy: []
  timestamp: '2021-09-02 12:45:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-max_flow.test.cpp
documentation_of: library/graph/flow/max_flow.cpp
layout: document
redirect_from:
- /library/library/graph/flow/max_flow.cpp
- /library/library/graph/flow/max_flow.cpp.html
title: "\u6700\u5927\u6D41"
---
## メモ
- ac-libraryからsimple_queue->dequeに変更
- [ドキュメント](https://github.com/atcoder/ac-library/blob/master/document_ja/maxflow.md)


