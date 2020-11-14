---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"example.test1.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n\
    \    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n    int\
    \ cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        cnt += binary_search(ALL(s),\
    \ t_i);\n    }\n    cout << cnt << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n\
    \    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n    int\
    \ cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        cnt += binary_search(ALL(s),\
    \ t_i);\n    }\n    cout << cnt << endl;\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: example.test1.cpp
  requiredBy: []
  timestamp: '2020-11-14 10:05:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: example.test1.cpp
layout: document
redirect_from:
- /library/example.test1.cpp
- /library/example.test1.cpp.html
title: example.test1.cpp
---
