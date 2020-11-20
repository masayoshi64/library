#define PROBLEM "https://yukicoder.me/problems/1408"
#include "library/template/template.cpp"
// library
#include "library/string/LongestCommonPrefixArray.cpp"
int main() {
    int n;
    cin >> n;
    vector<string> vs(n);
    scan(vs);
    int m;
    cin >> m;
    ll x, d;
    cin >> x >> d;
    LongestCommonPrefixArray lcp() rep(k, 1, m + 1) {
        int i = (x / (n - 1));
        int j = (x % (n - 1));
        if (i > j)
            swap(i, j);
        else
            j++;
        x = (x + d) % (n * (n - 1));
    }
}