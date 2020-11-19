#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "library/template/template.cpp"
// library
#include "library/graph/connected-components/TwoSat.cpp"
int main() {
    string p, cnf;
    int n, m;
    cin >> p >> cnf >> n >> m;
    TwoSat ts(n);
    rep(i, m) {
        int u, v, z;
        cin >> u >> v >> z;
        if (u < 0)
            u = ts.rev(-u - 1);
        else
            u--;
        if (v < 0)
            v = ts.rev(-v - 1);
        else
            v--;
        ts.add_or(u, v);
    }
    auto ret = ts.solve();
    if (ret.size()) {
        cout << "s SATISFIABLE" << endl;
        cout << "v ";
        rep(i, n) cout << (ret[i] ? i + 1 : -i - 1) << ' ';
        cout << 0 << ' ' << endl;
    } else {
        cout << "s UNSATISFIABLE" << endl;
    }
}