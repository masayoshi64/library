
template <typename T = int>
struct LowLink : Graph<T> {
   public:
    using Graph<T>::Graph;
    vector<int> ord, low, articulation;
    vector<Edge<T> > bridge;
    using Graph<T>::g;

    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)g.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
    }

    explicit LowLink(const Graph<T> &g) : Graph<T>(g) {}

   private:
    vector<int> used;

    int dfs(int idx, int k, int par) {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false;
        int cnt = 0;
        for (auto &to : g[idx]) {
            if (!used[to]) {  //後退辺でない場合
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                //根ではなく自分のord<=子のlowなら関節点
                is_articulation |= par >= 0 && low[to] >= ord[idx];
                //自分のord<子のlowなら橋
                if (ord[idx] < low[to]) bridge.emplace_back(to);
            } else {  //後退辺の場合
                low[idx] = min(low[idx], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;  // dfs木の頂点の場合
        if (is_articulation) articulation.push_back(idx);
        return k;
    }
};