---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DPL_5_G.test.cpp
    title: verify/aoj-DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod.test.cpp
    title: verify/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod_1000000007.test.cpp
    title: verify/yosupo-convolution_mod_1000000007.test.cpp
  - icon: ':x:'
    path: verify/yuki-650.test.cpp
    title: verify/yuki-650.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/mod/modint.cpp\"\ntemplate <int mod>\nstruct modint\
    \ {\n    int x;\n\n    modint() : x(0) {}\n\n    modint(long long y) : x(y >=\
    \ 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    modint& operator+=(const modint&\
    \ p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \n    modint& operator-=(const modint& p) {\n        if ((x += mod - p.x) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n\n    modint& operator*=(const modint&\
    \ p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n\
    \n    modint& operator/=(const modint& p) {\n        *this *= p.inverse();\n \
    \       return *this;\n    }\n\n    modint operator-() const { return modint(-x);\
    \ }\n\n    modint operator+(const modint& p) const { return modint(*this) += p;\
    \ }\n\n    modint operator-(const modint& p) const { return modint(*this) -= p;\
    \ }\n\n    modint operator*(const modint& p) const { return modint(*this) *= p;\
    \ }\n\n    modint operator/(const modint& p) const { return modint(*this) /= p;\
    \ }\n\n    bool operator==(const modint& p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const modint& p) const { return x != p.x; }\n\n    modint inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return modint(u);\n    }\n\n    modint pow(int64_t\
    \ n) const {\n        modint ret(1), mul(x);\n        while (n > 0) {\n      \
    \      if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const modint& p) {\n        return os << p.x;\n    }\n\n    friend istream&\
    \ operator>>(istream& is, modint& a) {\n        long long t;\n        is >> t;\n\
    \        a = modint<mod>(t);\n        return (is);\n    }\n\n    static int get_mod()\
    \ { return mod; }\n};\n"
  code: "template <int mod>\nstruct modint {\n    int x;\n\n    modint() : x(0) {}\n\
    \n    modint(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\
    \n    modint& operator+=(const modint& p) {\n        if ((x += p.x) >= mod) x\
    \ -= mod;\n        return *this;\n    }\n\n    modint& operator-=(const modint&\
    \ p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    modint& operator*=(const modint& p) {\n        x = (int)(1LL * x\
    \ * p.x % mod);\n        return *this;\n    }\n\n    modint& operator/=(const\
    \ modint& p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    modint operator-() const { return modint(-x); }\n\n    modint operator+(const\
    \ modint& p) const { return modint(*this) += p; }\n\n    modint operator-(const\
    \ modint& p) const { return modint(*this) -= p; }\n\n    modint operator*(const\
    \ modint& p) const { return modint(*this) *= p; }\n\n    modint operator/(const\
    \ modint& p) const { return modint(*this) /= p; }\n\n    bool operator==(const\
    \ modint& p) const { return x == p.x; }\n\n    bool operator!=(const modint& p)\
    \ const { return x != p.x; }\n\n    modint inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return modint(u);\n    }\n\n    modint pow(int64_t n) const {\n     \
    \   modint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1) ret\
    \ *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    friend ostream& operator<<(ostream& os, const modint& p)\
    \ {\n        return os << p.x;\n    }\n\n    friend istream& operator>>(istream&\
    \ is, modint& a) {\n        long long t;\n        is >> t;\n        a = modint<mod>(t);\n\
    \        return (is);\n    }\n\n    static int get_mod() { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/modint.cpp
  requiredBy: []
  timestamp: '2020-11-14 13:19:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo-convolution_mod_1000000007.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
  - verify/aoj-DPL_5_G.test.cpp
  - verify/yuki-650.test.cpp
documentation_of: library/mod/modint.cpp
layout: document
redirect_from:
- /library/library/mod/modint.cpp
- /library/library/mod/modint.cpp.html
title: library/mod/modint.cpp
---
