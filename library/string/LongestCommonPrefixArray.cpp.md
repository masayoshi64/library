---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/SuffixArray.cpp
    title: library/string/SuffixArray.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yuki-1408.cpp
    title: verify/yuki-1408.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/string/SuffixArray.cpp\"\nstruct SuffixArray {\n\
    \    vector<int> SA;\n    const string s;\n\n    SuffixArray(const string &str)\
    \ : s(str) {\n        SA.resize(s.size());\n        iota(begin(SA), end(SA), 0);\n\
    \        sort(begin(SA), end(SA),\n             [&](int a, int b) { return s[a]\
    \ == s[b] ? a > b : s[a] < s[b]; });\n        vector<int> classes(s.size()), c(s.begin(),\
    \ s.end()), cnt(s.size());\n        for (int len = 1; len < s.size(); len <<=\
    \ 1) {\n            for (int i = 0; i < s.size(); i++) {\n                if (i\
    \ > 0 && c[SA[i - 1]] == c[SA[i]] &&\n                    SA[i - 1] + len < s.size()\
    \ &&\n                    c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {\n  \
    \                  classes[SA[i]] = classes[SA[i - 1]];\n                } else\
    \ {\n                    classes[SA[i]] = i;\n                }\n            }\n\
    \            iota(begin(cnt), end(cnt), 0);\n            copy(begin(SA), end(SA),\
    \ begin(c));\n            for (int i = 0; i < s.size(); i++) {\n             \
    \   int s1 = c[i] - len;\n                if (s1 >= 0) SA[cnt[classes[s1]]++]\
    \ = s1;\n            }\n            classes.swap(c);\n        }\n    }\n\n   \
    \ int operator[](int k) const { return SA[k]; }\n\n    int size() const { return\
    \ s.size(); }\n\n    bool lt_substr(const string &t, int si = 0, int ti = 0) {\n\
    \        int sn = (int)s.size(), tn = (int)t.size();\n        while (si < sn &&\
    \ ti < tn) {\n            if (s[si] < t[ti]) return true;\n            if (s[si]\
    \ > t[ti]) return false;\n            ++si, ++ti;\n        }\n        return si\
    \ >= sn && ti < tn;\n    }\n\n    int lower_bound(const string &t) {\n       \
    \ int low = -1, high = (int)SA.size();\n        while (high - low > 1) {\n   \
    \         int mid = (low + high) / 2;\n            if (lt_substr(t, SA[mid]))\n\
    \                low = mid;\n            else\n                high = mid;\n \
    \       }\n        return high;\n    }\n\n    pair<int, int> lower_upper_bound(string\
    \ &t) {\n        int idx = lower_bound(t);\n        int low = idx - 1, high =\
    \ (int)SA.size();\n        t.back()++;\n        while (high - low > 1) {\n   \
    \         int mid = (low + high) / 2;\n            if (lt_substr(t, SA[mid]))\n\
    \                low = mid;\n            else\n                high = mid;\n \
    \       }\n        t.back()--;\n        return {idx, high};\n    }\n\n    void\
    \ show() {\n        for (int i = 0; i < size(); i++) {\n            cout << i\
    \ << \": \" << s.substr(SA[i]) << endl;\n        }\n    }\n};\n#line 2 \"library/string/LongestCommonPrefixArray.cpp\"\
    \n\nstruct LongestCommonPrefixArray {\n    const SuffixArray &SA;\n    vector<int>\
    \ LCP, rank;\n\n    LongestCommonPrefixArray(const SuffixArray &SA) : SA(SA),\
    \ LCP(SA.size()) {\n        rank.resize(SA.size());\n        for (int i = 0; i\
    \ < SA.size(); i++) {\n            rank[SA[i]] = i;\n        }\n        for (int\
    \ i = 0, h = 0; i < SA.size(); i++) {\n            if (rank[i] + 1 < SA.size())\
    \ {\n                for (int j = SA[rank[i] + 1];\n                     max(i,\
    \ j) + h < SA.size() && SA.s[i + h] == SA.s[j + h];\n                     ++h)\n\
    \                    ;\n                LCP[rank[i] + 1] = h;\n              \
    \  if (h > 0) --h;\n            }\n        }\n    }\n\n    int operator[](int\
    \ k) const { return LCP[k]; }\n\n    int size() const { return LCP.size(); }\n\
    \n    void show() {\n        for (int i = 0; i < size(); i++) {\n            cout\
    \ << i << \": \" << LCP[i] << \" \" << SA.s.substr(SA[i]) << endl;\n        }\n\
    \    }\n};\n"
  code: "#include \"library/string/SuffixArray.cpp\"\n\nstruct LongestCommonPrefixArray\
    \ {\n    const SuffixArray &SA;\n    vector<int> LCP, rank;\n\n    LongestCommonPrefixArray(const\
    \ SuffixArray &SA) : SA(SA), LCP(SA.size()) {\n        rank.resize(SA.size());\n\
    \        for (int i = 0; i < SA.size(); i++) {\n            rank[SA[i]] = i;\n\
    \        }\n        for (int i = 0, h = 0; i < SA.size(); i++) {\n           \
    \ if (rank[i] + 1 < SA.size()) {\n                for (int j = SA[rank[i] + 1];\n\
    \                     max(i, j) + h < SA.size() && SA.s[i + h] == SA.s[j + h];\n\
    \                     ++h)\n                    ;\n                LCP[rank[i]\
    \ + 1] = h;\n                if (h > 0) --h;\n            }\n        }\n    }\n\
    \n    int operator[](int k) const { return LCP[k]; }\n\n    int size() const {\
    \ return LCP.size(); }\n\n    void show() {\n        for (int i = 0; i < size();\
    \ i++) {\n            cout << i << \": \" << LCP[i] << \" \" << SA.s.substr(SA[i])\
    \ << endl;\n        }\n    }\n};"
  dependsOn:
  - library/string/SuffixArray.cpp
  isVerificationFile: false
  path: library/string/LongestCommonPrefixArray.cpp
  requiredBy:
  - verify/yuki-1408.cpp
  timestamp: '2020-11-19 21:50:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/LongestCommonPrefixArray.cpp
layout: document
redirect_from:
- /library/library/string/LongestCommonPrefixArray.cpp
- /library/library/string/LongestCommonPrefixArray.cpp.html
title: library/string/LongestCommonPrefixArray.cpp
---
