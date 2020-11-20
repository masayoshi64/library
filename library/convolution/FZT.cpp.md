---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj-2446.test.cpp
    title: verify/aoj-2446.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/convolution/FZT.cpp\"\n// \u90E8\u5206\u96C6\u5408\
    \u306B\u95A2\u3059\u308B\u548C\n// \u4E0A\u4F4D\u96C6\u5408\u306B\u95A2\u3059\u308B\
    \u548C\u306B\u3082\u3067\u304D\u308B\uFF08s->(1<<n)-1-s\u306B\u3059\u308B\u3060\
    \u3051)\ntemplate <typename T>\nvector<T> FZT(vector<T> f) {\n    int N = 0;\n\
    \    int tmp = f.size();\n    while (tmp > 1) N++, tmp /= 2;\n    for (int j =\
    \ 0; j < N; j++) {\n        for (int i = 0; i < (1 << N); i++) {\n           \
    \ if (i & (1 << j)) {\n                f[i] += f[i & ~(1 << j)];\n           \
    \ }\n        }\n    }\n    return f;\n}\n"
  code: "// \u90E8\u5206\u96C6\u5408\u306B\u95A2\u3059\u308B\u548C\n// \u4E0A\u4F4D\
    \u96C6\u5408\u306B\u95A2\u3059\u308B\u548C\u306B\u3082\u3067\u304D\u308B\uFF08\
    s->(1<<n)-1-s\u306B\u3059\u308B\u3060\u3051)\ntemplate <typename T>\nvector<T>\
    \ FZT(vector<T> f) {\n    int N = 0;\n    int tmp = f.size();\n    while (tmp\
    \ > 1) N++, tmp /= 2;\n    for (int j = 0; j < N; j++) {\n        for (int i =\
    \ 0; i < (1 << N); i++) {\n            if (i & (1 << j)) {\n                f[i]\
    \ += f[i & ~(1 << j)];\n            }\n        }\n    }\n    return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/FZT.cpp
  requiredBy: []
  timestamp: '2020-11-20 19:55:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj-2446.test.cpp
documentation_of: library/convolution/FZT.cpp
layout: document
redirect_from:
- /library/library/convolution/FZT.cpp
- /library/library/convolution/FZT.cpp.html
title: library/convolution/FZT.cpp
---
