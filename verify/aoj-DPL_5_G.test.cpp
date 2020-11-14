#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"
#include "library/template/template.cpp"
// library
#include "library/math/combination.cpp"
#include "library/mod/modint.cpp"
#define mod 1000000007ll
using mint = modint<mod>;
int main() {
    int n, k;
    cin >> n >> k;
    Combination<mint> comb(n);
    print(comb.Bell(n, k));
    return 0;
}