const int MAX_ROW = 100005;
const int MAX_COL = 65;

struct BitMatrix {
    int H, W, rank;
    vector<int> top;  // top bit
    bitset<MAX_COL> A[MAX_ROW];
    BitMatrix(int h = 1, int w = 1) : H(h), W(w), rank(0) { top.resize(h); }
    void build(bool is_extended = false) {
        rep(col, W) {
            if (is_extended && col == W - 1) break;
            int row = rank;
            for (; row < H; ++row) {
                if (A[row][col]) {
                    swap(A[rank], A[row]);
                    break;
                }
            }
            if (row == H) continue;
            top[rank] = col;
            rep(k, H) {
                if (k == rank) continue;
                if (A[k][col]) A[k] ^= A[rank];
            }
            ++rank;
        }
    }
    int solve(vector<int>& res) {
        // if it has no solution then return -1
        for (int row = rank; row < H; ++row)
            if (A[row][W - 1]) return -1;
        res.assign(W - 1, 0);
        for (int i = 0; i < rank; ++i) res[i] = A[i][W - 1];
        return rank;
    }
    inline bitset<MAX_COL>& operator[](int i) { return A[i]; }
};