#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "library/template/template.cpp"
// library
#include "library/math/extgcd.cpp"
int main() {
    ll a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
}