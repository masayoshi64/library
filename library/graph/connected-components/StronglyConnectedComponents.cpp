#pragma once
template <typename T = int>
struct StronglyConnectedComponents : Graph<T>
{
public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    vector<int> comp;          // id of scc
    Graph<T> dag;              // DAG
    vector<vector<int>> group; // lists of each scc

    void build()
    {
        rg = Graph<T>(g.size());
        // add reversed edges
        for (int i = 0; i < g.size(); i++)
        {
            for (auto &e : g[i])
            {
                rg.add_directed_edge(e.to, e.from, e.cost);
            }
        }
        comp.assign(g.size(), -1);
        used.assign(g.size(), 0);
        // dfs for (not reversed) graph
        for (int i = 0; i < g.size(); i++)
            dfs(i);
        reverse(begin(order), end(order));
        int ptr = 0;
        for (int i : order)
            if (comp[i] == -1)
                rdfs(i, ptr), ptr++;
        dag = Graph<T>(ptr);
        for (int i = 0; i < g.size(); i++)
        {
            for (auto &e : g[i])
            {
                int x = comp[e.from], y = comp[e.to];
                if (x == y)
                    continue;
                dag.add_directed_edge(x, y, e.cost);
            }
        }
        group.resize(ptr);
        for (int i = 0; i < g.size(); i++)
        {
            group[comp[i]].emplace_back(i);
        }
    }

    int operator[](int k) const { return comp[k]; }

private:
    vector<int> order, used; // order:post order
    Graph<T> rg;             // reversed graph

    void dfs(int idx)
    {
        if (exchange(used[idx], true))
            return;
        for (auto &to : g[idx])
            dfs(to);
        order.push_back(idx);
    }

    void rdfs(int idx, int cnt)
    {
        if (comp[idx] != -1)
            return;
        comp[idx] = cnt;
        for (auto &to : rg.g[idx])
            rdfs(to, cnt);
    }
};