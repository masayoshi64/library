---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/mod/ArbitaryModInt.cpp\"\nstruct ArbitraryModInt\
    \ {\n    int x;\n\n    ArbitraryModInt() : x(0) {}\n\n    ArbitraryModInt(int64_t\
    \ y)\n        : x(y >= 0 ? y % Mod() : (Mod() - (-y) % Mod()) % Mod()) {}\n\n\
    \    static int& Mod() {\n        static int Mod = 0;\n        return Mod;\n \
    \   }\n\n    static void set_mod(int md) { Mod() = md; }\n\n    ArbitraryModInt&\
    \ operator+=(const ArbitraryModInt& p) {\n        if ((x += p.x) >= Mod()) x -=\
    \ Mod();\n        return *this;\n    }\n\n    ArbitraryModInt& operator-=(const\
    \ ArbitraryModInt& p) {\n        if ((x += Mod() - p.x) >= Mod()) x -= Mod();\n\
    \        return *this;\n    }\n\n    ArbitraryModInt& operator*=(const ArbitraryModInt&\
    \ p) {\n        unsigned long long a = (unsigned long long)x * p.x;\n        unsigned\
    \ xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;\n        asm(\"divl %4; \\\
    n\t\"\n            : \"=a\"(d), \"=d\"(m)\n            : \"d\"(xh), \"a\"(xl),\
    \ \"r\"(Mod()));\n        x = m;\n        return *this;\n    }\n\n    ArbitraryModInt&\
    \ operator/=(const ArbitraryModInt& p) {\n        *this *= p.inverse();\n    \
    \    return *this;\n    }\n\n    ArbitraryModInt operator-() const { return ArbitraryModInt(-x);\
    \ }\n\n    ArbitraryModInt operator+(const ArbitraryModInt& p) const {\n     \
    \   return ArbitraryModInt(*this) += p;\n    }\n\n    ArbitraryModInt operator-(const\
    \ ArbitraryModInt& p) const {\n        return ArbitraryModInt(*this) -= p;\n \
    \   }\n\n    ArbitraryModInt operator*(const ArbitraryModInt& p) const {\n   \
    \     return ArbitraryModInt(*this) *= p;\n    }\n\n    ArbitraryModInt operator/(const\
    \ ArbitraryModInt& p) const {\n        return ArbitraryModInt(*this) /= p;\n \
    \   }\n\n    bool operator==(const ArbitraryModInt& p) const { return x == p.x;\
    \ }\n\n    bool operator!=(const ArbitraryModInt& p) const { return x != p.x;\
    \ }\n\n    ArbitraryModInt inverse() const {\n        int a = x, b = Mod(), u\
    \ = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n          \
    \  swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n       \
    \ return ArbitraryModInt(u);\n    }\n\n    ArbitraryModInt pow(int64_t n) const\
    \ {\n        ArbitraryModInt ret(1), mul(x);\n        while (n > 0) {\n      \
    \      if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const ArbitraryModInt& p) {\n        return os << p.x;\n    }\n\n    friend\
    \ istream& operator>>(istream& is, ArbitraryModInt& a) {\n        int64_t t;\n\
    \        is >> t;\n        a = ArbitraryModInt(t);\n        return (is);\n   \
    \ }\n\n    static int get_mod() { return Mod(); }\n\n    constexpr int get() const\
    \ { return x; }\n};\n#define amint ArbitraryModInt\n// amint::set_mod(mod);\n"
  code: "struct ArbitraryModInt {\n    int x;\n\n    ArbitraryModInt() : x(0) {}\n\
    \n    ArbitraryModInt(int64_t y)\n        : x(y >= 0 ? y % Mod() : (Mod() - (-y)\
    \ % Mod()) % Mod()) {}\n\n    static int& Mod() {\n        static int Mod = 0;\n\
    \        return Mod;\n    }\n\n    static void set_mod(int md) { Mod() = md; }\n\
    \n    ArbitraryModInt& operator+=(const ArbitraryModInt& p) {\n        if ((x\
    \ += p.x) >= Mod()) x -= Mod();\n        return *this;\n    }\n\n    ArbitraryModInt&\
    \ operator-=(const ArbitraryModInt& p) {\n        if ((x += Mod() - p.x) >= Mod())\
    \ x -= Mod();\n        return *this;\n    }\n\n    ArbitraryModInt& operator*=(const\
    \ ArbitraryModInt& p) {\n        unsigned long long a = (unsigned long long)x\
    \ * p.x;\n        unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;\n\
    \        asm(\"divl %4; \\n\t\"\n            : \"=a\"(d), \"=d\"(m)\n        \
    \    : \"d\"(xh), \"a\"(xl), \"r\"(Mod()));\n        x = m;\n        return *this;\n\
    \    }\n\n    ArbitraryModInt& operator/=(const ArbitraryModInt& p) {\n      \
    \  *this *= p.inverse();\n        return *this;\n    }\n\n    ArbitraryModInt\
    \ operator-() const { return ArbitraryModInt(-x); }\n\n    ArbitraryModInt operator+(const\
    \ ArbitraryModInt& p) const {\n        return ArbitraryModInt(*this) += p;\n \
    \   }\n\n    ArbitraryModInt operator-(const ArbitraryModInt& p) const {\n   \
    \     return ArbitraryModInt(*this) -= p;\n    }\n\n    ArbitraryModInt operator*(const\
    \ ArbitraryModInt& p) const {\n        return ArbitraryModInt(*this) *= p;\n \
    \   }\n\n    ArbitraryModInt operator/(const ArbitraryModInt& p) const {\n   \
    \     return ArbitraryModInt(*this) /= p;\n    }\n\n    bool operator==(const\
    \ ArbitraryModInt& p) const { return x == p.x; }\n\n    bool operator!=(const\
    \ ArbitraryModInt& p) const { return x != p.x; }\n\n    ArbitraryModInt inverse()\
    \ const {\n        int a = x, b = Mod(), u = 1, v = 0, t;\n        while (b >\
    \ 0) {\n            t = a / b;\n            swap(a -= t * b, b);\n           \
    \ swap(u -= t * v, v);\n        }\n        return ArbitraryModInt(u);\n    }\n\
    \n    ArbitraryModInt pow(int64_t n) const {\n        ArbitraryModInt ret(1),\
    \ mul(x);\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n     \
    \       mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n  \
    \  }\n\n    friend ostream& operator<<(ostream& os, const ArbitraryModInt& p)\
    \ {\n        return os << p.x;\n    }\n\n    friend istream& operator>>(istream&\
    \ is, ArbitraryModInt& a) {\n        int64_t t;\n        is >> t;\n        a =\
    \ ArbitraryModInt(t);\n        return (is);\n    }\n\n    static int get_mod()\
    \ { return Mod(); }\n\n    constexpr int get() const { return x; }\n};\n#define\
    \ amint ArbitraryModInt\n// amint::set_mod(mod);"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/ArbitaryModInt.cpp
  requiredBy: []
  timestamp: '2020-12-18 23:34:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mod/ArbitaryModInt.cpp
layout: document
redirect_from:
- /library/library/mod/ArbitaryModInt.cpp
- /library/library/mod/ArbitaryModInt.cpp.html
title: library/mod/ArbitaryModInt.cpp
---
