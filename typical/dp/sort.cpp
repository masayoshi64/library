#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include "library/template/template.cpp"
//
#include "library/mod/modint.cpp"
const ll mod = 1000000007;
using mint = modint<mod>;
// library
int main() {
    int n, w;
    cin >> n >> w;
    vi weight(n);
    scan(weight);
    if (vsum(weight) <= w) {
        print(1);
        return 0;
    }
    sort(rall(weight));
    vector<mint> dp(w + 1);
    mint ans = 0;
    vl cumsum(n + 1);
    rep(i, n) cumsum[i + 1] = cumsum[i] + weight[i];
    dp[0] = 1;
    rep(i, n) {
        vector<mint> tmp(w + 1);
        rep(j, w + 1) {
            if (j + weight[i] <= w) tmp[j + weight[i]] += dp[j];
            tmp[j] += dp[j];
            ll sm = j + cumsum[n] - cumsum[i + 1];
            // 最後に撮らないのがiの場合,
            // i番目が入らなければi番目より前のものは入らないので
            // i番目だけ調べればいい
            if (sm <= w && sm + weight[i] > w) ans += dp[j];
        }
        dp = tmp;
    }
    print(ans);
}