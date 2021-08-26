## メモ
Graphを継承しているので初期化はGraphに準じる
## 初期化
```c++
StronglyConnectedComponents<ll> scc(n);
scc.read();
scc.build();
```
## dag (Graph<T>)
縮約後のグラフ（DAG）が格納されている
## comp
元のグラフの頂点$v$が属する強連結成分のidを格納
## group
縮約後のグラフの頂点（強連結成分）に含まれる元のグラフの頂点のリスト
```c++
int i = scc.comp[v];
vector<int> group = scc.group[i];// v in group
```