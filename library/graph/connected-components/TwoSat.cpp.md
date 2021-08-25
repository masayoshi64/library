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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/graph/connected-components/StronglyConnectedComponents.cpp:\
    \ line -1: no such header\n"
  code: "#include \"../../library/graph/connected-components/StronglyConnectedComponents.cpp\"\
    \n\nstruct TwoSat : StronglyConnectedComponents<bool> {\n   public:\n    using\
    \ StronglyConnectedComponents<bool>::g;\n    using StronglyConnectedComponents<bool>::comp;\n\
    \    using StronglyConnectedComponents<bool>::add_edge;\n    int sz;\n\n    explicit\
    \ TwoSat(int v)\n        : sz(v), StronglyConnectedComponents<bool>(v + v) {}\n\
    \n    void add_if(int u, int v) {\n        // u -> v <=> !v -> !u\n        add_directed_edge(u,\
    \ v);\n        add_directed_edge(rev(v), rev(u));\n    }\n\n    void add_or(int\
    \ u, int v) {\n        // u or v <=> !u -> v\n        add_if(rev(u), v);\n   \
    \ }\n\n    void add_nand(int u, int v) {\n        // u nand v <=> u -> !v\n  \
    \      add_if(u, rev(v));\n    }\n\n    void set_true(int u) {\n        // u <=>\
    \ !u -> u\n        add_directed_edge(rev(u), u);\n    }\n\n    void set_false(int\
    \ u) {\n        // !u <=> u -> !u\n        add_directed_edge(u, rev(u));\n   \
    \ }\n\n    inline int rev(int x) {\n        if (x >= sz) return x - sz;\n    \
    \    return x + sz;\n    }\n\n    vector<int> solve() {\n        StronglyConnectedComponents<bool>::build();\n\
    \        vector<int> ret(sz);\n        for (int i = 0; i < sz; i++) {\n      \
    \      if (comp[i] == comp[rev(i)]) return {};\n            ret[i] = comp[i] >\
    \ comp[rev(i)];\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/connected-components/TwoSat.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/connected-components/TwoSat.cpp
layout: document
redirect_from:
- /library/library/graph/connected-components/TwoSat.cpp
- /library/library/graph/connected-components/TwoSat.cpp.html
title: library/graph/connected-components/TwoSat.cpp
---
