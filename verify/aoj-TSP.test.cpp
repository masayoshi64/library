#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja"

#include "library/template/template.cpp"
// library
#include "library/graph/distance/TSP.cpp"
int main() {
    int V, E;
    cin >> V >> E;
    Graph<int> g(V);
    g.read(E, 0, true, true);
    auto dp = TSP(g);
    cout << (dp[(1 << V) - 1][0] < inf ? dp[(1 << V) - 1][0] : -1) << endl;
}