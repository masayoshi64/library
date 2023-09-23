/**
 * @brief factorization(pollard)
 * @docs pollard.md
 */
#include "library/math/is_prime.cpp"
// In codeforces, delete __int128 in the second line.
// about O(N^1/4logN)
ll pollard_single(ll n) {
    auto f = [&](ll x) { return (__int128_t(x) * x + 1) % n; };
    // auto f = [&](ll x) { return (x * x + 1) % n; };
    if (is_prime(n)) return n;
    if (n % 2 == 0) return 2;
    ll st = 0;
    while (true) {
        st = xor64(n);
        ll x = st, y = f(x);
        while (true) {
            ll p = gcd((y - x + n), n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

vl pollard_rec(ll n) {
    if (n == 1) return {};
    ll x = pollard_single(n);
    if (x == n) return {x};
    vl a = pollard_rec(x);
    vl b = pollard_rec(n / x);
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

map<ll, int> pollard(ll n) {
    map<ll, int> res;
    for (ll a : pollard_rec(n)) {
        res[a]++;
    }
    return res;
}