## メモ
- fftとは名ばかりでnttを3つのmodで行って復元してる

## 初期化
```c++
FFT fft;
```

## multiply
- 任意mod用
```c++
auto c = fft.multiply(a, b);
```

## multiply_ll
- intやlong long用
- int128も行けると思われる
```c++
auto c = fft.multiply(a, b);
```