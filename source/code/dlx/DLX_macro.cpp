#define _l(id) node[id].l
#define _r(id) node[id].r
#define _u(id) node[id].u
#define _d(id) node[id].d
#define _row(id) node[id].row
#define _col(id) node[id].col
// 沿某方向遍历一条链
#define _for(i, start, dir) \
  for (std::size_t i = _##dir(start); i != start; i = _##dir(i))