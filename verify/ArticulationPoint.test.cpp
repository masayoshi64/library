#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "library/template/template.cpp"
// library
#include "library/graph/others/LowLink.cpp"
int main() {
    int v, e;
    cin >> v >> e;
    Graph g(v);
    g.read(e, 0);
    LowLink lg(g);
    lg.build();
    sort(all(lg.articulation));
    for (auto x : lg.articulation) {
        print(x);
    }
}