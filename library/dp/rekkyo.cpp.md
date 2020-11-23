---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yuki-545.cpp.cpp
    title: verify/yuki-545.cpp.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dp/rekkyo.cpp\"\ntemplate <typename T>\nvector<T>\
    \ rekkyo(const vector<T>& items) {\n    vector<T> res = {0}, tmp, tmp1;\n    for\
    \ (T item : items) {\n        for (auto val : res) {\n            tmp.pb(item\
    \ + val);\n        }\n        //\u30BD\u30FC\u30C8\u3055\u308C\u305F\u307E\u307E\
    merge\n        merge(all(res), all(tmp), back_inserter(tmp1));\n        swap(res,\
    \ tmp1);\n        tmp.clear();\n        tmp1.clear();\n    }\n    return res;\n\
    }\n\n// vector<T> a = rekkyo({items.begin(), items.begin() + n / 2});\n// vector<T>\
    \ b = rekkyo({items.begin() + n / 2, items.end()});\n"
  code: "template <typename T>\nvector<T> rekkyo(const vector<T>& items) {\n    vector<T>\
    \ res = {0}, tmp, tmp1;\n    for (T item : items) {\n        for (auto val : res)\
    \ {\n            tmp.pb(item + val);\n        }\n        //\u30BD\u30FC\u30C8\u3055\
    \u308C\u305F\u307E\u307Emerge\n        merge(all(res), all(tmp), back_inserter(tmp1));\n\
    \        swap(res, tmp1);\n        tmp.clear();\n        tmp1.clear();\n    }\n\
    \    return res;\n}\n\n// vector<T> a = rekkyo({items.begin(), items.begin() +\
    \ n / 2});\n// vector<T> b = rekkyo({items.begin() + n / 2, items.end()});"
  dependsOn: []
  isVerificationFile: false
  path: library/dp/rekkyo.cpp
  requiredBy:
  - verify/yuki-545.cpp.cpp
  timestamp: '2020-11-23 18:44:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dp/rekkyo.cpp
layout: document
redirect_from:
- /library/library/dp/rekkyo.cpp
- /library/library/dp/rekkyo.cpp.html
title: library/dp/rekkyo.cpp
---
