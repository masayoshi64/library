---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/graph/connected-components/StronglyConnectedComponents.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    library/template/template.cpp\"\n// library\n#include \"library/graph/connected-components/TwoSat.cpp\"\
    \nint main() {\n    string p, cnf;\n    int n, m;\n    cin >> p >> cnf >> n >>\
    \ m;\n    TwoSat ts(n);\n    rep(i, m) {\n        int u, v, z;\n        cin >>\
    \ u >> v >> z;\n        if (u < 0)\n            u = ts.rev(-u - 1);\n        else\n\
    \            u--;\n        if (v < 0)\n            v = ts.rev(-v - 1);\n     \
    \   else\n            v--;\n        ts.add_or(u, v);\n    }\n    auto ret = ts.solve();\n\
    \    if (ret.size()) {\n        cout << \"s SATISFIABLE\" << endl;\n        cout\
    \ << \"v \";\n        rep(i, n) cout << (ret[i] ? i + 1 : -i - 1) << ' ';\n  \
    \      cout << 0 << ' ' << endl;\n    } else {\n        cout << \"s UNSATISFIABLE\"\
    \ << endl;\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo-two_sat.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-two_sat.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-two_sat.test.cpp
- /verify/verify/yosupo-two_sat.test.cpp.html
title: verify/yosupo-two_sat.test.cpp
---
