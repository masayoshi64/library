/**
 * @brief 拡張ユークリッドの互除法
 * @docs docs/extgcd.md
 */

// give the solution which minimize |x|+|y|
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;  // gcd(a, b)
}