## メモ
- yosupo judgeで75msくらい（入出力高速化あり）

- [速いmodint](https://ei1333.github.io/library/math/combinatorics/montgomery-mod-int.cpp)を使うといいかもしれない

## 初期化

```c++
NTT<ntt> ntt;
```

## 畳み込み
```c++
ntt.multiply(a, b);
```
多分ビットリバースしてない



