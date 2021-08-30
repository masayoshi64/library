## 概要
以下の線形計画問題は最短路問題に帰着して解くことができる
$$
\min_x x_t-x_s \text{s.t. } x_i-x_j \leq w_{ij}
$$

## 方法
頂点$i, j$間に長さ$w_{ij}$の辺をはってdijkstraかbellman-fordで$s, t$の最短路を求めると
その長さが上の線形計画問題の最適値で、$x_i = dist[s][i]$が最適解になる。