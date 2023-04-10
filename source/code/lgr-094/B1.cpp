// 快读模板
// 赛时提醒: 快读没有太大必要使用
inline int64_t read() {
  int64_t s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}