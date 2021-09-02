## メモ
- あえてライブラリにするまでもない気もする

## 使い方
```c++
vector<int> s;
vector<int> dist = multi_source_dijkstra(g, s);
```
始点が複数ある場合への拡張