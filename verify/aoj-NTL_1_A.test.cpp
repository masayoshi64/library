#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "library/template/template.cpp"
// library
#include "library/math/pollard.cpp"
int main() {
    int n;
    cin >> n;
    auto res = pollard(n);
    cout << n << ':';
    for (auto [p, i] : res) {
        rep(j, i) cout << ' ' << p;
    }
    cout << endl;
}