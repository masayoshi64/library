#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include "library/template/template.cpp"
// library
#include "library/graph/flow/BipartiteMatching.cpp"
int main() {
    int X, Y, E;
    cin >> X >> Y >> E;
    BipartiteMatching bm(X, Y);
    rep(i, E) {
        int x, y;
        cin >> x >> y;
        bm.add_edge(x, y);
    }
    print(bm.matching());
}