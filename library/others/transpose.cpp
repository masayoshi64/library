template <typename T>
vector<vector<T>> transpose(vector<vector<T>>& vv) {
    int n = vv.size();
    int m = vv[0].size();
    vector<vector<T>> res(m, vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][i] = vv[i][j];
        }
    }
    return res;
}