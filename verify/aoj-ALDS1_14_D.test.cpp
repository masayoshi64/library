#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include "library/template/template.cpp"
// library
#include "library/string/SuffixArray.cpp"
int main() {
    string t;
    cin >> t;
    SuffixArray sa(t);
    int q;
    cin >> q;
    while (q--) {
        string p;
        cin >> p;
        auto range = sa.lower_upper_bound(p);
        print((range.first != range.second));
    }
}