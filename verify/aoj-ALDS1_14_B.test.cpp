#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "library/template/template.cpp"
// library
#include "library/string/RollingHash.cpp"
int main() {
    string t, p;
    cin >> t >> p;
    int n = t.size(), m = p.size();
    RollingHash rht(t), rhp(p);
    rep(i, n - m + 1) {
        if (rht.get(i, i + m) == rhp.get(0, m)) print(i);
    }
}