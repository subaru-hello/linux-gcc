//コマンドライン引数からファイル名を一つ以上受け取り、そのファイルの中身を標準出力へ書き込んでいる。
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//コマンドライン引数を標準出力へ書き込むメソッド
static void do_cat(const char *path);
static void die(const char *s);

int
main(int argc, char *argv[])
{
  int i;

// argv[0]にはプログラム名が入っている。
// 引数が2以上だったら引数の分だけ標準出力に渡している。
  if (argc < 2) {
    fprintf(stderr, "%s: file name not given\n", argv[0]);
    exit(1);
  }
  for (i = 1; i < argc; i++){
    do_cat(argv[i]);
  }
  exit(0);
}

#define BUFFER_SIZE 2048

static void
do_cat(const char *path)
{
  int fd;
  unsigned char buf[BUFFER_SIZE];
  int n;

//ファイルを読み込み専用でopenしている
  fd = open(path, O_RDONLY);
  if(fd < 0) die(path);
//;;で無限ループをしている
  for(;;) {
// sizeof bufでbufとBUFFER_SIZEに関連を持たせている
    n = read(fd, buf, sizeof buf);
    if (n < 0) die(path);
    if (n == 0) break;
    if ( write(STDOUT_FILENO, buf, n) < 0) die(path);
  }
  if (close(fd) < 0) die(path);
}

static void
die(const char *s)
{
  perror(s);
  exit(1);
}


