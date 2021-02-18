
//オーバーフローに注意

// ハミルトン閉路
template <typename T>
T TSP1(vector<vector<T>> dist) {
    int n = dist.size();
    T TINF = numeric_limits<T>::max();
    vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));
    dp[0][0] = 0;
    rep(s, (1 << n)) {
        rep(pv, n) {
            rep(nv, n) {
                chmin(dp[s | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);
                chmin(dp[s | (1 << nv)][nv], TINF / 2);
            }
        }
    }
    return vmin(dp[(1 << n) - 1]);
}

// ハミルトンパス from st
template <typename T>
T TSP2(vector<vector<T>> dist, int st) {
    int n = dist.size();
    T TINF = numeric_limits<T>::max();
    vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));
    dp[(1 << st)][st] = 0;
    rep(s, (1 << n)) {
        rep(pv, n) {
            rep(nv, n) {
                chmin(dp[s | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);
                chmin(dp[s | (1 << nv)][nv], TINF / 2);
            }
        }
    }
    return vmin(dp[(1 << n) - 1]);
}

// ハミルトンパス from anywhere
template <typename T>
T TSP3(vector<vector<T>> dist) {
    int n = dist.size();
    T TINF = numeric_limits<T>::max();
    vector<vector<T>> dp(1 << n, vector<T>(n, TINF / 2));
    rep(s, n) dp[(1 << s)][s] = 0;
    rep(s, (1 << n)) {
        rep(pv, n) {
            rep(nv, n) {
                chmin(dp[s | (1 << nv)][nv], dp[s][pv] + dist[pv][nv]);
                chmin(dp[s | (1 << nv)][nv], TINF / 2);
            }
        }
    }
    return vmin(dp[(1 << n) - 1]);
}