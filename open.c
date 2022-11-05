#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// ファイルに接続するために、システムコールopen()を使用している。
//　ファイルディスクリプタがあるパスにつながるストリームを作成。
//int open(const char *path, int flags);
int open(const char *path, int flags, mode_t mode);.
