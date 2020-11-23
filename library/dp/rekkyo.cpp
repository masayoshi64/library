template <typename T>
vector<T> rekkyo(const vector<T>& items) {
    vector<T> res = {0}, tmp, tmp1;
    for (T item : items) {
        for (auto val : res) {
            tmp.pb(item + val);
        }
        //ソートされたままmerge
        merge(all(res), all(tmp), back_inserter(tmp1));
        swap(res, tmp1);
        tmp.clear();
        tmp1.clear();
    }
    return res;
}

// vector<T> a = rekkyo({items.begin(), items.begin() + n / 2});
// vector<T> b = rekkyo({items.begin() + n / 2, items.end()});