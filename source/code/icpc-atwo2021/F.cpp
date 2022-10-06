#include <bits/stdc++.h>
#define int long long
#define inc(i) (++(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
using ll = long long;
using namespace std;
const int N = 200000 + 7;
int n, q;
int A[N];
struct Node {
  int l, r, ll, rl, w, flag, Sz;
  Node(int _l = 0, int _r = 0, int _ll = 0, int _rl = 0, int _w = 0, int _flag = 0, int _Sz = 0): l(_l), r(_r), ll(_ll), rl(_rl), w(_w), flag(_flag), Sz(_Sz) {}
  friend Node operator+(const Node &A, const Node &B) {
    if (A.Sz == 0) return B;
    if (B.Sz == 0) return A;
    Node C;
    C.w = A.w + B.w, C.l = A.l, C.r = B.r;
    C.ll = A.ll, C.rl = B.rl;
    C.Sz = A.Sz + B.Sz;
    if (A.r == B.l ^ 1) {
      C.w += A.rl * B.ll;
      if (A.rl == A.Sz) C.ll = B.ll + A.Sz;
      if (B.ll == B.Sz) C.rl = A.rl + B.Sz;
    }
    return C;
  }
} T[N << 2];
void Build(int x, int l, int r) {
  if (l == r) {
    T[x] = Node(A[l], A[r], 1, 1, 1, 0, 1);
    return;
  }
  int Mid = (l + r) >> 1;
  Build(x << 1, l, Mid), Build(x << 1 | 1, Mid + 1, r);
  T[x] = T[x << 1] + T[x << 1 | 1];
}
void Pushdown(int x) {
  if (T[x].flag) {
    T[x].flag = 0;
    T[x << 1].l ^= 1, T[x << 1].r ^= 1, T[x << 1].flag ^= 1;
    T[x << 1 | 1].l ^= 1, T[x << 1 | 1].r ^= 1, T[x << 1 | 1].flag ^= 1;
  }
}
void Update(int x, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    T[x].l ^= 1, T[x].r ^= 1, T[x].flag ^= 1;
    return;
  }
  Pushdown(x);
  int Mid = (l + r) >> 1;
  if (Mid >= L) Update(x << 1, l, Mid, L, R);
  if (Mid < R) Update(x << 1 | 1, Mid + 1, r, L, R);
  T[x] = T[x << 1] + T[x << 1 | 1];
}
Node Query(int x, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[x];
  Pushdown(x);
  int Mid = (l + r) >> 1;
  Node Ans;
  if (Mid >= L) Ans = Query(x << 1, l, Mid, L, R);
  if (Mid < R) Ans = Ans + Query(x << 1 | 1, Mid + 1, r, L, R);
  return Ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  Rep(i, 1, n) cin >> A[i];
  Build(1, 1, n);
  int opt, l, r;
  Rep(i, 1, q) {
    cin >> opt >> l >> r;
    if (opt == 1) Update(1, 1, n, l, r);
    else cout << Query(1, 1, n, l, r).w << '\n';
  }
  return 0;
}
