---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki-650.test.cpp
    title: verify/yuki-650.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/Matrix.cpp\"\ntemplate <class T>\nstruct Matrix\
    \ {\n    vector<vector<T>> A;\n\n    Matrix() {}\n\n    Matrix(size_t n, size_t\
    \ m) : A(n, vector<T>(m, 0)) {}\n\n    Matrix(size_t n) : A(n, vector<T>(n, 0)){};\n\
    \n    Matrix(vector<vector<T>> a) { A = a; }\n\n    size_t height() const { return\
    \ (A.size()); }\n\n    size_t width() const { return (A[0].size()); }\n\n    inline\
    \ const vector<T> &operator[](int k) const { return (A.at(k)); }\n\n    inline\
    \ vector<T> &operator[](int k) { return (A.at(k)); }\n\n    static Matrix I(size_t\
    \ n) {\n        Matrix mat(n);\n        for (int i = 0; i < n; i++) mat[i][i]\
    \ = 1;\n        return (mat);\n    }\n\n    Matrix &operator+=(const Matrix &B)\
    \ {\n        size_t n = height(), m = width();\n        assert(n == B.height()\
    \ && m == B.width());\n        for (int i = 0; i < n; i++)\n            for (int\
    \ j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n        return (*this);\n    }\n\
    \n    Matrix &operator-=(const Matrix &B) {\n        size_t n = height(), m =\
    \ width();\n        assert(n == B.height() && m == B.width());\n        for (int\
    \ i = 0; i < n; i++)\n            for (int j = 0; j < m; j++) (*this)[i][j] -=\
    \ B[i][j];\n        return (*this);\n    }\n\n    Matrix &operator*=(const Matrix\
    \ &B) {\n        size_t n = height(), m = B.width(), p = width();\n        assert(p\
    \ == B.height());\n        vector<vector<T>> C(n, vector<T>(m, 0));\n        for\
    \ (int i = 0; i < n; i++)\n            for (int j = 0; j < m; j++)\n         \
    \       for (int k = 0; k < p; k++)\n                    C[i][j] = (C[i][j] +\
    \ (*this)[i][k] * B[k][j]);\n        A.swap(C);\n        return (*this);\n   \
    \ }\n\n    Matrix &operator^=(long long k) {\n        Matrix B = Matrix::I(height());\n\
    \        while (k > 0) {\n            if (k & 1) B *= *this;\n            *this\
    \ *= *this;\n            k >>= 1LL;\n        }\n        A.swap(B.A);\n       \
    \ return (*this);\n    }\n\n    Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n    Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n    Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n    Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n    Matrix pow(long long n) {\n        Matrix ret\
    \ = I(height());\n        Matrix x = Matrix(*this);\n        while (n > 0) {\n\
    \            if (n & 1) (ret *= x);\n            (x *= x);\n            n >>=\
    \ 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        size_t n = p.height(), m = p.width();\n        for\
    \ (int i = 0; i < n; i++) {\n            os << \"[\";\n            for (int j\
    \ = 0; j < m; j++) {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\"\
    \ : \",\");\n            }\n        }\n        return (os);\n    }\n\n    T determinant()\
    \ {\n        Matrix B(*this);\n        assert(width() == height());\n        T\
    \ ret = 1;\n        for (int i = 0; i < width(); i++) {\n            int idx =\
    \ -1;\n            for (int j = i; j < width(); j++) {\n                if (B[j][i]\
    \ != 0) idx = j;\n            }\n            if (idx == -1) return (0);\n    \
    \        if (i != idx) {\n                ret *= -1;\n                swap(B[i],\
    \ B[idx]);\n            }\n            ret *= B[i][i];\n            T vv = B[i][i];\n\
    \            for (int j = 0; j < width(); j++) {\n                B[i][j] /= vv;\n\
    \            }\n            for (int j = i + 1; j < width(); j++) {\n        \
    \        T a = B[j][i];\n                for (int k = 0; k < width(); k++) {\n\
    \                    B[j][k] -= B[i][k] * a;\n                }\n            }\n\
    \        }\n        return (ret);\n    }\n};\n"
  code: "template <class T>\nstruct Matrix {\n    vector<vector<T>> A;\n\n    Matrix()\
    \ {}\n\n    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n\n    Matrix(size_t\
    \ n) : A(n, vector<T>(n, 0)){};\n\n    Matrix(vector<vector<T>> a) { A = a; }\n\
    \n    size_t height() const { return (A.size()); }\n\n    size_t width() const\
    \ { return (A[0].size()); }\n\n    inline const vector<T> &operator[](int k) const\
    \ { return (A.at(k)); }\n\n    inline vector<T> &operator[](int k) { return (A.at(k));\
    \ }\n\n    static Matrix I(size_t n) {\n        Matrix mat(n);\n        for (int\
    \ i = 0; i < n; i++) mat[i][i] = 1;\n        return (mat);\n    }\n\n    Matrix\
    \ &operator+=(const Matrix &B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() && m == B.width());\n        for (int i = 0; i\
    \ < n; i++)\n            for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n\
    \        return (*this);\n    }\n\n    Matrix &operator-=(const Matrix &B) {\n\
    \        size_t n = height(), m = width();\n        assert(n == B.height() &&\
    \ m == B.width());\n        for (int i = 0; i < n; i++)\n            for (int\
    \ j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n        return (*this);\n    }\n\
    \n    Matrix &operator*=(const Matrix &B) {\n        size_t n = height(), m =\
    \ B.width(), p = width();\n        assert(p == B.height());\n        vector<vector<T>>\
    \ C(n, vector<T>(m, 0));\n        for (int i = 0; i < n; i++)\n            for\
    \ (int j = 0; j < m; j++)\n                for (int k = 0; k < p; k++)\n     \
    \               C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n        A.swap(C);\n\
    \        return (*this);\n    }\n\n    Matrix &operator^=(long long k) {\n   \
    \     Matrix B = Matrix::I(height());\n        while (k > 0) {\n            if\
    \ (k & 1) B *= *this;\n            *this *= *this;\n            k >>= 1LL;\n \
    \       }\n        A.swap(B.A);\n        return (*this);\n    }\n\n    Matrix\
    \ operator+(const Matrix &B) const { return (Matrix(*this) += B); }\n\n    Matrix\
    \ operator-(const Matrix &B) const { return (Matrix(*this) -= B); }\n\n    Matrix\
    \ operator*(const Matrix &B) const { return (Matrix(*this) *= B); }\n\n    Matrix\
    \ operator^(const long long k) const { return (Matrix(*this) ^= k); }\n\n    Matrix\
    \ pow(long long n) {\n        Matrix ret = I(height());\n        Matrix x = Matrix(*this);\n\
    \        while (n > 0) {\n            if (n & 1) (ret *= x);\n            (x *=\
    \ x);\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, Matrix &p) {\n        size_t n = p.height(),\
    \ m = p.width();\n        for (int i = 0; i < n; i++) {\n            os << \"\
    [\";\n            for (int j = 0; j < m; j++) {\n                os << p[i][j]\
    \ << (j + 1 == m ? \"]\\n\" : \",\");\n            }\n        }\n        return\
    \ (os);\n    }\n\n    T determinant() {\n        Matrix B(*this);\n        assert(width()\
    \ == height());\n        T ret = 1;\n        for (int i = 0; i < width(); i++)\
    \ {\n            int idx = -1;\n            for (int j = i; j < width(); j++)\
    \ {\n                if (B[j][i] != 0) idx = j;\n            }\n            if\
    \ (idx == -1) return (0);\n            if (i != idx) {\n                ret *=\
    \ -1;\n                swap(B[i], B[idx]);\n            }\n            ret *=\
    \ B[i][i];\n            T vv = B[i][i];\n            for (int j = 0; j < width();\
    \ j++) {\n                B[i][j] /= vv;\n            }\n            for (int\
    \ j = i + 1; j < width(); j++) {\n                T a = B[j][i];\n           \
    \     for (int k = 0; k < width(); k++) {\n                    B[j][k] -= B[i][k]\
    \ * a;\n                }\n            }\n        }\n        return (ret);\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/Matrix.cpp
  requiredBy: []
  timestamp: '2020-11-18 22:08:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki-650.test.cpp
documentation_of: library/math/Matrix.cpp
layout: document
redirect_from:
- /library/library/math/Matrix.cpp
- /library/library/math/Matrix.cpp.html
title: library/math/Matrix.cpp
---
