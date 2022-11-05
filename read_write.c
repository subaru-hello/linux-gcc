//ヘッダファイルを読み込む
#include <unistd.h>

//符号なし整数型を引数にとり、符号あり整数を返す。
//OSやCPUに違いがあっても同じソースコードが使えるように独自型を定義している

ssize_t read(int fd, void *buf, size_t bufsize);

// 正常に書き込んだ時は書いたバイト数を返す。
ssize_t write(int fd, const void *buf, size_t bufsize);
