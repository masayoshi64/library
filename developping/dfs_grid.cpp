vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
mat<char> grid;
mat<int> dist;
rep(x, h) {
    rep(y, w) {
        rep(d, 4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && grid[nx][ny] == '.') {
                dist[nx][ny] = dist[x][y];
            }
        }
    }
}