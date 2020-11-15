/**
 * @brief is_prime(miller-rabin)
 * @docs docs/is_prime.md
 */
// codeforcesでは__int128が使えないので消すこと
// http://miller-rabin.appspot.com/
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        a %= n;
        if (a == 0) return true;
        ll t = d;
        ll y = modpow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = __int128_t(y) * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}