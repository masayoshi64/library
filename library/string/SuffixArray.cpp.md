---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_14_D.test.cpp
    title: verify/aoj-ALDS1_14_D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \": \" << s.substr(SA[i]) << endl;\n        }\n    }\n};\n"
  code: "struct SuffixArray {\n    vector<int> SA;\n    const string s;\n\n    SuffixArray(const\
    \ string &str) : s(str) {\n        SA.resize(s.size());\n        iota(begin(SA),\
    \ end(SA), 0);\n        sort(begin(SA), end(SA),\n             [&](int a, int\
    \ b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });\n        vector<int> classes(s.size()),\
    \ c(s.begin(), s.end()), cnt(s.size());\n        for (int len = 1; len < s.size();\
    \ len <<= 1) {\n            for (int i = 0; i < s.size(); i++) {\n           \
    \     if (i > 0 && c[SA[i - 1]] == c[SA[i]] &&\n                    SA[i - 1]\
    \ + len < s.size() &&\n                    c[SA[i - 1] + len / 2] == c[SA[i] +\
    \ len / 2]) {\n                    classes[SA[i]] = classes[SA[i - 1]];\n    \
    \            } else {\n                    classes[SA[i]] = i;\n             \
    \   }\n            }\n            iota(begin(cnt), end(cnt), 0);\n           \
    \ copy(begin(SA), end(SA), begin(c));\n            for (int i = 0; i < s.size();\
    \ i++) {\n                int s1 = c[i] - len;\n                if (s1 >= 0) SA[cnt[classes[s1]]++]\
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
    \ << \": \" << s.substr(SA[i]) << endl;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/string/SuffixArray.cpp
  requiredBy: []
  timestamp: '2020-11-19 13:05:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_14_D.test.cpp
documentation_of: library/string/SuffixArray.cpp
layout: document
redirect_from:
- /library/library/string/SuffixArray.cpp
- /library/library/string/SuffixArray.cpp.html
title: library/string/SuffixArray.cpp
---
