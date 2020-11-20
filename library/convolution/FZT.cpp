// 部分集合に関する和
// 上位集合に関する和にもできる（s->(1<<n)-1-sにするだけ)
template <typename T>
vector<T> FZT(vector<T> f) {
    int N = 0;
    int tmp = f.size();
    while (tmp) N++, tmp /= 2;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < (1 << N); i++) {
            if (i & (1 << j)) {
                f[i] += f[i & ~(1 << j)];
            }
        }
    }
    return f;
}