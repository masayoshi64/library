#define PROBLEM "https://atcoder.jp/contests/abc136/tasks/abc136_d"

#include "library/template/template.cpp"
// library
#include "library/others/Doubling.cpp"
int main() {
    string s;
    cin >> s;
    int n = s.size();
    Doubling dl(n, 1000000000);
    rep(i, n) { dl.set_next(i, (s[i] == 'L' ? i - 1 : i + 1)); }
    dl.build();
    vi ans(n);
    rep(i, n) { ans[dl.query(i, 1000000000)]++; }
    cout << ans;
}