#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include "library/template/template.cpp"
//
#include "library/mod/modint.cpp"
const ll mod = 1000000007;
using mint = modint<mod>;
// library
int main() {
    int n;
    cin >> n;
    vc c(n);
    scan(c);
    vector<mint> dp(n + 1);  // dp[i]:=保留した順位の数
    dp[0] = 1;
    // 前から見ていく
    rep(i, n) {
        vector<mint> tmp(n + 1);
        if (c[i] == '-') {
            continue;
        }
        rep(nokori, n + 1) {
            if (c[i] == 'D') {
                tmp[nokori] += dp[nokori] * nokori;
                if (nokori - 1 >= 0)
                    tmp[nokori - 1] += dp[nokori] * nokori * nokori;
            } else {
                if (nokori + 1 <= n) tmp[nokori + 1] += dp[nokori];
                tmp[nokori] += dp[nokori] * nokori;
            }
        }
        dp = tmp;
    }
    print(dp[0]);
}