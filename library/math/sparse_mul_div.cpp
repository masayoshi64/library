void mul(FPS& f, int n, int expand = true) {
    if (expand) f.resize(f.size() + n);
    rrep(i, SZ(f)) {
        if (i - n >= 0) f[i] -= f[i - n];
    }
}

void div(FPS& f, int n) {
    rep(i, SZ(f)) {
        if (i + n < SZ(f)) f[i + n] += f[i];
    }
}