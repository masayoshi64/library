/**
 * @brief Fast Zeta Transform
 * @docs docs/FZT.md
 * @details 全ての部分集合$T_i$について$\sum_{S \subset T_i}f(S)$を計算
 */
template <typename T>
vector<T> FZT(vector<T> f)
{
    int N = 0;
    int tmp = f.size();
    while (tmp > 1)
        N++, tmp /= 2;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < (1 << N); i++)
        {
            if (i & (1 << j))
            {
                f[i] += f[i & ~(1 << j)];
            }
        }
    }
    return f;
}