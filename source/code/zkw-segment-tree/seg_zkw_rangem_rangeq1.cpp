//区间修改+区间查询1
#include<cstdio>

const int MAXN = 2e5 + 5;
int tree[MAXN<<2];
int add[MAXN<<2]; //这个lazy tag表示当前结点已经更新完, 需要更新子结点
int n, N=1;

#define fp(i,l,r) for(register int i=(l);i<=(r);++i)
#define fd(i,r,l) for(register int i=(r);i>=(l);--i)

void build() {
  scanf("%d", &n);
  for(; N <= n+1; N <<= 1);
  fp(i, N+1, N+n) scanf("%d", tree+i);
  fd(i, N-1, 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void update(int s, int t, int k) {
  //lNum:  s一路走来已经包含了几个数
  //rNum:  t一路走来已经包含了几个数
  //nNum:  本层每个结点包含几个数
  int lNum=0, rNum=0, nNum=1;
  for(s = N+s-1, t = N+t+1; s^t^1; s >>= 1, t >>= 1, nNum <<= 1) {
    //更新tree
    tree[s] += k*lNum;
    tree[t] += k*rNum;
    //处理add
    if(~s&1) {add[s^1] += k; tree[s^1] += k*nNum; lNum += nNum;}
    if(t&1) {add[t^1] += k; tree[t^1] += k*nNum; rNum += nNum;}
  }
  //更新上层tree
  for(; s; s >>= 1, t >>= 1) {
    tree[s] += k*lNum;
    tree[t] += k*rNum;
  }
}

int query(int s, int t){
  int lNum=0, rNum=0, nNum=1;
  int ans=0;
  for(s = N+s-1, t = N+t+1; s^t^1; s >>= 1, t >>= 1, nNum <<= 1) {
    //根据标记更新
    if(add[s]) ans += add[s]*lNum;
    if(add[t]) ans += add[t]*rNum;
    //常规求和
    if(~s&1) {ans += tree[s^1]; lNum += nNum;}
    if(t&1) {ans += tree[t^1]; rNum += nNum;}
  }
  //处理上层标记
  for(; s; s >>= 1, t >>= 1) {
    ans += add[s]*lNum;
    ans += add[t]*rNum;
  }
  return ans;
}

int main() {
  // 同上
}
